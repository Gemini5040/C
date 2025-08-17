#include "mymenu.h"
#include "ui_mymenu.h"

QList<QList<QString>> mymenu::getlist()
{
    QList<QList<QString>> daya = mytopguanli2->getlist();
    return daya;
}

mymenu::mymenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mymenu)
{
    ui->setupUi(this);
    setWindowTitle("主页");
    mytopguanli1 = new topGuanLi;
    QList<QString> strlist1;
    strlist1 << "信息序号" << "用途" << "类型" << "时间" << "总计";
    mytopguanli1->init("财  务  管  理",strlist1);
    mytopguanli2 = new topGuanLi;
    QList<QString> strlist2;
    strlist2 << "成员序号" << "学号" << "姓名" << "性别" << "电话";
    mytopguanli2->init("成  员  管  理",strlist2);
    ui->stackedWidget->addWidget(mytopguanli1);
    ui->stackedWidget->addWidget(mytopguanli2);
    ui->stackedWidget->setCurrentWidget(mytopguanli1);

    mytongji = new tongji;
    ui->stackedWidget->addWidget(mytongji);
    connect(mytongji,&tongji::sendGn1,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = calculateMonthlyIncome(daya);
        mytongji->settext(data);
    });
    connect(mytongji,&tongji::sendGn2,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = calculateMonthlyExpenses(daya);
        mytongji->settext(data);
    });
    connect(mytongji,&tongji::sendGn3,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = calculateSemesterExpenses(daya);
        mytongji->settext(data);
    });
    connect(mytongji,&tongji::sendGn4,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = calculateSemesterIncome(daya);
        mytongji->settext(data);
    });
    connect(mytongji,&tongji::sendGn5,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = sortByMonth(daya);
        mytongji->settext(data);
    });
    connect(mytongji,&tongji::sendGn6,this,[=](){
        QList<QList<QString>> daya = mytopguanli1->getlist();
        QList<QList<QString>> data = sortBySemester(daya);
        mytongji->settext(data);
    });
}

void mymenu::setui(bool flag)
{
    if(flag == false)
    {
        ui->pushButton_2->hide();
    }
}

mymenu::~mymenu()
{
    delete ui;
}

void mymenu::on_pushButton_clicked()
{
    // 财务管理
    ui->stackedWidget->setCurrentWidget(mytopguanli1);
}

void mymenu::on_pushButton_2_clicked()
{
    // 成员管理
    ui->stackedWidget->setCurrentWidget(mytopguanli2);
}

void mymenu::on_pushButton_3_clicked()
{
    // 数据分析
    ui->stackedWidget->setCurrentWidget(mytongji);
}

// 统计每月收入
QList<QList<QString>> mymenu::calculateMonthlyIncome(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result;
    QList<QString> header;
    header << "月份" << "收入总计";
    result.append(header);

    QHash<QString, double> monthlyIncome;
    for (const auto& item : valuelist) {
        if (item.size() >= 4 && item[2] == "收入") {
            QString dateStr = item[3];
            QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
            QString month = date.toString("yyyy-MM");
            double amount = item[4].toDouble();
            monthlyIncome[month] += amount;
        }
    }

    for (auto it = monthlyIncome.begin(); it != monthlyIncome.end(); ++it) {
        QList<QString> row;
        row << it.key() << QString::number(it.value());
        result.append(row);
    }

    return result;
}

// 统计每月支出
QList<QList<QString>> mymenu::calculateMonthlyExpenses(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result;
    QList<QString> header;
    header << "月份" << "支出总计";
    result.append(header);

    QHash<QString, double> monthlyExpenses;
    for (const auto& item : valuelist) {
        if (item.size() >= 4 && item[2] == "支出") {
            QString dateStr = item[3];
            QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
            QString month = date.toString("yyyy-MM");
            double amount = item[4].toDouble();
            monthlyExpenses[month] += amount;
        }
    }

    for (auto it = monthlyExpenses.begin(); it != monthlyExpenses.end(); ++it) {
        QList<QString> row;
        row << it.key() << QString::number(it.value());
        result.append(row);
    }

    return result;
}

// 统计每学期支出
QList<QList<QString>> mymenu::calculateSemesterExpenses(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result;
    QList<QString> header;
    header << "学期" << "支出总计";
    result.append(header);

    QHash<QString, double> semesterExpenses;
    for (const auto& item : valuelist) {
        if (item.size() >= 4 && item[2] == "支出") {
            QString dateStr = item[3];
            QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
            int year = date.year();
            int month = date.month();
            QString semester;
            if (month >= 9) {
                semester = QString::number(year) + "-" + QString::number(year + 1);
            } else {
                semester = QString::number(year - 1) + "-" + QString::number(year);
            }
            double amount = item[4].toDouble();
            semesterExpenses[semester] += amount;
        }
    }

    for (auto it = semesterExpenses.begin(); it != semesterExpenses.end(); ++it) {
        QList<QString> row;
        row << it.key() << QString::number(it.value());
        result.append(row);
    }

    return result;
}

// 统计每学期收入
QList<QList<QString>> mymenu::calculateSemesterIncome(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result;
    QList<QString> header;
    header << "学期" << "收入总计";
    result.append(header);

    QHash<QString, double> semesterIncome;
    for (const auto& item : valuelist) {
        if (item.size() >= 4 && item[2] == "收入") {
            QString dateStr = item[3];
            QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
            int year = date.year();
            int month = date.month();
            QString semester;
            if (month >= 9) {
                semester = QString::number(year) + "-" + QString::number(year + 1);
            } else {
                semester = QString::number(year - 1) + "-" + QString::number(year);
            }
            double amount = item[4].toDouble();
            semesterIncome[semester] += amount;
        }
    }

    for (auto it = semesterIncome.begin(); it != semesterIncome.end(); ++it) {
        QList<QString> row;
        row << it.key() << QString::number(it.value());
        result.append(row);
    }

    return result;
}

// 按月排序
QList<QList<QString>> mymenu::sortByMonth(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result = valuelist;
    std::sort(result.begin(), result.end(), [](const QList<QString>& a, const QList<QString>& b) {
        if (a.size() >= 4 && b.size() >= 4) {
            QString dateStrA = a[3];
            QString dateStrB = b[3];
            QDate dateA = QDate::fromString(dateStrA, "yyyy-MM-dd");
            QDate dateB = QDate::fromString(dateStrB, "yyyy-MM-dd");
            return dateA < dateB;
        }
        return false;
    });
    return result;
}

// 按学期排序
QList<QList<QString>> mymenu::sortBySemester(const QList<QList<QString>>& valuelist) {
    QList<QList<QString>> result = valuelist;
    std::sort(result.begin(), result.end(), [](const QList<QString>& a, const QList<QString>& b) {
        if (a.size() >= 5 && b.size() >= 5) {
            // 将总计字段转换为 double 类型进行比较
            double totalA = a[4].toDouble();
            double totalB = b[4].toDouble();
            return totalA < totalB;
        }
        return false;
    });
    return result;
}
