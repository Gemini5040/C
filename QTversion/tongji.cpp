#include "tongji.h"
#include "ui_tongji.h"

tongji::tongji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tongji)
{
    ui->setupUi(this);
}

tongji::~tongji()
{
    delete ui;
}

void tongji::on_pushButton_clicked()
{
    // 统计每月收入
    emit sendGn1();
}

void tongji::on_pushButton_2_clicked()
{
    // 统计每月支出
    emit sendGn2();
}

void tongji::on_pushButton_3_clicked()
{
    // 统计每学期支出
    emit sendGn3();
}

void tongji::on_pushButton_4_clicked()
{
    // 统计每学期收入
    emit sendGn4();
}

void tongji::on_pushButton_5_clicked()
{
    // 按月份排序
    emit sendGn5();
}

void tongji::on_pushButton_6_clicked()
{
    // 按金额排序
    emit sendGn6();
}

void tongji::settext(QList<QList<QString>> data)
{
    ui->textEdit->clear();
    for (int i = 0;i < data.length();i ++) {
        QString showtext;
        for (int j = 0;j < data.at(i).length();j ++) {
            showtext.append(data.at(i).at(j));
            showtext.append(" ");
        }
        ui->textEdit->append(showtext);
    }
}

