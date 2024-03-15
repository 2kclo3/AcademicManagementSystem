#pragma once
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include<stdlib.h>
#include"io.h"


typedef struct _Snode//�γ̽ڵ������ĸ���ѧ���ɼ��ڵ�
{
	char sname[20];//����
	int snum;//ѧ��
	int score;
	int GPA;
	struct _Snode* next;//�¸�ѧ���ڵ�ĵ�ַ
}Snode,*Spnode;

typedef struct _Cnode//�γ̽ڵ�
{
	char cname[20];//�γ���
	int cnum;//�γ̺�
	char character[20];//�γ�����
	int average;//ƽ���ɼ�
	struct _Course* next;
	Spnode sphead;//ĳ���γ���ӵ�е�ѧ�������ͷ�ڵ�
}Cnode,*Cpnode;

void menu();//����ʱ�ã����ɾ��
void showAllCrs(); // ��ʾ���пγ̣�������ѧ���ɼ���
void showCrs(); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
void showStuInCrs(); // ������ʾ�����γ̵�ĳѧ��


//���к����Ĵ���ֵֻ��һ�����γ������ͷ�ڵ�
int addCrs(Cpnode phead); // ��ӿγ̣��������ɼ���
int addStuToCrs(Cpnode phead); // Ϊĳ�γ����ĳѧ���ɼ�
int modifyCrs(Cpnode phead); // �޸Ŀγ���Ϣ�����޸ĳɼ���
int modifyStuInCrs(Cpnode phead); // �޸�ĳ���γ̵�ĳѧ���ɼ�
int deleteCrs(Cpnode phead); // ɾ���γ�
int deleteStuInCrs(Cpnode phead); // ɾ��ĳ���γ̵�ĳѧ���ɼ�
size_t searchCrs(Cpnode phead); // ���ܿγ������������γ�
size_t searchStuInCrs(Cpnode phead); // �ڵ����γ����������µ�ѧ��




#endif
