#include "scenewidget.h"

SceneWidget::SceneWidget(QWidget *parent) :
    QWidget(parent)
{
    m_dom = new Dom();
    m_mode = WModeIdle;
    m_scn = new GraphicScene(this);
    m_view = new QGraphicsView(m_scn,this);
    m_scn->setSceneRect(0,0,250,250);

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
    case WModeAddVer:
    {
        Vertex* newvert = new Vertex(0,0);
        CmdAddVert* cmdadd = new CmdAddVert(newvert,m_scn);
        cmdadd->Do();
        m_dom->addVert(newvert);
        l_commands.append(cmdadd);
        //ui->textEdit->insertPlainText("Added vert\n");
        CmdVertSetPos *cmdsetpos = new CmdVertSetPos(newvert,pos);
        cmdsetpos->Do();
        l_commands.append(cmdsetpos);
        //ui->textEdit->insertPlainText("Set Pos\n");
        m_mode = WModeIdle;
    }
        break;
    case WModeAddArrowP1:
    {
        if (m_scn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            m_prevVert = m_currVert;
            m_currVert->setOpacity(0.25);
            m_mode = WModeAddArrowP2;
            //ui->textEdit->insertPlainText("Adding arrow, selected first item\n");
        }
    }
        break;
    case WModeAddArrowP2:
    {
        if (m_scn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            if (m_currVert != m_prevVert) {
                Arrow * newarr = new Arrow(m_prevVert,m_currVert);
                CmdAddArr *cmd = new CmdAddArr(newarr,m_scn);
                cmd->Do();
                //ui->textEdit->insertPlainText("Arrow added\n");
                m_dom->addArr(newarr);
                l_commands.append(cmd);
                m_mode = WModeIdle;
                m_prevVert->setOpacity(1);
                //ui->textEdit->insertPlainText("Adding arrow, selected second item\n");
            }else
            {
                //ui->textEdit->insertPlainText("First and second item is equal, please select another\n");
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
    //m_vertMenu->exec(QPoint(round(pos.x()),round(pos.y())));
}
