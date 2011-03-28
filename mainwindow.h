#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include "graphlib/arrow.h"
#include "graphlib/vertex.h"
#include "graphlib/graphicscene.h"
#include "command.h"
#include "dom.h"
#include "dombackend.h"
#include "vertattrsdlg.h"
#include "xmllib/xmlbackend.h"
#include "commands/cmdaddarr.h"
#include "commands/cmdaddvert.h"
#include "commands/cmdarrsetstartend.h"
#include "commands/cmdarrsettext.h"
#include "commands/cmddelarr.h"
#include "commands/cmddelvert.h"
#include "commands/cmdvertsetid.h"
#include "commands/cmdvertsetpos.h"
#include "commands/cmdvertsetsendorrecv.h"
#include "commands/cmdvertsettext.h"
#include "commands/cmdvertsettype.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum {
        WModeIdle = 0, //Состояние спокойствия, ждём пользователя
        WModeAddArrowP1 = 1, //Добавляем стрелку, ещё не выбрали элемент
        WModeAddArrowP2 = 2, //Добавляем стрелку, выбрали первый элемент
        WModeDelArrow = 3, //Удаляем стрелку при следующем выделении
        WModeAddVer = 4, //Добавляем вершину при следующем нажатии
        WModeDelVert = 5 //Удаляем вершину при следующем выделении
         };
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow* ui;
    QList<Vertex*> l_verts;
    QList<Arrow*> l_arrows;
    GraphicScene* m_scn;
    QGraphicsView* m_view;
    QList<Command*> l_commands;
    int m_state;
    QMenu* m_vertMenu;
    QAction* m_vertMenuInfoAction;
    QAction* m_vertMenuDeleteAction;
    VertAttrsDlg* vertattrdlg;
    Vertex *m_last,*m_curr;

private slots:
    void SceneSelection();
    void SceneMouseReleased(QPointF pos);
    void SceneContextMenu(QPointF pos);

    void AddVert();
    void AddArr();
    void Del();
    void Exit();

    void vertMenuInfo();
    void vertMenuDelete();
};

#endif // MAINWINDOW_H
