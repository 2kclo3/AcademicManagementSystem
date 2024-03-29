#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int jjmain(void) {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出


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













