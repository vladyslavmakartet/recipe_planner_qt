#ifndef SHOWFULLRECIPEDIALOG_H
#define SHOWFULLRECIPEDIALOG_H

#include <QDialog>
#include "dataholder.h"
#include "ingredienttablemodel.h"

namespace Ui {
class showFullRecipeDialog;
}

class showFullRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showFullRecipeDialog(const Recipe,QWidget *parent = nullptr);
    //explicit showFullRecipeDialog(const Recipe,QWidget *parent = nullptr);
    ~showFullRecipeDialog();

private:
    Ui::showFullRecipeDialog *ui;
    ingredientTableModel *FullRecipeModel;
};

#endif // SHOWFULLRECIPEDIALOG_H
