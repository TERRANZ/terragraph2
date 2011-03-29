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
    void signalOk(QString id, QString rem, QString text);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_btnSave_clicked();

private:
    Ui::VertAttrsDlg *ui;
    Vertex* m_vert;
};

#endif // VERTATTRSDLG_H
