#include "editinmaindialog.h"
#include "ui_editinmaindialog.h"


EditInMainDialog::EditInMainDialog(const Recipe recipe, const QModelIndex select,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInMainDialog)
{

    ui->setupUi(this);
    model = new ingredientTableModel(recipe.getRecipeIngredients());
    ingredientVector = recipe.getRecipeIngredients();

    ui->RecipeNameLineEdit->setText(recipe.getRecipeName());
    ui->RecipeTextEditEdit->setText(recipe.getRecipeDescription());
    ui->IngredientsTableViewEdit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->IngredientsTableViewEdit->setCornerButtonEnabled(false);
    ui->IngredientsTableViewEdit->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->IngredientsTableViewEdit->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");
    ui->IngredientsTableViewEdit->setModel(model);


    ui->IngredientsTableViewEdit->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->addButtonEdit->setEnabled(false);
    ui->modifyButtonEdit->setEnabled(false);
    ui->deleteButtonEdit->setEnabled(false);

    ui->applyButtonEdit->setEnabled(false);
    ui->IngredientsTableViewEdit->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->IngredientsTableViewEdit->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->ingredientNameLineEdit, &QLineEdit::textChanged, this, &EditInMainDialog::allLinesFilled);
    connect(ui->QuantityLineEdit, &QLineEdit::textChanged, this, &EditInMainDialog::allLinesFilled);
    connect(ui->UnitLineEdit, &QLineEdit::textChanged, this, &EditInMainDialog::allLinesFilled);

    connect(ui->RecipeNameLineEdit, &QLineEdit::textChanged, this, &EditInMainDialog::allFieldsFilled);
    connect(ui->RecipeTextEditEdit, &QTextEdit::textChanged, this, &EditInMainDialog::allFieldsFilled);
    connect(this, &EditInMainDialog::FieldsFilled, this, &EditInMainDialog::allFieldsFilled);

    connect(ui->IngredientsTableViewEdit, &QAbstractItemView::clicked,this, &EditInMainDialog::enableButtons);

    connect(this, &EditInMainDialog::clearLineEdits,ui->ingredientNameLineEdit, &QLineEdit::clear);
    connect(this, &EditInMainDialog::clearLineEdits,ui->QuantityLineEdit, &QLineEdit::clear);
    connect(this, &EditInMainDialog::clearLineEdits,ui->UnitLineEdit, &QLineEdit::clear);
    selected = select;
    connect(ui->applyButtonEdit, &QPushButton::clicked,this,&EditInMainDialog::on_applyButtonEdit_clicked);

}

void EditInMainDialog::allLinesFilled()
{
    ui->QuantityLineEdit->setValidator(new QDoubleValidator(0,1000,2,this));
    bool ok = !ui->ingredientNameLineEdit->text().isEmpty()
    && !ui->UnitLineEdit->text().isEmpty()
    && !ui->QuantityLineEdit->text().isEmpty();
    ui->addButtonEdit->setEnabled(ok);

}

void EditInMainDialog::allFieldsFilled()
{

    bool ok = model->rowCount() != 0
    && !ui->RecipeNameLineEdit->text().isEmpty()
    && !ui->RecipeTextEditEdit->document()->isEmpty();


    ui->applyButtonEdit->setEnabled(ok);
}


void EditInMainDialog::on_modifyButtonEdit_clicked()
{

    QModelIndex selected = model->index(ui->IngredientsTableViewEdit->selectionModel()->currentIndex().row(),0, QModelIndex());
    int selectedRow = ui->IngredientsTableViewEdit->selectionModel()->currentIndex().row();
    if (selected.isValid()){
        if(ui->ingredientNameLineEdit->text() != ingredientVector[selectedRow].getIngredientName()\
                || ui->QuantityLineEdit->text().toFloat() != ingredientVector[selectedRow].getIngredientQuantity()
                || ui->UnitLineEdit->text() != ingredientVector[selectedRow].getIngredientUnit()){

                if(!ui->ingredientNameLineEdit->text().isEmpty() && ui->ingredientNameLineEdit->text() != ingredientVector[selectedRow].getIngredientName()){
                    model->setData(selected,ui->ingredientNameLineEdit->text(),Qt::EditRole);
                    ingredientVector[selectedRow].setIngredientName(ui->ingredientNameLineEdit->text());
                }
                if(!ui->QuantityLineEdit->text().isEmpty() && ui->QuantityLineEdit->text().toFloat() != ingredientVector[selectedRow].getIngredientQuantity()){
                    if(ui->QuantityLineEdit->text().toFloat()!=0){
                        selected = model->index(ui->IngredientsTableViewEdit->selectionModel()->currentIndex().row(),1, QModelIndex());
                        model->setData(selected,ui->QuantityLineEdit->text().toFloat(),Qt::EditRole);
                        ingredientVector[selectedRow].setIngredientQuantity(ui->QuantityLineEdit->text().toFloat());
                }
                    }
                if(!ui->UnitLineEdit->text().isEmpty() && ui->UnitLineEdit->text() != ingredientVector[selectedRow].getIngredientUnit()){
                    selected = model->index(ui->IngredientsTableViewEdit->selectionModel()->currentIndex().row(),2, QModelIndex());
                    model->setData(selected,ui->UnitLineEdit->text(),Qt::EditRole);
                    ingredientVector[selectedRow].setIngredientUnit(ui->UnitLineEdit->text());
                }
                ui->IngredientsTableViewEdit->setModel(model);

                        ui->modifyButtonEdit->setEnabled(false);
                        ui->deleteButtonEdit->setEnabled(false);
                        emit clearLineEdits();
                        emit FieldsFilled();
        }
    }


}

