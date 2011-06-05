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
            foreach (Vertex *v,d->verts())
            {
                QDomElement channelstate = xmldocroot.createElement("state");
                channelstate.setAttribute("id",v->id());
                channelstate.setAttribute("type",v->send_or_recv());
                channelstate.setAttribute("x",v->pos().x());
                channelstate.setAttribute("y",v->pos().y());
                channelstate.setAttribute("rem",v->rem());
                modulechannel.appendChild(channelstate);
                foreach (Arrow *a,d->arrows())
                {
                    if (a->startitem() == v) {
                        QDomElement itemArrow;
                        itemArrow = xmldocroot.createElement("message");
                        itemArrow.setAttribute("state",a->stopitem()->id());
                        itemArrow.setAttribute("id",a->id());
                        itemArrow.setAttribute("x",a->breakX());
                        itemArrow.setAttribute("y",a->breakY());
                        itemArrow.setAttribute("rem",a->rem());
                        channelstate.appendChild(itemArrow);
                    }
                }
            }
        } break;
        case Dom::DTProcess:
        {
            QDomElement modulechannel = xmldocroot.createElement("process");
            modulechannel.setAttribute("id","");
            modulechannel.setAttribute("entry","");
            modulechannel.setAttribute("templet","");
            modulechannel.setAttribute("rem","");
            module.appendChild(modulechannel);
            foreach (Vertex *v,d->verts())
            {
                QDomElement processnode;
                switch (v->vtype())
                {
                case Vertex::VTPort:
                {
                    processnode = xmldocroot.createElement("port");
                    processnode.setAttribute("type",v->send_or_recv());
                }break;
                case Vertex::VTMethod:
                {
                    processnode = xmldocroot.createElement("method");
                    processnode.setAttribute("count",v->repCount());
                }break;
                default:
                {
                    processnode = xmldocroot.createElement("unk");
                }
                }
                processnode.setAttribute("id",v->id());
                processnode.setAttribute("x",v->pos().x());
                processnode.setAttribute("y",v->pos().y());
                processnode.setAttribute("rem",v->rem());
                modulechannel.appendChild(processnode);
                foreach (Arrow *a,d->arrows())
                {
                    if (a->startitem() == v) {
                        QDomElement itemArrow;
                        switch (a->arrowType())
                        {
                        case Arrow::ATCondition:
                        {
                            itemArrow = xmldocroot.createElement("condition");
                            itemArrow.setAttribute("method",a->stopitem()->id());
                        }break;
                        case Arrow::ATActivate:
                        {
                            itemArrow = xmldocroot.createElement("activate");
                            itemArrow.setAttribute("method",a->stopitem()->id());
                        }break;
                        case Arrow::ATSend:
                        {
                            itemArrow = xmldocroot.createElement("send");
                            itemArrow.setAttribute("port",a->stopitem()->id());
                        }break;
                        case Arrow::ATReceive:
                        {
                            itemArrow = xmldocroot.createElement("receive");
                            itemArrow.setAttribute("method",a->stopitem()->id());
                        }break;
                        default:
                        {
                            itemArrow = xmldocroot.createElement("unk");
                            itemArrow.setAttribute("next",a->stopitem()->id());
                        }
                        }
                        itemArrow.setAttribute("id",a->id());
                        itemArrow.setAttribute("x",a->breakX());
                        itemArrow.setAttribute("y",a->breakY());
                        itemArrow.setAttribute("rem",a->rem());
                        processnode.appendChild(itemArrow);
                    }
                }
            }

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
