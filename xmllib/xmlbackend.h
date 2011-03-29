#ifndef XMLBACKEND_H
#define XMLBACKEND_H

#include "../dom.h"
#include "../dombackend.h"
#include <QList>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

class XmlBackEnd: public DomBackEnd
{
public:
    XmlBackEnd();
    int SaveTo(QString &filename, Dom *d);
    Dom* LoadFrom(QString &filename);

private:
    void initDomTree();
    QDomDocument *document;

};

#endif // XMLBACKEND_H
