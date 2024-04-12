#pragma once
#pragma warning(disable:4996)
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <graphics.h>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <sysinfoapi.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include <iomanip>
#include<sstream>
#include"io.h"
#include<iostream>//调试用
using namespace std;


typedef struct _Snode//课程节点下属的各个学生成绩节点
{
	wchar_t sname[30];//姓名
	int snum;//学号,8位，不以0开头
	double score;
	double GPA;//先手动输入，以后改成自动通过成绩转换
	struct _Snode* next;//下个学生节点的地址
}Snode,*Spnode;

typedef struct Cnode_//课程节点
{
	wchar_t cname[30];//课程名
	int cnum;//课程号，五位数字
	wchar_t character[5];//课程性质：选修、必修
	double credit;//学分
	int SchYear;//学年
	int headcount;//总人数
	double totscore;//总成绩
	double averscore;//平均成绩
	double totGPA;//总GPA
	double averGPA;//平均GPA
	int PassNum;//及格人数
	double PassRate;//及格率
	int ExcelNum;//优秀人数
	double ExcelRate;//优秀率
	struct Cnode_ * next;//下一个课程节点
	Spnode sphead;//某个课程所拥有的学生链表的头节点
}_Cnode,*Cpnode;


void menu();//调试时用，最后删除

void showAllCrs(const Cpnode cphead, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max); // 显示所有课程（不包含学生成绩）
//Cpnode showCrs(Cpnode phead); // 显示单个课程信息（包含该课程所有学生的成绩）
//Spnode showStuInCrs(Cpnode phead); // 具体显示单个课程的某学生
void showAllStuInCrs(const Cpnode cplist, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max);


//参数列表：课程链表的头节点地址，课程名称，课程号，课程性质,学年
//如果已存在这门课，添加失败，返回0；否则返回1
int addCrs(Cpnode cphead, const wchar_t* cname, int cnum, const wchar_t* character, int SchYear); // 添加课程

//参数列表：目标课程的节点地址，学生姓名，学号，成绩
//如果已存在这名学生，添加失败，返回0；否则返回1
int addStuInCrs(Cpnode cplist, const wchar_t* sname, int snum, double score); // 为某课程添加某学生成绩

//参数列表：目标课程的节点地址，课程名称，课程号，课程性质,学年
//返回值不用管
//使用前先用searchCrs函数找到目标课程的节点地址
int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character, int SchYear); // 修改课程信息

//参数列表：目标课程的节点地址，目标学生的节点地址,学生姓名，学号，成绩
//返回值不用管
//使用前先用searchStuInCrs在目标课程的节点中找到目标学生的节点地址
int modifyStuInCrs(Cpnode cplist, Spnode splist, const wchar_t* sname, int snum, double score); // 修改某个课程的某学生成绩

//参数列表：课程链表的头节点地址，课程名称，课程号
//正常返回1,没找到返回0
int deleteCrs(Cpnode cphead, wchar_t* cname,int cnum); // 删除课程

//参数列表：目标课程的节点地址，学生姓名，学号
//正常返回1,没找到返回0
int deleteStuInCrs(Cpnode cplist, wchar_t* sname, int snum); // 删除某个课程的某学生成绩

void sortStuInCrs(Cpnode cplist, int op);//对某个课程节点中的学生链表排序
void sortCrs(Cpnode cphead, int op);//对课程链表排序

//参数列表：课程链表的头节点地址，课程名称，课程号
//找到了返回目标课程的节点地址，没找到返回NULL
Cpnode searchCrs(Cpnode cphead, const wchar_t* Cname, int Cnum); // 在总课程链表中搜索课程

//参数列表：目标课程的节点地址，学生姓名，学号
//找到了返回目标学生的节点地址，没找到返回NULL
Spnode searchStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum); // 在单个课程中搜索其下的学生

int look(Cpnode plist);//调试时用来看数据的
#endif
