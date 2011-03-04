#ifndef CMDVERTSETPOS_H
#define CMDVERTSETPOS_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QPointF>

class CmdVertSetPos : public Command
{
public:
    CmdVertSetPos();
private:
    QPointF m_newpos,m_oldpos;
};

#endif // CMDVERTSETPOS_H
