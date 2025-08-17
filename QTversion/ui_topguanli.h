/********************************************************************************
** Form generated from reading UI file 'topguanli.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPGUANLI_H
#define UI_TOPGUANLI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_topGuanLi
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *label;

    void setupUi(QWidget *topGuanLi)
    {
        if (topGuanLi->objectName().isEmpty())
            topGuanLi->setObjectName(QString::fromUtf8("topGuanLi"));
        topGuanLi->resize(1379, 660);
        gridLayout = new QGridLayout(topGuanLi);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(topGuanLi);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget = new QTableWidget(groupBox_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        gridLayout_4->addWidget(groupBox, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(371, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(400, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 2, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 28pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 2);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(topGuanLi);

        QMetaObject::connectSlotsByName(topGuanLi);
    } // setupUi

    void retranslateUi(QWidget *topGuanLi)
    {
        topGuanLi->setWindowTitle(QCoreApplication::translate("topGuanLi", "topGuanLi", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("topGuanLi", "\346\230\276\347\244\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("topGuanLi", "\346\223\215\344\275\234", nullptr));
        pushButton->setText(QCoreApplication::translate("topGuanLi", "\345\242\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("topGuanLi", "\345\210\240", nullptr));
        pushButton_3->setText(QCoreApplication::translate("topGuanLi", "\346\224\271", nullptr));
        pushButton_4->setText(QCoreApplication::translate("topGuanLi", "\346\237\245", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("topGuanLi", "\345\212\237\350\203\275", nullptr));
        label->setText(QCoreApplication::translate("topGuanLi", "\346\240\207\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class topGuanLi: public Ui_topGuanLi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPGUANLI_H
