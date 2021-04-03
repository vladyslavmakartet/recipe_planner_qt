#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionCreate_shopping_list,&QAction::triggered, this, &MainWindow::CreateShoppingList);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->tableView, &QAbstractItemView::clicked,this, &MainWindow::enableButtonsMainWindow);
    connect(ui->actionSave,&QAction::triggered, this, &MainWindow::saveFile);

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
        //connect(dialog, &EntryDialog::applyPressed,this,&MainWindow::setRecipe);
        connect(dialog, &EntryDialog::applyPressed,this,&MainWindow::setUpTableMain);
        //connect(ui->tableView, &QAbstractItemView::clicked,this, &EntryDialog::enableButtons);

}

void MainWindow::setUpTableMain(const Recipe &recipe)
{

    if(!recipes.contains(recipe)){
        recipes.append(recipe);
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
    //}
    }
}


void MainWindow::enableButtonsMainWindow()
{
    if(!recipes.isEmpty()){

        ui->editButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
    }

}











void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    showFullRecipeDialog *dialogFullRecipe = new showFullRecipeDialog(recipes[index.row()],this);
    dialogFullRecipe->show(); //CHECK IF ITEM WAS DELETED!!! POTENTIAL CRASH!!!
}

//void MainWindow::on_tableView_clicked()
//{
//            ui->editButton->setEnabled(true);
//            ui->deleteButton->setEnabled(true);
//}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
      {
         recipes.removeAt(selected.first().row());
         ui->tableView->model()->removeRow(selected.first().row());
         if (recipes.isEmpty())
         {
             ui->editButton->setEnabled(false);
             ui->deleteButton->setEnabled(false);

         }
      }
}

void MainWindow::on_editButton_clicked()
{
    //QModelIndexList selected = ui->tableView->selectionModel()->selectedIndexes();
    QModelIndex selected = mainModel->index(ui->tableView->selectionModel()->currentIndex().row(),0, QModelIndex());

    EditInMainDialog *editDataMainDialog = new EditInMainDialog(recipes[selected.row()],selected,this);
    editDataMainDialog->open();

    connect(editDataMainDialog, &EditInMainDialog::dataEdited,this,&MainWindow::updateData);
}
void MainWindow::updateData(const Recipe &recipe, QModelIndex selected)//QModelIndexList selected)
{
    recipes[selected.row()]=recipe;
    mainModel->setData(selected,recipes[selected.row()].getRecipeName(),Qt::EditRole);
    ui->tableView->setModel(mainModel);
    ui->tableView->resizeRowsToContents();
}

void MainWindow::write(QJsonObject &json) const
{
    QJsonArray recipeArray;
    for (const Recipe &recipe : recipes) {
        QJsonObject recipeObject;
        recipe.write(recipeObject);
        recipeArray.append(recipeObject);
    }
    json["recipe"] = recipeArray;
}

bool MainWindow::saveFileJSON() const
{
    QFile saveFile("recipes.json");

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QJsonObject recipeObject;
    write(recipeObject);
    saveFile.write(QJsonDocument(recipeObject).toJson());
    return true;
}

void MainWindow::saveFile()
{
    this->saveFileJSON();
}
