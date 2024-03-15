#pragma once
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include<stdlib.h>
#include"io.h"


typedef struct _Snode//课程节点下属的各个学生成绩节点
{
	char sname[20];//姓名
	int snum;//学号
	int score;
	int GPA;
	struct _Snode* next;//下个学生节点的地址
}Snode,*Spnode;

typedef struct _Cnode//课程节点
{
	char cname[20];//课程名
	int cnum;//课程号
	char character[20];//课程性质
	int average;//平均成绩
	struct _Course* next;
	Spnode sphead;//某个课程所拥有的学生链表的头节点
}Cnode,*Cpnode;

void menu();//调试时用，最后删除
void showAllCrs(); // 显示所有课程（不包含学生成绩）
void showCrs(); // 显示单个课程信息（包含该课程所有学生的成绩）
void showStuInCrs(); // 具体显示单个课程的某学生


//所有函数的传入值只有一个：课程链表的头节点
int addCrs(Cpnode phead); // 添加课程（不包含成绩）
int addStuToCrs(Cpnode phead); // 为某课程添加某学生成绩
int modifyCrs(Cpnode phead); // 修改课程信息（不修改成绩）
int modifyStuInCrs(Cpnode phead); // 修改某个课程的某学生成绩
int deleteCrs(Cpnode phead); // 删除课程
int deleteStuInCrs(Cpnode phead); // 删除某个课程的某学生成绩
size_t searchCrs(Cpnode phead); // 在总课程链表中搜索课程
size_t searchStuInCrs(Cpnode phead); // 在单个课程中搜索其下的学生




#endif
