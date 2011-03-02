#include "basegraphitem.h"

BaseGraphItem::BaseGraphItem(
        QString id, QString rem, QString text, QString next,
        int type, int send_or_recv)
{
    setId(id);
    setRem(rem);
    setText(text);
    setNext(next);
    setType(type);
    setSendOrRecv(send_or_recv);
}

void BaseGraphItem::setId(QString id)
{
    m_id = id;
}

void BaseGraphItem::setRem(QString rem)
{
    m_rem = rem;
}

void BaseGraphItem::setText(QString text)
{
    m_text = text;
}

void BaseGraphItem::setNext(QString next)
{
    m_next = next;
}

void BaseGraphItem::setType(int type)
{
    m_type = type;
}

void BaseGraphItem::setSendOrRecv(int send_or_recv)
{
    m_send_or_recv = send_or_recv;
}
