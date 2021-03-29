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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
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
    QLineEdit *lineEdit_4;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QListView *listView;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

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

        lineEdit_4 = new QLineEdit(EntryDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_4->addWidget(lineEdit_4);

        label = new QLabel(EntryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        textEdit = new QTextEdit(EntryDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);

        label_2 = new QLabel(EntryDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        listView = new QListView(EntryDialog);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_4->addWidget(listView);


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
        lineEdit = new QLineEdit(EntryDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(EntryDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(EntryDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label_5 = new QLabel(EntryDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_3 = new QLineEdit(EntryDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        label_6 = new QLabel(EntryDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_3);

        pushButton = new QPushButton(EntryDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EntryDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(EntryDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


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
        label->setText(QCoreApplication::translate("EntryDialog", "Recipe", nullptr));
        label_2->setText(QCoreApplication::translate("EntryDialog", "Ingreedients", nullptr));
        label_3->setText(QCoreApplication::translate("EntryDialog", "Item", nullptr));
        label_5->setText(QCoreApplication::translate("EntryDialog", "Quantity", nullptr));
        label_6->setText(QCoreApplication::translate("EntryDialog", "Unit", nullptr));
        pushButton->setText(QCoreApplication::translate("EntryDialog", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EntryDialog", "Modify", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EntryDialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntryDialog: public Ui_EntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYDIALOG_H
