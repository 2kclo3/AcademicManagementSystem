#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



bool showAllMajor(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm);

int mainLLLL(void) {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出



	// 初始化图形窗口
	initgraph(1280, 810);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();




	//testUI();


	//allStuUI();
	loginUI();







	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口





	return 0;
}


// 显示转专业管理专业
bool showAllMajor(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm) {
	List pCurrent = StuList->next; //从第一个有数据节点开始
	data.clear(); // 清空数组
	data.push_back(vector<wstring>(8, L"")); //增加一行(每行8列)

	//初始化表头
	data[0][0] = L"学号";
	data[0][1] = L"姓名";
	data[0][2] = L"性别";
	data[0][3] = L"年级";
	data[0][4] = L"学院";
	data[0][5] = L"专业";
	//data[0][6] = L"原学院";
	data[0][7] = L"原专业";



	int row = 1;
	while (pCurrent != NULL) { //遍历链表

		// 检测是否有搜索词
		if (wcsstr(std::to_wstring(pCurrent->item.data.ID).c_str(), searchTerm) != NULL // 数字转为字符串再转为wchar_t来进行比较
			|| wcsstr(pCurrent->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pCurrent->item.data.grade).c_str(), searchTerm) != NULL // 数字转为字符串再转为wchar_t来进行比较
			|| wcsstr(pCurrent->item.data.college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.major, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.original_college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.original_major, searchTerm) != NULL
			) {

			data.push_back(vector<std::wstring>(8, L"")); //增加一行(每行8列)

			//每行的内容
			data[row][0] = std::to_wstring(pCurrent->item.data.ID); //数字转为字符串
			data[row][1] = pCurrent->item.data.name;
			data[row][2] = (pCurrent->item.data.gender) ? L"男" : L"女";
			data[row][3] = std::to_wstring(pCurrent->item.data.grade); //数字转为字符串
			data[row][4] = pCurrent->item.data.college;
			data[row][5] = pCurrent->item.data.major;
			if (wcscmp(pCurrent->item.data.college, pCurrent->item.data.original_college) != 0 ||
				wcscmp(pCurrent->item.data.major, pCurrent->item.data.original_major) != 0) {
				//data[row][6] = pCurrent->item.data.original_college;
				data[row][7] = pCurrent->item.data.original_major;
			}

			row++; // 行数+1
		}

		pCurrent = pCurrent->next; // 移向下一个节点

	}

	return true;
}



