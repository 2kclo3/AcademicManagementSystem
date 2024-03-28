#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int main00000000000(void){ 

	

	Cpnode  crs = readCrs(CRS_FILE);
	List stu = readStu(STU_FILE);

	printStu(stu);
	printf("\n\n\n\n\n");
	printCrs(crs);

	getchar();



	saveStu(stu, STU_FILE);
	saveCrs(crs, CRS_FILE);


	

	return 0;
}












	////页面显示
	//char* current_page = show_page("hello"); //当前页：hello
	//int command; // 指令
	//int is_teacher;
	//while (1) {

	//	// 欢迎页
	//	if (!strcmp(current_page, "hello")) {
	//		command = getNumber(1); // 接收数字指令
	//		if (command == 0) {
	//			exit(0);
	//		}
	//		else if (command == 1) {
	//			current_page = show_page("login");
	//		}
	//	}

	//	// 登录页
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
	//		//登录先留着  
	//		// //TODO
	//	}

	//	// 菜单页
	//	else if (!strcmp(current_page, "menu")) {
	//		command = getNumber(5); // 接收数字指令
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

	//	//所有学生信息页面
	//	else if (!strcmp(current_page, "allStu")) {

	//	}

	//	//所有课程信息页面
	//	else if (!strcmp(current_page, "allCrs")) {
	//		//showMenu("请输入课程号", 0);
	//		//int cnum = getNumber(99999);
	//		//showMenu("请输入学年", 0);
	//		//int cgrade = getNumber(3000);

	//		//searchCrs();



	//	}

	//	//总体素质类信息信息页面
	//	else if (!strcmp(current_page, "allQuality")) {

	//	}

	//	//转专业管理页面
	//	else if (!strcmp(current_page, "changeMajor")) {

	//	}

	//	// 表格页
	//	else if (!strcmp(current_page, "sheet")) {
	//		command = getNumber(4); // 接收数字指令
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

	//	// 设置页
	//	else if (!strcmp(current_page, "settings")) {
	//		command = getNumber(3); // 接收数字指令
	//		if (command == 0) {
	//			current_page = show_page("menu");
	//		}
	//	}

	//	// 某页
	//	else if (!strcmp(current_page, "")) {
	//		command = getNumber(1); // 接收数字指令
	//	}

	//	// 不存在的页面
	//	else {
	//		break;
	//	}
	//}

