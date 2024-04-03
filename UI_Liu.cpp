#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainLiu(void) {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出



	// 初始化图形窗口
	initgraph(1280, 810);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();




	//testUI();


	loginUI();







	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口





	return 0;
}


void allQualityUI() {
	cleardevice();


	Text titleText(20, 50, L"素质类项目", 64);
	Button searchBtn(-50, 190, 330, 60, L"   查询", 1);
	Button addBtn(-50, 280, 330, 60, L"   添加", 1);
	Button modifyBtn(-50, 370, 330, 60, L"   修改", 1);
	Button deleteBtn(-50, 460, 330, 60, L"   删除", 1);
	Button backButton(-50, 550, 330, 60, L"   返回", 0);


	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->

		if (peekmessage(&msg, -1, true)) {
			if (searchBtn.mouseClick(msg)) {
			}
			if (addBtn.mouseClick(msg)) {
			}
			if (modifyBtn.mouseClick(msg)) {
			}
			if (deleteBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg)) {
				menuUI();
			}
		}


		showxy(msg);



		//<-
		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}


}


void QualityUI() {
}

