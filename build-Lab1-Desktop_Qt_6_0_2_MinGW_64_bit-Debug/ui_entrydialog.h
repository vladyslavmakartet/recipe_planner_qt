/********************************************************************************
** Form generated from reading UI file 'entrydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYDIALOG_H
#define UI_ENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntryDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *RecipeNameLine;
    QLabel *recipeLabel;
    QTextEdit *RecipeTextEdit;
    QLabel *ingredientsLabel;
    QTableView *IngredientsTableView;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *ingredientNameLine;
    QLabel *nameLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *QuantityLine;
    QLabel *quantityLabel;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *UnitLine;
    QLabel *unitLabel;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *EntryDialog)
    {
        if (EntryDialog->objectName().isEmpty())
            EntryDialog->setObjectName(QString::fromUtf8("EntryDialog"));
        EntryDialog->resize(800, 600);
        horizontalLayout_2 = new QHBoxLayout(EntryDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(EntryDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        RecipeNameLine = new QLineEdit(EntryDialog);
        RecipeNameLine->setObjectName(QString::fromUtf8("RecipeNameLine"));

        verticalLayout_4->addWidget(RecipeNameLine);

        recipeLabel = new QLabel(EntryDialog);
        recipeLabel->setObjectName(QString::fromUtf8("recipeLabel"));

        verticalLayout_4->addWidget(recipeLabel);

        RecipeTextEdit = new QTextEdit(EntryDialog);
        RecipeTextEdit->setObjectName(QString::fromUtf8("RecipeTextEdit"));

        verticalLayout_4->addWidget(RecipeTextEdit);

        ingredientsLabel = new QLabel(EntryDialog);
        ingredientsLabel->setObjectName(QString::fromUtf8("ingredientsLabel"));

        verticalLayout_4->addWidget(ingredientsLabel);

        IngredientsTableView = new QTableView(EntryDialog);
        IngredientsTableView->setObjectName(QString::fromUtf8("IngredientsTableView"));

        verticalLayout_4->addWidget(IngredientsTableView);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EntryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ingredientNameLine = new QLineEdit(EntryDialog);
        ingredientNameLine->setObjectName(QString::fromUtf8("ingredientNameLine"));

        verticalLayout->addWidget(ingredientNameLine);

        nameLabel = new QLabel(EntryDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        QuantityLine = new QLineEdit(EntryDialog);
        QuantityLine->setObjectName(QString::fromUtf8("QuantityLine"));

        verticalLayout_2->addWidget(QuantityLine);

        quantityLabel = new QLabel(EntryDialog);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));

        verticalLayout_2->addWidget(quantityLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        UnitLine = new QLineEdit(EntryDialog);
        UnitLine->setObjectName(QString::fromUtf8("UnitLine"));

        verticalLayout_3->addWidget(UnitLine);

        unitLabel = new QLabel(EntryDialog);
        unitLabel->setObjectName(QString::fromUtf8("unitLabel"));

        verticalLayout_3->addWidget(unitLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_3);

        addButton = new QPushButton(EntryDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        modifyButton = new QPushButton(EntryDialog);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));

        horizontalLayout->addWidget(modifyButton);

        deleteButton = new QPushButton(EntryDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        retranslateUi(EntryDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EntryDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EntryDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EntryDialog);
    } // setupUi

    void retranslateUi(QDialog *EntryDialog)
    {
        EntryDialog->setWindowTitle(QCoreApplication::translate("EntryDialog", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("EntryDialog", "Recipe name", nullptr));
        recipeLabel->setText(QCoreApplication::translate("EntryDialog", "Recipe", nullptr));
        ingredientsLabel->setText(QCoreApplication::translate("EntryDialog", "Ingredients", nullptr));
        nameLabel->setText(QCoreApplication::translate("EntryDialog", "Name", nullptr));
        quantityLabel->setText(QCoreApplication::translate("EntryDialog", "Quantity", nullptr));
        unitLabel->setText(QCoreApplication::translate("EntryDialog", "Unit", nullptr));
        addButton->setText(QCoreApplication::translate("EntryDialog", "Add", nullptr));
        modifyButton->setText(QCoreApplication::translate("EntryDialog", "Modify", nullptr));
        deleteButton->setText(QCoreApplication::translate("EntryDialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntryDialog: public Ui_EntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYDIALOG_H