void EditInMainDialog::on_addButtonEdit_clicked()
{

    if(!(ui->ingredientNameLineEdit->text().isEmpty() || ui->QuantityLineEdit->text().isEmpty() || ui->UnitLineEdit->text().isEmpty())){
        if(ui->QuantityLineEdit->text().toFloat()!=0){
            ingredient.setIngredientName(ui->ingredientNameLineEdit->text());
            ingredient.setIngredientQuantity(ui->QuantityLineEdit->text().toFloat());
            ingredient.setIngredientUnit(ui->UnitLineEdit->text());
            bool sameItem = false;

            if(!ingredientVector.isEmpty()){
                for(int i=0; i<ingredientVector.size(); i++){
                    if(ingredientVector[i].getIngredientName() == ingredient.getIngredientName()
                            && ingredientVector[i].getIngredientUnit() == ingredient.getIngredientUnit())
                            sameItem = true;
                }
             }



                if(!sameItem){
                    model->insertRow(model->rowCount());
                    QModelIndex index = model->index(model->rowCount()-1,0, QModelIndex());
                    model->setData(index,ui->ingredientNameLineEdit->text(),Qt::EditRole);
                    index = model->index(model->rowCount()-1,1, QModelIndex());
                    model->setData(index,ui->QuantityLineEdit->text().toFloat(),Qt::EditRole);
                    index = model->index(model->rowCount()-1,2, QModelIndex());
                    model->setData(index,ui->UnitLineEdit->text(),Qt::EditRole);
                    ui->IngredientsTableViewEdit->setModel(model);
                    ui->modifyButtonEdit->setEnabled(false);
                    ui->deleteButtonEdit->setEnabled(false);
                    ingredientVector.append(ingredient);
                    ui->IngredientsTableViewEdit->resizeRowsToContents();
                    emit clearLineEdits();
                    emit FieldsFilled();
                }

         }
    }

}

void EditInMainDialog::enableButtons()
{
    if(!ui->ingredientNameLineEdit->text().isEmpty() || !ui->QuantityLineEdit->text().isEmpty() || !ui->UnitLineEdit->text().isEmpty())
        ui->modifyButtonEdit->setEnabled(true);
    ui->deleteButtonEdit->setEnabled(true);
}



void EditInMainDialog::on_deleteButtonEdit_clicked()
{
    QModelIndexList selected = ui->IngredientsTableViewEdit->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
      {
         ingredientVector.removeAt(selected.first().row());
         ui->IngredientsTableViewEdit->model()->removeRow(selected.first().row());
         if (ingredientVector.isEmpty())
         {
             ui->modifyButtonEdit->setEnabled(false);
             ui->deleteButtonEdit->setEnabled(false);
         }
         emit FieldsFilled();
      }
}


void EditInMainDialog::on_okButtonEdit_clicked()
{
    done(Accepted);
}

void EditInMainDialog::on_applyButtonEdit_clicked()
{
    Recipe *recipe = new Recipe(ui->RecipeNameLineEdit->text(),ui->RecipeTextEditEdit->toPlainText(),ingredientVector);
    emit dataEdited(*recipe, selected);
    delete recipe;
    setResult(Accepted);
}

void EditInMainDialog::on_cancelButtonEdit_clicked()
{
    done(Rejected);
}




EditInMainDialog::~EditInMainDialog()
{
    delete ui;
}
