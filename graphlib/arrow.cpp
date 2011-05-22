#include "arrow.h"
#include <math.h>

const qreal Pi = 3.14;

Arrow::Arrow(Vertex *startItem, Vertex *endItem,
             QGraphicsItem *parent, QGraphicsScene *scene)
{
    m_startItem = startItem;
    m_endItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_colour = Qt::black;
    setPen(QPen(m_colour, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    setBreakX(startItem->x());
    setBreakY(startItem->y());
    setRem("arrow rem");
    setId("arrow id");
    setArrowType(ATMessage);
}

QRectF Arrow::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
           .normalized()
           .adjusted(-extra, -extra, extra, extra);
}

QPainterPath Arrow::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(m_arrowHead);
    return path;
}

void Arrow::processPosUpdate(const QPointF &newpos)
{
    QLineF line(mapFromItem(m_startItem, 0, 0), mapFromItem(m_endItem, 0, 0));
    setLine(line);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                  QWidget *)
{
    if (m_startItem->collidesWithItem(m_endItem))
        return;

    QPen myPen = pen();
    myPen.setColor(m_colour);
    qreal arrowSize = 20;
    painter->setPen(myPen);
    painter->setBrush(m_colour);

    //QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPointF p1 = m_startItem->pos();
    QPointF p2 = m_endItem->pos();
    qreal startdiff = m_startItem->boundingRect().width() / 2;
    qreal enddiff = m_endItem->boundingRect().width() / 2;

    p1.setX(p1.x()+startdiff);
    p1.setY(p1.y()+startdiff);
    p2.setX(p2.x()+enddiff);
    p2.setY(p2.y()+enddiff);

    QLineF centerLine(p1, p2);

    QPointF intersectPoint;

//    double ydiff = 1;
//    if (p1.y() > p2.y())
//        ydiff = -1;

    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0)
        angle = (Pi * 2) - angle;

    QLineF Line;
    QPointF p3,p4;
    p3 = p2 + (p1-p2)*enddiff/centerLine.length();
    p4 = p1 + (p2-p1)*startdiff/centerLine.length();
    Line.setPoints(p3,p4);

    setLine(Line);


    QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                            cos(angle + Pi / 3) * arrowSize);
    QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                            cos(angle + Pi - Pi / 3) * arrowSize);

    m_arrowHead.clear();
    m_arrowHead << line().p1() << arrowP1 << arrowP2;
    painter->drawLine(line());
    painter->drawPolygon(m_arrowHead);
    if (isSelected()) {
        painter->setPen(QPen(m_colour, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }
}
