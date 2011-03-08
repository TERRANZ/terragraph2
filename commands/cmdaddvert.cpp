#include "cmdaddvert.h"

CmdAddVert::CmdAddVert(Vertex* newver)
{
    setCmd(CMD_ADDVERT);
    m_newver = newver;
}