void changeMajorUI() {
	cleardevice();

	//drawLine();


	List allStuList = readStu(STU_FILE);

	vector<vector<std::wstring>> allStuData;
	showAllMajor(allStuList, allStuData, L"");

	Table allStuTable(310, 90, 940, 700, allStuData);

	Text titleText(25, 50, L"转专业管理", 64);
	Text IDText(-500, 150, L"", 32);
	Text nameText(-500, 220, L"", 32);
	Text genderText(-500, 290, L"", 32);
	Text gradeText(-500, 360, L"", 32);
	Text collegeText(-500, 430, L"", 32);
	Text majorText(-500, 500, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox gradeBox(-500, 360, 290, L"年级", L"");
	TextBox collegeBox(-500, 430, 290, L"学院", L"");
	TextBox majorBox(-500, 500, 290, L"专业", L"");

	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);
	Button modifyBtn(-50, 190, 330, 60, L"   转专业", 1);
	Button sortBtn(-50, 280, 330, 60, L"   排序", 1);
	Button exportBtn(-50, 370, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 460, 330, 60, L"   导入", 1);
	Button backButton(-50, 580, 330, 60, L"   返回", 0);
	Button modifyOKButton(-500, 580, 290, 60, L"确定修改", 1);
	Button cancelButton(-500, 660, 290, 60, L"取消", 0);

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//-------------------------------------------------

		// 输入框绘制(必须)
		searchInputBox.draw();
		gradeBox.draw();
		collegeBox.draw();
		majorBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// 鼠标点击事件
			if (searchBtn.mouseClick(msg)) {
				showAllMajor(allStuList, allStuData, searchInputBox.text);
				allStuTable.setData(allStuData);
			}


			if (cancelButton.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"转专业管理");

				// 清除输入框内容
				gradeBox.clear();
				collegeBox.clear();
				majorBox.clear();

				// 使表格可变化
				allStuTable.canChange = true;

				// 隐藏
				IDText.move(-500, 150);
				nameText.move(-500, 220);
				genderText.move(-500, 290);
				IDText.move(-500, 150);
				gradeBox.move(-500, 360);
				collegeBox.move(-500, 430);
				majorBox.move(-500, 500);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// 显示
				modifyBtn.move(-50, 190);
				sortBtn.move(-50, 280);
				exportBtn.move(-50, 370);
				inportBtn.move(-50, 460);
				backButton.move(-50, 580);

			}


			if (modifyBtn.mouseClick(msg)) {
				// 获取当前行
				int selectedRow = allStuTable.getSelectedRow();
				vector<std::wstring> selectedData = allStuData[selectedRow];

				// 未选择学生
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else if (selectedData[7] != L"") {
					MessageBox(GetHWnd(), L"每位学生最多转一次专业，本学生已达最大转专业次数！", L"错误!", MB_ICONERROR);
				}
				else {
					// 更改标题
					titleText.setText(L"转专业管理");
					// 隐藏
					modifyBtn.move(-500, 310);
					sortBtn.move(-500, 470);
					exportBtn.move(-500, 550);
					inportBtn.move(-500, 630);
					backButton.move(-500, 730);


					// 使表格不可变化
					allStuTable.canChange = false;


					//// 获取当前行 //上面写了
					//int selectedRow = allStuTable.getSelectedRow();
					//vector<std::wstring> selectedData = allStuData[selectedRow];


					// 文本框默认内容
					IDText.setText((L"学号: " + selectedData[0]).c_str()); // C++语法
					nameText.setText((L"姓名: " + selectedData[1]).c_str());
					genderText.setText((L"性别: " + selectedData[2]).c_str());
					gradeBox.setText(selectedData[3].c_str());
					collegeBox.setText(selectedData[4].c_str());
					majorBox.setText(selectedData[5].c_str());

					// 显示
					IDText.move(20, 180);
					nameText.move(20, 235);
					genderText.move(20, 290);
					gradeBox.move(10, 360);
					collegeBox.move(10, 430);
					majorBox.move(10, 500);
					modifyOKButton.move(10, 580);
					cancelButton.move(10, 660);
				}

			}

			if (modifyOKButton.mouseClick(msg)) {
				int id;
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
					getNumberInBox(9999, &grade, gradeBox.text) &&
					getTextInBox(college, collegeBox.text) &&
					getTextInBox(major, majorBox.text) &&
					(grade > 1970 && grade <= Current_year)
					) {
					if (MessageBox(GetHWnd(), (wstring(L"确定将这个学生的专业由\"") + modifyingStu->item.data.original_college + L"\"的\"" + modifyingStu->item.data.original_major + L"\"转为\"" + college + L"\"的\"" + major + L"\"吗？").c_str(), L"转专业确认", MB_YESNO | MB_ICONQUESTION) == IDYES) {
						// 修改
						modifyStu(&allStuList, modifyingStu, modifyingStu->item.data.name, tempID, modifyingStu->item.data.gender, grade, college, major);

						// 保存
						saveStu(allStuList, STU_FILE);

						// 使表格可变化
						allStuTable.canChange = true;

						// 刷新表格
						showAllMajor(allStuList, allStuData, searchInputBox.text);
						allStuTable.setData(allStuData);

					}

					// 使表格可变化
					allStuTable.canChange = true;

					// 清除输入框内容
					gradeBox.clear();
					collegeBox.clear();
					majorBox.clear();


					// 更改标题
					titleText.setText(L"转专业管理");

					// 隐藏
					IDText.move(-500, 150);
					nameText.move(-500, 220);
					genderText.move(-500, 290);
					gradeBox.move(-500, 360);
					collegeBox.move(-500, 430);
					majorBox.move(-500, 500);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// 显示
					modifyBtn.move(-50, 190);
					sortBtn.move(-50, 280);
					exportBtn.move(-50, 370);
					inportBtn.move(-50, 460);
					backButton.move(-50, 580);



				}
				// 输入错误
				else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}


			if (sortBtn.mouseClick(msg)) {
				sortStu(&allStuList);

				// 保存
				saveStu(allStuList, STU_FILE);

				// 刷新表格
				showAllMajor(allStuList, allStuData, L"");
				allStuTable.setData(allStuData);
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


