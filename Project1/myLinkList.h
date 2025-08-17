#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1

struct financeData {
	int number;
	char name[50];
	double income = 0;
	double expense = 0;
	char purpose[100];
	char when[11];
};

typedef struct {
	int year;
	int month;
	double total_income;
	double total_expense;
} YearMonthStat;

typedef struct {
	char purpose[100];
	int count;
} PurposeStat;

typedef struct LNode {
	financeData data;
	struct LNode* next;
}LNode, * LinkList;

int Init_L(LinkList& L);

void Iterate_L(LinkList& L);

int Insert_L(LinkList& L, financeData e);

int Delete_L(LinkList& L, int i);

int getLen_L(LinkList& L);

int getMaxNumber(LinkList& L);

void sortUpIncome(LinkList& L);

void sortDownIncome(LinkList& L);

void sortUpExpense(LinkList& L);

void sortDownExpense(LinkList& L);

void sortUpTime(LinkList& L);

void sortDownTime(LinkList& L);

LinkList getByNum(LinkList& L, int i);

int compare_purpose(const void* a, const void* b);

void financial_statistics(LinkList& L);

void SaveToFile(LinkList& L);