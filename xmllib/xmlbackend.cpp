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
    return 0;
}

void XmlBackEnd::initDomTree()
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
