#include "qtedit.h"
#include "ui_qtedit.h"

qtedit::qtedit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qtedit)
{
    ui->setupUi(this);
    setWindowTitle("编辑");
    qlabellist.append(ui->label);
    qlabellist.append(ui->label_2);
    qlabellist.append(ui->label_3);
    qlabellist.append(ui->label_4);
    qlabellist.append(ui->label_5);
    qlabellist.append(ui->label_6);
    qlabellist.append(ui->label_7);
    qlabellist.append(ui->label_8);
    qlabellist.append(ui->label_9);
    qlabellist.append(ui->label_10);
    qlabellist.append(ui->label_11);
    qlabellist.append(ui->label_12);
    qlabellist.append(ui->label_13);
    qlabellist.append(ui->label_14);
    qlabellist.append(ui->label_15);
    qlabellist.append(ui->label_16);
    qlinelist.append(ui->lineEdit);
    qlinelist.append(ui->lineEdit_2);
    qlinelist.append(ui->lineEdit_3);
    qlinelist.append(ui->lineEdit_4);
    qlinelist.append(ui->lineEdit_5);
    qlinelist.append(ui->lineEdit_6);
    qlinelist.append(ui->lineEdit_7);
    qlinelist.append(ui->lineEdit_8);
    qlinelist.append(ui->lineEdit_9);
    qlinelist.append(ui->lineEdit_10);
    qlinelist.append(ui->lineEdit_11);
    qlinelist.append(ui->lineEdit_12);
    qlinelist.append(ui->lineEdit_13);
    qlinelist.append(ui->lineEdit_14);
    qlinelist.append(ui->lineEdit_15);
    qlinelist.append(ui->lineEdit_16);
}

qtedit::~qtedit()
{
    delete ui;
}

void qtedit::guanli(QList<QString> data)
{
    for (int i = 0;i < data.length();i ++) {
        qlabellist.at(i)->setText(data.at(i));
    }
    for (int i = data.length();i < 16;i ++) {
        qlabellist.at(i)->hide();
        qlinelist.at(i)->hide();
    }
}

void qtedit::settext(QString str)
{
    ui->pushButton->setText(str);
}

void qtedit::on_pushButton_clicked()
{
    QList<QString> data;
    for (int i = 0;i < 16;i ++) {
        if(qlinelist.at(i)->text() == "")
        {
            data.append("空");
        }
        else
        {
            data.append(qlinelist.at(i)->text());
        }
    }
    emit sendstr(ui->pushButton->text(),data);
}

void qtedit::setlistlabel(QList<QString> data)
{
    for (int i = 0;i < data.length();i ++) {
        qlabellist.at(i)->setText(data.at(i));
    }
}
void qtedit::setlistline(QList<QString> data)
{
    for (int i = 0;i < data.length();i ++) {
        qlinelist.at(i)->setText(data.at(i));
    }
}
