#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"

//修改完后也要查重,避免出现把连个人的学号改重了或者课程改重了

int main0(void) 
{
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


void allCrsUI()
{
	cleardevice();
	Cpnode allCrsList = readCrs(CRS_FILE);
	vector<vector<std::wstring>> allCrsData;
	showAllCrs(allCrsList, allCrsData, L"");

	Table allCrsTable(310, 90, 940, 700, allCrsData);

	Text titleText(40, 50, L"所有课程", 64);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox cnameBox(-500, 150, 290, L"课程名称", L"");
	TextBox cnumBox(-500, 220, 290, L"课程号", L"");
	TextBox characterBox(-500, 290, 290, L"课程性质", L"");

	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);

	Button inquireCrsBtn(-50, 140, 330, 60, L"   查询课程", 1);
	Button addCrsBtn(-50, 220, 330, 60, L"   添加课程", 1);
	Button modifyCrsBtn(-50, 300, 330, 60, L"   修改", 1);
	Button deleteCrsBtn(-50, 380, 330, 60, L"   删除", 1);
	Button statisticBtn(-50, 460, 330, 60, L"   统计", 1);//这玩意干啥的？
	Button exportBtn(-50, 540, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 620, 330, 60, L"   导入", 1);
	Button backButton(-50, 700, 330, 60, L"   返回", 0);

	Button addOKButton(-500, 580, 290, 60, L"确定添加", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"确定修改", 1);
	Button cancelButton(-500, 660, 290, 60, L"取消", 0);


	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit())
	{
		ULONGLONG start_time = GetTickCount();
		//->

		searchInputBox.draw();
		cnameBox.draw();
		cnumBox.draw();
		characterBox.draw();

		if (peekmessage(&msg, -1, true))
		{
			if (searchBtn.mouseClick(msg))
			{
				showAllCrs(allCrsList, allCrsData, searchInputBox.text);
				allCrsTable.setData(allCrsData);
			}

			if (inquireCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"请选择课程", L"错误!", MB_ICONERROR);
				}
				else
				{
					// 获取课程节点信息
					wchar_t cname[30];
					int cnum;
					int selectedRow = allCrsTable.getSelectedRow(); // 获取当前行
					getTextInBox(cname, allCrsData[selectedRow][0].c_str());
					getNumberInBox(99999, &cnum, allCrsData[selectedRow][1].c_str());
					Cpnode cplist = searchCrs(allCrsList, cname, cnum);
					CrsUI(allCrsList, cplist);

				}
			}
			////////////////////////////////////////////
			if (addCrsBtn.mouseClick(msg))
			{
				// 更改标题
				titleText.setText(L"添加课程");
				// 隐藏
				inquireCrsBtn.move(-500, 140);
				addCrsBtn.move(-500, 220);
				modifyCrsBtn.move(-500, 300);
				deleteCrsBtn.move(-500, 380);
				statisticBtn.move(-500, 460);
				exportBtn.move(-500, 540);
				inportBtn.move(-500, 620);
				backButton.move(-500, 700);

				// 显示
				cnameBox.move(10, 140);
				cnumBox.move(10, 220);
				characterBox.move(10, 300);
				addOKButton.move(10, 380);
				cancelButton.move(10, 460);
			}

			if (addOKButton.mouseClick(msg))
			{
				wchar_t cname[30];
				int cnum;
				wchar_t character[5];

				// 判断输入格式
				if (
					getTextInBox(cname, cnameBox.text) &&
					getNumberInBox(99999, &cnum, cnumBox.text) &&
					getTextInBox(character, characterBox.text) &&
					cnum > 9999
					)
				{

					// 课程相同的情况,报错提醒
					if (!addCrs(allCrsList, cname, cnum, character))
					{
						MessageBox(GetHWnd(), L"该课程已经存在,请勿重复添加!", L"错误!", MB_ICONERROR);
					}
					else
					{
						// 保存
						saveCrs(allCrsList, CRS_FILE);

						// 刷新表格
						showAllCrs(allCrsList, allCrsData, L"");
						allCrsTable.setData(allCrsData);

						// 清除输入框内容
						cnameBox.clear();
						cnumBox.clear();
						characterBox.clear();


						// 更改标题
						titleText.setText(L"所有课程");

						// 隐藏
						cnameBox.move(-500, 140);
						cnumBox.move(-500, 220);
						characterBox.move(-500, 300);
						addOKButton.move(-500, 380);
						cancelButton.move(-500, 460);

						// 显示
						inquireCrsBtn.move(-50, 140);
						addCrsBtn.move(-50, 220);
						modifyCrsBtn.move(-50, 300);
						deleteCrsBtn.move(-50, 380);
						statisticBtn.move(-50, 460);
						exportBtn.move(-50, 540);
						inportBtn.move(-50, 620);
						backButton.move(-50, 700);

					}


				}
				// 输入错误
				else
				{
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (cancelButton.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"所有课程");

				// 清除输入框内容
				cnameBox.clear();
				cnumBox.clear();
				characterBox.clear();

				// 使表格可变化
				allCrsTable.canChange = true;

				// 隐藏
				cnameBox.move(-500, 150);
				cnumBox.move(-500, 220);
				characterBox.move(-500, 290);
				addOKButton.move(-500, 580);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// 显示
				inquireCrsBtn.move(-50, 140);
				addCrsBtn.move(-50, 220);
				modifyCrsBtn.move(-50, 300);
				deleteCrsBtn.move(-50, 380);
				statisticBtn.move(-50, 460);
				exportBtn.move(-50, 540);
				inportBtn.move(-50, 620);
				backButton.move(-50, 700);

			}

			if (modifyCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"请选择课程", L"错误!", MB_ICONERROR);
				}
				else
				{
					// 更改标题
					titleText.setText(L"修改课程");
					// 隐藏
					inquireCrsBtn.move(-500, 140);
					addCrsBtn.move(-500, 220);
					modifyCrsBtn.move(-500, 300);
					deleteCrsBtn.move(-500, 380);
					statisticBtn.move(-500, 460);
					exportBtn.move(-500, 540);
					inportBtn.move(-500, 620);
					backButton.move(-500, 700);


					// 使表格不可变化
					allCrsTable.canChange = false;


					// 获取当前行
					int selectedRow = allCrsTable.getSelectedRow();
					vector<std::wstring> selectedData = allCrsData[selectedRow];


					// 文本框默认内容
					cnameBox.setText(selectedData[0].c_str());
					cnumBox.setText(selectedData[1].c_str());
					characterBox.setText(selectedData[2].c_str());


					// 显示
					cnameBox.move(10, 140);
					cnumBox.move(10, 220);
					characterBox.move(10, 300);
					modifyOKButton.move(10, 380);
					cancelButton.move(10, 460);
				}

			}

			if (modifyOKButton.mouseClick(msg))
			{
				wchar_t cname[30];
				int cnum;
				wchar_t character[5];


				// 精确搜索课程节点
				wchar_t original_cname[30];
				int original_cnum;
				int selectedRow = allCrsTable.getSelectedRow(); // 获取当前行
				getTextInBox(original_cname, allCrsData[selectedRow][0].c_str());
				getNumberInBox(99999, &original_cnum, allCrsData[selectedRow][1].c_str());
				Cpnode modifyingCrs = searchCrs(allCrsList, original_cname, original_cnum);
				

				// 判断输入格式
				if (
					getTextInBox(cname, cnameBox.text) &&
					getNumberInBox(99999, &cnum, cnumBox.text) &&
					getTextInBox(character, characterBox.text) &&
					cnum > 9999
					)
				{

					// 修改
					modifyCrs(modifyingCrs, cname, cnum, character);

					// 保存
					saveCrs(allCrsList, CRS_FILE);

					// 使表格可变化
					allCrsTable.canChange = true;

					// 刷新表格
					//showAllCrs(allCrsList, allCrsData, searchInputBox.text);//这个怎么是searchInputBox.text
					showAllCrs(allCrsList, allCrsData, L"");
					allCrsTable.setData(allCrsData);

					// 清除输入框内容
					cnameBox.clear();
					cnumBox.clear();
					characterBox.clear();


					// 更改标题
					titleText.setText(L"所有课程");

					// 隐藏
					cnameBox.move(-500, 150);
					cnumBox.move(-500, 220);
					characterBox.move(-500, 290);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// 显示
					inquireCrsBtn.move(-50, 140);
					addCrsBtn.move(-50, 220);
					modifyCrsBtn.move(-50, 300);
					deleteCrsBtn.move(-50, 380);
					statisticBtn.move(-50, 460);
					exportBtn.move(-50, 540);
					inportBtn.move(-50, 620);
					backButton.move(-50, 700);



				}
				// 输入错误
				else
				{
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (deleteCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"请选择课程", L"错误!", MB_ICONERROR);
				}
				else
				{
					int result = MessageBox(GetHWnd(), L"确定删除这门课程吗?", L"删除课程", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES)
					{ // 点击确定

						// 获取课程节点信息
						wchar_t cname[30];
						int cnum;
						int selectedRow = allCrsTable.getSelectedRow(); // 获取当前行
						getTextInBox(cname, allCrsData[selectedRow][0].c_str());
						getNumberInBox(99999, &cnum, allCrsData[selectedRow][1].c_str());

						// 删除
						deleteCrs(allCrsList, cname, cnum);

						// 保存
						saveCrs(allCrsList, CRS_FILE);


						// 刷新表格
						showAllCrs(allCrsList, allCrsData, searchInputBox.text);
						allCrsTable.setData(allCrsData);
					}
				}
			}

			if (statisticBtn.mouseClick(msg)) {
			}
			if (exportBtn.mouseClick(msg)) {
			}
			if (inportBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg))
			{
				//return;不能直接return
				menuUI();
			}

			//表格鼠标滑动与点击
			allCrsTable.onMouse(msg);

			// 文本框输入
			searchInputBox.onMessage(msg);
			cnameBox.onMessage(msg);
			cnumBox.onMessage(msg);
			characterBox.onMessage(msg);
		}

		showxy(msg);





		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1)
		{
			Sleep(1);
		}

	}

}


