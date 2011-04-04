#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    enum CmdType{
        CMD_ADDVERT,
        CMD_DELVERT,
        CMD_ADDARR,
        CMD_DELARR,
        CMD_VERT_SET_INFO,
        CMD_VERT_SETPOS,
        CMD_ARR_SETSTART,
        CMD_ARR_SETEND,
        CMD_ARR_SET_INFO
    };
    virtual void Do() {};
    virtual void UnDo() {};
    void setCmd(CmdType cmd) {
        m_command = cmd;
    };
    CmdType  cmd() {
        return m_command;
    };

private:
    CmdType m_command;
};

#endif // COMMAND_H
