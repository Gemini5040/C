/********************************************************************************
** Form generated from reading UI file 'tongji.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONGJI_H
#define UI_TONGJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tongji
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *tongji)
    {
        if (tongji->objectName().isEmpty())
            tongji->setObjectName("tongji");
        tongji->resize(1043, 559);
        gridLayout_2 = new QGridLayout(tongji);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(tongji);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(tongji);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout->addWidget(pushButton_6);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(tongji);

        QMetaObject::connectSlotsByName(tongji);
    } // setupUi

    void retranslateUi(QWidget *tongji)
    {
        tongji->setWindowTitle(QCoreApplication::translate("tongji", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("tongji", "\346\230\276\347\244\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("tongji", "\346\223\215\344\275\234", nullptr));
        pushButton->setText(QCoreApplication::translate("tongji", "\347\273\237\350\256\241\346\257\217\346\234\210\346\224\266\345\205\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tongji", "\347\273\237\350\256\241\346\257\217\346\234\210\346\224\257\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tongji", "\347\273\237\350\256\241\346\257\217\345\255\246\346\234\237\346\224\257\345\207\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("tongji", "\347\273\237\350\256\241\346\257\217\345\255\246\346\234\237\346\224\266\345\205\245", nullptr));
        pushButton_5->setText(QCoreApplication::translate("tongji", "\346\214\211\346\234\210\344\273\275\346\216\222\345\272\217", nullptr));
        pushButton_6->setText(QCoreApplication::translate("tongji", "\346\214\211\351\207\221\351\242\235\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tongji: public Ui_tongji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONGJI_H
