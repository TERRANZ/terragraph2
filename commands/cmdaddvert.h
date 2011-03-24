#ifndef CMDADDVERT_H
#define CMDADDVERT_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include "../graphlib/graphicscene.h"

class CmdAddVert : public Command
{
public:
    CmdAddVert(Vertex *newver,GraphicScene *scn);
    void Do();
    void UnDo();
private:
    Vertex* m_newver;
    GraphicScene* m_scn;
};

#endif // CMDADDVERT_H
