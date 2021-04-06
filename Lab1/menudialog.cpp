#include "menudialog.h"
#include "ui_menudialog.h"
#include <QCommonStyle>
#include <QAbstractItemModel>
#include <algorithm>
MenuDialog::MenuDialog(const QVector<Recipe> recipes,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
    availableRecipeTableModel = new RecipeTableModel(recipes);
    toBeCookedRecipeTableModel = new RecipeTableModel();
    ingredientsTableModel = new ingredientTableModel();
    recipesAvailable = recipes;
    currentCounter = 0;
    newCounter = 0;

    ui->availableRecipesTableView->setModel(availableRecipeTableModel);

    //ui->availableRecipesTableView->resizeRowsToContents();
//    QCommonStyle style;
//    ui->pushButton_5->setIcon(style.standardIcon(QStyle::SP_ArrowBack));
//    ui->pushButton_4->setIcon(style.standardIcon(QStyle::SP_ArrowForward));
    ui->cookPushButton->setEnabled(false);
    ui->removePushButton->setEnabled(false);
    ui->availableRecipesTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->availableRecipesTableView->setCornerButtonEnabled(false);
    ui->availableRecipesTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing

    ui->availableRecipesTableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->availableRecipesTableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");

    ui->toBeCookedtableView->setModel(toBeCookedRecipeTableModel);

    ui->toBeCookedtableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->toBeCookedtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->toBeCookedtableView->setCornerButtonEnabled(false);
    ui->toBeCookedtableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->toBeCookedtableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");




    ui->ingredientsToBuyTableView->setModel(ingredientsTableModel);

    ui->ingredientsToBuyTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ingredientsToBuyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->ingredientsToBuyTableView->setCornerButtonEnabled(false);
    ui->ingredientsToBuyTableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->toBeCookedtableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");


    connect(ui->availableRecipesTableView, &QAbstractItemView::clicked,this, &MenuDialog::availableRecipeSelected);
    connect(ui->toBeCookedtableView, &QAbstractItemView::clicked,this, &MenuDialog::toBeCookedRecipeSelected);
    connect(this, &MenuDialog::toBeCookedUpdated,this, &MenuDialog::updateIngredientsTable);
    connect(ui->availableRecipesTableView, &QAbstractItemView::doubleClicked,this,&MenuDialog::on_cookPushButton_clicked);

}

MenuDialog::~MenuDialog()
{
    delete ui;
}
void MenuDialog::availableRecipeSelected()//QModelIndex selected)
{
    ui->cookPushButton->setEnabled(true);
    ui->removePushButton->setEnabled(false);
}
void MenuDialog::toBeCookedRecipeSelected()
{
    ui->cookPushButton->setEnabled(false);
    ui->removePushButton->setEnabled(true);
}

void MenuDialog::on_cookPushButton_clicked()
{
    QModelIndex selected = availableRecipeTableModel->index(ui->availableRecipesTableView->selectionModel()->currentIndex().row(),0, QModelIndex());
    recipesToCook.append(recipesAvailable[selected.row()]);
    toBeCookedRecipeTableModel->insertRow(toBeCookedRecipeTableModel->rowCount());
    QModelIndex index = toBeCookedRecipeTableModel->index(toBeCookedRecipeTableModel->rowCount()-1, 0, QModelIndex());
    toBeCookedRecipeTableModel->setData(index,recipesToCook[index.row()].getRecipeName(),Qt::EditRole);
    ui->toBeCookedtableView->setModel(toBeCookedRecipeTableModel);
    newCounter++;
    emit toBeCookedUpdated();

}

