#pragma once

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/*
显示菜单并提供选择
参数：(char*)标题，(int)选项数量，(char*)选项一，(char*)选项二...
返回：选项对应的数字
*/
int showMenu(char* title, int optNum, ...);


void showPage(); //显示页面


void showSheet(); //显示表格


void showChart();//显示图表


void welcome(); // 欢迎







#endif
