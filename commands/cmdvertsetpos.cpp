#include "cmdvertsetpos.h"

CmdVertSetPos::CmdVertSetPos(Vertex *v,QPointF newpos)
{
    setCmd(CMD_VERT_SETPOS);
    m_oldpos = v->pos();
    m_newpos = newpos;
    m_vert = v;
}

void CmdVertSetPos::Do()
{
    m_vert->setPos(m_newpos);
}

void CmdVertSetPos::UnDo()
{
    m_vert->setPos(m_oldpos);
}
