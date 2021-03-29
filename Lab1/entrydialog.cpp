#include "entrydialog.h"
#include "ui_entrydialog.h"

EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{
    ui->setupUi(this);
}

EntryDialog::~EntryDialog()
{
    delete ui;
}
