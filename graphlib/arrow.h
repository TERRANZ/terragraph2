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
#include "vertex.h"

class Arrow : public QGraphicsLineItem
{
public:
    Arrow(Vertex *startItem, Vertex *endItem,
          QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    Vertex *startitem() {
        return m_startItem;
    };
    Vertex *stopitem() {
        return m_endItem;
    };
    void processPosUpdate(const QPointF &newpos);
    QString id() {
        return m_id;
    };
    QString rem() {
        return m_rem;
    };
    void setId(QString id) {
        m_id = id;
    };
    void setRem(QString rem) {
        m_rem = rem;
    };
    qreal breakX() {
        return m_x;
    };
    qreal breakY() {
        return m_y;
    };
    void setBreakX(qreal x) {
        m_x = x;
    };
    void setBreakY(qreal y) {
        m_y = y;
    };

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    Vertex *m_startItem;
    Vertex *m_endItem;
    QColor m_colour;
    QPolygonF m_arrowHead;
    QString m_rem,m_id;
    qreal m_x,m_y;
};
#endif // ARROW_H
