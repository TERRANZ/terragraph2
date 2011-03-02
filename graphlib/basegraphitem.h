#ifndef BASEGRAPHITEM_H
#define BASEGRAPHITEM_H

#include <QGraphicsItem>
#include "geometry.h"

class BaseGraphItem : public QGraphicsItem
{
public:
    BaseGraphItem(
            QString m_id = "", QString m_rem = "", QString m_text = "", QString m_next = "",
            int m_type = 0, int m_send_or_recv = 0
                 );

private:
    QString m_id,m_rem,m_text,m_next;
    int m_type,m_send_or_recv;

};

#endif // BASEGRAPHITEM_H
