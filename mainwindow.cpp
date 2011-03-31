#include "mainwindow.h"
#include "math.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_procDom = new Dom();
    m_state = MainWindow::WModeIdle;
    m_procScn = new GraphicScene(ui->tbProc);
    m_procView = new QGraphicsView(m_procScn,ui->tbProc);
    m_chanScn = new GraphicScene(ui->tbChan);
    m_chanView = new QGraphicsView(m_chanScn,ui->tbChan);


    m_procScn->setSceneRect(0,0,250,250);
    m_chanScn->setSceneRect(0,0,150,250);

    connect(m_procScn,SIGNAL(mouseReleaseSignal(QPointF)),this,SLOT(SceneMouseReleased(QPointF)));
    connect(m_procScn,SIGNAL(selectionChanged()),this,SLOT(SceneSelection()));
    connect(m_procScn,SIGNAL(mouseContextMenuSignal(QPointF)),this,SLOT(SceneContextMenu(QPointF)));

    m_vertMenu = new QMenu(m_procView);
    m_vertMenuInfoAction = new QAction(this);
    m_vertMenuDeleteAction = new QAction(this);

    m_vertMenuInfoAction->setText(trUtf8("Инфо"));
    m_vertMenuInfoAction->setIcon(QIcon(":/icons/info"));
    m_vertMenuDeleteAction->setText(trUtf8("Удалить"));
    m_vertMenuDeleteAction->setIcon(QIcon(":/icons/delete"));
    m_vertMenu->addAction(m_vertMenuInfoAction);
    m_vertMenu->addAction(m_vertMenuDeleteAction);
    ui->menu_2->addAction(m_vertMenuInfoAction);
    connect(m_vertMenuInfoAction,SIGNAL(triggered()),this,SLOT(vertMenuInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::SceneSelection()
{
    m_prevVert = m_currVert;
    if (m_procScn->selectedItems().count() != 0)
    {
        m_currVert = dynamic_cast<Vertex*>(m_procScn->selectedItems().first());
    }
    else
    {
        m_currVert = 0;
    }

}

void MainWindow::SceneMouseReleased(QPointF pos)
{
    switch (m_state)
    {
    case WModeAddVer:
    {
        Vertex* newvert = new Vertex(0,0);
        CmdAddVert* cmdadd = new CmdAddVert(newvert,m_procScn);
        cmdadd->Do();
        m_procDom->addVert(newvert);
        l_commands.append(cmdadd);
        ui->textEdit->insertPlainText("Added vert\n");
        CmdVertSetPos *cmdsetpos = new CmdVertSetPos(newvert,pos);
        cmdsetpos->Do();
        l_commands.append(cmdsetpos);
        ui->textEdit->insertPlainText("Set Pos\n");
        m_state = WModeIdle;
    }
        break;
    case WModeAddArrowP1:
    {
        if (m_procScn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_procScn->selectedItems().first());
            m_prevVert = m_currVert;
            m_currVert->setOpacity(0.25);
            m_state = WModeAddArrowP2;
            ui->textEdit->insertPlainText("Adding arrow, selected first item\n");
        }
    }
        break;
    case WModeAddArrowP2:
    {
        if (m_procScn->selectedItems().count() == 1)
        {
            m_currVert = dynamic_cast<Vertex*>(m_procScn->selectedItems().first());
            if (m_currVert != m_prevVert) {
                Arrow * newarr = new Arrow(m_prevVert,m_currVert);
                CmdAddArr *cmd = new CmdAddArr(newarr,m_procScn);
                cmd->Do();
                ui->textEdit->insertPlainText("Arrow added\n");
                m_procDom->addArr(newarr);
                l_commands.append(cmd);
                m_state = WModeIdle;
                m_prevVert->setOpacity(1);
                ui->textEdit->insertPlainText("Adding arrow, selected second item\n");
            }else
            {
                ui->textEdit->insertPlainText("First and second item is equal, please select another\n");
            }
        }
    }
        break;
    default:
        break;
    }
}

void MainWindow::SceneContextMenu(QPointF pos)
{
     m_vertMenu->exec(QPoint(round(pos.x()),round(pos.y())));
}

void MainWindow::AddVert()
{
    m_state = WModeAddVer;
}

void MainWindow::AddArr()
{
    m_state = WModeAddArrowP1;
}

void MainWindow::Del()
{

}

void MainWindow::Exit()
{

}

void MainWindow::vertMenuInfo()
{
    if (m_currVert != 0)
    {
        vertattrdlg = new VertAttrsDlg(this);
        vertattrdlg->load(m_currVert);
        connect(vertattrdlg,SIGNAL(signalOk(QString,QString,QString)),
                this,SLOT(vertAttrSignalOk(QString,QString,QString)));
        vertattrdlg->show();
    }
}

void MainWindow::vertMenuDelete()
{

}

void MainWindow::vertAttrSignalOk(QString id, QString rem, QString text)
{
    CmdVertSetInfo *cmd = new CmdVertSetInfo(m_currVert,id,rem,text);
    cmd->Do();
    l_commands.append(cmd);
    ui->textEdit->insertPlainText("Setting info to vertex\n");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    m_currTab = index;
}
