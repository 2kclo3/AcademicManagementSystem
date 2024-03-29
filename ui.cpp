#pragma warning(disable:4996)
#include "ui.h"
#define PAGE_FILE "Page.txt"




//wchar_t* show_page(wchar_t* page_name)
//{
//	system("cls");//清空控制台内容
//	FILE* fp = NULL;
//	fp = fopen(PAGE_FILE, "r");//以只读方式打开文件
//	if (fp == NULL) {
//		wprintf(L"Read %s errer, please check and reboot the system!", PAGE_FILE);
//		exit(EXIT_FAILURE);
//	}
//	//当读取失败时，要求检查和重启本系统
//
//	wchar_t start_tag[30], end_tag[30];
//	swprintf(start_tag, L"%s<<<", page_name);
//	swprintf(end_tag, L">>>%s", page_name);//创建寻找的开始和结束标签
//
//	bool start_found = 0;
//	wchar_t line[512];
//	while (fgetws(line, sizeof(line), fp) != NULL) {//一行一行寻找标签并打印
//		if (_tcsstr(line, start_tag) != NULL) {
//			start_found = 1;
//			continue;
//		}//找到开始标签，跳过，从下一行开始打印
//		if (_tcsstr(line, end_tag) != NULL) {
//			break;
//		}//找到结束标签，结束循环
//		if (start_found == 1) {
//			wprintf(L"%s", line);
//		}//打印当前行
//	}
//
//	fclose(fp);//关闭文件
//	return page_name;
//
//}


void printStu(const List StuList) {

	List pStu = StuList->next; // 从头结点的下一个节点开始
	while (pStu != NULL) {
		wprintf(L"学生信息:\n%d\t%s\t%d\t%d\t%s\t%s\n\n课程：\n",
			pStu->item.data.ID,
			pStu->item.data.name,
			pStu->item.data.gender,
			pStu->item.data.grade,
			pStu->item.data.college,
			pStu->item.data.major);

		Crsnode* pcrs = pStu->item.crslist->crs_next; // 从下一个课程节点开始
		while (pcrs != NULL) {
			wprintf(L"%s\t%s\t%.1lf\t%d\t%d\t%.1lf\t%.1lf\n",
				pcrs->score.course_id,
				pcrs->score.course_name,
				pcrs->score.score,
				pcrs->score.semester,
				pcrs->score.course_nature,
				pcrs->score.credit,
				pcrs->score.grid);

			pcrs = pcrs->crs_next; // 移动到下一个节点
		}

		wprintf(L"\n科研成果：\n");
		Rnode* pres = pStu->item.rlist->rnext; // 从下一个科研成果节点开始
		while (pres != NULL) {
			wprintf(L"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.2lf\n",
				pres->research.paper_name,
				pres->research.journal_or_conference_name,
				pres->research.author,
				pres->research.date,
				pres->research.volume_num,
				pres->research.issue_num,
				pres->research.page,
				pres->research.GPA_bonus);

			pres = pres->rnext; // 移动到下一个节点
		}


		wprintf(L"\n竞赛获奖：\n");
		Cnode* pcpt = pStu->item.clist->cnext; // 从下一个竞赛获奖节点开始
		while (pcpt != NULL) {
			wprintf(L"%s\t%s\t%s\t%s\t%.2lf\n",
				pcpt->competition.competition_name,
				pcpt->competition.organizer,
				pcpt->competition.category,
				pcpt->competition.date,
				pcpt->competition.GPA_bonus);

			pcpt = pcpt->cnext; // 移动到下一个节点
		}


		wprintf(L"\n--------------------------------------------------------------------------\n\n");
		pStu = pStu->next; // 移动到下一个节点
	}


}




void printCrs(const Cpnode CrsList) {
	Cpnode pCrs = CrsList->next; // 从头结点的下一个节点开始
	while (pCrs != NULL) {
		wprintf(L"课程信息:\n%d\t%s\t%d\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\n学生：\n",
			pCrs->cnum,
			pCrs->cname,
			pCrs->character,
			pCrs->headcount,
			pCrs->totscore,
			pCrs->averscore,
			pCrs->totGPA,
			pCrs->averGPA); // 写入

		Spnode pstu = pCrs->sphead->next; // 从下一个学生节点开始
		while (pstu != NULL) {
			wprintf(L"%d\t%s\t%.1lf\t%.1lf\n",
				pstu->snum,
				pstu->sname,
				pstu->score,
				pstu->GPA); // 写入

			pstu = pstu->next; // 移动到下一个节点
		}
		wprintf(L"\n--------------------------------------------------------------------------\n\n");
		pCrs = pCrs->next; // 移动到下一个节点
	}
}







void drawLine() {
	setlinecolor(0x777777);
	for (int i = 0; i <= 1280; i += 50) {
		line(0, i, 1280, i);
		line(i, 0, i, 850);
	}
}

