#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainJi(void) {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出
	// 初始化图形窗口
	initgraph(1280, 810);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();

	//testUI();

	//------------
	allStuUI();
	//------------



	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口
	return 0;
}


void allStuUI() {
	cleardevice();

	//drawLine();


	List allStuList = readStu(STU_FILE);

	vector<vector<std::wstring>> allStuData;
	showAllStu(allStuList, allStuData, L"");

	Table allStuTable(310, 90, 940, 700, allStuData);

	Text titleText(40, 50, L"所有学生", 64);
	Text IDText(-500, 150, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox IDBox(-500, 150, 290, L"学号 ( 添加后不可更改！)", L"");
	TextBox nameBox(-500, 220, 290, L"姓名", L"");
	TextBox genderBox(-500, 290, 290, L"性别 ( 女:0, 男:1 )", L"");
	TextBox gradeBox(-500, 360, 290, L"年级", L"");
	TextBox collegeBox(-500, 430, 290, L"学院", L"");
	TextBox majorBox(-500, 500, 290, L"专业", L"");

	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);
	Button addBtn(-50, 150, 330, 60, L"   添加", 1);
	Button modifyBtn(-50, 230, 330, 60, L"   修改", 1);
	Button deleteBtn(-50, 310, 330, 60, L"   删除", 1);
	Button sortBtn(-50, 390, 330, 60, L"   排序", 1);
	Button exportBtn(-50, 470, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 550, 330, 60, L"   导入", 1);
	Button backButton(-50, 650, 330, 60, L"   返回", 0);
	Button addOKButton(-500, 580, 290, 60, L"确定添加", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"确定修改", 1);
	Button cancelButton(-500, 660, 290, 60, L"取消", 0);

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
				showAllStu(allStuList, allStuData, searchInputBox.text);
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
						showAllStu(allStuList, allStuData, L"");
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


					// 获取当前行
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
					showAllStu(allStuList, allStuData, searchInputBox.text);
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
						showAllStu(allStuList, allStuData, searchInputBox.text);
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
				//freeAllStu(allStuList); //TODO
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

		showxy(msg); // 显示坐标



		//-------------------------------------------------
		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}
}


void StuUI() {
}

