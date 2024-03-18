#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdbool.h>
#include "io.h"


struct student_data
{
	char name[30];//����
	int ID;//ѧ��
	int gender;//�Ա�
	int grade;//�꼶
	char college[50];//ѧԺ
	char major[50];//רҵ
};

struct score_info {
	char course_id[10];//�γ̺�
	char course_name[100];//�γ���
	double score;//�γ̳ɼ�
	int semester;//ѧ��ѧ��
	//char course_category[50]; //�γ����
	int course_nature;//�γ�����
	double credit;//ѧ��
	double grid;//����
	//int score_type;//�ɼ�����
	//char remark[1024];//��ע
	struct score_info* sco_next;
};

struct quality_projects_research {//���гɹ�
	char name[200];//�������ƣ���������ڿ����������
	char author[300];// ����������Ƿ�ΪͨѶ���߼���������
	char date[11];// ��������
	char page;// ҳ�뷶Χ
	char volume_num;// ����
	char issue_num;// ����
};

struct quality_projects_competition {//������
	char name[200];//��������
	char category[100];//�����
	char date[11];//��ʱ�� ����
	char organizer[100];//�ٰ쵥λ
};


typedef struct student_data Data;
typedef struct score_info Score;
typedef struct quality_projects_research Research;
typedef struct quality_projects_competition Competition;


typedef struct course {//ѧ���γ�����ڵ�
	Score score;
	struct course* next;
}Course;

typedef struct research_list {//���гɹ�����ڵ�
	int research_count;// ����
	Research research;
	struct research_list* r_next;
}Rnode;

typedef struct competition_list {//����������ڵ�
	int competition_count;// ����
	Competition competition;
	struct competition_list* c_next;
}Cnode;

typedef struct item {//һ��ѧ������߱���ȫ����Ϣ��������� ��������Ŀ�ɹ��������С�飩
	Data data;

	Course course;//�γ�����

	Rnode* rlist;//���гɹ�����
	Cnode* clist;//����������
}Item;


typedef struct node {  //�ڵ�
	Item item;
	struct node* next;
}Node;
typedef Node* List; //����



void showAllStu(); // ��ʾ����ѧ����Ϣ���������γ̣�


void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���


void showCrsInStu(); // ������ʾ����ѧ����ĳ�γ�


bool addStu(); // ���ѧ�����������γ̣�


bool addCrsToStu();// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�


void sortStu();// ������ѧ������


bool modifyStu();// �޸�ѧ����Ϣ�����޸Ŀγ̣�


bool modifyCrsInStu(); // �޸�ĳ��ѧ����ĳ�γ̼��ɼ�


bool deleteStu(); // ɾ��ѧ��


bool deleteCrsInStu(); // ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�


Node* searchStu(); // ����ѧ������������ѧ��


Node* searchCrsInStu(); // �ڵ���ѧ����������γ�











#endif
