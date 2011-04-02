#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    enum {
        CMD_ADDVERT = 0,
        CMD_DELVERT = 1,
        CMD_ADDARR  = 3,
        CMD_DELARR  = 4,
        CMD_VERT_SET_INFO = 5,
        CMD_VERT_SETPOS = 6,
        CMD_ARR_SETSTART = 7,
        CMD_ARR_SETEND   = 8,
        CMD_ARR_SET_INFO  = 9,
    };
    virtual void Do() {};
    virtual void UnDo() {};
    void setCmd(int cmd) {
        m_command = cmd;
    };
    int  cmd() {
        return m_command;
    };

private:
    int m_command;
};

#endif // COMMAND_H
