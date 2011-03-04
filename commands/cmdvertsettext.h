#ifndef CMDVERTSETTEXT_H
#define CMDVERTSETTEXT_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QString>

class CmdVertSetText : public Command
{
public:
    CmdVertSetText();
private:
     QString m_newtext,m_oldtext;
};

#endif // CMDVERTSETTEXT_H
