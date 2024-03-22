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



/*
显示页面
作用：显示页面
参数：页面名称
返回：页面名
*/
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

