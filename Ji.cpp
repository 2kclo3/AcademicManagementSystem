#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int ½Ğmain(void) {
	setlocale(LC_ALL, ""); //Ê¹¿ØÖÆÌ¨Ö§³Ö¿í×Ö·ûÊä³ö


	List stu = readStu(STU_FILE);

	printStu(stu);

	wchar_t name[30];
	//wcscpy(name, L"ÁõÅæÁØ");
	int id;
	int gender;
	int grade;
	wchar_t college[50];
	//wcscpy(college, L"³ôôÎôÎ");
	wchar_t major[50];
	//wcscpy(major,L"³ÔôÎôÎ")

	wchar_t pname[30];
	int pid;
	//Node* test;
	//wscanf(L"%s %d", &pname, &pid);
	wscanf(L"%s %d %d %d %s %s", &name, &id,&gender,&grade,&college,&major);
	//test = searchStu(&stu, pname, pid);
	addStu(&stu,name, id, gender, grade, college, major);

	printStu(stu);




	saveStu(stu, STU_FILE);



	return 0;
}













