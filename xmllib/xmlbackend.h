#ifndef XMLBACKEND_H
#define XMLBACKEND_H

#include "../dom.h"
#include "../dombackend.h"
#include "../graphlib/vertex.h"
#include "../graphlib/arrow.h"
#include <QList>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

class XmlBackEnd: public DomBackEnd
{
public:
    XmlBackEnd();
    int SaveTo(QString &filename,const  QList<Dom*> dl);
    QList<Dom*> LoadFrom(QString &filename);
    //void ParseItemArrows();

private:
    void initDomTree(QDomDocument &doc);
    QDomDocument *document;

};

#endif // XMLBACKEND_H
