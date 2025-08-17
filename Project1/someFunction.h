#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include <myLinkList.h>

void clear_input_buffer();

int is_valid_date(const char* date_str);

int loadDataFromFile(LinkList& L);