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
	system("cls");//��տ���̨����
	FILE* fp = NULL;
	fp = fopen(PAGE_FILE, "r");//��ֻ����ʽ���ļ�
	if (fp == NULL) {
		printf("Read %s errer, please check and reboot the system!", PAGE_FILE);
		exit(EXIT_FAILURE);
	}
	//����ȡʧ��ʱ��Ҫ�����������ϵͳ

	char start_tag[30], end_tag[30];
	sprintf(start_tag, "%s<<<", page_name);
	sprintf(end_tag, ">>>%s", page_name);//����Ѱ�ҵĿ�ʼ�ͽ�����ǩ

	bool start_found = 0;
	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {//һ��һ��Ѱ�ұ�ǩ����ӡ
		if (strstr(line, start_tag) != NULL) {
			start_found = 1;
			continue;
		}//�ҵ���ʼ��ǩ������������һ�п�ʼ��ӡ
		if (strstr(line, end_tag) != NULL) {
			break;
		}//�ҵ�������ǩ������ѭ��
		if (start_found == 1) {
			printf("%s", line);
		}//��ӡ��ǰ��
	}

	fclose(fp);//�ر��ļ�
	return page_name;

}


void printStu(const List StuList){

	List pStu = StuList->next; // ��ͷ������һ���ڵ㿪ʼ
	while (pStu != NULL) {
		printf("ѧ����Ϣ:%d\t%s\t%d\t%d\t%s\t%s\n\n�γ̣�\n",
			pStu->item.data.ID,
			pStu->item.data.name,
			pStu->item.data.gender,
			pStu->item.data.grade,
			pStu->item.data.college,
			pStu->item.data.major); 

		Crsnode* pcrs = pStu->item.crslist->crs_next; // ����һ���γ̽ڵ㿪ʼ
		while (pcrs != NULL) {
			printf("%s\t%s\t%.1lf\t%d\t%d\t%.1lf\t%.1lf\n",
				pcrs->score.course_id,
				pcrs->score.course_name,
				pcrs->score.score,
				pcrs->score.semester,
				pcrs->score.course_nature,
				pcrs->score.credit,
				pcrs->score.grid);

			pcrs = pcrs->crs_next; // �ƶ�����һ���ڵ�
		}

		printf("\n���гɹ���\n");
		Rnode* pres = pStu->item.rlist->rnext; // ����һ�����гɹ��ڵ㿪ʼ
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

			pres = pres->rnext; // �ƶ�����һ���ڵ�
		}


		printf("\n�����񽱣�\n");
		Cnode* pcpt = pStu->item.clist->cnext; // ����һ�������񽱽ڵ㿪ʼ
		while (pcpt != NULL) {
			printf("%s\t%s\t%s\t%s\t%.2lf\n",
				pcpt->competition.competition_name,
				pcpt->competition.organizer,
				pcpt->competition.category,
				pcpt->competition.date,
				pcpt->competition.GPA_bonus);

			pcpt = pcpt->cnext; // �ƶ�����һ���ڵ�
		}


		printf("\n\n");
		pStu = pStu->next; // �ƶ�����һ���ڵ�
	}


}




void printCrs(const Cpnode CrsList){
	Cpnode pCrs = CrsList->next; // ��ͷ������һ���ڵ㿪ʼ
	while (pCrs != NULL) {
		printf("�γ���Ϣ:%d\t%s\t%d\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\nѧ����\n",
			pCrs->cnum,
			pCrs->cname,
			pCrs->character,
			pCrs->headcount,
			pCrs->totscore,
			pCrs->averscore,
			pCrs->totGPA,
			pCrs->averGPA); // д��

		Spnode pstu = pCrs->sphead->next; // ����һ��ѧ���ڵ㿪ʼ
		while (pstu != NULL) {
			printf("%d\t%s\t%.1lf\t%.1lf\n",
				pstu->snum,
				pstu->sname,
				pstu->score,
				pstu->GPA); // д��

			pstu = pstu->next; // �ƶ�����һ���ڵ�
		}
		printf("\n\n");
		pCrs = pCrs->next; // �ƶ�����һ���ڵ�
	}
}





/*
��ʾ�����Ϣ
���ã���ʾ�����Ϣ
����������ͷ�ڵ�,�������
���أ���
*/
//void show_sheet(const List* const plist, int sheet_type) {
//	//system("cls");//��տ���̨����
//	Node* current = (*plist)->next;
//	system("cls");//��տ���̨����
//
//	if (sheet_type == 1) {// ѧ����Ϣ
//		if (IsListEmpty(plist)) {
//			printf("ѧ����ϢΪ�գ�������\"2\"�������\n\n");
//		}
//		else {
//			int cnt = 1;
//			printf("    | %-15s | %-8s |%-3s|\n", "����", "ѧ��", "�Ա�");
//			printf("----------------------------------------------------------------------------------------\n");
//			while (current != NULL) {// ����������ӡ����
//				printf("%4d| %-15s | %08d |%-3s |\n",
//					cnt++, current->item.data.name, current->item.data.ID, current->item.data.gender ? "Ů" : "��");
//
//				current = current->next;
//			}
//			printf("----------------------------------------------------------------------------------------\n\n");
//		}
//		printf("0:������һ��  1:��ѯѧ��  2:���ѧ��  3:�޸�ѧ����Ϣ  4:ɾ��ѧ��\n\n");
//	}
//	else if (sheet_type == 2) {
//	}
//}

