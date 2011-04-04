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
    explicit SceneWidget(QWidget *parent = 0,Dom::DomType type = Dom::DTChannel);
    enum SceneMode{
        SWModeIdle, //Состояние спокойствия, ждём пользователя
        SWModeAddArrowP1, //Добавляем стрелку, ещё не выбрали элемент
        SWModeAddArrowP2, //Добавляем стрелку, выбрали первый элемент
        SWModeDelArrow, //Удаляем стрелку при следующем выделении
        SWModeAddVer, //Добавляем вершину при следующем нажатии
        SWModeDelVert //Удаляем вершину при следующем выделении
    };
    void setMode(SceneMode m) {
        m_mode = m;
    };
    SceneMode mode() {
        return m_mode;
    };
    QGraphicsView* view() {
        return m_view;
    };
    Vertex* currVert() {
        return m_currVert;
    };
    Dom* dom(){
        return m_dom;
    }

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
    SceneMode m_mode;
    Dom *m_dom;

private slots:
    void SceneSelection();
    void SceneMouseReleased(QPointF pos);
    void SceneContextMenu(QPointF pos);
protected:
    void resizeEvent (QResizeEvent * event);
};

#endif // SCENEWIDGET_H
