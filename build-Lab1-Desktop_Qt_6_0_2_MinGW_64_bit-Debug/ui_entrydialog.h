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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntryDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *applyButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *RecipeNameLabel;
    QLineEdit *RecipeNameLine;
    QLabel *recipeLabel;
    QTextEdit *RecipeTextEdit;
    QLabel *ingredientsLabel;
    QTableView *IngredientsTableView;
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
        gridLayout_2 = new QGridLayout(EntryDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        okButton = new QPushButton(EntryDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        verticalLayout_5->addWidget(okButton);

        cancelButton = new QPushButton(EntryDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout_5->addWidget(cancelButton);

        applyButton = new QPushButton(EntryDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        verticalLayout_5->addWidget(applyButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        RecipeNameLabel = new QLabel(EntryDialog);
        RecipeNameLabel->setObjectName(QString::fromUtf8("RecipeNameLabel"));

        verticalLayout_4->addWidget(RecipeNameLabel);

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


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(EntryDialog);

        QMetaObject::connectSlotsByName(EntryDialog);
    } // setupUi

    void retranslateUi(QDialog *EntryDialog)
    {
        EntryDialog->setWindowTitle(QCoreApplication::translate("EntryDialog", "Add", nullptr));
        okButton->setText(QCoreApplication::translate("EntryDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("EntryDialog", "Cancel", nullptr));
        applyButton->setText(QCoreApplication::translate("EntryDialog", "Apply", nullptr));
        RecipeNameLabel->setText(QCoreApplication::translate("EntryDialog", "Recipe name", nullptr));
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
