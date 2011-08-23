#include "scenewidget.h"

SceneWidget::SceneWidget(QWidget *parent,Dom::DomType type) :
    QWidget(parent)
{
    m_dom = new Dom();
    m_dom->setType(type);
    m_mode = SWModeIdle;
    m_scn = new GraphicScene(this);
    m_view = new QGraphicsView(m_scn,this);
    m_scn->setSceneRect(0,0,5000,5000);

    connect(m_scn,SIGNAL(mouseReleaseSignal(QPointF)),this,SLOT(SceneMouseReleased(QPointF)));
    connect(m_scn,SIGNAL(selectionChanged()),this,SLOT(SceneSelection()));
    connect(m_scn,SIGNAL(mouseContextMenuSignal(QPointF)),this,SLOT(SceneContextMenu(QPointF)));
}


void SceneWidget::SceneSelection()
{
    m_prevVert = m_currVert;
    if (m_scn->selectedItems().count() != 0)
    {
        m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
    }
    else
    {
        m_currVert = 0;
    }
}

void SceneWidget::SceneMouseReleased(QPointF pos)
{
    switch (m_mode)
    {
    case SWModeDelVert:
    {
        m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());        
        foreach (Arrow * arr,m_dom->arrows())
        {
            if (arr->startitem() == m_currVert || arr->stopitem() == m_currVert)
            {
                CmdDelArr *cmdDelArr = new CmdDelArr(arr,m_scn);
                l_commands.append(cmdDelArr);
                emit logSignal("Del arr\n");
                cmdDelArr->Do();
            }
        }
        CmdDelVert* cmddel = new CmdDelVert(m_currVert,m_scn);
        l_commands.append(cmddel);
        emit logSignal("Del vert\n");
        cmddel->Do();
        m_mode = SWModeIdle;
    }
    break;
    case SWModeDelArrow:
    {
        Arrow *m_currArrow = dynamic_cast<Arrow*>(m_scn->selectedItems().first());
        CmdDelArr *cmdDelArr = new CmdDelArr(m_currArrow,m_scn);
        l_commands.append(cmdDelArr);
        emit logSignal("Del arr\n");
        cmdDelArr->Do();
    }
    break;
    case SWModeAddVer:
    {
        Vertex* newvert = new Vertex(0,0);
        QString newvertid;
        newvertid.setNum(m_dom->verts().count()+1);
        newvert->setId(newvert->id()+newvertid);
        if (m_dom->type() == Dom::DTProcess)
        {
            newvert->setVType(Vertex::VTMethod);
        }
        CmdAddVert* cmdadd = new CmdAddVert(newvert,m_scn);
        cmdadd->Do();
        m_dom->addVert(newvert);
        l_commands.append(cmdadd);
        emit logSignal("Added vert\n");
        CmdVertSetPos *cmdsetpos = new CmdVertSetPos(newvert,pos);
        cmdsetpos->Do();
        l_commands.append(cmdsetpos);
        emit logSignal("Set Pos\n");
        m_mode = SWModeIdle;
    }
    break;
    case SWModeAddArrowP1:
    {
        if (m_scn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            m_prevVert = m_currVert;
            m_currVert->setOpacity(0.25);
            m_mode = SWModeAddArrowP2;
            emit logSignal("Adding arrow, selected first item\n");
        }
    }
    break;
    case SWModeAddArrowP2:
    {
        if (m_scn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            if (m_currVert != m_prevVert) {
                Arrow * newarr = new Arrow(m_prevVert,m_currVert);
                switch (m_currVert->vtype())
                {
                case Vertex::VTPort:
                {
                    newarr->setArrowType(Arrow::ATSend);
                }break;
                case Vertex::VTMethod:
                {
                    newarr->setArrowType(Arrow::ATActivate);
                }
                }
                QString newarrid;
                newarrid.setNum(random());
                newarr->setId(newarr->id()+newarrid);
                CmdAddArr *cmd = new CmdAddArr(newarr,m_scn);
                cmd->Do();
                emit logSignal("Arrow added\n");
                m_dom->addArr(newarr);
                l_commands.append(cmd);
                m_mode = SWModeIdle;
                m_prevVert->setOpacity(1);
                emit logSignal("Adding arrow, selected second item\n");
            } else
            {
                emit logSignal("First and second item is equal, please select another\n");
            }
        }
    }
    break;
    default:
        break;
    }
}

void SceneWidget::SceneContextMenu(QPointF pos)
{
    emit contextMenuSignal(pos);
}

void SceneWidget::resizeEvent (QResizeEvent * event)
{
    //m_scn->setSceneRect(0,0,this->childrenRect().x(),this->childrenRect().y());
    QWidget::resizeEvent(event);
}

void SceneWidget::setVertexParams(QString id, QString rem, QString text,Vertex::VertType vtype)
{
    CmdVertSetInfo *cmd = new CmdVertSetInfo(currVert(),id,rem,text,vtype);
    cmd->Do();
    l_commands.append(cmd);
    emit logSignal("Setting info to vertex\n");
}

void SceneWidget::undo()
{
    Command* prevCmd = l_commands.last();
    prevCmd->UnDo();
    l_commands.removeOne(prevCmd);
    emit logSignal("Undo\n");
}

void SceneWidget::Redo()
{
    emit logSignal("Redo\n");
}
