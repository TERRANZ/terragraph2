#ifndef CMDDELVERT_H
#define CMDDELVERT_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include "../graphlib/graphicscene.h"

class CmdDelVert : public Command
{
public:
    CmdDelVert(Vertex* v,GraphicScene *scn);
    void Do();
    void UnDo();
private:
    Vertex* m_oldvert;
    GraphicScene *m_scn;
};

#endif // CMDDELVERT_H
