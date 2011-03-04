#ifndef CMDVERTSETSENDORRECV_H
#define CMDVERTSETSENDORRECV_H

#include "../command.h"
#include "../graphlib/vertex.h"
#include <QString>

class CmdVertSetSendOrRecv : public Command
{
public:
    CmdVertSetSendOrRecv();
private:
     QString m_newtext,m_oldtext;
};

#endif // CMDVERTSETSENDORRECV_H
