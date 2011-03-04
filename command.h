#ifndef COMMAND_H
#define COMMAND_H

#include <QPointF>
#include "graphlib/vertex.h"
#include "graphlib/arrow.h"
#include "dom.h"
#include <QString>

class Command
{
public:
    enum {
        CMD_ADDVERT = 0,
        CMD_DELVERT = 1,
        CMD_ADDARR  = 3,
        CMD_DELARR  = 4,
        CMD_VERT_SETTEXT = 5,
        CMD_VERT_SETID   = 6,
        CMD_VERT_SETPOS  = 7,
        CMD_VERT_SETTYPE = 8,
        CMD_ARR_SETSTART = 9,
        CMD_ARR_SETEND   = 10,
        CMD_ARR_SETETXT  = 11,
    };
    Command();

private:
    QPointF m_newpos,m_oldpos;
    QString m_newtext,m_oldtext;
    Vertex* m_newver;
    Arrow*  m_newarr;
    int     m_newtype,m_oldtype;
};

#endif // COMMAND_H
