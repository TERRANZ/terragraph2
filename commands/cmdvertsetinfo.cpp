#include "cmdvertsetinfo.h"

CmdVertSetInfo::CmdVertSetInfo(Vertex *v,QString id,QString rem, QString text)
{
    m_vert = v;
    m_oldid = v->id();
    m_oldrem = v->rem();
    m_oldtext = v->text();
    m_id = id;
    m_rem = rem;
    m_text = text;
    setCmd(Command::CMD_VERT_SET_INFO);
}

void CmdVertSetInfo::Do()
{
    m_vert->setId(m_id);
    m_vert->setRem(m_rem);
    m_vert->setText(m_text);
}

void CmdVertSetInfo::UnDo()
{
    m_vert->setId(m_oldid);
    m_vert->setRem(m_oldrem);
    m_vert->setText(m_oldtext);
}
