#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainALJKSJA(void) {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出



	// 初始化图形窗口
	initgraph(1280, 810);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();




	//testUI();


	allStuUI();
	//loginUI();







	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口





	return 0;
}














