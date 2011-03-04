#include "vertattrsdlg.h"
#include "ui_vertattrsdlg.h"

VertAttrsDlg::VertAttrsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VertAttrsDlg)
{
    ui->setupUi(this);
}

VertAttrsDlg::~VertAttrsDlg()
{
    delete ui;
}

void VertAttrsDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
