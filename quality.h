#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>


void showAllQuality(); // ��ʾ��������������Ŀ��ѧ��


Node searchStuInQuality(List); // ����������Ŀ������ѧ��


bool addQuality_rlist(List*);// �����������Ŀ
bool addQuality_clist(List*);


void modifyQuality(List*);// �޸���������Ŀ


Rnode searchRnode(Rnode*);//�ҳ����޸ĵ���������Ŀ�ڵ�
Cnode searchCnode(Cnode*);


bool deleteQuality(); // ɾ����������Ŀ











#endif
