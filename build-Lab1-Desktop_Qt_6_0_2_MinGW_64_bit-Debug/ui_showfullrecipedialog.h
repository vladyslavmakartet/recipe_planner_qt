/********************************************************************************
** Form generated from reading UI file 'showfullrecipedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWFULLRECIPEDIALOG_H
#define UI_SHOWFULLRECIPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_showFullRecipeDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *Name;
    QLabel *recipeLabel;
    QTextEdit *Description;
    QLabel *ingredientsLabel;
    QTableView *ingredientsTableView;
    QVBoxLayout *verticalLayout_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *showFullRecipeDialog)
    {
        if (showFullRecipeDialog->objectName().isEmpty())
            showFullRecipeDialog->setObjectName(QString::fromUtf8("showFullRecipeDialog"));
        showFullRecipeDialog->setWindowModality(Qt::WindowModal);
        showFullRecipeDialog->resize(430, 485);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showFullRecipeDialog->sizePolicy().hasHeightForWidth());
        showFullRecipeDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(showFullRecipeDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nameLabel = new QLabel(showFullRecipeDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        Name = new QLabel(showFullRecipeDialog);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setEnabled(true);
        Name->setAutoFillBackground(false);
        Name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        Name->setFrameShape(QFrame::StyledPanel);
        Name->setFrameShadow(QFrame::Sunken);
        Name->setLineWidth(0);
        Name->setMidLineWidth(0);
        Name->setWordWrap(true);
        Name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(Name);

        recipeLabel = new QLabel(showFullRecipeDialog);
        recipeLabel->setObjectName(QString::fromUtf8("recipeLabel"));

        verticalLayout->addWidget(recipeLabel);

        Description = new QTextEdit(showFullRecipeDialog);
        Description->setObjectName(QString::fromUtf8("Description"));
        Description->setReadOnly(true);

        verticalLayout->addWidget(Description);

        ingredientsLabel = new QLabel(showFullRecipeDialog);
        ingredientsLabel->setObjectName(QString::fromUtf8("ingredientsLabel"));

        verticalLayout->addWidget(ingredientsLabel);

        ingredientsTableView = new QTableView(showFullRecipeDialog);
        ingredientsTableView->setObjectName(QString::fromUtf8("ingredientsTableView"));
        ingredientsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ingredientsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ingredientsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ingredientsTableView->setCornerButtonEnabled(false);

        verticalLayout->addWidget(ingredientsTableView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonBox = new QDialogButtonBox(showFullRecipeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(showFullRecipeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, showFullRecipeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, showFullRecipeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(showFullRecipeDialog);
    } // setupUi

    void retranslateUi(QDialog *showFullRecipeDialog)
    {
        showFullRecipeDialog->setWindowTitle(QCoreApplication::translate("showFullRecipeDialog", "Info", nullptr));
        nameLabel->setText(QCoreApplication::translate("showFullRecipeDialog", "Name", nullptr));
        Name->setText(QString());
        recipeLabel->setText(QCoreApplication::translate("showFullRecipeDialog", "Recipe", nullptr));
        ingredientsLabel->setText(QCoreApplication::translate("showFullRecipeDialog", "Ingredients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showFullRecipeDialog: public Ui_showFullRecipeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFULLRECIPEDIALOG_H
