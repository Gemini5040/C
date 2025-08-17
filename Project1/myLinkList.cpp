#include <myLinkList.h>

int Init_L(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	return OK;
}

void Iterate_L(LinkList& L) {
	system("cls");
	printf("\n �༶����״����\n");
	printf("\n  %-6s %-10s %-10s %-10s %-15s %-12s\n",
		"���", "����", "����", "֧��", "��;", "����");
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");

	LinkList p = L->next;
	while (p != NULL) {
		printf("�U %-6d %-10s %-10.2f %-10.2f %-15s %-12s�U\n",
			p->data.number, p->data.name, p->data.income,
			p->data.expense, p->data.purpose, p->data.when);
		p = p->next;
	}
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
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

/* ����ͳ�������� */
void financial_statistics(LinkList &L) {
	system("cls");
	printf("��������ͳ�Ʊ���...\n");

	// ��ʼ��ͳ�����ݽṹ
	YearMonthStat* ym_stats = NULL;
	PurposeStat* purpose_stats = NULL;
	int ym_count = 0, purpose_count = 0;

	LinkList p = L->next;
	while (p != NULL) {
		// ��������
		int year, month;
		if (sscanf(p->data.when, "%d-%d", &year, &month) != 2) {
			printf("�������ڸ�ʽ: %s\n", p->data.when);
			p = p->next;
			continue;
		}

		// ��������ͳ��
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

		// ������;ͳ��
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

	// ��ӡ����ͳ�Ʊ�
	printf("\n  %-10s %-10s %-15s %-15s %-15s\n",
		"���", "�·�", "������", "��֧��", "������");
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	for (int i = 0; i < ym_count; i++) {
		double net = ym_stats[i].total_income - ym_stats[i].total_expense;
		printf("�U %-10d %-10d %-15.2f %-15.2f %-15.2f�U\n",
			ym_stats[i].year,
			ym_stats[i].month,
			ym_stats[i].total_income,
			ym_stats[i].total_expense,
			net);
	}
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	double total_income = 0, total_expense = 0;
	for (int i = 0; i < ym_count; i++) {
		total_income += ym_stats[i].total_income;
		total_expense += ym_stats[i].total_expense;
	}
	printf("  �ܼƣ�����%.2f ֧��%.2f ������%.2f\n",
		total_income, total_expense, total_income - total_expense);
	
	// ���򲢴�ӡ��;ͳ��
	qsort(purpose_stats, purpose_count, sizeof(PurposeStat), compare_purpose);

	printf("\n  %-20s %-10s\n", "��;", "ʹ�ô���");
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	for (int i = 0; i < purpose_count; i++) {
		printf("�U %-20s %-10d�U\n", purpose_stats[i].purpose, purpose_stats[i].count);
	}
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

	// �ͷ��ڴ�
	free(ym_stats);
	free(purpose_stats);
}

void SaveToFile(LinkList &L) {
	FILE* f = fopen("record.txt", "w");  // ʹ��д��ģʽ����ԭ������
	if (f == NULL) {
		printf("�����޷����������ļ���\n");
		printf("���»س�������...");
		getchar();
		return;
	}

	LinkList p = L->next;  // ����ͷ�ڵ�
	while (p != NULL) {
		// ʹ�ù̶���ʽд�룬����2λС��
		fprintf(f, "%d %s %.2f %.2f %s %s\n",
			p->data.number,
			p->data.name,
			p->data.income,
			p->data.expense,
			p->data.purpose,
			p->data.when);

		p = p->next;  // �ƶ�����һ���ڵ�
	}

	fclose(f);
	printf("�����ѳɹ����棡\n");
}