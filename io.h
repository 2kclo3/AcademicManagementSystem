#pragma once

#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <tchar.h>



int getNumber(int max); //��������

double getDouble(double max);

void getText(wchar_t* str); //��������

/*
��ʾ�˵����ṩѡ��
������(wchar_t*)���⣬(int)ѡ��������(wchar_t*)ѡ��һ��(wchar_t*)ѡ���...
���أ�ѡ���Ӧ������
*/
int showMenu(const wchar_t* title, int optNum, ...);








#endif
