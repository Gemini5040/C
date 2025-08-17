#include <myLinkList.h>

int Init_L(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	return OK;
}

void Iterate_L(LinkList& L) {
	system("cls");
	printf("\n 班级财务状况：\n");
	printf("\n  %-6s %-10s %-10s %-10s %-15s %-12s\n",
		"编号", "姓名", "收入", "支出", "用途", "日期");
	printf("╔═════════════════════════════════════════════════════════════════════╗\n");

	LinkList p = L->next;
	while (p != NULL) {
		printf("║ %-6d %-10s %-10.2f %-10.2f %-15s %-12s║\n",
			p->data.number, p->data.name, p->data.income,
			p->data.expense, p->data.purpose, p->data.when);
		p = p->next;
	}
	printf("╚═════════════════════════════════════════════════════════════════════╝\n");
}

int Insert_L(LinkList &L,financeData e) {
	LinkList p = L->next;
	int len = 0;
	while (p != NULL) {
		len++;
		p = p->next;
	}

	LinkList p1 = (LinkList)malloc(sizeof(LNode));
	p1->next = NULL;
	p1->data = e;
	LinkList p2 = L;
	for (int j = 1; j <= len; j++) {
		p2 = p2->next;
	}
	p1->next = p2->next;
	p2->next = p1;

	return OK;
}

int Delete_L(LinkList &L,int i) {
	LinkList p1 = L->next;
	while (p1->next != NULL && p1->next->data.number != i) {
		p1 = p1->next;
	}
	if (p1->next == NULL) return ERROR;
	LinkList p2 = p1->next;
	p1->next = p2->next;
	free(p2);

	return OK;
}

int getLen_L(LinkList& L) {
	int res = 0;
	LinkList p = L;
	while (p->next!= NULL) {
		res++;
		p = p->next;
	}
	return res;
}

int getMaxNumber(LinkList& L) {
	int res = 0;
	for (LinkList p = L->next; p != NULL; p = p->next) {
		if (p->data.number > res) res = p->data.number;
	}
	return res;
}

void sortUpIncome(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (q->data.income < m->data.income) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

void sortDownIncome(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (q->data.income > m->data.income) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

void sortUpExpense(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (q->data.expense < m->data.expense) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

void sortDownExpense(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (q->data.expense > m->data.expense) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

void sortUpTime(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (strcmp(q->data.when, m->data.when) < 0) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

void sortDownTime(LinkList& L) {
	for (LinkList p = L->next; p->next != NULL; p = p->next) {
		LinkList m = p;
		for (LinkList q = p->next; q != NULL; q = q->next) {
			if (strcmp(q->data.when, m->data.when) > 0) m = q;
		}
		if (m != p) {
			financeData tmp = m->data;
			m->data = p->data;
			p->data = tmp;
		}
	}
}

LinkList getByNum(LinkList& L, int i) {
	LinkList p = L->next;
	while (p != NULL && p->data.number != i) {
		p = p->next;
	}
	if (p == NULL) return NULL;

	return p;
}

int compare_purpose(const void* a, const void* b) {
	return ((PurposeStat*)b)->count - ((PurposeStat*)a)->count;
}

/* 分类统计主函数 */
void financial_statistics(LinkList &L) {
	system("cls");
	printf("正在生成统计报表...\n");

	// 初始化统计数据结构
	YearMonthStat* ym_stats = NULL;
	PurposeStat* purpose_stats = NULL;
	int ym_count = 0, purpose_count = 0;

	LinkList p = L->next;
	while (p != NULL) {
		// 解析日期
		int year, month;
		if (sscanf(p->data.when, "%d-%d", &year, &month) != 2) {
			printf("错误日期格式: %s\n", p->data.when);
			p = p->next;
			continue;
		}

		// 更新年月统计
		int found = 0;
		for (int i = 0; i < ym_count; i++) {
			if (ym_stats[i].year == year && ym_stats[i].month == month) {
				ym_stats[i].total_income += p->data.income;
				ym_stats[i].total_expense += p->data.expense;
				found = 1;
				break;
			}
		}
		if (!found) {
			ym_stats = (YearMonthStat*)realloc(ym_stats, (ym_count + 1) * sizeof(YearMonthStat));
			ym_stats[ym_count].year = year;
			ym_stats[ym_count].month = month;
			ym_stats[ym_count].total_income = p->data.income;
			ym_stats[ym_count].total_expense = p->data.expense;
			ym_count++;
		}

		// 更新用途统计
		found = 0;
		for (int i = 0; i < purpose_count; i++) {
			if (strcmp(purpose_stats[i].purpose, p->data.purpose) == 0) {
				purpose_stats[i].count++;
				found = 1;
				break;
			}
		}
		if (!found) {
			purpose_stats = (PurposeStat*)realloc(purpose_stats, (purpose_count + 1) * sizeof(PurposeStat));
			strncpy(purpose_stats[purpose_count].purpose, p->data.purpose, 99);
			purpose_stats[purpose_count].count = 1;
			purpose_count++;
		}

		p = p->next;
	}

	// 打印年月统计表
	printf("\n  %-10s %-10s %-15s %-15s %-15s\n",
		"年份", "月份", "总收入", "总支出", "净收入");
	printf("╔══════════════════════════════════════════════════════════════════════╗\n");
	for (int i = 0; i < ym_count; i++) {
		double net = ym_stats[i].total_income - ym_stats[i].total_expense;
		printf("║ %-10d %-10d %-15.2f %-15.2f %-15.2f║\n",
			ym_stats[i].year,
			ym_stats[i].month,
			ym_stats[i].total_income,
			ym_stats[i].total_expense,
			net);
	}
	printf("╚══════════════════════════════════════════════════════════════════════╝\n");
	double total_income = 0, total_expense = 0;
	for (int i = 0; i < ym_count; i++) {
		total_income += ym_stats[i].total_income;
		total_expense += ym_stats[i].total_expense;
	}
	printf("  总计：收入%.2f 支出%.2f 净收入%.2f\n",
		total_income, total_expense, total_income - total_expense);
	
	// 排序并打印用途统计
	qsort(purpose_stats, purpose_count, sizeof(PurposeStat), compare_purpose);

	printf("\n  %-20s %-10s\n", "用途", "使用次数");
	printf("╔════════════════════════════════╗\n");
	for (int i = 0; i < purpose_count; i++) {
		printf("║ %-20s %-10d║\n", purpose_stats[i].purpose, purpose_stats[i].count);
	}
	printf("╚════════════════════════════════╝\n");

	// 释放内存
	free(ym_stats);
	free(purpose_stats);
}

void SaveToFile(LinkList &L) {
	FILE* f = fopen("record.txt", "w");  // 使用写入模式覆盖原有内容
	if (f == NULL) {
		printf("错误：无法保存数据文件！\n");
		printf("按下回车键继续...");
		getchar();
		return;
	}

	LinkList p = L->next;  // 跳过头节点
	while (p != NULL) {
		// 使用固定格式写入，保留2位小数
		fprintf(f, "%d %s %.2f %.2f %s %s\n",
			p->data.number,
			p->data.name,
			p->data.income,
			p->data.expense,
			p->data.purpose,
			p->data.when);

		p = p->next;  // 移动到下一个节点
	}

	fclose(f);
	printf("数据已成功保存！\n");
}