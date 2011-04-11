#include "xmlbackend.h"

XmlBackEnd::XmlBackEnd()
{
}

int XmlBackEnd::SaveTo(QString &filename,const QList<Dom*> dl)
{
    QDomDocument xmldocroot("XML");
    QDomElement module = xmldocroot.createElement("module");
    xmldocroot.appendChild(module);
    module.setAttribute("id","id");
    module.setAttribute("rem","");
    module.setAttribute("ver","1.0");

    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadWrite)) {
        return 1;
    }

    foreach (Dom* d,dl)
    {
        switch (d->type())
        {
        case Dom::DTChannel:
        {
            QDomElement modulechannel = xmldocroot.createElement("channel");
            modulechannel.setAttribute("id","");
            modulechannel.setAttribute("entry","");
            modulechannel.setAttribute("templet","");
            modulechannel.setAttribute("rem","");
            module.appendChild(modulechannel);
            for (unsigned int i = 0; i<=d->childNodes().length();i++)
            {
                xmldocroot.appendChild(d->childNodes().at(i));
            }

//            foreach (Vertex *v,d->verts())
//            {
//                QDomElement channelstate = xmldocroot.createElement("state");
//                channelstate.setAttribute("id",v->id());
//                channelstate.setAttribute("type",v->send_or_recv());
//                channelstate.setAttribute("x",v->pos().x());
//                channelstate.setAttribute("y",v->pos().y());
//                channelstate.setAttribute("rem",v->rem());
//                modulechannel.appendChild(channelstate);
//                foreach (Arrow *a,d->arrows())
//                {
//                    if (a->startitem() == v) {
//                        QDomElement itemArrow;
//                        itemArrow = xmldocroot.createElement("message");
//                        itemArrow.setAttribute("state",a->stopitem()->id());
//                        itemArrow.setAttribute("id",a->id());
//                        itemArrow.setAttribute("x",a->breakX());
//                        itemArrow.setAttribute("y",a->breakY());
//                        itemArrow.setAttribute("rem",a->rem());
//                        channelstate.appendChild(itemArrow);
//                    }
//                }
//            }


        } break;
        case Dom::DTProcess:
        {
        } break;
        }
    }

    QTextStream out(file);
    xmldocroot.save(out, 4);
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
    doc.setContent(file);
    QDomElement moduleElement = doc.documentElement();
    QString rootTag = moduleElement.tagName();
    Dom *dom = new Dom();
    result.append(dom);
    if (rootTag == "module")
    {
//        dom->setModId(moduleElement.attribute("id","id"));
//        dom->setModVer(moduleElement.attribute("ver","0"));
//        dom->setModRem(moduleElement.attribute("rem","rem"));
//        //Заполнили параметры модуля, смотрим дальше
        QDomNode modNode = moduleElement.firstChild();
        while (!modNode.isNull())
        {
            if (modNode.isElement())
            {
                //QDomElement domElement = modNode.toElement();
                QDomElement modNodeElement = modNode.toElement();
                if (!modNodeElement.isNull())
                {
                    if (modNodeElement.tagName().toLower() == "process")
                    {
                        QDomNodeList l_methods = modNodeElement.elementsByTagName("method");
                        QDomNodeList l_ports = modNodeElement.elementsByTagName("port");
                        QString tmp;
                        for (int i = 0;i<l_methods.count();i++)
                        {
                            //                            tmp.setNum(i);
                            //                            GraphPrim *Start = a->getObjectById(items.item(i).toElement().attribute("id").toInt());
                            //                            QDomNode item = items.item(i);
                            //                            ParseItemArrows(item,a,p,Start);
                        }

                        for (int i = 0;i<l_ports.count();i++)
                        {
                            //                            tmp.setNum(i);
                            //                            GraphPrim *Start = a->getObjectById(items.item(i).toElement().attribute("id").toInt());
                            //                            QDomNode item = items.item(i);
                            //                            ParseItemArrows(item,a,p,Start);
                        }
                    }

                    if (modNodeElement.tagName().toLower() == "channel")
                    {
                        QDomNodeList l_states = modNodeElement.elementsByTagName("state");
                        for (int i = 0;i<l_states.count();i++)
                        {
                            //                            QString tmp;
                            //                            tmp.setNum(i);
                            //                            GraphPrim *Start = a->getObjectById(items.item(i).toElement().attribute("id").toInt());
                            //                            QDomNode item = items.item(i);
                            //                            ParseItemArrows(item,a,c,Start);
                        }
                    }
                }
            }
            modNode = modNode.nextSibling();
        }
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
