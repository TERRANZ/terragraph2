#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include <QFileDialog>
#include "graphlib/scenewidget.h"
#include "dom.h"
#include "dombackend.h"
#include "vertattrsdlg.h"
#include "xmllib/xmlbackend.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow* ui;
    int m_state;
    QMenu *m_vertMenu;
    QAction *m_vertMenuInfoAction;
    QAction *m_vertMenuDeleteAction;
    VertAttrsDlg *vertattrdlg;
    int m_currTab;
    SceneWidget *m_procSceneWidget,*m_chanSceneWidget,*m_currSceneWidget;

private slots:
    void AddVert();
    void AddArr();
    void Del();
    void Exit();
    void SaveAs();

    void vertMenuInfo();
    void vertMenuDelete();
    void vertAttrSignalOk(QString id, QString rem, QString text,Vertex::VertType vtype);
    void on_tabWidget_currentChanged(int index);
    void logSlot(QString logstr);
    void sceneContextMenuSignal(QPointF pos);
};

#endif // MAINWINDOW_H
