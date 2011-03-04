#ifndef VERTATTRSDLG_H
#define VERTATTRSDLG_H

#include <QDialog>

namespace Ui {
    class VertAttrsDlg;
}

class VertAttrsDlg : public QDialog {
    Q_OBJECT
public:
    VertAttrsDlg(QWidget *parent = 0);
    ~VertAttrsDlg();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::VertAttrsDlg *ui;
};

#endif // VERTATTRSDLG_H
