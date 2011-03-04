#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = MainWindow::WModeIdle;
    m_scn = new QGraphicsScene(ui->centralWidget);
    m_view = new QGraphicsView(m_scn,ui->centralWidget);
    ui->gridLayout->addWidget(m_view);
    m_scn->setSceneRect(0,0,250,250);
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

void MainWindow::AddVert()
{
    Vertex* newvert = new Vertex(0,m_scn);
    CmdAddVert* cmd = new CmdAddVert(newvert);
    l_commands.append(cmd);
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

