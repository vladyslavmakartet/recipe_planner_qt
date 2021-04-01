#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"
#include "menudialog.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionCreate_shopping_list,&QAction::triggered, this, &MainWindow::CreateShoppingList);


    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);



//#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CreateShoppingList()
{
   MenuDialog *dialog = new MenuDialog(this);
   dialog->setWindowModality(Qt::WindowModal);
   dialog->show();
}
void MainWindow::exit()
{
    QCoreApplication::quit();
}




void MainWindow::on_addButton_clicked()
{
        EntryDialog *dialog = new EntryDialog(this);
        //dialog->setWindowModality(Qt::WindowModal);
        //dialog->show();
        // or
        dialog->setModal(true);
        dialog->exec();

}
