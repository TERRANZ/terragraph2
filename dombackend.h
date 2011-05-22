#ifndef DOMBACKEND_H
#define DOMBACKEND_H

#include <QString>
#include <QList>
#include "dom.h"

class DomBackEnd
{
public:
    virtual int SaveTo(QString &/*filename*/,const QList<Dom*> /*dom*/) {
        return 0;
    };
    virtual QList<Dom*> LoadFrom(QString &/*filename*/) {
        QList<Dom*> result;
        return result;
    };
};

#endif // DOMBACKEND_H