void showxy(ExMessage& msg) {

	wchar_t text[50];
	swprintf(text, L"x:%d, y:%d", msg.x, msg.y);
	setfillcolor(BLACK);
	solidrectangle(0, 0, 220, 36);

	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(32, 0, L"微软雅黑");
	outtextxy(0, 0, text);



}


void testUI() {
	//drawLine();


	// 创建按钮对象并绘制
	//Button button1(-50, 100, 300, 50, L"测试按钮", 0x00009688, WHITE);
	//Text text1(100, 0, L"测试 Test", 50, BLACK);
	//Button button2(-50, 160, 300, 50, L"测试按钮", 0x123456, WHITE);
	Button exitButton(50, 500, 200, 60, L"退出", LIGHTBLUE, WHITE);
	Button selectRowBtn1(350, 400, 300, 60, L"选择的行数", 0x123456, WHITE);

	//TextBox box1(50, 250, 500, L"测试1", L"ceshi");
	//TextBox box2(90, 400, 800, L"测试2", L"");



	Table table1(300, 100, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"学号",L"姓名",L"性别",L"成绩"},
			{L"2023001",L"张三",L"男",L"6000"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023003",L"王五",L"男",L"90"},
			{L"2023004",L"小红",L"女",L"80"},
			{L"2023005",L"小黑",L"男",L"70"},
			{L"2023006",L"小白",L"男",L"60"},
			{L"2023007",L"小黑",L"男",L"70"},
			{L"2023008",L"王五",L"男",L"60"},
			{L"2023009",L"王五",L"女",L"40"},
			{L"2023010",L"王五666",L"男",L"30"},
			{L"2023011",L"王五",L"男",L"20"},
			{L"2023012",L"王五",L"女",L"10"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023012",L"王五",L"女",L"10"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三777",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五888",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三999",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"Last",L"女",L"100"},
		}
	);

	Table table2(700, 50, 400, 720, RGB(55, 61, 53), WHITE,
		{
			{L"学号",L"姓名",L"性别",L"成绩"},
			{L"2023001",L"张三",L"男",L"6000"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023003",L"王五",L"男",L"90"},
			{L"2023004",L"小红",L"女",L"80"},
			{L"2023005",L"小黑",L"男",L"70"},
			{L"2023006",L"小白",L"男",L"60"},
			{L"2023007",L"小黑",L"男",L"70"},
			{L"2023008",L"王五",L"男",L"60"},
			{L"2023009",L"王五",L"女",L"40"},
			{L"2023010",L"王五666",L"男",L"30"},
			{L"2023011",L"王五",L"男",L"20"},
			{L"2023012",L"王五",L"女",L"10"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023012",L"王五",L"女",L"10"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三777",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五888",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三999",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023013",L"王五",L"男",L"80"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023014",L"王五",L"女",L"90"},
			{L"2023015",L"王五",L"女",L"100"},
			{L"2023001",L"张三",L"男",L"60"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023015",L"Last",L"女",L"100"},
		}
	);


	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//box1.draw();
		//box2.draw();

		if (peekmessage(&msg, -1, true)) {


			//box1.onMessage(msg);
			//box2.onMessage(msg);
			//if (button1.mouseClick(msg)) {
			//	wprintf(L"press button1\n");
			//	wprintf(L"box1 is:%s\n", box1.text);
			//}
			if (selectRowBtn1.mouseClick(msg)) {
				printf("%d\n", table1.getSelectedRow());
			}
			if (exitButton.mouseClick(msg)) {
				exit(0);
			}
			table1.onScrollandClick(msg);
			table2.onScrollandClick(msg);
			////box1.onMessage(msg);
			////box2.onMessage(msg);
		}

		showxy(msg);


		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}
	}





}


void loginUI() {
	cleardevice();



	//drawLine();


	Text titleText(200, 100, L"你好，请登录!", 64, RGB(228, 226, 223));
	TextBox accountBox(200, 300, 880, L"账号", L"");
	TextBox passwordBox(200, 400, 880, L"密码", L"");
	Button loginButton(200, 500, 420, 60, L"登录", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exitButton(660, 500, 420, 60, L"退出", RGB(73, 78, 70), RGB(200, 198, 195));

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		accountBox.draw();
		passwordBox.draw();

		if (peekmessage(&msg, -1, true)) {
			accountBox.onMessage(msg);
			passwordBox.onMessage(msg);
			if (loginButton.mouseClick(msg)) {
				wprintf(L"Account:%s\nPassword:%s\n", accountBox.text, passwordBox.text);
				menuUI();
			}
			if (exitButton.mouseClick(msg)) {
				exit(0);
			}
		}

		showxy(msg);



		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}
	}






}


