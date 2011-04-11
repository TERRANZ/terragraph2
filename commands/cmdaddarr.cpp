#include "cmdaddarr.h"

CmdAddArr::CmdAddArr(Arrow *a,GraphicScene *scn)
{
    m_arr = a;
    m_scn = scn;
    setCmd(CMD_ADDARR);
}

void CmdAddArr::Do()
{
    m_scn->addItem(m_arr);
}

void CmdAddArr::UnDo()
{
    m_scn->removeItem(m_arr);
}
