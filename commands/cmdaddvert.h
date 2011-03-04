#ifndef CMDADDVERT_H
#define CMDADDVERT_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QPointF>

class CmdAddVert : public Command
{
public:
    CmdAddVert(Vertex *newver);
private:
    Vertex* m_newver;
};

#endif // CMDADDVERT_H
