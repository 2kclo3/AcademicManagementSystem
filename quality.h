#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>

#include"student.h"


void showAllQuality(); // ��ʾ��������������Ŀ��ѧ��


Node* searchStuInQuality(List); // ����������Ŀ������ѧ��


void Initialize_Quality_List(List);// ��ʼ����������Ŀ������Ϊÿ��ѧ����r/clist��������ڱ��ڵ㣩


bool addQuality_rlist(List*);// �����������Ŀ
bool addQuality_clist(List*);


Rnode searchRnode(Rnode*);// �ҳ���ѧ�����޸ĵ���������Ŀ�ڵ�
Cnode searchCnode(Cnode*);


void modifyQuality_rlist(List* plist);// �޸���������Ŀ
void modifyQuality_clist(List* plist);





bool deleteQuality(); // ɾ����������Ŀ











#endif
