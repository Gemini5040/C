/********************************************************************************
** Form generated from reading UI file 'mymenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMENU_H
#define UI_MYMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mymenu
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *mymenu)
    {
        if (mymenu->objectName().isEmpty())
            mymenu->setObjectName("mymenu");
        mymenu->resize(1322, 706);
        gridLayout = new QGridLayout(mymenu);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(mymenu);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 565, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 5, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(mymenu);

        QMetaObject::connectSlotsByName(mymenu);
    } // setupUi

    void retranslateUi(QWidget *mymenu)
    {
        mymenu->setWindowTitle(QCoreApplication::translate("mymenu", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("mymenu", "\350\264\242\345\212\241\347\256\241\347\220\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mymenu", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mymenu", "\346\210\220\345\221\230\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mymenu: public Ui_mymenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMENU_H
