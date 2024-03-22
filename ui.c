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
��ʾҳ��
���ã���ʾҳ��
������ҳ������
���أ�ҳ����
*/
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

