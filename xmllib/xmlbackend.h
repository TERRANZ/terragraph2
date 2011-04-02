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
    int SaveTo(QString &filename, QList<Dom*> dl);
    QList<Dom*> LoadFrom(QString &filename);

private:
    void initDomTree(QDomDocument &doc);
    QDomDocument *document;

};

#endif // XMLBACKEND_H
