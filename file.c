#pragma warning(disable:4996)

#include "file.h"




List readStu(char* file_name) {
	FILE* fp;
	List StuList = (List)malloc(sizeof(Node));
	StuList->next = NULL;
	StuList->item.crslist = (Crsnode*)malloc(sizeof(Crsnode));
	StuList->item.crslist->crs_next = NULL;

	fp = fopen(file_name, "r");//读取文件
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//读取失败退出

	List tnode = (List)malloc(sizeof(Node)); //为tnode申请内存(临时存放)
	tnode->next = NULL;
	Crsnode* tcrs = (Crsnode*)malloc(sizeof(Crsnode)); //为tcrs申请内存(临时存放)
	tcrs->crs_next = NULL;

	//TODO

	if (tnode == NULL || tcrs == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// 分配失败

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // 跳过空行
			continue;
		}

		if (sscanf(line, "%d %s %d %d %s %s",
			&tnode->item.data.ID,
			&tnode->item.data.name,
			&tnode->item.data.gender,
			&tnode->item.data.grade,
			&tnode->item.data.college,
			&tnode->item.data.major
		) == 6) { // 读取学生信息

			tnode->item.crslist = (Crsnode*)malloc(sizeof(Crsnode)); //为一个crslist申请内存(添加到链表中的crslist)
			tnode->item.crslist->crs_next = NULL;

			if (tnode->item.crslist == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// 分配失败

			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&tcrs->score.course_id,
					&tcrs->score.course_name,
					&tcrs->score.score,
					&tcrs->score.semester,
					&tcrs->score.course_nature,
					&tcrs->score.credit,
					&tcrs->score.grid
				) == 7) { // 读取学生信息

					// 添加到链表
					Crsnode* crsnode = (Crsnode*)malloc(sizeof(Crsnode)); //为crsnode申请内存(添加到链表中的crsnode)
					if (crsnode == NULL) {
						printf("error!");
						exit(EXIT_FAILURE);
					}// 分配失败
					memcpy(crsnode, tcrs, sizeof(Crsnode));
					Crsnode* ptmp = tnode->item.crslist;
					while (ptmp->crs_next != NULL) {
						ptmp = ptmp->crs_next;
					}
					ptmp->crs_next = crsnode;


				}
			}

			// 添加到链表
			List Coursenode = (List)malloc(sizeof(Node)); //为Coursenode申请内存(添加到链表中的Coursenode)
			if (Coursenode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			memcpy(Coursenode, tnode, sizeof(Node));
			List ptmp = StuList;
			while (ptmp->next != NULL) {
				ptmp = ptmp->next;
			}
			ptmp->next = Coursenode;

		}
	}
	free(tnode);
	free(tcrs);
	fclose(fp);
	return StuList;

}

Cpnode readCrs(char* file_name) {
	FILE* fp;
	Cpnode CrsList = (Cpnode)malloc(sizeof(_Cnode));
	CrsList->next = NULL;
	CrsList->sphead = (Spnode)malloc(sizeof(Snode));
	CrsList->sphead->next = NULL;

	fp = fopen(file_name, "r");//读取文件
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//读取失败退出

	Cpnode tcnode = (Cpnode)malloc(sizeof(_Cnode)); //为tcnode申请内存(存放临时的Cpnode)
	tcnode->next = NULL;
	Spnode tsnode = (Spnode)malloc(sizeof(Snode)); //为tsnode申请内存(存放临时的Spnode)
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
		) == 8) { // 读取课程信息

			tcnode->sphead = (Spnode)malloc(sizeof(Snode));//为一个sphead申请内存(添加到链表中的sphead)
			tcnode->sphead->next = NULL;
			if (tcnode->sphead == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// 分配失败

			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&tsnode->snum,
					&tsnode->sname,
					&tsnode->score,
					&tsnode->GPA
				) == 4) { // 读取学生信息
					tsnode->next = NULL;

					// 添加到链表
					Spnode snode = (Spnode)malloc(sizeof(Snode)); //为snode申请内存(添加到链表中的snode)
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
			Cpnode cnode = (Cpnode)malloc(sizeof(_Cnode)); //为cnode申请内存(添加到链表中的cnode)
			if (cnode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			memcpy(cnode, tcnode, sizeof(_Cnode));
			Cpnode ptmp = CrsList;
			while (ptmp->next != NULL) {
				ptmp = ptmp->next;
			}
			ptmp->next = cnode;


		}
	}
	free(tcnode);
	free(tsnode);
	fclose(fp);
	return CrsList;



}

bool saveStu(List StuList, char* file_name)
{
	return false;
}

bool saveCrs(Cpnode CrsList, char* file_name)
{
	return false;
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
