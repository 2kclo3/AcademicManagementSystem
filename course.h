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
#include <iomanip>
#include<sstream>
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
	double credit;//ѧ��
	int SchYear;//ѧ��
	int headcount;//������
	double totscore;//�ܳɼ�
	double averscore;//ƽ���ɼ�
	double totGPA;//��GPA
	double averGPA;//ƽ��GPA
	int PassNum;//��������
	double PassRate;//������
	int ExcelNum;//��������
	double ExcelRate;//������
	struct Cnode_ * next;//��һ���γ̽ڵ�
	Spnode sphead;//ĳ���γ���ӵ�е�ѧ�������ͷ�ڵ�
}_Cnode,*Cpnode;


void menu();//����ʱ�ã����ɾ��

void showAllCrs(const Cpnode cphead, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max); // ��ʾ���пγ̣�������ѧ���ɼ���
//Cpnode showCrs(Cpnode phead); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
//Spnode showStuInCrs(Cpnode phead); // ������ʾ�����γ̵�ĳѧ��
void showAllStuInCrs(const Cpnode cplist, vector<vector<wstring>>& data, const wchar_t* searchTerm, int op, int min, int max);


int addCrs(Cpnode cphead, const wchar_t* cname, int cnum, const wchar_t* character, double credit, int SchYear); // ��ӿγ�

int addStuInCrs(Cpnode cplist, const wchar_t* sname, int snum, double score); // Ϊĳ�γ����ĳѧ���ɼ�

int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character, double credit, int SchYear); // �޸Ŀγ���Ϣ

int modifyStuInCrs(Cpnode cplist, Spnode splist, const wchar_t* sname, int snum, double score); // �޸�ĳ���γ̵�ĳѧ���ɼ�

int deleteCrs(Cpnode cphead, wchar_t* cname,int cnum); // ɾ���γ�

int deleteStuInCrs(Cpnode cplist, wchar_t* sname, int snum); // ɾ��ĳ���γ̵�ĳѧ���ɼ�

void sortStuInCrs(Cpnode cplist, int op);//��ĳ���γ̽ڵ��е�ѧ����������
void sortCrs(Cpnode cphead, int op);//�Կγ���������

Cpnode searchCrs(Cpnode cphead,int Cnum); // ���ܿγ������������γ�

Spnode searchStuInCrs(Cpnode cplist,int Snum); // �ڵ����γ����������µ�ѧ��

int look(Cpnode plist);//����ʱ���������ݵ�
#endif
