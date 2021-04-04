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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_showFullRecipeDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *Name;
    QLabel *descriptionLabel;
    QTextEdit *Description;
    QLabel *ingredientsLabel;
    QTableView *ingredientsTableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *showFullRecipeDialog)
    {
        if (showFullRecipeDialog->objectName().isEmpty())
            showFullRecipeDialog->setObjectName(QString::fromUtf8("showFullRecipeDialog"));
        showFullRecipeDialog->resize(488, 452);
        horizontalLayout_2 = new QHBoxLayout(showFullRecipeDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
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

        descriptionLabel = new QLabel(showFullRecipeDialog);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        verticalLayout->addWidget(descriptionLabel);

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


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(showFullRecipeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        horizontalLayout_2->addLayout(horizontalLayout);


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
        descriptionLabel->setText(QCoreApplication::translate("showFullRecipeDialog", "Description", nullptr));
        ingredientsLabel->setText(QCoreApplication::translate("showFullRecipeDialog", "Ingredients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showFullRecipeDialog: public Ui_showFullRecipeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFULLRECIPEDIALOG_H
