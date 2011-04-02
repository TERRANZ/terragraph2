#include "mainwindow.h"
#include "math.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_procSceneWidget = new SceneWidget(0,0);
    m_chanSceneWidget = new SceneWidget(0,1);
    QBoxLayout *l_proc = new QBoxLayout(QBoxLayout::LeftToRight,ui->tbProc);
    QBoxLayout *l_chan = new QBoxLayout(QBoxLayout::LeftToRight,ui->tbChan);
    m_currSceneWidget = m_procSceneWidget;

    ui->tbProc->setLayout(l_proc);
    ui->tbChan->setLayout(l_chan);
    ui->tbProc->layout()->addWidget(m_procSceneWidget);
    ui->tbChan->layout()->addWidget(m_chanSceneWidget);

    connect(m_procSceneWidget,SIGNAL(logSignal(QString)),this,SLOT(logSlot(QString)));
    connect(m_chanSceneWidget,SIGNAL(logSignal(QString)),this,SLOT(logSlot(QString)));
    connect(m_procSceneWidget,SIGNAL(contextMenuSignal(QPointF)),this,SLOT(sceneContextMenuSignal(QPointF)));
    connect(m_chanSceneWidget,SIGNAL(contextMenuSignal(QPointF)),this,SLOT(sceneContextMenuSignal(QPointF)));

    m_vertMenu = new QMenu();
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

void MainWindow::AddVert()
{
    m_currSceneWidget->setMode(SceneWidget::WModeAddVer);
}

void MainWindow::AddArr()
{
    m_currSceneWidget->setMode(SceneWidget::WModeAddArrowP1);
}

void MainWindow::Del()
{

}

void MainWindow::Exit()
{

}

void MainWindow::vertMenuInfo()
{
    if (m_currSceneWidget->currVert() != 0)
    {
        vertattrdlg = new VertAttrsDlg(this);
        vertattrdlg->load(m_currSceneWidget->currVert());
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
    //    CmdVertSetInfo *cmd = new CmdVertSetInfo(m_currSceneWidget->currVert(),id,rem,text);
    //    cmd->Do();
    //    l_commands.append(cmd);
    //    ui->textEdit->insertPlainText("Setting info to vertex\n");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    m_currTab = index;
    switch (index)
    {
    case 0:
    {
        //Process tab selected
        m_currSceneWidget = m_procSceneWidget;
    }
    break;
    case 1:
    {
        //Channel tab selected
        m_currSceneWidget = m_chanSceneWidget;
    }
    break;
    }
}

void MainWindow::logSlot(QString logstr)
{
    ui->textEdit->insertPlainText(logstr);
}

void MainWindow::sceneContextMenuSignal(QPointF pos)
{
    m_vertMenu->exec(QPoint(round(pos.x()),round(pos.y())));
}
