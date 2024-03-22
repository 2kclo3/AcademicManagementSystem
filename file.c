#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

	Cpnode tcnode = (Cpnode)malloc(sizeof(Cnode)); //为cnode申请内存
	tcnode->next = NULL;
	tcnode->sphead = (Spnode)malloc(sizeof(Snode));
	tcnode->sphead->next = NULL;
	Spnode tsnode = (Spnode)malloc(sizeof(Snode)); //为tsnode申请内存
	tsnode->next = NULL;
	if (tcnode == NULL || tsnode == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// 分配失败

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // 跳过空行
			continue;
		}

		if (sscanf(line, "%d %s %d %d %lf %lf %lf %lf",
			&tcnode->cnum,
			&tcnode->cname,
			&tcnode->character,
			&tcnode->headcount,
			&tcnode->totscore,
			&tcnode->averscore,
			&tcnode->totGPA,
			&tcnode->averGPA
		) == 8) { // 读取学生信息
			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&tsnode->snum,
					&tsnode->sname,
					&tsnode->score,
					&tsnode->GPA
				) == 4) {
					tsnode->next = NULL;

					// 添加到链表
					Spnode snode = (Spnode)malloc(sizeof(Snode)); //为snode申请内存
					if (snode == NULL) {
						printf("error!");
						exit(EXIT_FAILURE);
					}// 分配失败
					memcpy(snode, tsnode, sizeof(Snode));
					Spnode ptmp = tcnode->sphead;
					while (ptmp->next != NULL) {
						ptmp = ptmp->next;
					}
					ptmp->next = snode;


				}
			}

			// 添加到链表
			Cpnode cnode = (Cpnode)malloc(sizeof(Cnode)); //为cnode申请内存
			if (cnode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			memcpy(cnode, tcnode, sizeof(Cnode));
			Cpnode ptmp = CrsList;
			while (ptmp->next != NULL) {
				ptmp = ptmp->next;
			}
			ptmp->next = cnode;

		}
	}
	fclose(fp);
	return &CrsList;



}


/*
保存文件
作用：将链表保存到文件中
参数：链表首地址,文件路径
返回：是否成功
*/
//bool save(List* plist, char* file_name) {
//	FILE* fp;
//	Node* ptmp = (*plist)->next;
//	fp = fopen(file_name, "wb");//打开文件
//	if (fp == NULL) {
//		printf("Write \"%s\" error, please check and reboot the system!", file_name);
//		exit(EXIT_FAILURE);
//	}//打开失败
//
//	while (ptmp != NULL && fwrite(&(ptmp->item), sizeof(Item), 1, fp) == 1) {
//		ptmp = ptmp->next;
//	}// 写入文件
//	fclose(fp);
//	return true;
//}
//
