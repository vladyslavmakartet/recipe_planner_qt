#include "showfullrecipedialog.h"
#include "ui_showfullrecipedialog.h"

showFullRecipeDialog::showFullRecipeDialog(const Recipe data,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showFullRecipeDialog)
{
    ui->setupUi(this);
    ui->Name->setText(data.getRecipeName());
    ui->Description->setText(data.getRecipeDescription());
    FullRecipeModel = new ingredientTableModel();



    ui->ingredientsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ingredientsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ingredientsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ingredientsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->ingredientsTableView->setWordWrap(true);

    ui->ingredientsTableView->setCornerButtonEnabled(false);
    ui->ingredientsTableView->setStyleSheet("QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
        "}");
    ui->ingredientsTableView->setStyleSheet("QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
        "}");
    QModelIndex index;
    QVector<Ingredient> ingredient = data.getRecipeIngredients();

    for(int i=0; i<ingredient.size();i++){
        FullRecipeModel->insertRow(FullRecipeModel->rowCount());
        index = FullRecipeModel->index(FullRecipeModel->rowCount()-1,0, QModelIndex());
        FullRecipeModel->setData(index,ingredient[i].getIngredientName(),Qt::EditRole);

        index = FullRecipeModel->index(FullRecipeModel->rowCount()-1,1, QModelIndex());
        FullRecipeModel->setData(index,ingredient[i].getIngredientQuantity(),Qt::EditRole);

        index = FullRecipeModel->index(FullRecipeModel->rowCount()-1,2, QModelIndex());
        FullRecipeModel->setData(index,ingredient[i].getIngredientUnit(),Qt::EditRole);

    }
    ui->ingredientsTableView->setModel(FullRecipeModel);

}

showFullRecipeDialog::~showFullRecipeDialog()
{
    delete ui;
}
