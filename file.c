#pragma warning(disable:4996)

#include "file.h"




List readStu(char* file_name) {
	FILE* fp;
	List StuList = (List)malloc(sizeof(Node));
	StuList->next = NULL;
	StuList->item.crslist = (Crsnode*)malloc(sizeof(Crsnode));
	StuList->item.crslist->crs_next = NULL;

	fp = fopen(file_name, "r");//��ȡ�ļ�
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//��ȡʧ���˳�

	List tnode = (List)malloc(sizeof(Node)); //Ϊtnode�����ڴ�(��ʱ���)
	tnode->next = NULL;
	Crsnode* tcrs = (Crsnode*)malloc(sizeof(Crsnode)); //Ϊtcrs�����ڴ�(��ʱ���)
	tcrs->crs_next = NULL;

	//TODO

	if (tnode == NULL || tcrs == NULL) {
		printf("error!");
		exit(EXIT_FAILURE);
	}// ����ʧ��

	char line[512];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '\n') { // ��������
			continue;
		}

		if (sscanf(line, "%d %s %d %d %s %s",
			&tnode->item.data.ID,
			&tnode->item.data.name,
			&tnode->item.data.gender,
			&tnode->item.data.grade,
			&tnode->item.data.college,
			&tnode->item.data.major
		) == 6) { // ��ȡѧ����Ϣ

			tnode->item.crslist = (Crsnode*)malloc(sizeof(Crsnode)); //Ϊһ��crslist�����ڴ�(��ӵ������е�crslist)
			tnode->item.crslist->crs_next = NULL;

			if (tnode->item.crslist == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// ����ʧ��

			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // ��������
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
				) == 7) { // ��ȡѧ����Ϣ

					// ��ӵ�����
					Crsnode* crsnode = (Crsnode*)malloc(sizeof(Crsnode)); //Ϊcrsnode�����ڴ�(��ӵ������е�crsnode)
					if (crsnode == NULL) {
						printf("error!");
						exit(EXIT_FAILURE);
					}// ����ʧ��
					memcpy(crsnode, tcrs, sizeof(Crsnode));
					Crsnode* ptmp = tnode->item.crslist;
					while (ptmp->crs_next != NULL) {
						ptmp = ptmp->crs_next;
					}
					ptmp->crs_next = crsnode;


				}
			}

			// ��ӵ�����
			List Coursenode = (List)malloc(sizeof(Node)); //ΪCoursenode�����ڴ�(��ӵ������е�Coursenode)
			if (Coursenode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// ����ʧ��
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

	fp = fopen(file_name, "r");//��ȡ�ļ�
	if (fp == NULL) {
		printf("Read \"%s\" error, please check and reboot the system!", file_name);
		exit(EXIT_FAILURE);
	}//��ȡʧ���˳�

	Cpnode tcnode = (Cpnode)malloc(sizeof(_Cnode)); //Ϊtcnode�����ڴ�(�����ʱ��Cpnode)
	tcnode->next = NULL;
	Spnode tsnode = (Spnode)malloc(sizeof(Snode)); //Ϊtsnode�����ڴ�(�����ʱ��Spnode)
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
		) == 8) { // ��ȡ�γ���Ϣ

			tcnode->sphead = (Spnode)malloc(sizeof(Snode));//Ϊһ��sphead�����ڴ�(��ӵ������е�sphead)
			tcnode->sphead->next = NULL;
			if (tcnode->sphead == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// ����ʧ��

			while (fgets(line, sizeof(line), fp) != NULL) {
				if (line[0] == '\n') { // ��������
					break;
				}
				if (sscanf(line, "%s %s %lf %d %d %lf %lf",
					&tsnode->snum,
					&tsnode->sname,
					&tsnode->score,
					&tsnode->GPA
				) == 4) { // ��ȡѧ����Ϣ
					tsnode->next = NULL;

					// ��ӵ�����
					Spnode snode = (Spnode)malloc(sizeof(Snode)); //Ϊsnode�����ڴ�(��ӵ������е�snode)
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
			Cpnode cnode = (Cpnode)malloc(sizeof(_Cnode)); //Ϊcnode�����ڴ�(��ӵ������е�cnode)
			if (cnode == NULL) {
				printf("error!");
				exit(EXIT_FAILURE);
			}// ����ʧ��
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
