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


Node* searchStuInQuality(List,wchar_t*); // ����������Ŀ������ѧ��


bool addQuality_rlist(Node* Stu,	// �����������Ŀ
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

void show_Research_menu(const wchar_t* title, Rnode* rhead);//�����޸�ʱȷ�����账���������ڵ�
void show_Competition_menu(const wchar_t* title, Cnode* chead);


Rnode* searchRnode(Rnode*);// �ҳ���ѧ�����޸ĵ���������Ŀ�ڵ㣨����show_quality_menuʹ�ã�
Cnode* searchCnode(Cnode*);


void modifyQuality_rlist(Node*);// �޸���������Ŀ
void modifyQuality_clist(Node*);


void deleteQuality_rlist(List*);	// ɾ����������Ŀ
void deleteQuality_clist(List*);












#endif
