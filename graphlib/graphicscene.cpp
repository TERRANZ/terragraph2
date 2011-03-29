#include "graphicscene.h"

GraphicScene::GraphicScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void GraphicScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    emit mouseReleaseSignal(event->scenePos());
}

void GraphicScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QGraphicsScene::contextMenuEvent(event);
    emit mouseContextMenuSignal(event->screenPos());
}
