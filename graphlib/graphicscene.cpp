#include "graphicscene.h"

GraphicScene::GraphicScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void GraphicScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressSignal(event->pos());
}
