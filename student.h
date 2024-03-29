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
	wchar_t name[30];//����
	int ID;//ѧ��
	int gender;//�Ա�
	int grade;//�꼶
	wchar_t college[50];//ѧԺ
	wchar_t major[50];//רҵ
};

struct score_info {
	wchar_t course_id[10];//�γ̺�
	wchar_t course_name[100];//�γ���
	double score;//�γ̳ɼ�
	int semester;//ѧ��ѧ��
	//wchar_t course_category[50]; //�γ����
	int course_nature;//�γ�����
	double credit;//ѧ��
	double grid;//����
	//int score_type;//�ɼ�����
	//wchar_t remark[1024];//��ע
	struct score_info* sco_next;
};

struct quality_projects_research {//���гɹ�
	wchar_t paper_name[200];//��������
	wchar_t journal_or_conference_name[200];//��������ڿ����������
	wchar_t author[300];// ����������Ƿ�ΪͨѶ���߼���������
	wchar_t date[11];// ��������
	wchar_t volume_num[10];// ����
	wchar_t issue_num[10];// ����
	wchar_t page[15];// ҳ�뷶Χ
	double GPA_bonus;
};

struct quality_projects_competition {//������
	wchar_t competition_name[200];//��������
	wchar_t organizer[100];//�ٰ쵥λ
	wchar_t category[100];//�����
	wchar_t date[11];//��ʱ�� ����
	double GPA_bonus;
};


typedef struct student_data Data;
typedef struct score_info Score;
typedef struct quality_projects_research Research;
typedef struct quality_projects_competition Competition;


typedef struct course_list{//ѧ���γ�����ڵ�
	Score score;
	struct course_list* crs_next;
}Crsnode;

typedef struct research_list {//���гɹ�����ڵ�
	Research research;
	struct research_list* rnext;
}Rnode;

typedef struct competition_list {//����������ڵ�
	Competition competition;
	struct competition_list* cnext;
}Cnode;

typedef struct item {//һ��ѧ������߱���ȫ����Ϣ��������� ��������Ŀ�ɹ��������С�飩
	Data data;

	Crsnode* crslist;//�γ�����

	Rnode* rlist; 
	Cnode* clist;//����������
}Item;


typedef struct node {  //�ڵ�
	Item item;
	struct node* next;
}Node;
typedef Node* List; //����



void showAllStu(); // ��ʾ����ѧ����Ϣ���������γ̣�


void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���

bool Initialize_Stu_Crslist(List);//��ʼ��ÿ��ѧ���Ŀγ�����

void showCrsInStu(); // ������ʾ����ѧ����ĳ�γ�


bool addStu(); // ���ѧ�����������γ̣�


bool addCrsToStu();// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�


void sortStu();// ������ѧ������


bool modifyStu();// �޸�ѧ����Ϣ�����޸Ŀγ̣�


bool modifyCrsInStu(); // �޸�ĳ��ѧ����ĳ�γ̼��ɼ�


bool deleteStu(List* plist,Node* delstu); // ɾ��ѧ��


bool deleteCrsInStu(); // ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�


Node* searchStu(List* plist, wchar_t* pname, int pID); // ����ѧ������������ѧ��


Crsnode* searchCrsInStu(Crsnode* crs_head); // �ڵ���ѧ����������γ�











#endif
