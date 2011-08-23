#ifndef CMDDELARR_H
#define CMDDELARR_H

#include "../command.h"
#include "../graphlib/arrow.h"
#include "../graphlib/graphicscene.h"

class CmdDelArr : public Command
{
public:
    CmdDelArr(Arrow *a,GraphicScene *scn);
    void Do();
    void UnDo();
private:
    Arrow *m_arr;
    GraphicScene *m_scn;
};

#endif // CMDDELARR_H
