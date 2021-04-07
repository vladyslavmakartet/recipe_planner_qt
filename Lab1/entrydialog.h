#ifndef ENTRYDIALOG_H
#define ENTRYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include "ui_entrydialog.h"
#include <QStringListModel>
#include "dataholder.h"
#include "recipetablemodel.h"
#include "ingredienttablemodel.h"


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
    void on_okButton_clicked();
    void on_applyButton_clicked();
    void on_cancelButton_clicked();

signals:
    void clearLineEdits();
    void FieldsFilled();
    void applyPressed(const Recipe &recipe);

private:
    Ui::EntryDialog *ui;
    ingredientTableModel *model;
    Ingredient ingredient;
    QVector<Ingredient> ingredientVector;
};

#endif // ENTRYDIALOG_H
