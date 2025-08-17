#ifndef TOPGUANLI_H
#define TOPGUANLI_H

#include <QWidget>
#include "qtedit.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QDebug>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class topGuanLi; }
QT_END_NAMESPACE

class topGuanLi : public QWidget
{
    Q_OBJECT

public:
    topGuanLi(QWidget *parent = nullptr);
    ~topGuanLi();

    QList<QList<QString>> getlist();


    void init(QString str,QList<QString> data);
    bool saveValueList(QString title,const QList<QList<QString>>& valuelist);
    QList<QList<QString>> readValueList(QString title);

private:
    void displayDataInTableWidget(QTableWidget *tableWidget,
                                             const QList<QList<QString>> &valuelist,
                                             const QList<QString> &title);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    QList<QList<QString>> valuelist;
    Ui::topGuanLi *ui;
    qtedit *myqtedit;
    QList<QString> title;
    QString filetitle;
    int listlength = 0;
};
#endif // TOPGUANLI_H
