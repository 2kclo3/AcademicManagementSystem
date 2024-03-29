#pragma once
#pragma warning(disable:4996)
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <tchar.h>
#include"io.h"


//�ȵ��Ժ��ټӸ�������Ŀ
typedef struct _Snode//�γ̽ڵ������ĸ���ѧ���ɼ��ڵ�
{
	wchar_t sname[30];//����
	int snum;//ѧ��
	double score;
	double GPA;//���ֶ����룬�Ժ�ĳ��Զ�ͨ���ɼ�ת��
	struct _Snode* next;//�¸�ѧ���ڵ�ĵ�ַ
}Snode,*Spnode;

typedef struct Cnode_//�γ̽ڵ�
{
	wchar_t cname[30];//�γ���
	int cnum;//�γ̺�
	int character;//�γ�����(����/ѡ��)��������һ���ż��������ɴ�����ˣ�����ѡ�ɣ���ֹ�������
	int headcount;//������
	double totscore;//�ܳɼ���û��ʵ�����壬���������������Ч��
	double averscore;//ƽ���ɼ�
	double totGPA;//��GPA����û��ʵ�����壬���������������Ч��
	double averGPA;//ƽ��GPA
	struct Cnode_ * next;//��һ���γ̽ڵ�
	Spnode sphead;//ĳ���γ���ӵ�е�ѧ�������ͷ�ڵ�
}_Cnode,*Cpnode;



void menu();//����ʱ�ã����ɾ��
Cpnode showAllCrs(Cpnode phead); // ��ʾ���пγ̣�������ѧ���ɼ���
Cpnode showCrs(Cpnode phead); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
Spnode showStuInCrs(Cpnode phead); // ������ʾ�����γ̵�ĳѧ��


//���к����Ĵ���ֵֻ��һ�����γ������ͷ�ڵ�
int addCrs(Cpnode phead); // ��ӿγ̣��������ɼ���
int addStuToCrs(Cpnode phead); // Ϊĳ�γ����ĳѧ���ɼ�
int modifyCrs(Cpnode phead); // �޸Ŀγ���Ϣ�����޸ĳɼ���
int modifyStuInCrs(Cpnode phead); // �޸�ĳ���γ̵�ĳѧ���ɼ�
int deleteCrs(Cpnode phead); // ɾ���γ�
int deleteStuInCrs(Cpnode phead); // ɾ��ĳ���γ̵�ĳѧ���ɼ�
Cpnode searchCrs(Cpnode phead); // ���ܿγ������������γ�
Spnode searchStuInCrs(Spnode phead); // �ڵ����γ����������µ�ѧ��

int look(Cpnode phead);//����ʱ���������ݵ�




#endif
