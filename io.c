#include "io.h"
#include <math.h>


int getNumber(int max) {
	printf(">>> ");//��ʾ����

	char line[1024];
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';

	if (!strcmp(line, "\0")) {
		return getNumber(max);
	}//û����Ͱ��˻س�

	char ch;
	int command = 0;
	int err = 1;
	int is_num = 0;
	int is_continue = 1;
	int is_all_space = 1;

	for (int i = 0; i < strlen(line); i++) {
		//for (int i = 0; line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'); i++) {
		err = 0;
		if (!(line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))) {
			err = 1;
			is_all_space = 0;
			break;
		}//������ֱ�Ӵ���
		if (line[i] == ' ') {
			if (is_num == 0) {
				continue;
			}
			is_continue = 0;
			continue;
		}//ȥ���ո�
		if (is_continue == 1) {
			command = command * 10 + line[i] - '0';//ƴ������
			is_num = 1;
			is_all_space = 0;
		}
		else {
			err = 1;
			break;
		}
		if (command > max) {
			err = 1;
			break;
		}//������
	}

	if (is_all_space == 1) {
		return getNumber(max);
	}//��������ȫ�ǿո�

	if (err == 0) {
		return command;
	}
	else {
		//printf("�������ݲ��Ϸ������������룡\n");
		printf("\"%s\" �������ݲ��Ϸ������������룡\n", line);
		return getNumber(max);
	}

}


double getDouble(double max) {
	fflush(stdin);
	printf(">>> ");//��ʾ����

	char line[1024];
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';

	if (!strcmp(line, "\0")) {
		return getDouble(max);
	}//û����Ͱ��˻س�

	char ch;
	int command = 0;
	int err = 1;
	int is_num = 0;
	int is_continue = 1;
	int is_all_space = 1;
	int is_dot = 0;
	int dot = 0;

	for (int i = 0; i < strlen(line); i++) {
		//for (int i = 0; line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'); i++) {
		err = 0;
		if (!(line[i] == ' ' || (line[i] >= '0' && line[i] <= '9') || line[i] == '.')) {
			err = 1;
			is_all_space = 0;
			break;
		}//������ֱ�Ӵ���
		if (line[i] == ' ') {
			if (is_num == 0) {
				continue;
			}
			is_continue = 0;
			continue;
		}//ȥ���ո�
		if (line[i] == '.') {
			if (is_dot == 0) {
				is_dot = 1;
				continue;
			}
			else {
				err = 1; // ���С����
				is_all_space = 0;
				break;
			}
		}
		if (is_continue == 1) {
			if (is_dot == 1) {
				dot++;
				if (dot > 2) {
					err = 1; // С��λ��̫��
					is_all_space = 0;
					break;
				}
			}
			command = command * 10 + line[i] - '0';//ƴ������
			is_num = 1;
			is_all_space = 0;
		}
		else {
			err = 1;
			break;
		}
		if (command / pow(10, dot) > max) {
			err = 1;
			break;
		}//������
	}

	if (is_all_space == 1) {
		return getDouble(max);
	}//��������ȫ�ǿո�

	if (err == 0) {
		return command / pow(10, dot);
	}
	else {
		//printf("�������ݲ��Ϸ������������룡\n");
		printf("\"%s\" �������ݲ��Ϸ������������룡\n", line);
		return getDouble(max);
	}

}


void getText(char* str) {
	fflush(stdin);
	printf(">>> ");//��ʾ����

	char line[10240];
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';// ��ȡһ����

	if (!strcmp(line, "\0")) {
		return getText(str);
	}//û����Ͱ��˻س�

	//int start_space = 1;
	//int end_space = 1;
	int len = 0;
	int is_all_space = 1;
	for (int i = 0; line[i]; i++) {// ����ַ�����
		if (line[i] == ' ') {
			continue;
		}// ȥ���ո�
		str[len++] = line[i];
		is_all_space = 0;
	}
	str[len] = '\0';

	if (is_all_space == 1) {
		getText(str);
	}// ���ȫ�ǿո�
	return true;

}
