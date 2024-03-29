#pragma once
#pragma warning(disable:4996)

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>
#include <tchar.h>
#include"student.h"
#include"io.h"
#include"ui.h"


Node* searchStuInQuality(List,wchar_t*); // 在素质类项目中搜索学生


bool addQuality_rlist(Node* Stu,	// 添加素质类项目
	wchar_t* paper_name, 
	wchar_t* journal_or_conference_name, 
	wchar_t* author, 
	wchar_t* date, 
	wchar_t* volume_num, 
	wchar_t* issue_num, 
	wchar_t* page, 
	double GPA_bonus);
bool addQuality_clist(Node* Stu,
	wchar_t* competition_name,
	wchar_t* organizer,
	wchar_t* category,
	wchar_t* date,
	double GPA_bonus);

void show_Research_menu(const wchar_t* title, Rnode* rhead);//方便修改时确认所需处理的素质类节点
void show_Competition_menu(const wchar_t* title, Cnode* chead);


Rnode* searchRnode(Rnode*);// 找出此学生待修改的素质类项目节点（搭配show_quality_menu使用）
Cnode* searchCnode(Cnode*);


void modifyQuality_rlist(Node*);// 修改素质类项目
void modifyQuality_clist(Node*);


void deleteQuality_rlist(List*);	// 删除素质类项目
void deleteQuality_clist(List*);












#endif
