#include "vertex.h"

Vertex::Vertex(
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

void Vertex::setId(QString id)
{
    m_id = id;
}

void Vertex::setRem(QString rem)
{
    m_rem = rem;
}

void Vertex::setText(QString text)
{
    m_text = text;
}

void Vertex::setNext(QString next)
{
    m_next = next;
}

void Vertex::setType(int type)
{
    m_type = type;
}

void Vertex::setSendOrRecv(int send_or_recv)
{
    m_send_or_recv = send_or_recv;
}
