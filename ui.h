#pragma once

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "student.h"
#include "course.h"



/*
��ʾ�˵����ṩѡ��
������(char*)���⣬(int)ѡ��������(char*)ѡ��һ��(char*)ѡ���...
���أ�ѡ���Ӧ������
*/
int showMenu(char* title, int optNum, ...);


void printStu(const List StuList);


//void printCrs(const Cpnode CrsList); //�����ϾͲ���,���˹���




/*
��ʾҳ��
���ã���ʾҳ��
������ҳ������
���أ�ҳ����
*/
char* show_page(char* page_name);


/*
��ʾ�����Ϣ
���ã���ʾ�����Ϣ
����������ͷ�ڵ�,�������
���أ���
*/
//void show_sheet(List* plist, int sheet_type);







#endif
