#pragma once

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>


/*
��ʾ�˵����ṩѡ��
������(char*)���⣬(int)ѡ��������(char*)ѡ��һ��(char*)ѡ���...
���أ�ѡ���Ӧ������
*/
int showMenu(char* title, int optNum, ...);


void showPage(); //��ʾҳ��


void showSheet(); //��ʾ���


void showChart();//��ʾͼ��


void welcome(); // ��ӭ

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
