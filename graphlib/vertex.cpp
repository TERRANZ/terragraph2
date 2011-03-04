#include "vertex.h"

Vertex::Vertex(QGraphicsItem *parent,QGraphicsScene *scn)
    :QGraphicsEllipseItem(parent,scn)
{
    m_scn = scn;
    m_graphText = new QGraphicsTextItem(this,m_scn);
    m_graphText->setPos(0,7);
    setId("");
    setRem("");
    setText("");
    setNext("");
    setType(0);
    setSendOrRecv(1);
    this->setRect(0,0,30,30);
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
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
    m_graphText->setPlainText(text);
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
