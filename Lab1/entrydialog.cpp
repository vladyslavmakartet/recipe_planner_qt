#include "entrydialog.h"


EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{

    ui->setupUi(this);
    model = new ingredientTableModel();

    ui->IngredientsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->IngredientsTableView->setCornerButtonEnabled(false);
    ui->IngredientsTableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->IngredientsTableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");
    ui->IngredientsTableView->setModel(model);


    ui->IngredientsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->addButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);

    ui->applyButton->setEnabled(false);
    ui->IngredientsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->IngredientsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->ingredientNameLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);
    connect(ui->QuantityLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);
    connect(ui->UnitLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);

    connect(ui->RecipeNameLine, &QLineEdit::textChanged, this, &EntryDialog::allFieldsFilled);
    connect(ui->RecipeTextEdit, &QTextEdit::textChanged, this, &EntryDialog::allFieldsFilled);
    connect(this, &EntryDialog::FieldsFilled, this, &EntryDialog::allFieldsFilled);

    connect(ui->IngredientsTableView, &QAbstractItemView::clicked,this, &EntryDialog::enableButtons);


    connect(this, &EntryDialog::clearLineEdits,ui->ingredientNameLine, &QLineEdit::clear);
    connect(this, &EntryDialog::clearLineEdits,ui->QuantityLine, &QLineEdit::clear);
    connect(this, &EntryDialog::clearLineEdits,ui->UnitLine, &QLineEdit::clear);

}

EntryDialog::~EntryDialog()
{
    delete ui;
}


void EntryDialog::allLinesFilled()
{
    ui->QuantityLine->setValidator(new QDoubleValidator(0,1000,2,this));
    bool ok = !ui->ingredientNameLine->text().isEmpty()
    && !ui->UnitLine->text().isEmpty()
    && !ui->QuantityLine->text().isEmpty();
    ui->addButton->setEnabled(ok);

}

void EntryDialog::allFieldsFilled()
{

    bool ok = model->rowCount() != 0
    && !ui->RecipeNameLine->text().isEmpty()
    && !ui->RecipeTextEdit->document()->isEmpty();

    ui->applyButton->setEnabled(ok);
}


void EntryDialog::on_modifyButton_clicked()
{
    QModelIndex selected = model->index(ui->IngredientsTableView->selectionModel()->currentIndex().row(),0, QModelIndex());
    int selectedRow = ui->IngredientsTableView->selectionModel()->currentIndex().row();
    if (selected.isValid()){
        if(ui->ingredientNameLine->text() != ingredientVector[selectedRow].getIngredientName()\
                || ui->QuantityLine->text().toFloat() != ingredientVector[selectedRow].getIngredientQuantity()
                || ui->UnitLine->text() != ingredientVector[selectedRow].getIngredientUnit()){

                if(!ui->ingredientNameLine->text().isEmpty() && ui->ingredientNameLine->text() != ingredientVector[selectedRow].getIngredientName()){
                    model->setData(selected,ui->ingredientNameLine->text(),Qt::EditRole);
                    ingredientVector[selectedRow].setIngredientName(ui->ingredientNameLine->text());
                }
                if(!ui->QuantityLine->text().isEmpty() && ui->QuantityLine->text().toFloat() != ingredientVector[selectedRow].getIngredientQuantity()){
                    if(ui->QuantityLine->text().toFloat()!=0)
                    {
                        selected = model->index(ui->IngredientsTableView->selectionModel()->currentIndex().row(),1, QModelIndex());
                        model->setData(selected,ui->QuantityLine->text().toFloat(),Qt::EditRole);
                        ingredientVector[selectedRow].setIngredientQuantity(ui->QuantityLine->text().toFloat());
                    }
                }
                if(!ui->UnitLine->text().isEmpty() && ui->UnitLine->text() != ingredientVector[selectedRow].getIngredientUnit()){
                    selected = model->index(ui->IngredientsTableView->selectionModel()->currentIndex().row(),2, QModelIndex());
                    model->setData(selected,ui->UnitLine->text(),Qt::EditRole);
                    ingredientVector[selectedRow].setIngredientUnit(ui->UnitLine->text());
                }
                ui->IngredientsTableView->setModel(model);

                        ui->modifyButton->setEnabled(false);
                        ui->deleteButton->setEnabled(false);
                        emit clearLineEdits();
        }
    }


}

void EntryDialog::on_addButton_clicked()
{

    if(!(ui->ingredientNameLine->text().isEmpty() || ui->QuantityLine->text().isEmpty() || ui->UnitLine->text().isEmpty())){
        if(ui->QuantityLine->text().toFloat()!=0){
            ingredient.setIngredientName(ui->ingredientNameLine->text());
            ingredient.setIngredientQuantity(ui->QuantityLine->text().toFloat());
            ingredient.setIngredientUnit(ui->UnitLine->text());
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
                    model->setData(index,ui->ingredientNameLine->text(),Qt::EditRole);
                    index = model->index(model->rowCount()-1,1, QModelIndex());
                    model->setData(index,ui->QuantityLine->text().toFloat(),Qt::EditRole);
                    index = model->index(model->rowCount()-1,2, QModelIndex());
                    model->setData(index,ui->UnitLine->text(),Qt::EditRole);
                    ui->IngredientsTableView->setModel(model);
                    ui->modifyButton->setEnabled(false);
                    ui->deleteButton->setEnabled(false);
                    ingredientVector.append(ingredient);
                    ui->IngredientsTableView->resizeRowsToContents();
                    emit clearLineEdits();
                    emit FieldsFilled();
                }
         }
    }

}

void EntryDialog::enableButtons()
{
    if(!ui->ingredientNameLine->text().isEmpty() || !ui->QuantityLine->text().isEmpty() || !ui->UnitLine->text().isEmpty())
        ui->modifyButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
}



void EntryDialog::on_deleteButton_clicked()
{
    QModelIndexList selected = ui->IngredientsTableView->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
      {
         ingredientVector.removeAt(selected.first().row());
         ui->IngredientsTableView->model()->removeRow(selected.first().row());
         if (ingredientVector.isEmpty())
         {
             ui->modifyButton->setEnabled(false);
             ui->deleteButton->setEnabled(false);
             emit FieldsFilled();
         }
      }
}


void EntryDialog::on_okButton_clicked()
{
    done(Accepted);
}

void EntryDialog::on_applyButton_clicked()
{
    Recipe *recipe = new Recipe(ui->RecipeNameLine->text(),ui->RecipeTextEdit->toPlainText(),ingredientVector);
    emit applyPressed(*recipe);
    delete recipe;
    setResult(Accepted);
}

void EntryDialog::on_cancelButton_clicked()
{
    done(Rejected);
}