void CrsUI(Cpnode cphead, Cpnode cplist)
{
	cleardevice();
	Spnode allStuInCrsList = cplist->sphead;
	vector<vector<std::wstring>>allStuInCrsData;
	showAllStuInCrs(cplist, allStuInCrsData, L"");

	Table allStuInCrsTable(310, 90, 940, 700, allStuInCrsData);

	Text GPAText(-500, 370, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");

	TextBox snameBox(-500, 150, 290, L"学生姓名", L"");
	TextBox snumBox(-500, 220, 290, L"学号", L"");
	TextBox scoreBox(-500, 290, 290, L"成绩", L"");


	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);

	Button addStuInCrsBtn(-50, 140, 330, 60, L"   添加学生", 1);
	Button modifyStuInCrsBtn(-50, 220, 330, 60, L"   修改学生", 1);
	Button deleteStuInCrsBtn(-50, 300, 330, 60, L"   删除学生", 1);
	Button backButton(-50, 380, 330, 60, L"   返回", 0);

	Button addOKButton(-500, 580, 290, 60, L"确定添加", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"确定修改", 1);
	Button cancelButton(-500, 660, 290, 60, L"取消", 0);

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit())
	{
		ULONGLONG start_time = GetTickCount();
		//->

		searchInputBox.draw();
		snameBox.draw();
		snumBox.draw();
		scoreBox.draw();

		if (peekmessage(&msg, -1, true))
		{
			if (searchBtn.mouseClick(msg))
			{
				showAllStuInCrs(cplist, allStuInCrsData, searchInputBox.text);
				allStuInCrsTable.setData(allStuInCrsData);
			}


			if (addStuInCrsBtn.mouseClick(msg))
			{
				// 隐藏
				addStuInCrsBtn.move(-500, 220);
				modifyStuInCrsBtn.move(-500, 300);
				deleteStuInCrsBtn.move(-500, 380);
				backButton.move(-500, 700);

				// 显示
				snameBox.move(10, 140);
				snumBox.move(10, 220);
				scoreBox.move(10, 300);

				addOKButton.move(10, 380);
				cancelButton.move(10, 460);
			}

			if (addOKButton.mouseClick(msg))
			{
				wchar_t sname[30];
				int snum;
				double score;

				// 判断输入格式

				if (
					getTextInBox(sname, snameBox.text) &&
					getNumberInBox(99999999, &snum, snumBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					snum > 9999999 && score >= 0
					)
				{


					if (!addStuInCrs(cplist, sname, snum, score))
					{
						MessageBox(GetHWnd(), L"该学生已经存在,请勿重复添加!", L"错误!", MB_ICONERROR);
					}
					else
					{
						// 保存
						saveCrs(cphead, CRS_FILE);

						// 刷新表格
						showAllStuInCrs(cplist, allStuInCrsData, L"");
						allStuInCrsTable.setData(allStuInCrsData);

						// 清除输入框内容
						snameBox.clear();
						snumBox.clear();
						scoreBox.clear();




						// 隐藏
						snameBox.move(-500, 140);
						snumBox.move(-500, 220);
						scoreBox.move(-500, 300);
						addOKButton.move(-500, 380);
						cancelButton.move(-500, 460);

						// 显示
						addStuInCrsBtn.move(-50, 220);
						modifyStuInCrsBtn.move(-50, 300);
						deleteStuInCrsBtn.move(-50, 380);
						backButton.move(-50, 460);

					}


				}
				// 输入错误
				else
				{
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (cancelButton.mouseClick(msg)) 
			{

				// 清除输入框内容
				snameBox.clear();
				snumBox.clear();
				scoreBox.clear();

				// 使表格可变化
				allStuInCrsTable.canChange = true;

				// 隐藏
				snameBox.move(-500, 150);
				snumBox.move(-500, 220);
				scoreBox.move(-500, 290);
				addOKButton.move(-500, 580);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// 显示
				addStuInCrsBtn.move(-50, 220);
				modifyStuInCrsBtn.move(-50, 300);
				deleteStuInCrsBtn.move(-50, 380);
				backButton.move(-50, 460);

			}

			if (modifyStuInCrsBtn.mouseClick(msg))
			{
				if (allStuInCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"请选择课程", L"错误!", MB_ICONERROR);
				}
				else
				{
					// 隐藏
					addStuInCrsBtn.move(-500, 220);
					modifyStuInCrsBtn.move(-500, 300);
					deleteStuInCrsBtn.move(-500, 380);
					backButton.move(-500, 700);


					// 使表格不可变化
					allStuInCrsTable.canChange = false;


					// 获取当前行
					int selectedRow = allStuInCrsTable.getSelectedRow();
					vector<std::wstring> selectedData = allStuInCrsData[selectedRow];


					// 文本框默认内容
					snameBox.setText(selectedData[0].c_str());
					snumBox.setText(selectedData[1].c_str());
					scoreBox.setText(selectedData[2].c_str());


					// 显示
					snameBox.move(10, 140);
					snumBox.move(10, 220);
					scoreBox.move(10, 300);
					modifyOKButton.move(10, 380);
					cancelButton.move(10, 460);
				}

			}

			if (modifyOKButton.mouseClick(msg))
			{
				wchar_t sname[30];
				int snum;
				double score;


				// 精确搜索课程节点
				wchar_t original_sname[30];
				int original_snum;
				int selectedRow = allStuInCrsTable.getSelectedRow(); // 获取当前行
				getTextInBox(original_sname, allStuInCrsData[selectedRow][0].c_str());
				getNumberInBox(99999999, &original_snum, allStuInCrsData[selectedRow][1].c_str());
				Spnode modifyingStu = searchStuInCrs(cplist, original_sname, original_snum);

				// 判断输入格式
				if (
					getTextInBox(sname, snameBox.text) &&
					getNumberInBox(99999999, &snum, snumBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					snum > 9999999&&score>=0
					)
				{

					// 修改
					modifyStuInCrs(cplist, modifyingStu, sname, snum, score);

					// 保存
					saveCrs(cphead, CRS_FILE);

					// 使表格可变化
					allStuInCrsTable.canChange = true;

					// 刷新表格
					showAllStuInCrs(cplist, allStuInCrsData, L"");
					allStuInCrsTable.setData(allStuInCrsData);

					// 清除输入框内容
					snameBox.clear();
					snumBox.clear();
					scoreBox.clear();



					// 隐藏
					snameBox.move(-500, 150);
					snumBox.move(-500, 220);
					scoreBox.move(-500, 290);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// 显示
					addStuInCrsBtn.move(-50, 220);
					modifyStuInCrsBtn.move(-50, 300);
					deleteStuInCrsBtn.move(-50, 380);
					backButton.move(-50, 460);



				}
				// 输入错误
				else
				{
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (deleteStuInCrsBtn.mouseClick(msg))
			{
				if (allStuInCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"请选择学生", L"错误!", MB_ICONERROR);
				}
				else
				{
					int result = MessageBox(GetHWnd(), L"确定删除这名学生吗?", L"删除学生", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES)
					{ // 点击确定

						wchar_t sname[30];
						int snum;
						int selectedRow = allStuInCrsTable.getSelectedRow(); // 获取当前行
						getTextInBox(sname, allStuInCrsData[selectedRow][0].c_str());
						getNumberInBox(99999999, &snum, allStuInCrsData[selectedRow][1].c_str());

						// 删除
						deleteStuInCrs(cplist, sname, snum);

						// 保存
						saveCrs(cphead, CRS_FILE);


						// 刷新表格
						showAllStuInCrs(cplist, allStuInCrsData, searchInputBox.text);
						allStuInCrsTable.setData(allStuInCrsData);
					}
				}
			}

			if (backButton.mouseClick(msg))
			{
				//return;不能直接return
				allCrsUI();
			}

			//表格鼠标滑动与点击
			allStuInCrsTable.onMouse(msg);

			// 文本框输入
			searchInputBox.onMessage(msg);
			snameBox.onMessage(msg);
			snumBox.onMessage(msg);
			scoreBox.onMessage(msg);
		}

		showxy(msg);





		FlushBatchDraw(); //批量绘图

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1)
		{
			Sleep(1);
		}

	}
	return;
}






