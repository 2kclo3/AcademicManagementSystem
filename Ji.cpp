#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int jjmain(void) {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����


	List stu = readStu(STU_FILE);

	printStu(stu);
	wchar_t name[16];
	int id;
	Node* test;
	wscanf(L"%s %d", &name, &id);
	test = searchStu(&stu, name, id);
	deleteStu(&stu, test);
	printStu(stu);




	saveStu(stu, STU_FILE);



	return 0;
}













