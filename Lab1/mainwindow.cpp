#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    EntryDialog *dialog = new EntryDialog(this);
    dialog->show();
}

void MainWindow::on_editButton_clicked()
{

}

void MainWindow::on_deleteButton_clicked()
{

}
