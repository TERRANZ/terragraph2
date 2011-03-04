#ifndef CMDVERTSETID_H
#define CMDVERTSETID_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QString>

class CmdVertSetId : public Command
{
public:
    CmdVertSetId();
private:
     QString m_newtext,m_oldtext;
};

#endif // CMDVERTSETID_H
