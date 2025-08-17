#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    mymymenu = new mymenu;
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    zhlist = mymymenu->getlist();
    qDebug() << zhlist;
    QString zh = ui->lineEdit->text();
    QString mm = ui->lineEdit_2->text();
    if(zh == "admin" && mm == "admin")
    {
        this->hide();
        mymymenu->show();
        QMessageBox::warning(nullptr,"提示","管理员登陆");
        return;
    }
    else
    {
        for (int i = 0;i < zhlist.length();i ++) {
            if(zh == zhlist.at(i).at(1))
            {
                this->hide();
                mymymenu->show();
                mymymenu->setui(false);
                QMessageBox::warning(nullptr,"提示","普通成员登陆");
                return;
            }
        }
    }

}
