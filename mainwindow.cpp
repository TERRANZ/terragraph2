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
    Vertex *newver = new Vertex();
    newver->setRect(0,0,30,30);
    m_scn->addItem(newver);
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
