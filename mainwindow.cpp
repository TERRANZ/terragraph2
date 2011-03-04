#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scn = new QGraphicsScene(ui->centralWidget);
    m_view = new QGraphicsView(m_scn,ui->centralWidget);
    ui->gridLayout->addWidget(m_view);
    m_scn->setSceneRect(0,0,250,250);
    Vertex *newver = new Vertex(0,m_scn);
    newver->setText("txt1");
    Vertex *newver2 = new Vertex(0,m_scn);
    newver2->setText("txt2");
    Arrow* arr = new Arrow(newver,newver2,0,m_scn);
    m_scn->addItem(arr);
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
