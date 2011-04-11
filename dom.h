#ifndef DOM_H
#define DOM_H

#include <QObject>
#include <QList>
#include <QDomDocument>
#include "graphlib/vertex.h"
#include "graphlib/arrow.h"

class Dom: public QDomDocument
{
public:
    Dom();
    ~Dom();

    enum DomType
    {
        DTChannel,
        DTProcess
    };

    void addVert(Vertex *v);

    void delVert(Vertex *v);

    void addArr(Arrow *a);

    void delArr(Arrow *a);

    void setType(DomType t);

    DomType type() {
        return m_type;
    };

private:
    DomType m_type;
    QDomElement m_module;
};

#endif // DOM_H
