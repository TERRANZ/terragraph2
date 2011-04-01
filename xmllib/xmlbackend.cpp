#include "xmlbackend.h"

XmlBackEnd::XmlBackEnd()
{
}

int XmlBackEnd::SaveTo(QString &filename, Dom *d)
{
    return 0;
}

Dom* XmlBackEnd::LoadFrom(QString &filename)
{
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }
    QDomDocument doc;
    Dom *dom = new Dom();
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
    return dom;
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
