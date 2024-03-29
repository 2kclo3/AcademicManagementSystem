#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int main00() {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出

	Cpnode  crs = readCrs(CRS_FILE);
	List stu = readStu(STU_FILE);
	
	 
	printStu(stu);
	return 0;
}
