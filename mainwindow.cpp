#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = MainWindow::WModeIdle;
    m_scn = new GraphicScene(ui->centralWidget);
    m_view = new QGraphicsView(m_scn,ui->centralWidget);
    ui->verticalLayout->addWidget(m_view,Qt::AlignTop);
    m_scn->setSceneRect(0,0,250,250);
    connect(m_scn,SIGNAL(mouseReleaseSignal(QPointF)),this,SLOT(SceneMouseReleased(QPointF)));
    connect(m_scn,SIGNAL(selectionChanged()),this,SLOT(SceneSelection()));
    connect(m_scn,SIGNAL(mouseContextMenuSignal(QPointF)),this,SLOT(SceneContextMenu(QPointF)));
    m_vertMenu = new QMenu(m_view);
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
    m_last = m_curr;
    if (m_scn->selectedItems().count() != 0)
    {
        m_curr = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
    }
    else
    {
        m_curr = 0;
    }

}

void MainWindow::SceneMouseReleased(QPointF pos)
{
    switch (m_state)
    {
    case WModeAddVer:
    {
        Vertex* newvert = new Vertex(0,0);
        CmdAddVert* cmdadd = new CmdAddVert(newvert,m_scn);
        cmdadd->Do();
        l_verts.append(newvert);
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
        if (m_scn->selectedItems().count() == 1)
        {
            m_curr = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            m_last = m_curr;
            m_curr->setOpacity(0.25);
            m_state = WModeAddArrowP2;
            ui->textEdit->insertPlainText("Adding arrow, selected first item\n");
        }
    }
        break;
    case WModeAddArrowP2:
    {
        if (m_scn->selectedItems().count() == 1)
        {
            m_curr = dynamic_cast<Vertex*>(m_scn->selectedItems().first());
            if (m_curr != m_last) {
                Arrow * newarr = new Arrow(m_last,m_curr);
                CmdAddArr *cmd = new CmdAddArr(newarr,m_scn);
                cmd->Do();
                l_arrows.append(newarr);
                l_commands.append(cmd);
                m_state = WModeIdle;
                m_last->setOpacity(1);
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
    // m_vertMenu->exec(pos,m_vertMenuInfoAction);
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
    if (m_curr != 0)
    {
        vertattrdlg = new VertAttrsDlg(this);
        vertattrdlg->load(m_curr);
        connect(vertattrdlg,SIGNAL(signalOk(Vertex*)),this,SLOT(vertAttrSignalOk(Vertex*)));
        vertattrdlg->show();
    }
}

void MainWindow::vertMenuDelete()
{

}

void MainWindow::vertAttrSignalOk(Vertex *v)
{
    m_curr = v;
}
