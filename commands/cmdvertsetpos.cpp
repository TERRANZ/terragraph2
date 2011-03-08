#include "cmdvertsetpos.h"

CmdVertSetPos::CmdVertSetPos(Vertex *v,QPointF newpos)
{
    setCmd(CMD_VERT_SETPOS);
    m_oldpos = v->pos();
    m_newpos = newpos;
    v->setPos(newpos);
}
