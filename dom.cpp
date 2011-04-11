#include "dom.h"
/*
  один dom описывает один процесс или канал, зависит от domtype
  в нём храним списки вершин и стрелок между ними
  стрелка является дочерним объектом для вершины и не может
  висеть в воздухе => при удалении вершины, удаляется и стрелка
  */
Dom::Dom()
    :QDomDocument("XML")
{
    QString t;
    setType(DTChannel);
    switch (type())
    {
    case DTChannel: t = "channel";break;
    case DTProcess: t = "process";break;
    }
    m_module = createElement(t);
    appendChild(m_module);
}

Dom::~Dom()
{
}

void Dom::addVert(Vertex *v)
{
    QString vtype;
    switch (v->type())
    {
    case Vertex::VTState:
    {
        vtype = "state";
    }break;
    case Vertex::VTPort:
    {
        vtype = "port";
    }break;
    case Vertex::VTMethod:
    {
        vtype = "method";
    }break;
    }

    QDomElement vertex = createElement(vtype);
    vertex.setAttribute("id",v->id());
    vertex.setAttribute("type",v->send_or_recv());
    vertex.setAttribute("x",v->pos().x());
    vertex.setAttribute("y",v->pos().y());
    vertex.setAttribute("rem",v->rem());
    m_module.appendChild(vertex);
}

void Dom::delVert(Vertex *v)
{

}

void Dom::addArr(Arrow *a)
{
    QDomElement arr;
    arr = createElement("message");
    arr.setAttribute("state",a->stopitem()->id());
    arr.setAttribute("id",a->id());
    arr.setAttribute("x",a->breakX());
    arr.setAttribute("y",a->breakY());
    arr.setAttribute("rem",a->rem());
    for (unsigned int i = 0;i<=childNodes().length();i++)
    {
        QDomNode cn = childNodes().at(i);
        for (unsigned int j = 0;j<=cn.attributes().length();j++)
        {
            QDomElement ne = cn.attributes().item(j).toElement();
            if (ne.attribute("id") == a->stopitem()->id())
            {
                ne.appendChild(arr);
            }
        }
    }
}

void Dom::delArr(Arrow *a)
{

}

void Dom::setType(DomType t)
{
    m_type = t;
}
