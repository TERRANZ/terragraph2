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
    connect(m_scn,SIGNAL(mousePressSignal(QPointF)),this,SLOT(SceneMousePressed(QPointF)));
    connect(m_scn,SIGNAL(selectionChanged()),this,SLOT(SceneSelection()));
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

}

void MainWindow::SceneMousePressed(QPointF pos)
{
    switch (m_state)
    {
    case WModeAddVer:
        {
            Vertex* newvert = new Vertex(0,m_scn);
            CmdAddVert* cmd = new CmdAddVert(newvert);
            l_commands.append(cmd);
            ui->textEdit->insertPlainText("Added vert\n");
            m_state = WModeIdle;
        }
        break;
    case WModeAddArrowP1:
        {

        }
        break;
    case WModeAddArrowP2:
        {

        }
        break;
    default:
        break;
    }
}

void MainWindow::AddVert()
{
    m_state = WModeAddVer;
}

void MainWindow::AddArr()
{

}

void MainWindow::Del()
{

}

void MainWindow::Exit()
{

}

