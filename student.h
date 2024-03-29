#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <tchar.h>
#include "io.h"



struct student_data
{
	wchar_t name[30];//姓名
	int ID;//学号
	int gender;//性别
	int grade;//年级
	wchar_t college[50];//学院
	wchar_t major[50];//专业
};

struct score_info {
	wchar_t course_id[10];//课程号
	wchar_t course_name[100];//课程名
	double score;//课程成绩
	int semester;//学年学期
	//wchar_t course_category[50]; //课程类别
	int course_nature;//课程性质
	double credit;//学分
	double grid;//绩点
	//int score_type;//成绩类型
	//wchar_t remark[1024];//备注
	struct score_info* sco_next;
};

struct quality_projects_research {//科研成果
	wchar_t paper_name[200];//论文名称
	wchar_t journal_or_conference_name[200];//所发表的期刊或会议名称
	wchar_t author[300];// 作者情况（是否为通讯作者及作者排序）
	wchar_t date[11];// 发表年月
	wchar_t volume_num[10];// 卷数
	wchar_t issue_num[10];// 刊号
	wchar_t page[15];// 页码范围
	double GPA_bonus;
};

struct quality_projects_competition {//竞赛获奖
	wchar_t competition_name[200];//竞赛名称
	wchar_t organizer[100];//举办单位
	wchar_t category[100];//获奖类别
	wchar_t date[11];//获奖时间 年月
	double GPA_bonus;
};


typedef struct student_data Data;
typedef struct score_info Score;
typedef struct quality_projects_research Research;
typedef struct quality_projects_competition Competition;


typedef struct course_list{//学生课程链表节点
	Score score;
	struct course_list* crs_next;
}Crsnode;

typedef struct research_list {//科研成果链表节点
	Research research;
	struct research_list* rnext;
}Rnode;

typedef struct competition_list {//竞赛获奖链表节点
	Competition competition;
	struct competition_list* cnext;
}Cnode;

typedef struct item {//一个学生所需具备的全部信息（共三大块 素质类项目成果拆成了两小块）
	Data data;

	Crsnode* crslist;//课程链表

	Rnode* rlist; 
	Cnode* clist;//竞赛获奖链表
}Item;


typedef struct node {  //节点
	Item item;
	struct node* next;
}Node;
typedef Node* List; //链表



void showAllStu(); // 显示所有学生信息（不包含课程）


void showStu(); // 显示单个学生信息（包含其课程成绩）

bool Initialize_Stu_Crslist(List);//初始化每个学生的课程链表

void showCrsInStu(); // 具体显示单个学生的某课程


bool addStu(); // 添加学生（不包含课程）


bool addCrsToStu();// 为某个学生添加某课程及成绩


void sortStu();// 排序总学生链表


bool modifyStu();// 修改学生信息（不修改课程）


bool modifyCrsInStu(); // 修改某个学生的某课程及成绩


bool deleteStu(List* plist,Node* delstu); // 删除学生


bool deleteCrsInStu(); // 删除某个学生的某课程及成绩


Node* searchStu(List* plist, wchar_t* pname, int pID); // 在总学生链表中搜索学生


Crsnode* searchCrsInStu(Crsnode* crs_head); // 在单个学生中搜索其课程











#endif
