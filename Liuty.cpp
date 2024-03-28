#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int mainAAAAA(void){ 
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出



	Cpnode  crs = readCrs(CRS_FILE);
	List stu = readStu(STU_FILE);


	// 初始化图形窗口
	initgraph(1280, 820);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();




	testUI();


	//loginUI();







	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口
	



	saveStu(stu, STU_FILE);
	saveCrs(crs, CRS_FILE);


	

	return 0;
}













