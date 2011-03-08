#ifndef VERTATTRSDLG_H
#define VERTATTRSDLG_H

#include <QDialog>
#include "graphlib/vertex.h"

namespace Ui {
    class VertAttrsDlg;
}

class VertAttrsDlg : public QDialog {
    Q_OBJECT
public:
    VertAttrsDlg(QWidget *parent = 0);
    ~VertAttrsDlg();
    void load(Vertex *v);

signals:
    void signalOk(Vertex *v);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::VertAttrsDlg *ui;
};

#endif // VERTATTRSDLG_H
