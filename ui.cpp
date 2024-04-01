#pragma warning(disable:4996)
#include "ui.h"
#define PAGE_FILE "Page.txt"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



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
		wprintf(L"课程信息:\n%d\t%s\t%s\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\n学生：\n",
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
	Button selectRowBtn1(350, 500, 300, 60, L"选择的行数", 0x123456, WHITE);

	//TextBox box1(50, 250, 500, L"测试1", L"ceshi");
	//TextBox box2(90, 400, 800, L"测试2", L"");


	TextBox selectBox(280, 400, 300, L"哪个表格", L"");

	Table table1(360, 100, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"1学号",L"姓名",L"性别",L"成绩"},
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

	Table table3(30, 150, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"3学号",L"姓名",L"性别",L"成绩"},
			{L"2023001",L"张三",L"男",L"6000"},
			{L"2023002",L"李四",L"男",L"50"},
			{L"2023003",L"王五",L"男",L"90"},
			{L"2023015",L"Last",L"女",L"100"},
		}
	);

	Table table2(700, 50, 450, 720, RGB(55, 61, 53), WHITE,
		{
			{L"2学号",L"姓名",L"性别",L"成绩", L"test1", L"test0333"},
			{L"2023001",L"张三",L"男",L"6000", L"test222"},
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
		selectBox.draw();

		if (peekmessage(&msg, -1, true)) {


			//box1.onMessage(msg);
			//box2.onMessage(msg);
			//if (button1.mouseClick(msg)) {
			//	wprintf(L"press button1\n");
			//	wprintf(L"box1 is:%s\n", box1.text);
			//}
			if (selectRowBtn1.mouseClick(msg)) {
				if (!wcscmp(selectBox.text, L"1")) {
					printf("%d\n", table1.getSelectedRow());
				}
				else if (!wcscmp(selectBox.text, L"2")) {
					printf("%d\n", table2.getSelectedRow());
				}
				else if (!wcscmp(selectBox.text, L"3")) {
					printf("%d\n", table3.getSelectedRow());
				}

			}
			if (exitButton.mouseClick(msg)) {
				exit(0);
			}
			table1.onMouse(msg);
			table2.onMouse(msg);
			table3.onMouse(msg);
			////box1.onMessage(msg);
			////box2.onMessage(msg);
			selectBox.onMessage(msg);
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

	//drawLine();


	List allStuList = readStu(STU_FILE);

	vector<vector<std::wstring>> allStuData;
	showAllStuTest(allStuList, allStuData, L"");

	Table allStuTable(310, 90, 940, 700, RGB(55, 61, 53), WHITE, allStuData);

	Text titleText(40, 50, L"所有学生", 64, RGB(228, 226, 223));
	Text IDText(-500, 150, L"", 32, WHITE);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox IDBox(-500, 150, 290, L"学号(不可更改)", L"");
	TextBox nameBox(-500, 220, 290, L"姓名", L"");
	TextBox genderBox(-500, 290, 290, L"性别 (女:0,男:1)", L"");
	TextBox gradeBox(-500, 360, 290, L"年级", L"");
	TextBox collegeBox(-500, 430, 290, L"学院", L"");
	TextBox majorBox(-500, 500, 290, L"专业", L"");

	Button searchBtn(1150, 20, 100, 50, L"搜索", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 150, 330, 60, L"   添加", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 230, 330, 60, L"   修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 310, 330, 60, L"   删除", RGB(191, 202, 185), RGB(42, 51, 40));
	Button sortBtn(-50, 390, 330, 60, L"   排序", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 470, 330, 60, L"   导出", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 550, 330, 60, L"   导入", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 650, 330, 60, L"   返回", RGB(73, 78, 70), RGB(200, 198, 195));
	Button addOKButton(-500, 580, 290, 60, L"确定添加", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyOKButton(-500, 580, 290, 60, L"确定修改", RGB(191, 202, 185), RGB(42, 51, 40));
	Button cancelButton(-500, 660, 290, 60, L"取消", RGB(73, 78, 70), RGB(200, 198, 195));

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//-------------------------------------------------

		// 输入框绘制(必须)
		searchInputBox.draw();
		IDBox.draw();
		nameBox.draw();
		genderBox.draw();
		gradeBox.draw();
		collegeBox.draw();
		majorBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// 鼠标点击事件
			if (searchBtn.mouseClick(msg)) {
				showAllStuTest(allStuList, allStuData, searchInputBox.text);
				allStuTable.setData(allStuData);
			}

			if (addBtn.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"添加学生");
				// 隐藏
				addBtn.move(-500, 150);
				modifyBtn.move(-500, 230);
				deleteBtn.move(-500, 310);
				sortBtn.move(-500, 390);
				exportBtn.move(-500, 470);
				inportBtn.move(-500, 550);
				backButton.move(-500, 650);

				// 显示
				IDBox.move(10, 150);
				nameBox.move(10, 220);
				genderBox.move(10, 290);
				gradeBox.move(10, 360);
				collegeBox.move(10, 430);
				majorBox.move(10, 500);
				addOKButton.move(10, 580);
				cancelButton.move(10, 660);
			}

			if (cancelButton.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"所有学生");

				// 清除输入框内容
				IDBox.clear();
				nameBox.clear();
				genderBox.clear();
				gradeBox.clear();
				collegeBox.clear();
				majorBox.clear();

				// 使表格可变化
				allStuTable.canChange = true;

				// 隐藏
				IDBox.move(-500, 150);
				IDText.move(-500, 150);
				nameBox.move(-500, 220);
				genderBox.move(-500, 290);
				gradeBox.move(-500, 360);
				collegeBox.move(-500, 430);
				majorBox.move(-500, 500);
				addOKButton.move(-500, 580);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// 显示
				addBtn.move(-50, 150);
				modifyBtn.move(-50, 230);
				deleteBtn.move(-50, 310);
				sortBtn.move(-50, 390);
				exportBtn.move(-50, 470);
				inportBtn.move(-50, 550);
				backButton.move(-50, 650);

			}

			if (addOKButton.mouseClick(msg)) {
				int id;
				wchar_t name[30];
				int gender;
				int grade;
				wchar_t college[50];
				wchar_t major[50];

				// 获取当前年份(判断年级要用)
				time_t Current_time = time(NULL);
				int Current_year = localtime(&Current_time)->tm_year + 1900;

				// 判断输入格式
				if (
					getNumberInBox(99999999, &id, IDBox.text) &&
					getTextInBox(name, nameBox.text) &&
					getNumberInBox(1, &gender, genderBox.text) &&
					getNumberInBox(9999, &grade, gradeBox.text) &&
					getTextInBox(college, collegeBox.text) &&
					getTextInBox(major, majorBox.text) &&
					(id > 9999999 && id < 100000000) &&
					(grade > 1970 && grade <= Current_year)
					) {

					// 学号相同的情况,报错提醒
					if (!addStu(&allStuList, name, id, gender, grade, college, major)) {
						MessageBox(GetHWnd(), L"该学生已经存在,请勿重复添加!", L"错误!", MB_ICONERROR);
					}
					// 否则保存
					else {
						// 保存
						saveStu(allStuList, STU_FILE);

						// 刷新表格
						showAllStuTest(allStuList, allStuData, searchInputBox.text);
						allStuTable.setData(allStuData);

						// 清除输入框内容
						IDBox.clear();
						nameBox.clear();
						genderBox.clear();
						gradeBox.clear();
						collegeBox.clear();
						majorBox.clear();


						// 更改标题
						titleText.setText(L"所有学生");

						// 隐藏
						IDBox.move(-500, 150);
						nameBox.move(-500, 220);
						genderBox.move(-500, 290);
						gradeBox.move(-500, 360);
						collegeBox.move(-500, 430);
						majorBox.move(-500, 500);
						addOKButton.move(-500, 580);
						cancelButton.move(-500, 660);

						// 显示
						addBtn.move(-50, 150);
						modifyBtn.move(-50, 230);
						deleteBtn.move(-50, 310);
						sortBtn.move(-50, 390);
						exportBtn.move(-50, 470);
						inportBtn.move(-50, 550);
						backButton.move(-50, 650);

					}


				}
				// 输入错误
				else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (modifyBtn.mouseClick(msg)) {
				// 未选择学生
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else {
					// 更改标题
					titleText.setText(L"修改学生");
					// 隐藏
					addBtn.move(-500, 150);
					modifyBtn.move(-500, 230);
					deleteBtn.move(-500, 310);
					sortBtn.move(-500, 390);
					exportBtn.move(-500, 470);
					inportBtn.move(-500, 550);
					backButton.move(-500, 650);


					// 使表格不可变化
					allStuTable.canChange = false;


					// 获取当前列
					int selectedRow = allStuTable.getSelectedRow();
					vector<std::wstring> selectedData = allStuData[selectedRow];


					// 文本框默认内容
					IDText.setText((L"学号:" + selectedData[0]).c_str()); // C++语法
					nameBox.setText(selectedData[1].c_str());
					genderBox.setText(wcscmp(selectedData[2].c_str(), L"男") ? L"0" : L"1");
					gradeBox.setText(selectedData[3].c_str());
					collegeBox.setText(selectedData[4].c_str());
					majorBox.setText(selectedData[5].c_str());

					// 显示
					IDText.move(20, 180);
					nameBox.move(10, 220);
					genderBox.move(10, 290);
					gradeBox.move(10, 360);
					collegeBox.move(10, 430);
					majorBox.move(10, 500);
					modifyOKButton.move(10, 580);
					cancelButton.move(10, 660);
				}

			}

			if (modifyOKButton.mouseClick(msg)) {
				int id;
				wchar_t name[30];
				int gender;
				int grade;
				wchar_t college[50];
				wchar_t major[50];

				// 获取当前年份(判断年级要用)
				time_t Current_time = time(NULL);
				int Current_year = localtime(&Current_time)->tm_year + 1900;

				// 精确搜索学生节点
				int tempID;
				int selectedRow = allStuTable.getSelectedRow(); // 获取当前列
				getNumberInBox(99999999, &tempID, allStuData[selectedRow][0].c_str());
				Node* modifyingStu = searchStu(&allStuList, (wchar_t*)allStuData[selectedRow][1].c_str(), tempID);

				// 判断输入格式
				if (
					getTextInBox(name, nameBox.text) &&
					getNumberInBox(1, &gender, genderBox.text) &&
					getNumberInBox(9999, &grade, gradeBox.text) &&
					getTextInBox(college, collegeBox.text) &&
					getTextInBox(major, majorBox.text) &&
					(grade > 1970 && grade <= Current_year)
					) {

					// 修改
					modifyStu(&allStuList, modifyingStu, name, tempID, gender, grade, college, major);

					// 保存
					saveStu(allStuList, STU_FILE);

					// 使表格可变化
					allStuTable.canChange = true;

					// 刷新表格
					showAllStuTest(allStuList, allStuData, searchInputBox.text);
					allStuTable.setData(allStuData);

					// 清除输入框内容
					IDBox.clear();
					nameBox.clear();
					genderBox.clear();
					gradeBox.clear();
					collegeBox.clear();
					majorBox.clear();


					// 更改标题
					titleText.setText(L"所有学生");

					// 隐藏
					IDBox.move(-500, 150);
					nameBox.move(-500, 220);
					genderBox.move(-500, 290);
					gradeBox.move(-500, 360);
					collegeBox.move(-500, 430);
					majorBox.move(-500, 500);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// 显示
					addBtn.move(-50, 150);
					modifyBtn.move(-50, 230);
					deleteBtn.move(-50, 310);
					sortBtn.move(-50, 390);
					exportBtn.move(-50, 470);
					inportBtn.move(-50, 550);
					backButton.move(-50, 650);



				}
				// 输入错误
				else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (deleteBtn.mouseClick(msg)) {
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else {
					int result = MessageBox(GetHWnd(), L"确定删除这个学生吗?", L"删除学生", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) { // 点击确定

						// 获取当前年份(判断年级要用)
						time_t Current_time = time(NULL);
						int Current_year = localtime(&Current_time)->tm_year + 1900;

						// 精确搜索学生节点
						int tempID;
						int selectedRow = allStuTable.getSelectedRow(); // 获取当前列
						getNumberInBox(99999999, &tempID, allStuData[selectedRow][0].c_str());
						Node* deletingStu = searchStu(&allStuList, (wchar_t*)allStuData[selectedRow][1].c_str(), tempID);

						// 删除
						deleteStu(&allStuList, deletingStu);

						// 保存
						saveStu(allStuList, STU_FILE);


						// 刷新表格
						showAllStuTest(allStuList, allStuData, searchInputBox.text);
						allStuTable.setData(allStuData);
					}
				}
			}

			if (sortBtn.mouseClick(msg)) {
				//TODO
			}

			if (exportBtn.mouseClick(msg)) {
				//TODO
			}

			if (inportBtn.mouseClick(msg)) {
				//TODO
			}

			if (backButton.mouseClick(msg)) {
				free(allStuList); //TODO
				menuUI();
			}


			//表格鼠标滑动与点击
			allStuTable.onMouse(msg);

			// 文本框输入
			searchInputBox.onMessage(msg);
			IDBox.onMessage(msg);
			nameBox.onMessage(msg);
			genderBox.onMessage(msg);
			gradeBox.onMessage(msg);
			collegeBox.onMessage(msg);
			majorBox.onMessage(msg);
		}

		//showxy(msg); // 显示坐标



		//-------------------------------------------------
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









bool showAllStuTest(const List StuList, vector<vector<std::wstring>>& data, const wchar_t* searchTerm) {
	List pCurrent = StuList->next; //从第一个有数据节点开始
	data.clear(); // 清空数组
	data.push_back(vector<std::wstring>(6, L"")); //增加一行(每行6列)

	//初始化表头
	data[0][0] = L"学号";
	data[0][1] = L"姓名";
	data[0][2] = L"性别";
	data[0][3] = L"年级";
	data[0][4] = L"学院";
	data[0][5] = L"专业";


	int row = 1;
	while (pCurrent != NULL) { //遍历链表
		//if (searchTerm != NULL) {

		// 检测是否有搜索词
		if (wcsstr(std::to_wstring(pCurrent->item.data.ID).c_str(), searchTerm) != NULL // 数字转为字符串再转为wchar_t来进行比较
			|| wcsstr(pCurrent->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pCurrent->item.data.grade).c_str(), searchTerm) != NULL // 数字转为字符串再转为wchar_t来进行比较
			|| wcsstr(pCurrent->item.data.college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.major, searchTerm) != NULL
			) {

			data.push_back(vector<std::wstring>(6, L"")); //增加一行(每行6列)

			//每行的内容
			data[row][0] = std::to_wstring(pCurrent->item.data.ID); //数字转为字符串
			data[row][1] = pCurrent->item.data.name;
			data[row][2] = (pCurrent->item.data.gender) ? L"男" : L"女";
			data[row][3] = std::to_wstring(pCurrent->item.data.grade); //数字转为字符串
			data[row][4] = pCurrent->item.data.college;
			data[row][5] = pCurrent->item.data.major;

			row++; // 行数+1
		}

		pCurrent = pCurrent->next; // 移向下一个节点

	}

	return true;
}





