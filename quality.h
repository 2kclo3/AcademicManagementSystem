#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>


void showAllQuality(); // 显示所有有素质类项目的学生


Node searchStuInQuality(List); // 在素质类项目中搜索学生


bool addQuality_rlist(List*);// 添加素质类项目
bool addQuality_clist(List*);


void modifyQuality(List*);// 修改素质类项目


Rnode searchRnode(Rnode*);//找出待修改的素质类项目节点
Cnode searchCnode(Cnode*);


bool deleteQuality(); // 删除素质类项目











#endif
