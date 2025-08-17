#include "topguanli.h"
#include "ui_topguanli.h"

topGuanLi::topGuanLi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::topGuanLi)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowTitle("主页");
    myqtedit = new qtedit;
    ui->stackedWidget->addWidget(myqtedit);
    ui->stackedWidget->setCurrentWidget(myqtedit);
    connect(myqtedit,&qtedit::sendstr,this,[=](QString str,QList<QString> data){
        if(str == "增")
        {
            for (int i = 0;i < valuelist.length();i ++) {
                if(valuelist.at(i).at(0) == data.at(0))
                {
                    QMessageBox::warning(nullptr,"警告","增加失败，已存在！");
                    return;
                }
            }
            valuelist.append(data);
            displayDataInTableWidget(ui->tableWidget,valuelist,title);
            QMessageBox::warning(nullptr,"提示","增加成功！");
        }
        else if(str == "删")
        {
            for (int i = 0;i < valuelist.length();i ++) {
                if(valuelist.at(i).at(0) == data.at(0))
                {
                    valuelist.removeAt(i);
                    displayDataInTableWidget(ui->tableWidget,valuelist,title);
                    QMessageBox::warning(nullptr,"提示","删除成功！");
                    return;
                }
            }
            QMessageBox::warning(nullptr,"警告","删除失败，不存在！");
        }
        else if(str == "改")
        {
            for (int i = 0;i < valuelist.length();i ++) {
                if(valuelist.at(i).at(0) == data.at(0))
                {
                    for (int j = 0;j < data.length();j ++) {
                        valuelist[i][j] = data.at(j);
                    }
                    displayDataInTableWidget(ui->tableWidget,valuelist,title);
                    QMessageBox::warning(nullptr,"提示","修改成功！");
                    return;
                }
            }
            QMessageBox::warning(nullptr,"提示","修改失败，不存在！");
        }
        else if(str == "查")
        {
            for (int i = 0;i < valuelist.length();i ++) {
                if(valuelist.at(i).at(0) == data.at(0))
                {
                    myqtedit->setlistline(valuelist.at(i));
                    displayDataInTableWidget(ui->tableWidget,valuelist,title);
                    QMessageBox::warning(nullptr,"提示","查询成功！");
                    return;
                }
            }
            QMessageBox::warning(nullptr,"提示","查询失败，不存在！");
        }
    });
}

topGuanLi::~topGuanLi()
{
    delete ui;
}

void topGuanLi::init(QString str,QList<QString> data)
{
    filetitle = str;
    myqtedit->guanli(data);
    ui->label->setText(str);
    myqtedit->setlistlabel(data);
    title = data;
    valuelist = readValueList(filetitle);
    displayDataInTableWidget(ui->tableWidget,valuelist,title);
    listlength = data.length();
}
void topGuanLi::displayDataInTableWidget(QTableWidget *tableWidget,
                                         const QList<QList<QString>> &valuelist,
                                         const QList<QString> &title)
{
    tableWidget->setColumnCount(title.size());
    tableWidget->setRowCount(valuelist.size());
    tableWidget->setHorizontalHeaderLabels(title);
    for (int row = 0; row < valuelist.size(); ++row) {
        const QList<QString> &rowData = valuelist[row];
        for (int col = 0; col < rowData.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(rowData[col]);
            tableWidget->setItem(row, col, item);
        }
    }
    saveValueList(filetitle,valuelist);
}

void topGuanLi::on_pushButton_clicked()
{
    myqtedit->settext("增");
}

void topGuanLi::on_pushButton_2_clicked()
{
    myqtedit->settext("删");
}

void topGuanLi::on_pushButton_3_clicked()
{
    myqtedit->settext("改");
}

void topGuanLi::on_pushButton_4_clicked()
{
    myqtedit->settext("查");
}

bool topGuanLi::saveValueList(QString title,const QList<QList<QString>>& valuelist)
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/" + title + ".dat";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    for (const auto& innerList : valuelist) {
        QString line;
        for (const auto& str : innerList) {
            line += str + " ";
        }
        // 去掉最后一个多余的
        if (!line.isEmpty()) {
            line.chop(1);
        }
        out << line << "\n";
    }
    file.close();
    return true;
}

QList<QList<QString>> topGuanLi::readValueList(QString title)
{
    QList<QList<QString>> valuelist;
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/" + title + ".dat";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return valuelist;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList items = line.split(' ');
        valuelist.append(items);
    }
    file.close();
    return valuelist;
}
QList<QList<QString>> topGuanLi::getlist()
{
    QList<QList<QString>> buflist;
    for (int i =  0;i < valuelist.length();i ++) {
        QList<QString> buff;
        for (int j = 0;j < listlength;j ++) {
            buff.append(valuelist.at(i).at(j));
        }
        buflist.append(buff);
    }
    return buflist;
}


