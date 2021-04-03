#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataholder.h"
#include "recipetablemodel.h"
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

signals:


private:
    Ui::MainWindow *ui;
    QVector<Recipe> recipes;
    RecipeTableModel *mainModel;
    void setUpTableMain();
};
#endif // MAINWINDOW_H
