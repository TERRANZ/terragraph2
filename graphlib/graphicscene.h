#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GraphicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicScene(QObject *parent = 0);

signals:
    void mousePressSignal(QPointF pos);
public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // GRAPHICSCENE_H
