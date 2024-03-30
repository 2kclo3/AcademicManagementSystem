#pragma once
#pragma warning(disable:4996)
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <tchar.h>
#include"io.h"
#include<iostream>//调试用
using namespace std;


typedef struct _Snode//课程节点下属的各个学生成绩节点
{
	wchar_t sname[30];//姓名
	int snum;//学号
	double score;
	double GPA;//先手动输入，以后改成自动通过成绩转换
	struct _Snode* next;//下个学生节点的地址
}Snode,*Spnode;

typedef struct Cnode_//课程节点
{
	wchar_t cname[30];//课程名
	int cnum;//课程号
	wchar_t character[5];//课程性质：选修、必修
	int headcount;//总人数
	double totscore;//总成绩，没有实际意义，但可以提升代码的效率
	double averscore;//平均成绩
	double totGPA;//总GPA，，没有实际意义，但可以提升代码的效率
	double averGPA;//平均GPA
	struct Cnode_ * next;//下一个课程节点
	Spnode sphead;//某个课程所拥有的学生链表的头节点
}_Cnode,*Cpnode;


void menu();//调试时用，最后删除
//Cpnode showAllCrs(Cpnode phead); // 显示所有课程（不包含学生成绩）
//Cpnode showCrs(Cpnode phead); // 显示单个课程信息（包含该课程所有学生的成绩）
//Spnode showStuInCrs(Cpnode phead); // 具体显示单个课程的某学生


int addCrs(Cpnode cphead, const wchar_t* Cname, int Cnum, const wchar_t* Character); // 添加课程（不包含成绩）
int addStuToCrs(Cpnode cplist, const wchar_t* Sname, int Snum, double Score); // 为某课程添加某学生成绩

int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character); // 修改课程信息（不修改成绩）
int modifyStuInCrs(Cpnode cplist, Spnode splist, const wchar_t* Sname, int Snum, double Score); // 修改某个课程的某学生成绩

int deleteCrs(Cpnode cphead, Cpnode target_cplist); // 删除课程
int deleteStuInCrs(Cpnode cplist, Spnode target_splist); // 删除某个课程的某学生成绩

Cpnode searchCrs(Cpnode cphead, const wchar_t* Cname, int Cnum); // 在总课程链表中搜索课程
Spnode searchStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum); // 在单个课程中搜索其下的学生

int look(Cpnode plist);//调试时用来看数据的
#endif
