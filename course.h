#pragma once
#pragma warning(disable:4996)
#ifndef _COURSE_H_
#define _COURSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <graphics.h>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <sysinfoapi.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include"io.h"
#include<iostream>//������
using namespace std;


typedef struct _Snode//�γ̽ڵ������ĸ���ѧ���ɼ��ڵ�
{
	wchar_t sname[30];//����
	int snum;//ѧ��,8λ������0��ͷ
	double score;
	double GPA;//���ֶ����룬�Ժ�ĳ��Զ�ͨ���ɼ�ת��
	struct _Snode* next;//�¸�ѧ���ڵ�ĵ�ַ
}Snode,*Spnode;

typedef struct Cnode_//�γ̽ڵ�
{
	wchar_t cname[30];//�γ���
	int cnum;//�γ̺ţ���λ����
	wchar_t character[5];//�γ����ʣ�ѡ�ޡ�����
	int SchYear;//ѧ��
	int headcount;//������
	double totscore;//�ܳɼ���û��ʵ�����壬���������������Ч��
	double averscore;//ƽ���ɼ�
	double totGPA;//��GPA����û��ʵ�����壬���������������Ч��
	double averGPA;//ƽ��GPA
	int PassNum;//���������������㼰����
	int ExcelNum;//����������������������
	struct Cnode_ * next;//��һ���γ̽ڵ�
	Spnode sphead;//ĳ���γ���ӵ�е�ѧ�������ͷ�ڵ�
}_Cnode,*Cpnode;


void menu();//����ʱ�ã����ɾ��

void showAllCrs(const Cpnode cphead, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max); // ��ʾ���пγ̣�������ѧ���ɼ���
//Cpnode showCrs(Cpnode phead); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
//Spnode showStuInCrs(Cpnode phead); // ������ʾ�����γ̵�ĳѧ��
void showAllStuInCrs(const Cpnode cplist, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max);


//�����б��γ������ͷ�ڵ��ַ���γ����ƣ��γ̺ţ��γ�����,ѧ��
//����Ѵ������ſΣ����ʧ�ܣ�����0�����򷵻�1
int addCrs(Cpnode cphead, const wchar_t* Cname, int Cnum, const wchar_t* Character,int SchYear); // ��ӿγ̣��������ɼ���

//�����б�Ŀ��γ̵Ľڵ��ַ��ѧ��������ѧ�ţ��ɼ�
//����Ѵ�������ѧ�������ʧ�ܣ�����0�����򷵻�1
int addStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum, double Score); // Ϊĳ�γ����ĳѧ���ɼ�

int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character); // �޸Ŀγ���Ϣ�����޸ĳɼ���
int modifyStuInCrs(Cpnode cplist, Spnode splist, const wchar_t* Sname, int Snum, double Score); // �޸�ĳ���γ̵�ĳѧ���ɼ�

int deleteCrs(Cpnode cphead, wchar_t* cname,int cnum); // ɾ���γ�
int deleteStuInCrs(Cpnode cplist, wchar_t* sname, int snum); // ɾ��ĳ���γ̵�ĳѧ���ɼ�

void sortStuInCrs(Cpnode cplist, int op);//��ĳ���γ̽ڵ��е�ѧ����������
void sortCrs(Cpnode cphead, int op);//�Կγ���������

Cpnode searchCrs(Cpnode cphead, const wchar_t* Cname, int Cnum); // ���ܿγ������������γ�
Spnode searchStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum); // �ڵ����γ����������µ�ѧ��

int look(Cpnode plist);//����ʱ���������ݵ�
#endif
