#ifndef CMDADDARR_H
#define CMDADDARR_H

#include "../command.h"
#include "../graphlib/arrow.h"
#include "../graphlib/graphicscene.h"

class CmdAddArr : public Command
{
public:
    CmdAddArr(Arrow *a,GraphicScene *scn);
    void Do();
    void UnDo();
private:
    Arrow* m_arr;
    GraphicScene *m_scn;
};

#endif // CMDADDARR_H
