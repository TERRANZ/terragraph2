#ifndef CMDVERTSETINFO_H
#define CMDVERTSETINFO_H

#include "../command.h"
#include "../graphlib/vertex.h"

class CmdVertSetInfo : public Command
{
public:
    CmdVertSetInfo(Vertex *v,QString id,QString rem, QString text);
    void Do();
    void UnDo();

private:
    Vertex* m_vert;
    QString m_id,m_rem,m_text,m_oldid,m_oldrem,m_oldtext;
};

#endif // CMDVERTSETINFO_H
