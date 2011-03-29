#ifndef DOMBACKEND_H
#define DOMBACKEND_H

#include <QString>
#include "dom.h"

class DomBackEnd
{
public:
    DomBackEnd() {};
    virtual int SaveTo(QString &/*filename*/, Dom* /*dom*/){return 0;};
    virtual Dom* LoadFrom(QString &/*filename*/) {return 0;};
};

#endif // DOMBACKEND_H
