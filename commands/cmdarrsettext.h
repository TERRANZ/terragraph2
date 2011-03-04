#ifndef CMDARRSETTEXT_H
#define CMDARRSETTEXT_H

#include "../command.h"
#include "../graphlib/arrow.h"
#include <QString>

class CmdArrSetText : public Command
{
public:
    CmdArrSetText();
private:
    QString m_newtext,m_oldtext;
};

#endif // CMDARRSETTEXT_H
