#pragma once

#ifndef _QUALITY_H_
#define _QUALITY_H_

#include <stdio.h>
#include<stdbool.h>

typedef struct quality_projects_research {//科研成果
	char name[200];//论文名称，所发表的期刊或会议名称
	char author[300];// 作者情况（是否为通讯作者及作者排序）
	char date[11];// 发表年月
	char page;// 页码范围
	char volume_num;// 卷数
	char issue_num;// 刊号
}Research;

typedef struct quality_projects_competition {//竞赛获奖
	char name[200];//竞赛名称
	char category[100];//获奖类别
	char date[11];//获奖时间 年月
	char organizer[100];//举办单位
}Competition;

typedef struct quality {
	int research_count;// 数量
	Research* research;
	int competition_count;// 数量
	Competition* competition;
}Quality;

void showAllQuality(); // 显示所有有素质类项目的学生


Node searchStuInQuality(List); // 在素质类项目中搜索学生


bool addQuality(); // 添加素质类项目


bool modifyQuality(); // 修改素质类项目


bool deleteQuality(); // 删除素质类项目











#endif
