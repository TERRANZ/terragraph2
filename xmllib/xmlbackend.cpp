#include "xmlbackend.h"

XmlBackEnd::XmlBackEnd()
{
}

int XmlBackEnd::SaveTo(QString &filename,QList<Dom*> dl)
{
    foreach (Dom* d,dl)
    {

    }

    return 0;
}

QList<Dom*> XmlBackEnd::LoadFrom(QString &filename)
{
    QList<Dom*> result;
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return result;
    }

    QDomDocument doc;
    Dom *dom = new Dom();
    result.append(dom);
    doc.setContent(file);
    QDomElement moduleElement = doc.documentElement();
    QString rootTag = moduleElement.tagName();
    if (rootTag == "module")
    {
        dom->setModId(moduleElement.attribute("id","id"));
        dom->setModVer(moduleElement.attribute("ver","0"));
        dom->setModRem(moduleElement.attribute("rem","rem"));
    }
    file->close();
    return result;
}

void XmlBackEnd::initDomTree(QDomDocument &doc)
{
    /*Тут надо создать начальные элементы, пустые списки
    <module id="Sample" ver="1" rem="Sample module description file">
    <include file="another_module_file" module="mod"/>
    <param id="rtl" value="gprt.h"/>
    <assemble id="Asm" templet="" rem="Sample assemble 'Asm' declaration">
    </assemble>
    </module>
    */
}
