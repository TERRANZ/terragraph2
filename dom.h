#ifndef DOM_H
#define DOM_H

#include <QObject>
#include <QList>
#include "graphlib/vertex.h"
#include "graphlib/arrow.h"

class Dom: public QObject
{
    Q_OBJECT
public:
    Dom();
    ~Dom();

    int addVert(Vertex *v)
    {
        l_verts.append(v);
        return l_verts.indexOf(v);
    }

    void delVert(Vertex *v)
    {
        l_verts.removeOne(v);
    }

    void delVert(int ind)
    {
        l_verts.removeAt(ind);
    }

    int addArr(Arrow *a)
    {
        l_arrows.append(a);
        return l_arrows.indexOf(a);
    }

    void delArr(Arrow *a)
    {
        l_arrows.removeOne(a);
    }

    void delArr(int ind)
    {
        l_arrows.removeAt(ind);
    }

    void setType(int t) {
        m_type = t;
    };
    int type() {
        return m_type;
    };

    void setModId(QString id) {
        m_modId = id;
    };
    void setModVer(QString ver) {
        m_modVer = ver;
    };
    void setModRem(QString rem) {
        m_modRem = rem;
    };
    QString modId() {
        return m_modId;
    };
    QString modVer() {
        return m_modVer;
    };
    QString modRem() {
        return m_modRem;
    };

    QList<Vertex*> const verts() { return l_verts;};
    QList<Arrow*> const arrows() { return l_arrows;};
private:
    QList<Vertex*> l_verts;
    QList<Arrow*> l_arrows;
    QString m_modId,m_modVer,m_modRem;
    int m_type; //0 - channel, 1 - process
};

#endif // DOM_H
