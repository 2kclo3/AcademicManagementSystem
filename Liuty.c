#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int main888999(void){ 

	

	Cpnode  crs = readCrs(CRS_FILE);

	Cpnode Crscrt = crs->next;
	while (Crscrt != NULL) {
		printf("%d\n", Crscrt->cnum);
		Spnode stu = Crscrt->sphead->next;
		while (stu != NULL) {
			printf("%s\n", stu->sname);
			stu = stu->next;
		}
		Crscrt = Crscrt->next;
		printf("\n");

	}


	List stu = readStu(STU_FILE);

	List Stucrt = stu->next;
	while (Stucrt != NULL) {
		printf("%s\n", Stucrt->item.data.name);
		Crsnode* stu = Stucrt->item.crslist->crs_next;
		while (stu != NULL) {
			printf("%s\n", stu->score.course_name);
			stu = stu->crs_next;
		}
		Stucrt = Stucrt->next;
		printf("\n");

	}


	char testName[30];
	scanf("%s", &testName);
	strcpy(stu->next->item.data.name, testName);
	char crs1[30];
	scanf("%s", &crs1);
	strcpy(stu->next->next->item.crslist->crs_next->score.course_name, crs1);

	int testID;
	scanf("%d", &testID);
	crs->next->next->cnum = testID;
	strcpy(crs->next->sphead->next->next->sname, testName);


	saveStu(stu, STU_FILE);
	saveCrs(crs, CRS_FILE);
















	
	////ҳ����ʾ
	//char* current_page = show_page("hello"); //��ǰҳ��hello
	//int command; // ָ��
	//int is_teacher;
	//while (1) {

	//	// ��ӭҳ
	//	if (!strcmp(current_page, "hello")) {
	//		command = getNumber(1); // ��������ָ��
	//		if (command == 0) {
	//			exit(0);
	//		}
	//		else if (command == 1) {
	//			current_page = show_page("login");
	//		}
	//	}

	//	// ��¼ҳ
	//	else if (!strcmp(current_page, "login")) {
	//		command = getNumber(3);
	//		if (command == 0) {
	//			current_page = show_page("hello");
	//		}
	//		else if (command == 1) {
	//			is_teacher = 1;
	//			current_page = show_page("menu");
	//		}
	//		else if (command == 2) {
	//			current_page = show_page("menu");
	//		}
	//		else if (command == 3) {
	//			current_page = show_page("menu");
	//		}
	//		//system("pause"); 
	//		//��¼������  
	//		// //TODO
	//	}

	//	// �˵�ҳ
	//	else if (!strcmp(current_page, "menu")) {
	//		command = getNumber(5); // ��������ָ��
	//		if (command == 0) {
	//			current_page = show_page("login");
	//		}
	//		else if (command == 1) {
	//			//List* list = read(FILE_NAME);
	//			////show_sheet(list, 1);
	//			//current_page = "sheet";
	//			current_page = show_page("allStu");
	//		}
	//		else if (command == 2) {

	//			current_page = show_page("allCrs");
	//		}
	//		else if (command == 3) {
	//			current_page = show_page("allQuality");
	//		}
	//		else if (command == 4) {
	//			current_page = show_page("changeMajor");
	//		}
	//		else if (command == 5) {
	//			current_page = show_page("settings");
	//		}
	//	}

	//	//����ѧ����Ϣҳ��
	//	else if (!strcmp(current_page, "allStu")) {

	//	}

	//	//���пγ���Ϣҳ��
	//	else if (!strcmp(current_page, "allCrs")) {
	//		//showMenu("������γ̺�", 0);
	//		//int cnum = getNumber(99999);
	//		//showMenu("������ѧ��", 0);
	//		//int cgrade = getNumber(3000);

	//		//searchCrs();



	//	}

	//	//������������Ϣ��Ϣҳ��
	//	else if (!strcmp(current_page, "allQuality")) {

	//	}

	//	//תרҵ����ҳ��
	//	else if (!strcmp(current_page, "changeMajor")) {

	//	}

	//	// ���ҳ
	//	else if (!strcmp(current_page, "sheet")) {
	//		command = getNumber(4); // ��������ָ��
	//		if (command == 0) {
	//			current_page = show_page("menu");
	//		}
	//		else if (command == 1) {
	//		}
	//		else if (command == 2) {
	//		}
	//		else if (command == 3) {
	//		}
	//		else if (command == 4) {
	//		}
	//	}

	//	// ����ҳ
	//	else if (!strcmp(current_page, "settings")) {
	//		command = getNumber(3); // ��������ָ��
	//		if (command == 0) {
	//			current_page = show_page("menu");
	//		}
	//	}

	//	// ĳҳ
	//	else if (!strcmp(current_page, "")) {
	//		command = getNumber(1); // ��������ָ��
	//	}

	//	// �����ڵ�ҳ��
	//	else {
	//		break;
	//	}
	//}

	return 0;
}
