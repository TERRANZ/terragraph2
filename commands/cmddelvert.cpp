#include "cmddelvert.h"

CmdDelVert::CmdDelVert(Vertex* v,GraphicScene *scn)
{
    m_oldvert = v;
    m_scn = scn;
    setCmd(CMD_DELVERT);
}

void CmdDelVert::Do()
{
    m_scn->removeItem(m_oldvert);
}

void CmdDelVert::UnDo()
{
    m_scn->addItem(m_oldvert);
}
