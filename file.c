#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

	Item* item = (Item*)malloc(sizeof(Item)); //Ϊitem�����ڴ�
	item->score = (Score*)malloc(sizeof(Score));
	item->score->sco_next = NULL;
	Score* score = (Score*)malloc(sizeof(Score)); //Ϊscore�����ڴ�
	if (item == NULL || score == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// ����ʧ��

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // ��������
			continue;
		}

		if (sscanf(line, "%d %s %d %d %s %s",
			&item->data.ID,
			&item->data.name,
			&item->data.gender,
			&item->data.grade,
			&item->data.college,
			&item->data.major) == 6) { // ��ȡѧ����Ϣ
			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // ��������
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
					AddScore(score, item); // ��ӵ�����
				}
			}
			AddItem(item, &list); // ��ӵ�����
			item->score->sco_next = NULL;
		}
	}
	fclose(fp);
	return &list;



}


/*
�����ļ�
���ã��������浽�ļ���
�����������׵�ַ,�ļ�·��
���أ��Ƿ�ɹ�
*/
bool save(List* plist, char* file_name) {
	FILE* fp;
	Node* ptmp = (*plist)->next;
	fp = fopen(file_name, "wb");//���ļ�
	if (fp == NULL) {
		printf("Write \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//��ʧ��

	while (ptmp != NULL && fwrite(&(ptmp->item), sizeof(Item), 1, fp) == 1) {
		ptmp = ptmp->next;
	}// д���ļ�
	fclose(fp);
	return true;
}

