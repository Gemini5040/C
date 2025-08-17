#include <QApplication>
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    QString styleSheet = R"(
        /* 设置应用程序整体背景为天空蓝 */
        QWidget {
            background-color: skyblue;
        }

        /* 设置 QPushButton 样式 */
        QPushButton {
            background-color: lightblue; /* 浅蓝色 */
            border: 2px solid lightblue; /* 边框颜色与背景颜色一致 */
            border-radius: 5px;
            padding: 5px;
            color: #4B0082; /* 深紫色文字 */
        }
        QPushButton:hover {
            background-color: #ADD8E6; /* 鼠标悬停时颜色稍深的浅蓝色 */
            border: 2px solid #ADD8E6; /* 悬停时边框颜色也改变 */
        }
        QPushButton:pressed {
            background-color: #87CEEB; /* 按下时更深的蓝色 */
            border: 2px solid #87CEEB; /* 按下时边框颜色也改变 */
        }

        /* 设置 QLabel 样式 */
        QLabel {
            background-color: lightblue; /* 浅蓝色 */
            padding: 5px;
            color: #4B0082; /* 深紫色文字 */
        }

        /* 设置 QLineEdit 样式 */
        QLineEdit {
            background-color: lightblue; /* 浅蓝色 */
            border: 2px solid lightblue; /* 边框颜色与背景颜色一致 */
            border-radius: 5px;
            padding: 5px;
            color: #4B0082; /* 深紫色文字 */
        }

        /* 设置 QTextEdit 样式 */
        QTextEdit {
            background-color: lightblue; /* 浅蓝色 */
            border: 2px solid lightblue; /* 边框颜色与背景颜色一致 */
            border-radius: 5px;
            padding: 5px;
            color: #4B0082; /* 深紫色文字 */
        }
        QTextEdit:hover {
            background-color: #ADD8E6; /* 鼠标悬停时颜色稍深的浅蓝色 */
            border: 2px solid #ADD8E6; /* 悬停时边框颜色也改变 */
        }
        QTextEdit:focus {
            background-color: #87CEEB; /* 获得焦点时更深的蓝色 */
            border: 2px solid #87CEEB; /* 获得焦点时边框颜色也改变 */
        }

        /* 设置 QTableWidget 样式 */
        QTableWidget {
            background-color: lightblue; /* 浅蓝色 */
            border: 2px solid lightblue; /* 边框颜色与背景颜色一致 */
            border-radius: 5px;
            padding: 5px;
            color: #4B0082; /* 深紫色文字 */
        }
        QTableWidget::item:hover {
            background-color: #ADD8E6; /* 鼠标悬停在表格项上时颜色稍深的浅蓝色 */
        }
        QTableWidget::item:selected {
            background-color: #87CEEB; /* 选中表格项时更深的蓝色 */
        }
        QHeaderView::section {
            background-color: lightblue; /* 表头背景颜色 */
            border: 2px solid lightblue;
            padding: 5px;
            color: #4B0082; /* 表头文字颜色 */
        }
    )";
    a.setStyleSheet(styleSheet);


    return a.exec();
}
