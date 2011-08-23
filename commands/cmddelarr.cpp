#include "cmddelarr.h"

CmdDelArr::CmdDelArr(Arrow *a,GraphicScene *scn)
{
    m_arr = a;
    m_scn = scn;
}

void CmdDelArr::Do()
{
    m_scn->removeItem(m_arr);
}

void CmdDelArr::UnDo()
{
    m_scn->addItem(m_arr);
}
