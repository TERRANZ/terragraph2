#ifndef CMDVERTSETPOS_H
#define CMDVERTSETPOS_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QPointF>

class CmdVertSetPos : public Command
{
public:
    CmdVertSetPos(Vertex *v,QPointF newpos);
    void Do();
    void UnDo();
private:
    QPointF m_newpos,m_oldpos;
    Vertex* m_vert;
};

#endif // CMDVERTSETPOS_H