void menuUI() {
	cleardevice();


	//drawLine();

	Text titleText(90, 50, L"欢迎", 64, RGB(228, 226, 223));
	Button allStuButton(-50, 170, 350, 60, L"  查看学生", RGB(191, 202, 185), RGB(42, 51, 40));
	Button allCrsButton(-50, 250, 350, 60, L"  查看课程", RGB(191, 202, 185), RGB(42, 51, 40));
	Button allQualityButton(-50, 330, 350, 60, L"  素质类项目管理", RGB(191, 202, 185), RGB(42, 51, 40));
	Button changeMajorButton(-50, 410, 350, 60, L"  转专业管理", RGB(191, 202, 185), RGB(42, 51, 40));
	Button settingsButton(-50, 490, 350, 60, L"  设置", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exitButton(-50, 580, 350, 60, L"  退出登录", RGB(73, 78, 70), RGB(200, 198, 195));

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();

		if (peekmessage(&msg, -1, true)) {
			if (allStuButton.mouseClick(msg)) {
				allStuUI();
			}
			if (allCrsButton.mouseClick(msg)) {
				allCrsUI();
			}
			if (allQualityButton.mouseClick(msg)) {
				allQualityUI();
			}
			if (changeMajorButton.mouseClick(msg)) {
				changeMajorUI();
			}
			if (settingsButton.mouseClick(msg)) {
				settingsUI();
			}
			if (exitButton.mouseClick(msg)) {
				loginUI();
			}
		}

		showxy(msg);




		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}
	}







}


void allStuUI() {
	cleardevice();

	drawLine();


	Text titleText(40, 50, L"所有学生", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   查询学生", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   添加", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   删除", RGB(191, 202, 185), RGB(42, 51, 40));
	Button sortBtn(-50, 460, 330, 60, L"   排序", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 540, 330, 60, L"   导出", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 620, 330, 60, L"   导入", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 700, 330, 60, L"   返回", RGB(73, 78, 70), RGB(200, 198, 195));


	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->

		if (peekmessage(&msg, -1, true)) {
			if (searchBtn.mouseClick(msg)) {

				//// 后续将修改输入方式
				//wchar_t stuID[512];
				//InputBox(stuID, 512, L"请输入学号", L"查询学生", L"", 0, 0, false);
				printStu(readStu(".\\data\\Student.txt"));

			}
			if (addBtn.mouseClick(msg)) {
			}
			if (modifyBtn.mouseClick(msg)) {
			}
			if (deleteBtn.mouseClick(msg)) {
			}
			if (sortBtn.mouseClick(msg)) {
			}
			if (exportBtn.mouseClick(msg)) {
			}
			if (inportBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg)) {
				menuUI();
			}
		}

		showxy(msg);



		//<-
		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}
}


void allCrsUI() {
	cleardevice();

	drawLine();


	Text titleText(40, 50, L"所有课程", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   查询课程", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   添加课程", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   删除", RGB(191, 202, 185), RGB(42, 51, 40));
	Button statisticBtn(-50, 460, 330, 60, L"   统计", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 540, 330, 60, L"   导出", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 620, 330, 60, L"   导入", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 700, 330, 60, L"   返回", RGB(73, 78, 70), RGB(200, 198, 195));


	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->

		if (peekmessage(&msg, -1, true)) {
			if (searchBtn.mouseClick(msg)) {
				printCrs(readCrs(".\\data\\Course.txt"));
			}
			if (addBtn.mouseClick(msg)) {
			}
			if (modifyBtn.mouseClick(msg)) {
			}
			if (deleteBtn.mouseClick(msg)) {
			}
			if (statisticBtn.mouseClick(msg)) {
			}
			if (exportBtn.mouseClick(msg)) {
			}
			if (inportBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg)) {
				menuUI();
			}
		}

		showxy(msg);




		//<-
		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}

}


void StuUI() {
}


void allQualityUI() {
	cleardevice();

	drawLine();


	Text titleText(20, 50, L"素质类项目", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 190, 330, 60, L"   查询", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 280, 330, 60, L"   添加", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 370, 330, 60, L"   修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 460, 330, 60, L"   删除", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 550, 330, 60, L"   返回", RGB(73, 78, 70), RGB(200, 198, 195));


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
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}


}


void changeMajorUI() {


}


void CrsUI() {
}


void settingsUI() {

	cleardevice();

	drawLine();


	Text titleText(90, 50, L"设置", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   查询课程", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   添加课程", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   删除", RGB(191, 202, 185), RGB(42, 51, 40));
	Button statisticBtn(-50, 460, 330, 60, L"   统计", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 540, 330, 60, L"   导出", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 620, 330, 60, L"   导入", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 700, 330, 60, L"   返回", RGB(73, 78, 70), RGB(200, 198, 195));


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
			if (statisticBtn.mouseClick(msg)) {
			}
			if (exportBtn.mouseClick(msg)) {
			}
			if (inportBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg)) {
				menuUI();
			}
		}

		showxy(msg);



		//<-
		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}


}


void QualityUI() {
}






