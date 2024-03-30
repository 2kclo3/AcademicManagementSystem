#pragma once
#pragma warning(disable:4996)
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <tchar.h>
#include"io.h"
#include<iostream>//������
using namespace std;


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
	wchar_t character[5];//�γ����ʣ�ѡ�ޡ�����
	int headcount;//������
	double totscore;//�ܳɼ���û��ʵ�����壬���������������Ч��
	double averscore;//ƽ���ɼ�
	double totGPA;//��GPA����û��ʵ�����壬���������������Ч��
	double averGPA;//ƽ��GPA
	struct Cnode_ * next;//��һ���γ̽ڵ�
	Spnode sphead;//ĳ���γ���ӵ�е�ѧ�������ͷ�ڵ�
}_Cnode,*Cpnode;


void menu();//����ʱ�ã����ɾ��
//Cpnode showAllCrs(Cpnode phead); // ��ʾ���пγ̣�������ѧ���ɼ���
//Cpnode showCrs(Cpnode phead); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
//Spnode showStuInCrs(Cpnode phead); // ������ʾ�����γ̵�ĳѧ��


int addCrs(Cpnode cphead, const wchar_t* Cname, int Cnum, const wchar_t* Character); // ��ӿγ̣��������ɼ���
int addStuToCrs(Cpnode cplist, const wchar_t* Sname, int Snum, double Score); // Ϊĳ�γ����ĳѧ���ɼ�

int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character); // �޸Ŀγ���Ϣ�����޸ĳɼ���
int modifyStuInCrs(Cpnode cplist, Spnode splist, const wchar_t* Sname, int Snum, double Score); // �޸�ĳ���γ̵�ĳѧ���ɼ�

int deleteCrs(Cpnode cphead, Cpnode target_cplist); // ɾ���γ�
int deleteStuInCrs(Cpnode cplist, Spnode target_splist); // ɾ��ĳ���γ̵�ĳѧ���ɼ�

Cpnode searchCrs(Cpnode cphead, const wchar_t* Cname, int Cnum); // ���ܿγ������������γ�
Spnode searchStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum); // �ڵ����γ����������µ�ѧ��

int look(Cpnode plist);//����ʱ���������ݵ�
#endif
