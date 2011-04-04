#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QResizeEvent>
#include "arrow.h"
#include "graphicscene.h"
#include "vertex.h"
#include "dom.h"
#include "command.h"
#include "commands/cmdaddarr.h"
#include "commands/cmdaddvert.h"
#include "commands/cmdarrsetstartend.h"
#include "commands/cmddelarr.h"
#include "commands/cmddelvert.h"
#include "commands/cmdvertsetpos.h"
#include "commands/cmdvertsetinfo.h"

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = 0,int type = 0);
    enum {
        WModeIdle = 0, //Состояние спокойствия, ждём пользователя
        WModeAddArrowP1 = 1, //Добавляем стрелку, ещё не выбрали элемент
        WModeAddArrowP2 = 2, //Добавляем стрелку, выбрали первый элемент
        WModeDelArrow = 3, //Удаляем стрелку при следующем выделении
        WModeAddVer = 4, //Добавляем вершину при следующем нажатии
        WModeDelVert = 5 //Удаляем вершину при следующем выделении
    };
    void setMode(int m) {
        m_mode = m;
    };
    int mode() {
        return m_mode;
    };
    QGraphicsView* view() {
        return m_view;
    };
    Vertex* currVert() {
        return m_currVert;
    };

    void setVertexParams(QString id, QString rem, QString text);
signals:
    void logSignal(QString msg);
    void contextMenuSignal(QPointF pos);

public slots:

private:
    GraphicScene *m_scn;
    QGraphicsView *m_view;
    QList<Command*> l_commands;
    Vertex *m_prevVert,*m_currVert;
    int m_mode;
    Dom *m_dom;

private slots:
    void SceneSelection();
    void SceneMouseReleased(QPointF pos);
    void SceneContextMenu(QPointF pos);
protected:
    void resizeEvent (QResizeEvent * event);
};

#endif // SCENEWIDGET_H
