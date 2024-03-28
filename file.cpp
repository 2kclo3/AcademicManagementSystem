#pragma warning(disable:4996)

#include "file.h"




List readStu(const char* file_name) {
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
	Rnode* trnode = (Rnode*)malloc(sizeof(Rnode)); //为trnode申请内存(临时存放)
	trnode->rnext = NULL;
	Cnode* tcnode = (Cnode*)malloc(sizeof(Cnode)); //为tcnode申请内存(临时存放)
	tcnode->cnext = NULL;

	//TODO

	if (tnode == NULL || tcrs == NULL || trnode == NULL || tcnode == NULL) {
		wprintf(L"error!");
		exit(EXIT_FAILURE);
	}// 分配失败

	wchar_t line[512];
	while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
		if (line[0] == '\n') { // 跳过空行
			continue;
		}

		if (swscanf(line, L"%d %s %d %d %s %s",
			&tnode->item.data.ID,
			&tnode->item.data.name,
			&tnode->item.data.gender,
			&tnode->item.data.grade,
			&tnode->item.data.college,
			&tnode->item.data.major
		) == 6) { // 读取学生信息





			tnode->item.crslist = (Crsnode*)malloc(sizeof(Crsnode)); //为一个crslist申请内存(添加到链表中的crslist)
			if (tnode->item.crslist == NULL) {
				wprintf(L"error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			tnode->item.crslist->crs_next = NULL;

			while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (swscanf(line, L"%s %s %lf %d %d %lf %lf",
					&tcrs->score.course_id,
					&tcrs->score.course_name,
					&tcrs->score.score,
					&tcrs->score.semester,
					&tcrs->score.course_nature,
					&tcrs->score.credit,
					&tcrs->score.grid
				) == 7) { // 读取课程信息

					// 添加到链表
					Crsnode* crsnode = (Crsnode*)malloc(sizeof(Crsnode)); //为crsnode申请内存(添加到链表中的crsnode)
					if (crsnode == NULL) {
						wprintf(L"error!");
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



			tnode->item.rlist = (Rnode*)malloc(sizeof(Rnode)); //为一个rlist申请内存(添加到链表中的rlist)
			if (tnode->item.rlist == NULL) {
				wprintf(L"error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			tnode->item.rlist->rnext = NULL;

			while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (swscanf(line, L"%s %s %s %s %s %s %s %lf",
					&trnode->research.paper_name,
					&trnode->research.journal_or_conference_name,
					&trnode->research.author,
					&trnode->research.date,
					&trnode->research.volume_num,
					&trnode->research.issue_num,
					&trnode->research.page,
					&trnode->research.GPA_bonus
				) == 8) { // 读取科研成果信息

					// 添加到链表
					Rnode* resnode = (Rnode*)malloc(sizeof(Rnode)); //为resnode申请内存(添加到链表中的resnode)
					if (resnode == NULL) {
						wprintf(L"error!");
						exit(EXIT_FAILURE);
					}// 分配失败
					memcpy(resnode, trnode, sizeof(Rnode));
					Rnode* ptmp = tnode->item.rlist;
					while (ptmp->rnext != NULL) {
						ptmp = ptmp->rnext;
					}
					ptmp->rnext = resnode;
				}
			}





			tnode->item.clist = (Cnode*)malloc(sizeof(Cnode)); //为一个clist申请内存(添加到链表中的clist)
			if (tnode->item.clist == NULL) {
				wprintf(L"error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			tnode->item.clist->cnext = NULL;

			while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (swscanf(line, L"%s %s %s %s %lf",
					&tcnode->competition.competition_name,
					&tcnode->competition.organizer,
					&tcnode->competition.category,
					&tcnode->competition.date,
					&tcnode->competition.GPA_bonus
				) == 5) { // 读取竞赛获奖信息

					// 添加到链表
					Cnode* cptnode = (Cnode*)malloc(sizeof(Cnode)); //为cptnode申请内存(添加到链表中的cptnode)
					if (cptnode == NULL) {
						wprintf(L"error!");
						exit(EXIT_FAILURE);
					}// 分配失败
					memcpy(cptnode, tcnode, sizeof(Cnode));
					Cnode* ptmp = tnode->item.clist;
					while (ptmp->cnext != NULL) {
						ptmp = ptmp->cnext;
					}
					ptmp->cnext = cptnode;
				}
			}







			// 添加到链表
			List Coursenode = (List)malloc(sizeof(Node)); //为Coursenode申请内存(添加到链表中的Coursenode)
			if (Coursenode == NULL) {
				wprintf(L"error!");
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
	free(trnode);
	free(tcnode);
	fclose(fp);
	return StuList;

}

Cpnode readCrs(const char* file_name) {
	FILE* fp;
	Cpnode CrsList = (Cpnode)malloc(sizeof(_Cnode));
	CrsList->next = NULL;
	CrsList->sphead = (Spnode)malloc(sizeof(Snode));
	CrsList->sphead->next = NULL;

	fp = fopen(file_name, "r");//读取文件
	if (fp == NULL) {
		printf("Write to \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//读取失败退出

	Cpnode tcnode = (Cpnode)malloc(sizeof(_Cnode)); //为tcnode申请内存(存放临时的Cpnode)
	tcnode->next = NULL;
	Spnode tsnode = (Spnode)malloc(sizeof(Snode)); //为tsnode申请内存(存放临时的Spnode)
	tsnode->next = NULL;
	if (tcnode == NULL || tsnode == NULL) {
		wprintf(L"error!");
		exit(EXIT_FAILURE);
	}// 分配失败

	wchar_t line[512];
	while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
		if (line[0] == '\n') { // 跳过空行
			continue;
		}

		if (swscanf(line, L"%d %s %d %d %lf %lf %lf %lf",
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
			if (tcnode->sphead == NULL) {
				wprintf(L"error!");
				exit(EXIT_FAILURE);
			}// 分配失败
			tcnode->sphead->next = NULL;

			while (fgetws(line, sizeof(line) / sizeof(line[0]), fp) != NULL) {
				if (line[0] == '\n') { // 跳过空行
					break;
				}
				if (swscanf(line, L"%d %s %lf %lf",
					&tsnode->snum,
					&tsnode->sname,
					&tsnode->score,
					&tsnode->GPA
				) == 4) { // 读取学生信息
					tsnode->next = NULL;

					// 添加到链表
					Spnode snode = (Spnode)malloc(sizeof(Snode)); //为snode申请内存(添加到链表中的snode)
					if (snode == NULL) {
						wprintf(L"error!");
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
				wprintf(L"error!");
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

bool saveStu(List StuList, const char* file_name) {
	FILE* fp;
	fp = fopen(file_name, "w"); // 打开文件
	if (fp == NULL) {
		printf("Write \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//打开失败

	List pStu = StuList->next; // 从头结点的下一个节点开始
	while (pStu != NULL) {
		fwprintf(fp, L"%d %s %d %d %s %s\n",
			pStu->item.data.ID,
			pStu->item.data.name,
			pStu->item.data.gender,
			pStu->item.data.grade,
			pStu->item.data.college,
			pStu->item.data.major); // 写入

		Crsnode* pcrs = pStu->item.crslist->crs_next; // 从下一个课程节点开始
		while (pcrs != NULL) {
			fwprintf(fp, L"%s %s %.1lf %d %d %.1lf %.1lf\n",
				pcrs->score.course_id,
				pcrs->score.course_name,
				pcrs->score.score,
				pcrs->score.semester,
				pcrs->score.course_nature,
				pcrs->score.credit,
				pcrs->score.grid); // 写入

			pcrs = pcrs->crs_next; // 移动到下一个节点
		}
		fwprintf(fp, L"\n");


		Rnode* pres = pStu->item.rlist->rnext; // 从下一个科研成果节点开始
		while (pres != NULL) {
			fwprintf(fp, L"%s %s %s %s %s %s %s %.2lf\n",
				pres->research.paper_name,
				pres->research.journal_or_conference_name,
				pres->research.author,
				pres->research.date,
				pres->research.volume_num,
				pres->research.issue_num,
				pres->research.page,
				pres->research.GPA_bonus); // 写入

			pres = pres->rnext; // 移动到下一个节点
		}
		fwprintf(fp, L"\n");


		Cnode* pcpt = pStu->item.clist->cnext; // 从下一个竞赛获奖节点开始
		while (pcpt != NULL) {
			fwprintf(fp, L"%s %s %s %s %.2lf\n",
				pcpt->competition.competition_name,
				pcpt->competition.organizer,
				pcpt->competition.category,
				pcpt->competition.date,
				pcpt->competition.GPA_bonus); // 写入

			pcpt = pcpt->cnext; // 移动到下一个节点
		}
		fwprintf(fp, L"\n");



		pStu = pStu->next; // 移动到下一个节点
	}
	fclose(fp);
	return true;
}

bool saveCrs(Cpnode CrsList, const char* file_name) {
	FILE* fp;
	fp = fopen(file_name, "w"); // 打开文件
	if (fp == NULL) {
		printf("Write \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//打开失败

	Cpnode pCrs = CrsList->next; // 从头结点的下一个节点开始
	while (pCrs != NULL) {
		fwprintf(fp, L"%d %s %d %d %.1lf %.2lf %.1lf %.2lf\n",
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
			fwprintf(fp, L"%d %s %.1lf %.1lf\n",
				pstu->snum,
				pstu->sname,
				pstu->score,
				pstu->GPA); // 写入

			pstu = pstu->next; // 移动到下一个节点
		}
		fwprintf(fp, L"\n");
		pCrs = pCrs->next; // 移动到下一个节点
	}
	fclose(fp);
	return true;
}


