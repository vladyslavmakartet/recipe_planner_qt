#include "entrydialog.h"


EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{
    model = new QStringListModel();


    ui->setupUi(this);

    ui->addButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
    ui->IngreedientsListView->setEditTriggers(QAbstractItemView::NoEditTriggers); //To disable editing
    ui->IngreedientsListView->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->ItemLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);
    connect(ui->QuantityLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);
    connect(ui->UnitLine, &QLineEdit::textChanged, this, &EntryDialog::allLinesFilled);

    connect(ui->RecipeNameLine, &QLineEdit::textChanged, this, &EntryDialog::allFieldsFilled);
    connect(ui->RecipeTextEdit, &QTextEdit::textChanged, this, &EntryDialog::allFieldsFilled);
    connect(this, &EntryDialog::FieldsFilled, this, &EntryDialog::allFieldsFilled);

    connect(ui->IngreedientsListView, &QAbstractItemView::clicked,this, &EntryDialog::enableButtons);
    connect(ui->modifyButton, &QPushButton::clicked, this, &EntryDialog::on_modifyButton_clicked);


    connect(this, &EntryDialog::clearLineEdits,ui->ItemLine, &QLineEdit::clear);
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
    bool ok = !ui->ItemLine->text().isEmpty()
    && !ui->UnitLine->text().isEmpty()
    && !ui->QuantityLine->text().isEmpty();
    ui->addButton->setEnabled(ok);

}

void EntryDialog::allFieldsFilled()
{

    bool ok = model->rowCount() != 0
    && !ui->RecipeNameLine->text().isEmpty()
    && !ui->RecipeTextEdit->document()->isEmpty();

    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(ok);

}

void EntryDialog::on_addButton_clicked()
{

    if(!(ui->ItemLine->text().isEmpty() || ui->QuantityLine->text().isEmpty() || ui->UnitLine->text().isEmpty())){
        string = ui->ItemLine->text() + " " + ui->QuantityLine->text() + " " + ui->UnitLine->text();

        if(!list.contains(string)){
            list << string;

            model->setStringList(list);
            ui->IngreedientsListView->setModel(model);

            ui->modifyButton->setEnabled(false);
            ui->deleteButton->setEnabled(false);
            emit clearLineEdits();
            emit FieldsFilled();
        }
    }

}

void EntryDialog::enableButtons()
{

    ui->modifyButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
}

void EntryDialog::on_modifyButton_clicked()
{
    QModelIndexList selected = ui->IngreedientsListView->selectionModel()->selectedIndexes();
    if(!(ui->ItemLine->text().isEmpty() || ui->QuantityLine->text().isEmpty() || ui->UnitLine->text().isEmpty())){
        string = ui->ItemLine->text() + " " + ui->QuantityLine->text() + " " + ui->UnitLine->text();
            if (!selected.isEmpty()){
                if (list[selected.first().row()] != string){
                    list[selected.first().row()]=string; //list.replace(selected.first().row(),string);
                    model->setStringList(list);
                    ui->modifyButton->setEnabled(false);
                    ui->deleteButton->setEnabled(false);
                    emit clearLineEdits();
                }
            }
         }
}

void EntryDialog::on_deleteButton_clicked()
{
    QModelIndexList selected = ui->IngreedientsListView->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
      {
         list.removeAt(selected.first().row());
         ((QStringListModel*) ui->IngreedientsListView->model())->setStringList(list);
         if (list.isEmpty())
         {
             ui->modifyButton->setEnabled(false);
             ui->deleteButton->setEnabled(false);
             emit FieldsFilled();
         }
      }
}

void EntryDialog::on_buttonBox_accepted()
{
    //Recipe *recipe = new Recipe(ui->RecipeNameLine->text(),ui->RecipeTextEdit->toPlainText());
}
