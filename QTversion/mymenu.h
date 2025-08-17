#ifndef MYMENU_H
#define MYMENU_H

#include <QDate>
#include <QWidget>
#include "topguanli.h"
#include "tongji.h"

namespace Ui {
class mymenu;
}

class mymenu : public QWidget
{
    Q_OBJECT

public:
    explicit mymenu(QWidget *parent = nullptr);
    ~mymenu();

    void setui(bool flag);
    QList<QList<QString>> getlist();

private:
    QList<QList<QString>> calculateMonthlyIncome(const QList<QList<QString>>& valuelist);
    QList<QList<QString>> calculateMonthlyExpenses(const QList<QList<QString>>& valuelist);
    QList<QList<QString>> calculateSemesterExpenses(const QList<QList<QString>>& valuelist);
    QList<QList<QString>> calculateSemesterIncome(const QList<QList<QString>>& valuelist);
    QList<QList<QString>> sortByMonth(const QList<QList<QString>>& valuelist);
    QList<QList<QString>> sortBySemester(const QList<QList<QString>>& valuelist);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mymenu *ui;

    topGuanLi *mytopguanli1;
    topGuanLi *mytopguanli2;
    tongji *mytongji;
};

#endif // MYMENU_H
