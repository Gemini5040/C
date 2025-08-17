#include <someFunction.h>

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <myLinkList.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_valid_date(const char* date_str) {
    // 检查字符串长度是否为10且格式正确
    if (strlen(date_str) != 10) return 0;
    if (date_str[4] != '-' || date_str[7] != '-') return 0;

    // 验证各部分是否全为数字
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date_str[i])) return 0;
    }

    // 提取年月日
    int year, month, day;
    if (sscanf(date_str, "%d-%d-%d", &year, &month, &day) != 3) return 0;

    // 验证年月日范围
    if (year < 1 || month < 1 || month > 12 || day < 1) return 0;

    // 各月份天数验证
    int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // 处理闰年二月
    if (month == 2) {
        int is_leap = 0;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            is_leap = 1;
        }
        days_in_month[1] = is_leap ? 29 : 28;
    }

    return day <= days_in_month[month - 1];
}

int loadDataFromFile(LinkList& L) {
    FILE* f = fopen("record.txt", "r");
    if (f == NULL) {
        printf("无法打开数据文件！\n");
        f = fopen("record.txt", "w");
        if (f == NULL) {
            printf("无法创建文件！\n");
            printf("\n按下回车键继续...");
            getchar();
            return 0;
        }
        else {
            printf("数据文件不存在，已自动创建！\n");
            printf("\n按下回车键继续...");
            getchar();
        }
    }

    financeData t;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, "%d %49s %lf %lf %99s %19s", &t.number, t.name, &t.income, &t.expense, t.purpose, t.when) == 6) {
            Insert_L(L, t);
        }
    }
    fclose(f);

    return 1;
}