#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "recipetablemodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QTableView tableView;
//    RecipeTableModel recipeTableMode;
//    tableView.setModel(&recipeTableMode);
//    tableView.show();

    w.show();
    return a.exec();
}
