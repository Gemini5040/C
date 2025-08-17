#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // 用于清屏功能
#include <myLinkList.h>
#include <someFunction.h>
#include <ctype.h>  // 用于isdigit函数

void welcome_screen() {
    printf("\n\n\n\n\n\n\n\n");
    printf("                        ╔═════════════════════════════════════════════════╗\n");
    printf("                        ║                                                 ║\n");
    printf("                        ║                                                 ║\n");
    printf("                        ║             欢迎来到班级财务管理系统！          ║\n");
    printf("                        ║                                                 ║\n");
    printf("                        ║                   Version 1.8                   ║\n");
    printf("                        ║                                                 ║\n");
    printf("                        ║                                                 ║\n");
    printf("                        ╚═════════════════════════════════════════════════╝\n");
    printf("\n\n                                        按回车键进入系统...");
    getchar();
    system("cls");  // 清屏（Windows系统）
}

int main() {
    // 显示欢迎界面
    welcome_screen();

    // 登录验证
    char username[50];
    char password[20];

    printf("════════════════════════ 用户登录 ════════════════════════\n\n");
    printf("  请输入用户名：");
    scanf("%49s", username);  // 限制输入长度防止溢出
    clear_input_buffer();

    printf("  请输入密码：");
    scanf("%19s", password);
    clear_input_buffer();

    int chance = 3;
    while (1) {
        if (!strcmp(username, "admin") && !strcmp(password, "1")) {
            break;
        }
        else if (!strcmp(username, "user") && !strcmp(password, "2")) {
            break;
        }
        else if(chance){
            printf("\n  用户名或密码错误！还有%d次机会！按下回车键以重新输入！",chance--);
            getchar();
            system("cls");
            printf("════════════════════════ 用户登录 ════════════════════════\n\n");
            printf("  用户名：");
            scanf("%49s", username);
            clear_input_buffer();
            printf("  密码：");
            scanf("%19s", password);
            clear_input_buffer();
        }
        else {
            system("cls");
            return 0;
        }
    }

    printf("\n══════════════════════════════════════════════════════════\n\n");
    printf("  登录成功！按下回车键继续...");
    getchar();
    system("cls");

    LinkList L;
    Init_L(L);

    if (!strcmp(username, "admin") && !strcmp(password, "1")) {
        if (!loadDataFromFile(L)) return 0;

        int flag = 1;
        while (flag) {
            system("cls");
            printf("******用户身份：管理员******\n");

            printf("\n 请选择操作：\n");
            printf("┌───┬──────────────────────┐\n");
            printf("│ 1 │ 录入信息             │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 2 │ 修改班级成员信息     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 3 │ 删除班级成员信息     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 4 │ 查询班级财务状况     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 5 │ 排序班级财务状况     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 6 │ 分类统计             │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 7 │ 更新数据库           │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 0 │ 退出系统             │\n");
            printf("└───┴──────────────────────┘\n");
            printf(" 请输入选项：");
            char op1;
            scanf(" %c", &op1);    // 添加空格跳过空白字符

            printf("\n");

            switch (op1) {
            case '1': {
                financeData newData;
                newData.number = getMaxNumber(L) + 1;
                printf("  姓名：");
                scanf("%s", newData.name);
                printf("  收入：");
                while (1) {
                    scanf("%lf", &newData.income);
                    if (newData.income > 0) {
                        break;
                    }
                    else {
                        printf("  收入格式错误，请重新输入：");
                    }
                }
                printf("  支出：");
                while (1) {
                    scanf("%lf", &newData.expense);
                    if (newData.expense > 0) {
                        break;
                    }
                    else {
                        printf("  支出格式错误，请重新输入：");
                    }
                }
                printf("  时间：");
                char tmpWhen[30];
                while (1) {
                    scanf("%10s", tmpWhen);
                    if (strcmp(tmpWhen, "2024-01-01") > 0 && is_valid_date(tmpWhen)) {
                        strcpy(newData.when, tmpWhen);
                        break;
                    }
                    else {
                        printf("  日期格式错误，请重新输入：");
                    }
                }
                printf("  用途：");
                scanf("%s", newData.purpose);

                Insert_L(L, newData);

                break;
            }

            case '2': {
                printf("  请输入你要修改的成员信息的编号：");
                int num;
                scanf("%d", &num);
                LinkList toSet = getByNum(L, num);
                if (toSet == NULL) {
                    printf("  成员不存在！请按下回车键继续...");
                    clear_input_buffer();
                    getchar();
                }
                else {
                    char op2;
                    printf("\n  请选择要修改的信息：\n");
                    printf("  1-->姓名\n");
                    printf("  2-->收入\n");
                    printf("  3-->支出\n");
                    printf("  4-->用途\n");
                    printf("  5-->时间\n");
                    printf("  0-->取消\n\n");
                    printf("  请输入选项：");
                    scanf(" %c", &op2);    // 添加空格跳过空白字符

                    switch (op2)
                    {
                    case '1': {
                        char newName[50];
                        printf("  请输入修改后的姓名：");
                        scanf("%49s", newName);
                        strcpy(toSet->data.name, newName);
                        break;
                    }
                    case '2': {
                        double newIncome;
                        printf("  请输入修改后的收入：");
                        while (1) {
                            scanf("%lf", &newIncome);
                            if (newIncome >= 0) {
                                break;
                            }
                            else {
                                printf("  收入格式错误，请重新输入：");
                            }
                        }
                        toSet->data.income = newIncome;
                        break;
                    }
                    case '3': {
                        double newExpense;
                        printf("  请输入修改后的支出：");
                        while (1) {
                            scanf("%lf", &newExpense);
                            if (newExpense >= 0) {
                                break;
                            }
                            else {
                                printf("  支出格式错误，请重新输入：");
                            }
                        }
                        toSet->data.expense = newExpense;
                        break;
                    }
                    case '4': {
                        char newPurPose[100];
                        printf("  请输入修改后的用途：");
                        scanf("%99s", newPurPose);
                        strcpy(toSet->data.purpose, newPurPose);
                        break;
                    }
                    case '5': {
                        char newWhen[11];
                        printf("  请输入修改后的时间：");
                        while (1) {
                            scanf("%10s", newWhen);
                            if (strcmp(newWhen, "2024-01-01") > 0 && is_valid_date(newWhen)) {
                                strcpy(toSet->data.when, newWhen);
                                break;
                            }
                            else {
                                printf("  日期格式错误，请重新输入：");
                            }
                        }
                        break;
                    }
                    case '0': {
                        break;
                    }
                    default: {
                        printf("  无效的操作！按下回车键继续...");
                        clear_input_buffer();
                        getchar();
                        break;
                    }
                    }
                }
                printf("  \n修改成功！请按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '3': {
                printf("  请输入你要删除的成员信息的编号：");
                int num;
                scanf("%d", &num);
                if (Delete_L(L, num)) {
                    printf("\n  信息删除成功！");
                }
                else {
                    printf("\n  信息删除失败！");
                }
                printf("按下回车键继续...");
                clear_input_buffer();
                getchar();

                break;
            }

            case '4': {
                Iterate_L(L);
                printf("\n按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '5': {
                printf("  请选择排序的依据：\n");
                printf("  1-->按收入从低到高：\n");
                printf("  2-->按收入从高到低：\n");
                printf("  3-->按支出从低到高：\n");
                printf("  4-->按支出从高到低\n");
                printf("  5-->按时间顺序：\n");
                printf("  6-->按时间逆序：\n");
                printf("  0-->取消\n\n");
                printf("  请输入选项：");
                char op3;
                scanf(" %c", &op3);

                switch (op3)
                {
                case '1': {
                    sortUpIncome(L);
                    break;
                }
                case '2': {
                    sortDownIncome(L);
                    break;
                }
                case '3': {
                    sortUpExpense(L);
                    break;
                }
                case '4': {
                    sortDownExpense(L);
                    break;
                }
                case '5': {
                    sortUpTime(L);
                    break;
                }
                case '6': {
                    sortDownTime(L);
                    break;
                }
                case '0': {
                    break;
                }
                default: {
                    printf("  无效的操作！按下回车键继续...");
                    clear_input_buffer();
                    getchar();
                    break;
                }
                }

                break;
            }

            case '6': {
                financial_statistics(L);
                printf("\n统计完成！按回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '7': {
                SaveToFile(L);
                printf("按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '0': {
                flag = 0;
                break;
            }

            default: {
                printf("  无效的操作！按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }
            }
        }
    }
    else if (!strcmp(username, "user") && !strcmp(password, "2")) {
        if (!loadDataFromFile(L)) return 0;

        int flag = 1;
        while (flag) {
            system("cls");
            printf("******用户身份：普通用户******\n");

            printf("\n 请选择操作：\n");
            printf("┌───┬──────────────────────┐\n");
            printf("│ 1 │ 录入信息             │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 2 │ 向管理员提出修改申请 │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 3 │ 向管理员提出删除申请 │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 4 │ 查询班级财务状况     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 5 │ 排序班级财务状况     │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 6 │ 分类统计             │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 7 │ 保存录入信息         │\n");
            printf("├───┼──────────────────────┤\n");
            printf("│ 0 │ 退出系统             │\n");
            printf("└───┴──────────────────────┘\n");
            printf(" 请输入选项：");
            char op1;
            scanf(" %c", &op1);    // 添加空格跳过空白字符

            printf("\n");

            switch (op1) {
            case '1': {
                financeData newData;
                newData.number = getMaxNumber(L) + 1;
                printf("  姓名：");
                scanf("%s", newData.name);
                printf("  收入：");
                while (1) {
                    scanf("%lf", &newData.income);
                    if (newData.income > 0) {
                        break;
                    }
                    else {
                        printf("  收入格式错误，请重新输入：");
                    }
                }
                printf("  支出：");
                while (1) {
                    scanf("%lf", &newData.expense);
                    if (newData.expense > 0) {
                        break;
                    }
                    else {
                        printf("  支出格式错误，请重新输入：");
                    }
                }
                printf("  时间：");
                char tmpWhen[30];
                while (1) {
                    scanf("%10s", tmpWhen);
                    if (strcmp(tmpWhen, "2024-01-01") > 0 && is_valid_date(tmpWhen)) {
                        strcpy(newData.when, tmpWhen);
                        break;
                    }
                    else {
                        printf("  日期格式错误，请重新输入：");
                    }
                }
                printf("  用途：");
                scanf("%s", newData.purpose);

                Insert_L(L, newData);

                break;
            }

            case '2': {
                printf("  申请提交成功，请留意管理员的回复！");
                clear_input_buffer();
                getchar();

                break;
            }

            case '3': {
                printf("  申请提交成功，请留意管理员的回复！");
                clear_input_buffer();
                getchar();

                break;
            }

            case '4': {
                Iterate_L(L);
                printf("\n按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '5': {
                printf("  请选择排序的依据：\n");
                printf("  1-->按收入从低到高：\n");
                printf("  2-->按收入从高到低：\n");
                printf("  3-->按支出从低到高：\n");
                printf("  4-->按支出从高到低\n");
                printf("  5-->按时间顺序：\n");
                printf("  6-->按时间逆序：\n");
                printf("  0-->取消\n\n");
                printf("  请输入选项：");
                char op3;
                scanf(" %c", &op3);

                switch (op3)
                {
                case '1': {
                    sortUpIncome(L);
                    break;
                }
                case '2': {
                    sortDownIncome(L);
                    break;
                }
                case '3': {
                    sortUpExpense(L);
                    break;
                }
                case '4': {
                    sortDownExpense(L);
                    break;
                }
                case '5': {
                    sortUpTime(L);
                    break;
                }
                case '6': {
                    sortDownTime(L);
                    break;
                }
                case '0': {
                    break;
                }
                default: {
                    printf("  无效的操作！按下回车键继续...");
                    clear_input_buffer();
                    getchar();
                    break;
                }
                }

                break;
            }

            case '6': {
                financial_statistics(L);
                printf("\n统计完成！按回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '7': {
                SaveToFile(L);
                printf("按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }

            case '0': {
                flag = 0;
                break;
            }

            default: {
                printf("  无效的操作！按下回车键继续...");
                clear_input_buffer();
                getchar();
                break;
            }
            }
        }
    }

    system("cls");
    printf("已退出系统！\n\n");

    SaveToFile(L);

    return 0;
}