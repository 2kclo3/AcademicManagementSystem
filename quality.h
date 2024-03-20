#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>

#include"student.h"


Node* searchStuInQuality(List); // ����������Ŀ������ѧ��


void Initialize_Quality_List(List);// ��ʼ����������Ŀ������Ϊÿ��ѧ����r/clist��������ڱ��ڵ㣩


bool addQuality_rlist(List*);// �����������Ŀ
bool addQuality_clist(List*);

void show_Research_menu(char* title, Rnode* rhead);//�����޸�ʱȷ�����账���������ڵ�
void show_Competition_menu(char* title, Cnode* chead);


Rnode searchRnode(Rnode*);// �ҳ���ѧ�����޸ĵ���������Ŀ�ڵ㣨����show_quality_menuʹ�ã�
Cnode searchCnode(Cnode*);


void modifyQuality_rlist(List* plist);// �޸���������Ŀ
void modifyQuality_clist(List* plist);





bool deleteQuality(); // ɾ����������Ŀ











#endif
