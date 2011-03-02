#ifndef BASEGRAPHITEM_H
#define BASEGRAPHITEM_H

#include <QGraphicsItem>
#include "geometry.h"

class BaseGraphItem : public QGraphicsItem
{
public:
    BaseGraphItem(
            QString id = "", QString rem = "", QString text = "", QString next = "",
            int type = 0, int send_or_recv = 0
                                                 );

    QString id() {return m_id;};
    QString rem() {return m_rem;};
    QString text() {return m_text;};
    QString next() {return m_next;};
    int     type() {return m_type;};
    int     send_or_recv() {return m_send_or_recv;};
    void setId(QString id);
    void setRem(QString rem);
    void setText(QString text);
    void setNext(QString next);
    void setType(int type);
    void setSendOrRecv(int send_or_recv);
private:
    QString m_id,m_rem,m_text,m_next;
    int m_type,m_send_or_recv;

};

#endif // BASEGRAPHITEM_H
