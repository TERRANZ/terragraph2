#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
    Exception(QString info) {setInfo(info);};
    void setInfo(QString info) {m_info = info;};
    QString info() {return m_info;};
private:
    QString m_info;
};

#endif // EXCEPTION_H
