#ifndef BASEGRAPHITEM_H
#define BASEGRAPHITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include "geometry.h"

class Vertex : public QGraphicsEllipseItem
{
public:
    enum VertType{
        VTPort = 0,
        VTMethod = 1,
        VTState = 2
    };
    Vertex(QGraphicsItem *parent,QGraphicsScene *scn);

    QString id() {
        return m_id;
    };
    QString rem() {
        return m_rem;
    };
    QString text() {
        return m_text;
    };
    QString next() {
        return m_next;
    };
    VertType     vtype() {
        return m_type;
    };
    int     send_or_recv() {
        return m_send_or_recv;
    };
    int     repCount() {
        return m_repcount;
    };
    void setId(QString id);
    void setRem(QString rem);
    void setText(QString text);
    void setNext(QString next);
    void setType(VertType vtype);
    void setSendOrRecv(int send_or_recv);
    void setRepCount(int repCount);

private:
    QString m_id,m_rem,m_text,m_next;
    int m_send_or_recv,m_repcount;
    VertType m_type;
    QGraphicsTextItem* m_graphText;
    QGraphicsScene* m_scn;
protected:

};

#endif // BASEGRAPHITEM_H
