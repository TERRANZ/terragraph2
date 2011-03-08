#include "cmdaddvert.h"

CmdAddVert::CmdAddVert(Vertex* newver,GraphicScene *scn)
{
    setCmd(CMD_ADDVERT);
    m_newver = newver;
    m_scn = scn;
}

void CmdAddVert::Do()
{
    m_scn->addItem(m_newver);
}

void CmdAddVert::Undo()
{
    m_scn->removeItem(m_newver);
}
