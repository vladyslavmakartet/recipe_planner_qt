#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataholder.h"
#include "recipetablemodel.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"
#include "menudialog.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "showfullrecipedialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRecipe(const Recipe &recipe);

private slots:
    void CreateShoppingList();
    void exit();
    void on_addButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

signals:


private:
    Ui::MainWindow *ui;
    QVector<Recipe> recipes;
    RecipeTableModel *mainModel;
    void setUpTableMain();
};
#endif // MAINWINDOW_H
