#ifndef CMDVERTSETTYPE_H
#define CMDVERTSETTYPE_H

#include "../command.h"
#include "../graphlib/vertex.h"

class CmdVertSetType : public Command
{
public:
    CmdVertSetType();
private:
    int m_newtype,m_oldtype;
};

#endif // CMDVERTSETTYPE_H
