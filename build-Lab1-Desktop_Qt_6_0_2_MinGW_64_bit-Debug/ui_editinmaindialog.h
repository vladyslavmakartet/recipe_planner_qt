/********************************************************************************
** Form generated from reading UI file 'editinmaindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINMAINDIALOG_H
#define UI_EDITINMAINDIALOG_H

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

class Ui_EditInMainDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_16;
    QPushButton *okButtonEdit;
    QPushButton *cancelButtonEdit;
    QPushButton *applyButtonEdit;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_17;
    QLabel *RecipeNameLabelEdit;
    QLineEdit *RecipeNameLineEdit;
    QLabel *recipeLabelEdit;
    QTextEdit *RecipeTextEditEdit;
    QLabel *ingredientsLabelEdit;
    QTableView *IngredientsTableViewEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_18;
    QLineEdit *ingredientNameLineEdit;
    QLabel *nameLabelEdit;
    QVBoxLayout *verticalLayout_19;
    QLineEdit *QuantityLineEdit;
    QLabel *quantityLabelEdit;
    QVBoxLayout *verticalLayout_20;
    QLineEdit *UnitLineEdit;
    QLabel *unitLabelEdit;
    QPushButton *addButtonEdit;
    QPushButton *modifyButtonEdit;
    QPushButton *deleteButtonEdit;

    void setupUi(QDialog *EditInMainDialog)
    {
        if (EditInMainDialog->objectName().isEmpty())
            EditInMainDialog->setObjectName(QString::fromUtf8("EditInMainDialog"));
        EditInMainDialog->resize(800, 600);
        gridLayout_5 = new QGridLayout(EditInMainDialog);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        okButtonEdit = new QPushButton(EditInMainDialog);
        okButtonEdit->setObjectName(QString::fromUtf8("okButtonEdit"));

        verticalLayout_16->addWidget(okButtonEdit);

        cancelButtonEdit = new QPushButton(EditInMainDialog);
        cancelButtonEdit->setObjectName(QString::fromUtf8("cancelButtonEdit"));

        verticalLayout_16->addWidget(cancelButtonEdit);

        applyButtonEdit = new QPushButton(EditInMainDialog);
        applyButtonEdit->setObjectName(QString::fromUtf8("applyButtonEdit"));

        verticalLayout_16->addWidget(applyButtonEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_4);


        gridLayout_4->addLayout(verticalLayout_16, 0, 1, 1, 1);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        RecipeNameLabelEdit = new QLabel(EditInMainDialog);
        RecipeNameLabelEdit->setObjectName(QString::fromUtf8("RecipeNameLabelEdit"));

        verticalLayout_17->addWidget(RecipeNameLabelEdit);

        RecipeNameLineEdit = new QLineEdit(EditInMainDialog);
        RecipeNameLineEdit->setObjectName(QString::fromUtf8("RecipeNameLineEdit"));
        RecipeNameLineEdit->setMaxLength(256);

        verticalLayout_17->addWidget(RecipeNameLineEdit);

        recipeLabelEdit = new QLabel(EditInMainDialog);
        recipeLabelEdit->setObjectName(QString::fromUtf8("recipeLabelEdit"));

        verticalLayout_17->addWidget(recipeLabelEdit);

        RecipeTextEditEdit = new QTextEdit(EditInMainDialog);
        RecipeTextEditEdit->setObjectName(QString::fromUtf8("RecipeTextEditEdit"));

        verticalLayout_17->addWidget(RecipeTextEditEdit);

        ingredientsLabelEdit = new QLabel(EditInMainDialog);
        ingredientsLabelEdit->setObjectName(QString::fromUtf8("ingredientsLabelEdit"));

        verticalLayout_17->addWidget(ingredientsLabelEdit);

        IngredientsTableViewEdit = new QTableView(EditInMainDialog);
        IngredientsTableViewEdit->setObjectName(QString::fromUtf8("IngredientsTableViewEdit"));

        verticalLayout_17->addWidget(IngredientsTableViewEdit);


        gridLayout_4->addLayout(verticalLayout_17, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        ingredientNameLineEdit = new QLineEdit(EditInMainDialog);
        ingredientNameLineEdit->setObjectName(QString::fromUtf8("ingredientNameLineEdit"));
        ingredientNameLineEdit->setMaxLength(256);

        verticalLayout_18->addWidget(ingredientNameLineEdit);

        nameLabelEdit = new QLabel(EditInMainDialog);
        nameLabelEdit->setObjectName(QString::fromUtf8("nameLabelEdit"));

        verticalLayout_18->addWidget(nameLabelEdit, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_4->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        QuantityLineEdit = new QLineEdit(EditInMainDialog);
        QuantityLineEdit->setObjectName(QString::fromUtf8("QuantityLineEdit"));
        QuantityLineEdit->setMaxLength(256);

        verticalLayout_19->addWidget(QuantityLineEdit);

        quantityLabelEdit = new QLabel(EditInMainDialog);
        quantityLabelEdit->setObjectName(QString::fromUtf8("quantityLabelEdit"));

        verticalLayout_19->addWidget(quantityLabelEdit, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_4->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        UnitLineEdit = new QLineEdit(EditInMainDialog);
        UnitLineEdit->setObjectName(QString::fromUtf8("UnitLineEdit"));
        UnitLineEdit->setMaxLength(256);

        verticalLayout_20->addWidget(UnitLineEdit);

        unitLabelEdit = new QLabel(EditInMainDialog);
        unitLabelEdit->setObjectName(QString::fromUtf8("unitLabelEdit"));

        verticalLayout_20->addWidget(unitLabelEdit, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_4->addLayout(verticalLayout_20);

        addButtonEdit = new QPushButton(EditInMainDialog);
        addButtonEdit->setObjectName(QString::fromUtf8("addButtonEdit"));

        horizontalLayout_4->addWidget(addButtonEdit, 0, Qt::AlignTop);

        modifyButtonEdit = new QPushButton(EditInMainDialog);
        modifyButtonEdit->setObjectName(QString::fromUtf8("modifyButtonEdit"));

        horizontalLayout_4->addWidget(modifyButtonEdit, 0, Qt::AlignTop);

        deleteButtonEdit = new QPushButton(EditInMainDialog);
        deleteButtonEdit->setObjectName(QString::fromUtf8("deleteButtonEdit"));

        horizontalLayout_4->addWidget(deleteButtonEdit, 0, Qt::AlignTop);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(EditInMainDialog);

        QMetaObject::connectSlotsByName(EditInMainDialog);
    } // setupUi

    void retranslateUi(QDialog *EditInMainDialog)
    {
        EditInMainDialog->setWindowTitle(QCoreApplication::translate("EditInMainDialog", "Edit", nullptr));
        okButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "OK", nullptr));
        cancelButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "Cancel", nullptr));
#if QT_CONFIG(tooltip)
        applyButtonEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Save changes</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        applyButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "Apply", nullptr));
        RecipeNameLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Recipe name", nullptr));
#if QT_CONFIG(tooltip)
        RecipeNameLineEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Enter recipe name</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        recipeLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Recipe", nullptr));
#if QT_CONFIG(tooltip)
        RecipeTextEditEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Enter text</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ingredientsLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Ingredients", nullptr));
#if QT_CONFIG(tooltip)
        ingredientNameLineEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Ingredient name</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        nameLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Name", nullptr));
#if QT_CONFIG(tooltip)
        QuantityLineEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Ingredient quantity</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        quantityLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Quantity", nullptr));
#if QT_CONFIG(tooltip)
        UnitLineEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Ingredient unit of measurement</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        unitLabelEdit->setText(QCoreApplication::translate("EditInMainDialog", "Unit", nullptr));
#if QT_CONFIG(tooltip)
        addButtonEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Add ingredient</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "Add", nullptr));
#if QT_CONFIG(tooltip)
        modifyButtonEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Modify selected ingredient</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        modifyButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "Modify", nullptr));
#if QT_CONFIG(tooltip)
        deleteButtonEdit->setToolTip(QCoreApplication::translate("EditInMainDialog", "<html><head/><body><p>Delete selected ingredient</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButtonEdit->setText(QCoreApplication::translate("EditInMainDialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditInMainDialog: public Ui_EditInMainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINMAINDIALOG_H
