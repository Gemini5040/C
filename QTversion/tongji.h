#ifndef TONGJI_H
#define TONGJI_H

#include <QWidget>

namespace Ui {
class tongji;
}

class tongji : public QWidget
{
    Q_OBJECT

public:
    explicit tongji(QWidget *parent = nullptr);
    ~tongji();

    void settext(QList<QList<QString>> data);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

signals:
    void sendGn1();
    void sendGn2();
    void sendGn3();
    void sendGn4();
    void sendGn5();
    void sendGn6();
private:
    Ui::tongji *ui;
};

#endif // TONGJI_H
