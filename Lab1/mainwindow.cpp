#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionCreate_shopping_list,&QAction::triggered, this, &MainWindow::CreateShoppingList);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);

    mainModel = new RecipeTableModel();
    ui->tableView->setModel(mainModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setWordWrap(true);
    ui->editButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    //ui->IngredientsTableView->setStyleSheet("QHeaderView::section { background-color:gray }");
    //ui->IngredientsTableView->setStyleSheet("QHeaderView::section { gridline-color: blue }");
    ui->tableView->setCornerButtonEnabled(false);
    ui->tableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->tableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing



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
        //dialog->setModal(true);
        //dialog->setAttribute(Qt::WA_DeleteOnClose);
        //dialog->exec();
        dialog->open();
        connect(dialog, &EntryDialog::applyPressed,this,&MainWindow::setRecipe);
        connect(dialog, &EntryDialog::applyPressed,this,&MainWindow::setUpTableMain);


}
void MainWindow::setRecipe(const Recipe &recipe)
{
    recipes.append(recipe);
}
void MainWindow::setUpTableMain()
{
    if (!recipes.isEmpty())
    {
        mainModel->insertRow(mainModel->rowCount());
        QModelIndex index = mainModel->index(mainModel->rowCount()-1, 0, QModelIndex());
        mainModel->setData(index,recipes[index.row()].getRecipeName(),Qt::EditRole);
        ui->tableView->setModel(mainModel);
        ui->tableView->resizeRowsToContents();
        //mainModel->index(mainModel->rowCount())

        //index = mainModel->index(mainModel->rowCount()-1, 1, QModelIndex());
        //mainModel->setData(index,recipes[index.row()].getRecipeDescription(),Qt::EditRole);
        //index = mainModel->index(mainModel->rowCount()-1, 2, QModelIndex());
        //mainModel->setData(index,QVariant::fromValue(recipes[index.row()].getRecipeIngredients()),Qt::EditRole);
        //ui->tableView->setModel(mainModel);
    }
}














void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    showFullRecipeDialog *dialogFullRecipe = new showFullRecipeDialog(recipes[index.row()],this);
    dialogFullRecipe->open();
}
