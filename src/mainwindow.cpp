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
    connect(ui->actionSave_As,&QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionOpen,&QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionAbout,&QAction::triggered, this, &MainWindow::showAbout);
    mainModel = new RecipeTableModel();
    ui->tableView->setModel(mainModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setWordWrap(true);
    ui->editButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CreateShoppingList()
{
   MenuDialog *dialog = new MenuDialog(recipes,this);
   dialog->open();
}
void MainWindow::exit()
{
    QCoreApplication::quit();
}




void MainWindow::on_addButton_clicked()
{
        EntryDialog *dialog = new EntryDialog(this);
        dialog->open();
        connect(dialog, &EntryDialog::applyPressed,this,&MainWindow::setUpTableMain);

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
    dialogFullRecipe->show();
}


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
    QModelIndex selected = mainModel->index(ui->tableView->selectionModel()->currentIndex().row(),0, QModelIndex());

    EditInMainDialog *editDataMainDialog = new EditInMainDialog(recipes[selected.row()],selected,this);
    editDataMainDialog->open();

    connect(editDataMainDialog, &EditInMainDialog::dataEdited,this,&MainWindow::updateData);
}
void MainWindow::updateData(const Recipe &recipe, QModelIndex selected)
{
    recipes[selected.row()]=recipe;
    mainModel->setData(selected,recipes[selected.row()].getRecipeName(),Qt::EditRole);
    ui->tableView->setModel(mainModel);
    ui->tableView->resizeRowsToContents();
}

void MainWindow::write(QJsonObject &json) const
{
    if(!recipes.isEmpty()){
    QJsonArray recipeArray;
    for (const Recipe &recipe : recipes) {
        QJsonObject recipeObject;
        recipe.write(recipeObject);
        recipeArray.append(recipeObject);
    }
    if (!recipeArray.isEmpty())
        json["recipes"] = recipeArray;
}

}

bool MainWindow::saveFileJSON(bool saveAs) const
{
    if(recipes.isEmpty()){
        QMessageBox::warning(nullptr, tr("No recipes to save"),
               tr("There are no recipes to save. Add a recipe and try again."));
        return false;
    }
    QString fileName = "recipes.json";
    if(saveAs){
        fileName = QFileDialog::getSaveFileName(nullptr,
            tr("Save Recipes"), "",
            tr("Recipes (*.json);;Json (*.json)"));
        if (fileName.isEmpty())
            return false;
    }

    QFile saveFile(fileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Unable to open file.");
        return false;
    }
    QJsonObject recipeObject;
    write(recipeObject);
    if (!recipeObject.isEmpty()){
        saveFile.write(QJsonDocument(recipeObject).toJson(QJsonDocument::Indented));
        return true;
    }
    else return false;
}

void MainWindow::saveFile()
{
    this->saveFileJSON(false);
}
void MainWindow::saveFileAs()
{
       this->saveFileJSON(true);
}

void MainWindow::read(const QJsonObject &json)
{
    if (json.contains("recipes") && json["recipes"].isArray()){
        QJsonArray recipesArray = json["recipes"].toArray();
        recipes.clear();
        recipes.reserve(recipesArray.size());
        for(int recipesIndex = 0; recipesIndex < recipesArray.size(); ++recipesIndex){
            QJsonObject recipesObject = recipesArray[recipesIndex].toObject();
            Recipe recipe;
            recipe.read(recipesObject);
            recipes.append(recipe);
        }
    }
}
bool MainWindow::loadFile()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Recipes"), "",
        tr("Recipes (*.json);;Json (*.json)"));
    if(filename.isEmpty())
        return false;
    else {
        QFile loadFile(filename);
        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Unable to open file.");
            return false;
        }
        QByteArray saveData = loadFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        if(loadDoc.isEmpty()){
            QMessageBox::warning(this, tr("No recipes in file"),
                   tr("The file you are attempting to open contains no recipes."));
            return false;
        }
        read(loadDoc.object());
        return true;
    }
}
void MainWindow::openFile()
{
    if(this->loadFile()){
        mainModel = new RecipeTableModel(recipes);
        ui->tableView->setModel(mainModel);
    }
}
void MainWindow::showAbout()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("About");
    messageBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    messageBox.setTextFormat(Qt::TextFormat(Qt::RichText));
    messageBox.setIconPixmap(QPixmap(":/images/images/info1.png"));
    messageBox.setWindowIcon(QIcon(":/images/images/food2.png"));
    messageBox.setText("<h2><strong>Recipe Planner</strong></h2><p>This is a small program with a GUI designed for the creation/modification of recipes and calculation of ingredients one needs to buy after creating a shopping list.</p><p>The program is one of the assignments for the EGUI course at Warsaw University of Technology.</p><p>Created in <em>Qt Creator 4.14.2</em> based on Qt 5.15.2 (MSVC 2019, 64 bit)</p><p>Developed and designed by Vladyslav Makartet</p>");
    messageBox.exec();
}
