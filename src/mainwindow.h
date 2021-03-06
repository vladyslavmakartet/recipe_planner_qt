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
#include "editinmaindialog.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUpTableMain(const Recipe &recipe);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    bool saveFileJSON(bool) const;
    bool loadFile();

private slots:
    void CreateShoppingList();
    void exit();
    void on_addButton_clicked();
    void enableButtonsMainWindow();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_deleteButton_clicked();
    void on_editButton_clicked();
    void updateData(const Recipe &recipe, const QModelIndex);
    void saveFile();
    void saveFileAs();
    void openFile();
    void showAbout();


signals:

private:
    Ui::MainWindow *ui;
    QVector<Recipe> recipes;
    RecipeTableModel *mainModel;

};
#endif // MAINWINDOW_H
