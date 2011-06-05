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

void VertAttrsDlg::load(Vertex *v)
{
    m_vert = v;
    ui->le_name->setText(v->id());
    ui->le_rem->setText(v->rem());
    ui->le_chan->setText(v->text());
    ui->spCount->setValue(v->repCount());
    switch (v->vtype())
    {
    case Vertex::VTMethod:
    {
        ui->rbMethod->setChecked(true);
    }break;
    case Vertex::VTPort:
    {
        ui->rbPort->setChecked(true);
    }break;
    case Vertex::VTState:
    {
        ui->rbState->setChecked(true);
    }break;
    }
}

void VertAttrsDlg::on_btnSave_clicked()
{
    Vertex::VertType t;
    if (ui->rbMethod->isChecked())
    {
        t = Vertex::VTMethod;
    }else
    {
        if (ui->rbPort->isChecked())
        {
            t = Vertex::VTPort;
        }else
        {
            t = Vertex::VTState;
        }
    }
    emit signalOk(ui->le_name->text(),ui->le_rem->text(),ui->le_chan->text(),t);
}
