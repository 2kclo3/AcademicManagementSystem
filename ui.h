#pragma once

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


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







#endif
