#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>

#include"student.h"


void showAllQuality(); // 显示所有有素质类项目的学生


Node* searchStuInQuality(List); // 在素质类项目中搜索学生


void Initialize_Quality_List(List);// 初始化素质类项目的链表（为每个学生的r/clist链表加入哨兵节点）


bool addQuality_rlist(List*);// 添加素质类项目
bool addQuality_clist(List*);


Rnode searchRnode(Rnode*);// 找出此学生待修改的素质类项目节点
Cnode searchCnode(Cnode*);


void modifyQuality_rlist(List* plist);// 修改素质类项目
void modifyQuality_clist(List* plist);





bool deleteQuality(); // 删除素质类项目











#endif
