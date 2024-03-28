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
显示菜单并提供选择
参数：(char*)标题，(int)选项数量，(char*)选项一，(char*)选项二...
返回：选项对应的数字
*/
int showMenu(char* title, int optNum, ...);


void printStu(const List StuList);


//void printCrs(const Cpnode CrsList); //这句加上就不对,奇了怪了




/*
显示页面
作用：显示页面
参数：页面名称
返回：页面名
*/
char* show_page(char* page_name);


/*
显示表格信息
作用：显示表格信息
参数：链表头节点,表格类型
返回：空
*/
//void show_sheet(List* plist, int sheet_type);







#endif
