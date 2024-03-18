#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdbool.h>
#include "io.h"


struct student_data
{
	char name[30];//姓名
	int ID;//学号
	int gender;//性别
	int grade;//年级
	char college[50];//学院
	char major[50];//专业
};

struct score_info {
	char course_id[10];//课程号
	char course_name[100];//课程名
	double score;//课程成绩
	int semester;//学年学期
	//char course_category[50]; //课程类别
	int course_nature;//课程性质
	double credit;//学分
	double grid;//绩点
	//int score_type;//成绩类型
	//char remark[1024];//备注
	struct score_info* sco_next;
};

struct quality_projects_research {//科研成果
	char name[200];//论文名称，所发表的期刊或会议名称
	char author[300];// 作者情况（是否为通讯作者及作者排序）
	char date[11];// 发表年月
	char page;// 页码范围
	char volume_num;// 卷数
	char issue_num;// 刊号
};

struct quality_projects_competition {//竞赛获奖
	char name[200];//竞赛名称
	char category[100];//获奖类别
	char date[11];//获奖时间 年月
	char organizer[100];//举办单位
};


typedef struct student_data Data;
typedef struct score_info Score;
typedef struct quality_projects_research Research;
typedef struct quality_projects_competition Competition;


typedef struct course {//学生课程链表节点
	Score score;
	struct course* next;
}Course;

typedef struct research_list {//科研成果链表节点
	int research_count;// 数量
	Research research;
	struct research_list* r_next;
}Rnode;

typedef struct competition_list {//竞赛获奖链表节点
	int competition_count;// 数量
	Competition competition;
	struct competition_list* c_next;
}Cnode;

typedef struct item {//一个学生所需具备的全部信息（共三大块 素质类项目成果拆成了两小块）
	Data data;

	Course course;//课程链表

	Rnode* rlist;//科研成果链表
	Cnode* clist;//竞赛获奖链表
}Item;


typedef struct node {  //节点
	Item item;
	struct node* next;
}Node;
typedef Node* List; //链表



void showAllStu(); // 显示所有学生信息（不包含课程）


void showStu(); // 显示单个学生信息（包含其课程成绩）


void showCrsInStu(); // 具体显示单个学生的某课程


bool addStu(); // 添加学生（不包含课程）


bool addCrsToStu();// 为某个学生添加某课程及成绩


void sortStu();// 排序总学生链表


bool modifyStu();// 修改学生信息（不修改课程）


bool modifyCrsInStu(); // 修改某个学生的某课程及成绩


bool deleteStu(); // 删除学生


bool deleteCrsInStu(); // 删除某个学生的某课程及成绩


Node* searchStu(); // 在总学生链表中搜索学生


Node* searchCrsInStu(); // 在单个学生中搜索其课程











#endif
