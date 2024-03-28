#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ui.h"
#define PAGE_FILE "Page.txt"


int showMenu(char* title, int optNum, ...){
	printf("%s\n\n", title);

	va_list args;
	va_start(args, optNum);

	for (int i = 1; i <= optNum; i++) {
		printf("%2d:%s\n", i, va_arg(args, char*));
	}
	va_end(args);
}



char* show_page(char* page_name)
{
	system("cls");//清空控制台内容
	FILE* fp = NULL;
	fp = fopen(PAGE_FILE, "r");//以只读方式打开文件
	if (fp == NULL) {
		printf("Read %s errer, please check and reboot the system!", PAGE_FILE);
		exit(EXIT_FAILURE);
	}
	//当读取失败时，要求检查和重启本系统

	char start_tag[30], end_tag[30];
	sprintf(start_tag, "%s<<<", page_name);
	sprintf(end_tag, ">>>%s", page_name);//创建寻找的开始和结束标签

	bool start_found = 0;
	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {//一行一行寻找标签并打印
		if (strstr(line, start_tag) != NULL) {
			start_found = 1;
			continue;
		}//找到开始标签，跳过，从下一行开始打印
		if (strstr(line, end_tag) != NULL) {
			break;
		}//找到结束标签，结束循环
		if (start_found == 1) {
			printf("%s", line);
		}//打印当前行
	}

	fclose(fp);//关闭文件
	return page_name;

}


void printStu(const List StuList){

	List pStu = StuList->next; // 从头结点的下一个节点开始
	while (pStu != NULL) {
		printf("学生信息:%d\t%s\t%d\t%d\t%s\t%s\n\n课程：\n",
			pStu->item.data.ID,
			pStu->item.data.name,
			pStu->item.data.gender,
			pStu->item.data.grade,
			pStu->item.data.college,
			pStu->item.data.major); 

		Crsnode* pcrs = pStu->item.crslist->crs_next; // 从下一个课程节点开始
		while (pcrs != NULL) {
			printf("%s\t%s\t%.1lf\t%d\t%d\t%.1lf\t%.1lf\n",
				pcrs->score.course_id,
				pcrs->score.course_name,
				pcrs->score.score,
				pcrs->score.semester,
				pcrs->score.course_nature,
				pcrs->score.credit,
				pcrs->score.grid);

			pcrs = pcrs->crs_next; // 移动到下一个节点
		}

		printf("\n科研成果：\n");
		Rnode* pres = pStu->item.rlist->rnext; // 从下一个科研成果节点开始
		while (pres != NULL) {
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.2lf\n",
				pres->research.paper_name,
				pres->research.journal_or_conference_name,
				pres->research.author,
				pres->research.date,
				pres->research.volume_num,
				pres->research.issue_num,
				pres->research.page,
				pres->research.GPA_bonus);

			pres = pres->rnext; // 移动到下一个节点
		}


		printf("\n竞赛获奖：\n");
		Cnode* pcpt = pStu->item.clist->cnext; // 从下一个竞赛获奖节点开始
		while (pcpt != NULL) {
			printf("%s\t%s\t%s\t%s\t%.2lf\n",
				pcpt->competition.competition_name,
				pcpt->competition.organizer,
				pcpt->competition.category,
				pcpt->competition.date,
				pcpt->competition.GPA_bonus);

			pcpt = pcpt->cnext; // 移动到下一个节点
		}


		printf("\n\n");
		pStu = pStu->next; // 移动到下一个节点
	}


}




void printCrs(const Cpnode CrsList){
	Cpnode pCrs = CrsList->next; // 从头结点的下一个节点开始
	while (pCrs != NULL) {
		printf("课程信息:%d\t%s\t%d\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\n学生：\n",
			pCrs->cnum,
			pCrs->cname,
			pCrs->character,
			pCrs->headcount,
			pCrs->totscore,
			pCrs->averscore,
			pCrs->totGPA,
			pCrs->averGPA); // 写入

		Spnode pstu = pCrs->sphead->next; // 从下一个学生节点开始
		while (pstu != NULL) {
			printf("%d\t%s\t%.1lf\t%.1lf\n",
				pstu->snum,
				pstu->sname,
				pstu->score,
				pstu->GPA); // 写入

			pstu = pstu->next; // 移动到下一个节点
		}
		printf("\n\n");
		pCrs = pCrs->next; // 移动到下一个节点
	}
}





/*
显示表格信息
作用：显示表格信息
参数：链表头节点,表格类型
返回：空
*/
//void show_sheet(const List* const plist, int sheet_type) {
//	//system("cls");//清空控制台内容
//	Node* current = (*plist)->next;
//	system("cls");//清空控制台内容
//
//	if (sheet_type == 1) {// 学生信息
//		if (IsListEmpty(plist)) {
//			printf("学生信息为空，请输入\"2\"添加数据\n\n");
//		}
//		else {
//			int cnt = 1;
//			printf("    | %-15s | %-8s |%-3s|\n", "姓名", "学号", "性别");
//			printf("----------------------------------------------------------------------------------------\n");
//			while (current != NULL) {// 遍历链表并打印数据
//				printf("%4d| %-15s | %08d |%-3s |\n",
//					cnt++, current->item.data.name, current->item.data.ID, current->item.data.gender ? "女" : "男");
//
//				current = current->next;
//			}
//			printf("----------------------------------------------------------------------------------------\n\n");
//		}
//		printf("0:返回上一级  1:查询学生  2:添加学生  3:修改学生信息  4:删除学生\n\n");
//	}
//	else if (sheet_type == 2) {
//	}
//}