void MenuDialog::on_removePushButton_clicked()
{
    QModelIndexList selected = ui->toBeCookedtableView->selectionModel()->selectedIndexes();
    bool flag = false;
    bool done = false;
    if (!selected.isEmpty())
        {
             //QVector<Ingredient> tempIngredients = recipesToCook[selected.first().row()].getRecipeIngredients();
             for(int i=0;i<ingredientsVector.size();i++)
                 {
                     for(int j=0;j<recipesToCook[selected.first().row()].getRecipeIngredients().size();)
                         {
                             if(ingredientsVector[i].getIngredientName() == recipesToCook[selected.first().row()].getRecipeIngredients()[j].getIngredientName()
                                     && ingredientsVector[i].getIngredientUnit() == recipesToCook[selected.first().row()].getRecipeIngredients()[j].getIngredientUnit())
                                 {
                                     ingredientsVector[i].setIngredientQuantity(ingredientsVector[i].getIngredientQuantity() - recipesToCook[selected.first().row()].getRecipeIngredients()[j].getIngredientQuantity());

                                     if(ingredientsVector[i].getIngredientQuantity()<=0)
                                         {
                                             ingredientsVector.removeAt(i);
                                             j=0;
                                             if(ingredientsVector.size()<=i)
                                             {
                                                done = true;
                                                break;
                                             }
                                             if(ingredientsVector.isEmpty())
                                             {
                                                 flag = true;
                                                 break;
                                             }
                                         }
                                     else j++;
                                 }
                             else
                                 {
                                    if(!flag)
                                        j++;
                                    else break;
                                 }
                            }
                    if(flag) break;
             if(done) break;
             }
        }

         recipesToCook.removeAt(selected.first().row());
         ui->toBeCookedtableView->model()->removeRow(selected.first().row());
         newCounter--;
         currentCounter--;
         if (recipesToCook.isEmpty())
         {
            ui->removePushButton->setEnabled(false);

         }

         ingredientsTableModel = new ingredientTableModel(ingredientsVector);


         ui->ingredientsToBuyTableView->setModel(ingredientsTableModel);

         //emit toBeCookedUpdated(false);
}


void MenuDialog::updateIngredientsTable()
{
   // if(decision)
    //{
        //bool sameElements = false;
//        for(; currentCounter < newCounter; currentCounter++)
//        {
//            if(ingredientsVector.isEmpty())
//                ingredientsVector.append(recipesToCook[currentCounter].getRecipeIngredients());
//            else
//            {
//                for(int i=0;i<ingredientsVector.size();i++)
//                {
//                    for(int j=0;j<recipesToCook[currentCounter].getRecipeIngredients().size();j++)
//                    {
//                        if(ingredientsVector[i].getIngredientName() == recipesToCook[currentCounter].getRecipeIngredients()[j].getIngredientName()
//                                && ingredientsVector[i].getIngredientUnit() == recipesToCook[currentCounter].getRecipeIngredients()[j].getIngredientUnit())
//                        {
//                            ingredientsVector[i].setIngredientQuantity(ingredientsVector[i].getIngredientQuantity() + recipesToCook[currentCounter].getRecipeIngredients()[j].getIngredientQuantity());
//                            //sameElements=true;
//                        }
//                        else
//                        {
//                            //sameElements=false;
//                            //Ingredient newIng = recipesToCook[currentCounter].getRecipeIngredients()[j];

//                            if(!ingredientsVector.contains(recipesToCook[currentCounter].getRecipeIngredients()[j]))
//                            {
//                                ingredientsVector.append(recipesToCook[currentCounter].getRecipeIngredients()[j]);
//                            }
//                        }
//                    }
//                }

//            }

//        }
    if(ingredientsVector.isEmpty())
    {
        ingredientsVector.append(recipesToCook[currentCounter].getRecipeIngredients());
    }
    else
    {
        for(int j=0;j<recipesToCook[currentCounter].getRecipeIngredients().size();j++){
            if(ingredientsVector.contains(recipesToCook[currentCounter].getRecipeIngredients()[j]))
            {
                int index= ingredientsVector.indexOf(recipesToCook[currentCounter].getRecipeIngredients()[j]);
                if(index!=(-1))
                    ingredientsVector[index].setIngredientQuantity(ingredientsVector[index].getIngredientQuantity() + recipesToCook[currentCounter].getRecipeIngredients()[j].getIngredientQuantity());
            }
            else
            {
                ingredientsVector.append(recipesToCook[currentCounter].getRecipeIngredients()[j]);
            }
        }
    }
    currentCounter++;


    std::sort(ingredientsVector.begin(), ingredientsVector.end());

    ingredientsTableModel = new ingredientTableModel(ingredientsVector);


         ui->ingredientsToBuyTableView->setModel(ingredientsTableModel);

}




























