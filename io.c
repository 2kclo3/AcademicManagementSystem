#include "io.h"


int getNumber(int max) {
	printf(">>> ");//提示输入

	char line[1024];
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';

	if (!strcmp(line, "\0")) {
		return getNumber(max);
	}//没输入就按了回车

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
		}//非数字直接错误
		if (line[i] == ' ') {
			if (is_num == 0) {
				continue;
			}
			is_continue = 0;
			continue;
		}//去掉空格
		if (is_continue == 1) {
			command = command * 10 + line[i] - '0';//拼接数字
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
		}//错误处理
	}

	if (is_all_space == 1) {
		return getNumber(max);
	}//如果输入的全是空格

	if (err == 0) {
		return command;
	}
	else {
		//printf("输入数据不合法，请重新输入！\n");
		printf("\"%s\" 不是有效的命令，请重新输入！\n", line);
		return getNumber(max);
	}

}



char* getText(char* str) {
	printf(">>> ");//提示输入

	char line[10240];
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';// 获取一整行

	if (!strcmp(line, "\0")) {
		return getText(str);
	}//没输入就按了回车

	//int start_space = 1;
	//int end_space = 1;
	int len = 0;
	int is_all_space = 1;
	for (int i = 0; line[i]; i++) {// 逐个字符遍历
		if (line[i] == ' ') {
			continue;
		}// 去掉空格
		str[len++] = line[i];
		is_all_space = 0;
	}
	str[len] = '\0';

	if (is_all_space == 1) {
		getText(str);
	}// 如果全是空格
	return true;

}
