#ifndef QTEDIT_H
#define QTEDIT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
namespace Ui {
class qtedit;
}

class qtedit : public QWidget
{
    Q_OBJECT

public:
    explicit qtedit(QWidget *parent = nullptr);
    ~qtedit();

    void guanli(QList<QString> data);
    void settext(QString str);
    void setlistlabel(QList<QString> data);
    void setlistline(QList<QString> data);

signals:
    void sendstr(QString str,QList<QString> data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::qtedit *ui;

private:
    QList<QLabel *> qlabellist;
    QList<QLineEdit *> qlinelist;
};

#endif // QTEDIT_H
