#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>

#include "dataholder.h"
#include "recipetablemodel.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "showfullrecipedialog.h"
#include "editinmaindialog.h"
namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(const QVector<Recipe> recipes,QWidget *parent = nullptr);
    ~MenuDialog();
private slots:
    void availableRecipeSelected();
    void toBeCookedRecipeSelected();
    void on_cookPushButton_clicked();
    void on_removePushButton_clicked();
    void updateIngredientsTable();
signals:
    void toBeCookedUpdated();
private:
    Ui::MenuDialog *ui;
    ingredientTableModel *ingredientsTableModel;
    RecipeTableModel *availableRecipeTableModel;
    RecipeTableModel *toBeCookedRecipeTableModel;
    QVector<Recipe> recipesToCook;
    QVector<Recipe> recipesAvailable;
    QVector<Ingredient> ingredientsVector;
    int currentCounter;
    int newCounter;
};

#endif // MENUDIALOG_H
