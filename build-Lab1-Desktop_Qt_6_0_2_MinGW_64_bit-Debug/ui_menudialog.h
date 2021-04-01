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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MenuDialog
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListView *listView;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListView *listView_2;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *MenuDialog)
    {
        if (MenuDialog->objectName().isEmpty())
            MenuDialog->setObjectName(QString::fromUtf8("MenuDialog"));
        MenuDialog->setEnabled(true);
        MenuDialog->resize(800, 600);
        gridLayout_3 = new QGridLayout(MenuDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(MenuDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        listView = new QListView(MenuDialog);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(MenuDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        listView_2 = new QListView(MenuDialog);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        verticalLayout_3->addWidget(listView_2);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(MenuDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(MenuDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(MenuDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        pushButton = new QPushButton(MenuDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MenuDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(MenuDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(MenuDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MenuDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MenuDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MenuDialog);
    } // setupUi

    void retranslateUi(QDialog *MenuDialog)
    {
        MenuDialog->setWindowTitle(QCoreApplication::translate("MenuDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("MenuDialog", "Added Recipes", nullptr));
        label_3->setText(QCoreApplication::translate("MenuDialog", "Ingredients to buy", nullptr));
        label->setText(QCoreApplication::translate("MenuDialog", "Recipe", nullptr));
        pushButton->setText(QCoreApplication::translate("MenuDialog", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuDialog", "Delete", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MenuDialog", "Modify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuDialog: public Ui_MenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUDIALOG_H
