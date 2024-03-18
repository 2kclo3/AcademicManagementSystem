#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>

typedef struct quality_projects_research {//���гɹ�
	char name[200];//�������ƣ���������ڿ����������
	char author[300];// ����������Ƿ�ΪͨѶ���߼���������
	char date[11];// ��������
	char page;// ҳ�뷶Χ
	char volume_num;// ����
	char issue_num;// ����
}Research;

typedef struct quality_projects_competition {//������
	char name[200];//��������
	char category[100];//�����
	char date[11];//��ʱ�� ����
	char organizer[100];//�ٰ쵥λ
}Competition;

typedef struct quality {
	int research_count;// ����
	Research* research;
	int competition_count;// ����
	Competition* competition;
}Quality;

void showAllQuality(); // ��ʾ��������������Ŀ��ѧ��


Node searchStuInQuality(List); // ����������Ŀ������ѧ��


bool addQuality(); // �����������Ŀ


bool modifyQuality(); // �޸���������Ŀ


bool deleteQuality(); // ɾ����������Ŀ











#endif
