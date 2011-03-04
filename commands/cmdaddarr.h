#ifndef CMDADDARR_H
#define CMDADDARR_H

#include "../command.h"
#include "../graphlib/arrow.h"

class CmdAddArr : public Command
{
public:
    CmdAddArr();
private:
    Arrow* m_newarr;
};

#endif // CMDADDARR_H
