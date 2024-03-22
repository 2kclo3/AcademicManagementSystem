#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"
#include "course.h"



/*
读取文件
作用：读取数据链表文件，返回一个链表首地址
参数：文件路径
返回：读取文件后保存到内存里的链表的首地址
*/
Cpnode readCrs(char* file_name) {
	FILE* fp;
	Cpnode CrsList = (Cpnode)malloc(sizeof(Cnode));
	CrsList->next = NULL;
	CrsList->sphead = (Spnode)malloc(sizeof(Snode));
	CrsList->sphead->next = NULL;
	
	fp = fopen(file_name, "r");//读取文件
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//读取失败退出

	Item* item = (Item*)malloc(sizeof(Item)); //为item申请内存
	item->score = (Score*)malloc(sizeof(Score));
	item->score->sco_next = NULL;
	Score* score = (Score*)malloc(sizeof(Score)); //为score申请内存
	if (item == NULL || score == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// 分配失败

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // 跳过空行
			continue;
		}

		if (sscanf(line, "%d %s %d %d %s %s",
			&item->data.ID,
			&item->data.name,
			&item->data.gender,
			&item->data.grade,
			&item->data.college,
			&item->data.major) == 6) { // 读取学生信息
			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&score->course_id,
					&score->course_name,
					&score->score,
					&score->semester,
					&score->course_nature,
					&score->credit,
					&score->grid) == 7) {
					score->sco_next = NULL;
					AddScore(score, item); // 添加到链表
				}
			}
			AddItem(item, &list); // 添加到链表
			item->score->sco_next = NULL;
		}
	}
	fclose(fp);
	return &list;



}


/*
保存文件
作用：将链表保存到文件中
参数：链表首地址,文件路径
返回：是否成功
*/
bool save(List* plist, char* file_name) {
	FILE* fp;
	Node* ptmp = (*plist)->next;
	fp = fopen(file_name, "wb");//打开文件
	if (fp == NULL) {
		printf("Write \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//打开失败

	while (ptmp != NULL && fwrite(&(ptmp->item), sizeof(Item), 1, fp) == 1) {
		ptmp = ptmp->next;
	}// 写入文件
	fclose(fp);
	return true;
}

