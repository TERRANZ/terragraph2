#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>
#include <QPen>
#include <QPainter>

class Arrow : public QGraphicsLineItem
{
public:
    Arrow(QGraphicsItem *startItem, QGraphicsItem *endItem,
            QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QGraphicsItem *startitem() {return m_startItem;};
    QGraphicsItem *stopitem() {return m_endItem;};
    void processPosUpdate(const QPointF &newpos);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    QGraphicsItem *m_startItem;
    QGraphicsItem *m_endItem;
    QColor m_colour;
    QPolygonF m_arrowHead;
};
#endif // ARROW_H
