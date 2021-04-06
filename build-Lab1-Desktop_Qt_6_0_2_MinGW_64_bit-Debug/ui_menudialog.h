/********************************************************************************
** Form generated from reading UI file 'menudialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUDIALOG_H
#define UI_MENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MenuDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *availableRecipesLabel;
    QTableView *availableRecipesTableView;
    QVBoxLayout *verticalLayout_5;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *cookPushButton;
    QPushButton *removePushButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *toBeCookedLabel;
    QTableView *toBeCookedtableView;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *ingredientsToBuyLabel;
    QTableView *ingredientsToBuyTableView;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MenuDialog)
    {
        if (MenuDialog->objectName().isEmpty())
            MenuDialog->setObjectName(QString::fromUtf8("MenuDialog"));
        MenuDialog->setEnabled(true);
        MenuDialog->resize(800, 600);
        gridLayout_2 = new QGridLayout(MenuDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        availableRecipesLabel = new QLabel(MenuDialog);
        availableRecipesLabel->setObjectName(QString::fromUtf8("availableRecipesLabel"));

        verticalLayout_2->addWidget(availableRecipesLabel);

        availableRecipesTableView = new QTableView(MenuDialog);
        availableRecipesTableView->setObjectName(QString::fromUtf8("availableRecipesTableView"));
        availableRecipesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        availableRecipesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(availableRecipesTableView);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        buttonBox = new QDialogButtonBox(MenuDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);

        cookPushButton = new QPushButton(MenuDialog);
        cookPushButton->setObjectName(QString::fromUtf8("cookPushButton"));

        verticalLayout_5->addWidget(cookPushButton);

        removePushButton = new QPushButton(MenuDialog);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        verticalLayout_5->addWidget(removePushButton);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_5, 0, 4, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toBeCookedLabel = new QLabel(MenuDialog);
        toBeCookedLabel->setObjectName(QString::fromUtf8("toBeCookedLabel"));

        verticalLayout_3->addWidget(toBeCookedLabel);

        toBeCookedtableView = new QTableView(MenuDialog);
        toBeCookedtableView->setObjectName(QString::fromUtf8("toBeCookedtableView"));
        toBeCookedtableView->setSelectionMode(QAbstractItemView::SingleSelection);
        toBeCookedtableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(toBeCookedtableView);


        gridLayout->addLayout(verticalLayout_3, 0, 3, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4->setContentsMargins(0, -1, 0, 0);

        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ingredientsToBuyLabel = new QLabel(MenuDialog);
        ingredientsToBuyLabel->setObjectName(QString::fromUtf8("ingredientsToBuyLabel"));

        verticalLayout->addWidget(ingredientsToBuyLabel);

        ingredientsToBuyTableView = new QTableView(MenuDialog);
        ingredientsToBuyTableView->setObjectName(QString::fromUtf8("ingredientsToBuyTableView"));
        ingredientsToBuyTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ingredientsToBuyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(ingredientsToBuyTableView);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(MenuDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MenuDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MenuDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MenuDialog);
    } // setupUi

    void retranslateUi(QDialog *MenuDialog)
    {
        MenuDialog->setWindowTitle(QCoreApplication::translate("MenuDialog", "Shopping List", nullptr));
        availableRecipesLabel->setText(QCoreApplication::translate("MenuDialog", "Available Recipes", nullptr));
        cookPushButton->setText(QCoreApplication::translate("MenuDialog", "Cook", nullptr));
        removePushButton->setText(QCoreApplication::translate("MenuDialog", "Remove", nullptr));
        toBeCookedLabel->setText(QCoreApplication::translate("MenuDialog", "To be cooked", nullptr));
        ingredientsToBuyLabel->setText(QCoreApplication::translate("MenuDialog", "Ingredients to buy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuDialog: public Ui_MenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUDIALOG_H
