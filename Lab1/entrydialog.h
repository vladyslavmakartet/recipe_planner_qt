#ifndef ENTRYDIALOG_H
#define ENTRYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include "ui_entrydialog.h"
#include <QStringListModel>
#include "dataholder.h"


namespace Ui {
class EntryDialog;
}

class EntryDialog : public QDialog
{
    Q_OBJECT


public:
    explicit EntryDialog(QWidget *parent = nullptr);
    ~EntryDialog();

private slots:
    void allLinesFilled();
    void allFieldsFilled();
    void on_addButton_clicked();
    void enableButtons();
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();
    void on_buttonBox_accepted();

signals:
    void clearLineEdits();
    void FieldsFilled();
private:
    Ui::EntryDialog *ui;
    QStringListModel *model;

    QStringList list;
    QString string;
};

#endif // ENTRYDIALOG_H
