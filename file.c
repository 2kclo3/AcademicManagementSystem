#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file.h"
#include "course.h"



/*
��ȡ�ļ�
���ã���ȡ���������ļ�������һ�������׵�ַ
�������ļ�·��
���أ���ȡ�ļ��󱣴浽�ڴ����������׵�ַ
*/
Cpnode readCrs(char* file_name) {
	FILE* fp;
	Cpnode CrsList = (Cpnode)malloc(sizeof(Cnode));
	CrsList->next = NULL;
	CrsList->sphead = (Spnode)malloc(sizeof(Snode));
	CrsList->sphead->next = NULL;

	fp = fopen(file_name, "r");//��ȡ�ļ�
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//��ȡʧ���˳�

	Cpnode tcnode = (Cpnode)malloc(sizeof(Cnode)); //Ϊcnode�����ڴ�
	tcnode->next = NULL;
	tcnode->sphead = (Spnode)malloc(sizeof(Snode));
	tcnode->sphead->next = NULL;
	Spnode tsnode = (Spnode)malloc(sizeof(Snode)); //Ϊtsnode�����ڴ�
	tsnode->next = NULL;
	if (tcnode == NULL || tsnode == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// ����ʧ��

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // ��������
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
		) == 8) { // ��ȡѧ����Ϣ
			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // ��������
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&tsnode->snum,
					&tsnode->sname,
					&tsnode->score,
					&tsnode->GPA
				) == 4) {
					tsnode->next = NULL;

					// ��ӵ�����
					Spnode snode = (Spnode)malloc(sizeof(Snode)); //Ϊsnode�����ڴ�
					if (snode == NULL) {
						printf("error!");
						exit(EXIT_FAILURE);
					}// ����ʧ��
					memcpy(snode, tsnode, sizeof(Snode));
					Spnode ptmp = tcnode->sphead;
					while (ptmp->next != NULL) {
						ptmp = ptmp->next;
					}
					ptmp->next = snode;


				}
			}

			// ��ӵ�����
			Cpnode cnode = (Cpnode)malloc(sizeof(Cnode)); //Ϊcnode�����ڴ�
			if (cnode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// ����ʧ��
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
�����ļ�
���ã��������浽�ļ���
�����������׵�ַ,�ļ�·��
���أ��Ƿ�ɹ�
*/
//bool save(List* plist, char* file_name) {
//	FILE* fp;
//	Node* ptmp = (*plist)->next;
//	fp = fopen(file_name, "wb");//���ļ�
//	if (fp == NULL) {
//		printf("Write \"%s\" error, please check and reboot the system!", file_name);
//		exit(EXIT_FAILURE);
//	}//��ʧ��
//
//	while (ptmp != NULL && fwrite(&(ptmp->item), sizeof(Item), 1, fp) == 1) {
//		ptmp = ptmp->next;
//	}// д���ļ�
//	fclose(fp);
//	return true;
//}
//
