#ifndef EDITINMAINDIALOG_H
#define EDITINMAINDIALOG_H

#include <QDialog>

#include <QLineEdit>
#include <QTextEdit>
#include "ui_entrydialog.h"
#include <QStringListModel>
#include "dataholder.h"
#include "recipetablemodel.h"
#include "ingredienttablemodel.h"

namespace Ui {
class EditInMainDialog;
}

class EditInMainDialog : public QDialog
{
    Q_OBJECT

public:
    //explicit EditInMainDialog(const Recipe,const QModelIndexList,QWidget *parent = nullptr);
    explicit EditInMainDialog(const Recipe,const QModelIndex,QWidget *parent = nullptr);
    ~EditInMainDialog();

private slots:
    void allLinesFilled();
    void allFieldsFilled();
    void on_addButtonEdit_clicked();
    void enableButtons();
    void on_modifyButtonEdit_clicked();
    void on_deleteButtonEdit_clicked();
    void on_okButtonEdit_clicked();
    void on_applyButtonEdit_clicked();
    void on_cancelButtonEdit_clicked();
    //void on_applyButton_clicked_data_edited();
signals:
    void clearLineEdits();
    void FieldsFilled();
    void applyPressed(const Recipe &recipe);
    void dataEdited(const Recipe &recipe, const QModelIndex selected);
    void tableChanged();

private:
    Ui::EditInMainDialog *ui;
    ingredientTableModel *model;
    Ingredient ingredient;
    QVector<Ingredient> ingredientVector;
    QModelIndex selected;
};

#endif // EDITINMAINDIALOG_H
