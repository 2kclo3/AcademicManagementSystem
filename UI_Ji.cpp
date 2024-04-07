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
	Text nameText(-500, 220, L"", 32);
	Text genderText(-500, 290, L"", 32);
	Text gradeText(-500, 360, L"", 32);
	Text collegeText(-500, 430, L"", 32);
	Text majorText(-500, 500, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox IDBox(-500, 150, 290, L"学号 ( 添加后不可更改！)", L"");
	TextBox nameBox(-500, 220, 290, L"姓名", L"");
	TextBox genderBox(-500, 290, 290, L"性别 ( 女:0, 男:1 )", L"");
	TextBox gradeBox(-500, 360, 290, L"年级", L"");
	TextBox collegeBox(-500, 430, 290, L"学院", L"");
	TextBox majorBox(-500, 500, 290, L"专业", L"");
	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);
	Button lookBtn(-50, 150, 330, 60, L"   学生课程", 1);//
	Button lookcancelBtn(-500, 150, 290, 60, L"   返回主页面", 1);
	Button addBtn(-50, 230, 330, 60, L"   添加", 1);//
	Button modifyBtn(-50, 310, 330, 60, L"   修改", 1);
	Button deleteBtn(-50, 390, 330, 60, L"   删除", 1);
	Button sortBtn(-50, 470, 330, 60, L"   排序", 1);
	Button exportBtn(-50, 550, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 630, 330, 60, L"   导入", 1);
	Button backButton(-50, 730, 330, 60, L"   返回", 0);
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
				lookBtn.move(-500, 150);
				addBtn.move(-500, 230);
				modifyBtn.move(-500, 310);
				deleteBtn.move(-500, 390);
				sortBtn.move(-500, 470);
				exportBtn.move(-500, 550);
				inportBtn.move(-500, 630);
				backButton.move(-500, 730);

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

			if (lookBtn.mouseClick(msg)) {

				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else {
					wchar_t cname[30];
					int cid;
					int selectedRow = allStuTable.getSelectedRow();
					getNumberInBox(99999999,&cid, allStuData[selectedRow][0].c_str());
					getTextInBox(cname, allStuData[selectedRow][1].c_str());
					Node* Crs = searchStu(&allStuList, cname, cid);
					StuUI(Crs, allStuList);

					//	// 隐藏
					//	lookBtn.move(-500, 150);
					//	addBtn.move(-500, 230);
					//	modifyBtn.move(-500, 310);
					//	deleteBtn.move(-500, 390);
					//	sortBtn.move(-500, 470);
					//	exportBtn.move(-500, 550);
					//	inportBtn.move(-500, 630);
					//	backButton.move(-500, 730);

					//	// 获取当前行
					//	int selectedRow = allStuTable.getSelectedRow();
					//	vector<std::wstring> selectedData = allStuData[selectedRow];

					//	// 使表格不可变化
					//	allStuTable.canChange = false;

					//	// 文本框默认内容
					//	IDText.setText((L"学号:" + selectedData[0]).c_str()); // C++语法
					//	nameText.setText((L"姓名:"+ selectedData[1]).c_str());
					//	genderText.setText((L"性别:"+selectedData[2]).c_str());
					//	gradeText.setText((L"年级:" + selectedData[3]).c_str());
					//	collegeText.setText((L"学院:" + selectedData[4]).c_str());
					//	majorText.setText((L"专业:" + selectedData[5]).c_str());

					//	//显示
					//	IDText.move(10, 150);
					//	nameText.move(10, 220);
					//	genderText.move(10, 290);
					//	gradeText.move(10, 360);
					//	collegeText.move(10, 430);
					//	majorText.move(10, 500);
					//	lookcancelBtn.move(10, 570);
				}

			}

			//if (lookcancelBtn.mouseClick(msg)) {

				//// 更改标题
				//titleText.setText(L"所有学生");

				//// 使表格可变化
				//allStuTable.canChange = true;

				////隐藏
				//IDText.move(-500, 150);
				//nameText.move(-500, 220);
				//genderText.move(-500, 290);
				//gradeText.move(-500, 360);
				//collegeText.move(-500, 430);
				//majorText.move(-500, 500);
				//lookcancelBtn.move(-500, 570);

				//// 显示
				//lookBtn.move(-50, 150);
				//addBtn.move(-50, 230);
				//modifyBtn.move(-50, 310);
				//deleteBtn.move(-50, 390);
				//sortBtn.move(-50, 470);
				//exportBtn.move(-50, 550);
				//inportBtn.move(-50, 630);
				//backButton.move(-50, 730);
		//}

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
				lookBtn.move(-50, 150);
				addBtn.move(-50, 230);
				modifyBtn.move(-50, 310);
				deleteBtn.move(-50, 390);
				sortBtn.move(-50, 470);
				exportBtn.move(-50, 550);
				inportBtn.move(-50, 630);
				backButton.move(-50, 730);

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
						lookBtn.move(-50, 150);
						addBtn.move(-50, 230);
						modifyBtn.move(-50, 310);
						deleteBtn.move(-50, 390);
						sortBtn.move(-50, 470);
						exportBtn.move(-50, 550);
						inportBtn.move(-50, 630);
						backButton.move(-50, 730);

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
					lookBtn.move(-500, 150);
					addBtn.move(-500, 230);
					modifyBtn.move(-500, 310);
					deleteBtn.move(-500, 390);
					sortBtn.move(-500, 470);
					exportBtn.move(-500, 550);
					inportBtn.move(-500, 630);
					backButton.move(-500, 730);


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
					lookBtn.move(-50, 150);
					addBtn.move(-50, 230);
					modifyBtn.move(-50, 310);
					deleteBtn.move(-50, 390);
					sortBtn.move(-50, 470);
					exportBtn.move(-50, 550);
					inportBtn.move(-50, 630);
					backButton.move(-50, 730);



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
				sortStu(&allStuList);

				// 刷新表格
				showAllStu(allStuList, allStuData, L"");
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



	void StuUI(Node* Crs,List allStuList) {


		cleardevice();
		Crsnode* allCrsInStuList = Crs->item.crslist->crs_next;
		vector<vector<std::wstring>>allCrsINStuData;
		showStu(Crs, allCrsINStuData, L"");

		Table allCrsINStuTable(310, 90, 940, 700, allCrsINStuData);


		//输入框
		TextBox searchInputBox(310, 20, 820, L"搜索", L"");

		TextBox course_idBox(-500, 100, 290, L"课程编号", L"");
		TextBox course_nameBox(-500, 150, 290, L"课程名字", L"");
		TextBox scoreBox(-500, 220, 290, L"成绩", L"");
		TextBox course_natureBox(-500, 250, 290, L"课程性质", L"");
		TextBox creditBox(-500, 300, 290, L"学分", L"");
		TextBox gridBox(-500, 350, 290, L"绩点", L"");
		TextBox semesterBox(-500, 400, 290, L"学期", L"");//////////////////////////////////////


		//按钮
		Button searchBtn(1150, 20, 100, 50, L"搜索", 1);

		Button addCrsBtn(-50, 220, 330, 60, L"   添加课程", 1);
		Button modifyCrsBtn(-50, 300, 330, 60, L"   修改课程", 1);
		Button deleteCrsBtn(-50, 380, 330, 60, L"   删除课程", 1);
		Button backButton(-50, 700, 330, 60, L"   返回", 0);

		Button addOKButton(-500, 580, 290, 60, L"确定添加", 1);
		Button modifyOKButton(-500, 580, 290, 60, L"确定修改", 1);
		Button cancelButton(-500, 660, 290, 60, L"取消", 0);

		// 处理鼠标事件
		ExMessage msg;
		while (!_kbhit()) {
			ULONGLONG start_time = GetTickCount();
			//-------------------------------------------------

			searchInputBox.draw();

			course_idBox.draw();
			course_nameBox.draw();
			scoreBox.draw();
			course_natureBox.draw();
			creditBox.draw();
			gridBox.draw();
			semesterBox.draw();/////////////////////////////


			if (peekmessage(&msg, -1, true)) {
				//鼠标点击事件

				//搜索
				if (searchBtn.mouseClick(msg)) {
					showStu(Crs, allCrsINStuData, searchInputBox.text);
					allCrsINStuTable.setData(allCrsINStuData);
				}

				if (addCrsBtn.mouseClick(msg)) {

					// 使表格不可变化
					allCrsINStuTable.canChange = false;


					//隐藏
					addCrsBtn.move(-500, 220);
					modifyCrsBtn.move(-500, 300);
					deleteCrsBtn.move(-500, 380);
					backButton.move(-500, 700);

					//显示
					course_idBox.move(10, 100);
					course_nameBox.move(10, 180);
					scoreBox.move(10, 260);
					course_natureBox.move(10, 340);
					creditBox.move(10, 420);
					gridBox.move(10, 500);
					semesterBox.move(10,580);

					addOKButton.move(10, 650);
					cancelButton.move(10, 730);

				}

				if (addOKButton.mouseClick(msg)) {
					wchar_t course_id[10];//课程号
					wchar_t course_name[100];//课程名
					double score;//课程成绩
					int semester;//学年学期
					int course_nature;//课程性质
					double credit;//学分
					double grid;//绩点

					//判断出输入格式
					if (
						getTextInBox(course_id, course_idBox.text) &&
						getTextInBox(course_name, course_nameBox.text) &&
						getDoubleInBox(100, &score, scoreBox.text) &&
						getNumberInBox(8, &semester, semesterBox.text) &&
						getNumberInBox(1, &course_nature, course_natureBox.text) &&
						getDoubleInBox(4, &credit, creditBox.text) &&
						getDoubleInBox(4, &grid, gridBox.text)&&
						grid>=0 && credit>=0 && score>=0 && semester >= 0 && course_nature>= 0 
						) {
						addCrsToStu(Crs, course_id, course_name, score, semester, course_nature, credit, grid);
						
						// 保存
						saveStu(allStuList, STU_FILE);

						// 刷新表格
						showStu(Crs, allCrsINStuData, L"");
						allCrsINStuTable.setData(allCrsINStuData);

						//清除
						course_idBox.clear();
						course_nameBox.clear();
						scoreBox.clear();
						course_natureBox.clear();
						semesterBox.clear();
						creditBox.clear();
						gridBox.clear();

						//隐藏
						course_idBox.move(-500, 100);
						course_nameBox.move(-500, 180);
						scoreBox.move(-500, 260);
						course_natureBox.move(-500, 340);
						creditBox.move(-500, 420);
						gridBox.move(-500, 500);
						semesterBox.move(-500, 580);

						addOKButton.move(-500, 650);
						cancelButton.move(-500, 730);

						//显示
						addCrsBtn.move(-50, 220);
						modifyCrsBtn.move(-50, 300);
						deleteCrsBtn.move(-50, 380);
						backButton.move(-50, 700);

						allCrsINStuTable.canChange = true;
					}
				}

				if (cancelButton.mouseClick(msg)) {

					// 使表格可变化
					allCrsINStuTable.canChange = true;


					//清除
					course_idBox.clear();
					course_nameBox.clear();
					scoreBox.clear();
					course_natureBox.clear();
					semesterBox.clear();
					creditBox.clear();
					gridBox.clear();

					//隐藏
					course_idBox.move(-500, 100);
					course_nameBox.move(-500, 180);
					scoreBox.move(-500, 260);
					course_natureBox.move(-500, 340);
					creditBox.move(-500, 420);
					gridBox.move(-500, 500);

					addOKButton.move(-500, 600);
					cancelButton.move(-500, 700);

					//显示
					addCrsBtn.move(-50, 220);
					modifyCrsBtn.move(-50, 300);
					deleteCrsBtn.move(-50, 380);
					backButton.move(-50, 700);
				}

				if (backButton.mouseClick(msg))
				{
					allStuUI();
				}


				//表格鼠标滑动与点击
				allCrsINStuTable.onMouse(msg);


				// 文本框输入
				searchInputBox.onMessage(msg);
				course_idBox.onMessage(msg);
				course_nameBox.onMessage(msg);
				scoreBox.onMessage(msg);
				course_natureBox.onMessage(msg);
				creditBox.onMessage(msg);
				gridBox.onMessage(msg);
				semesterBox.onMessage(msg);
			}


			showxy(msg);
			//-------------------------------------------------
			FlushBatchDraw(); //批量绘图

			ULONGLONG end_time = GetTickCount();
			if (end_time - start_time < 1) {
				Sleep(1);
			}

		}
	}

