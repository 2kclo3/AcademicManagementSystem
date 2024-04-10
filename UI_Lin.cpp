#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainLin() {
	setlocale(LC_ALL, ""); //使控制台支持宽字符输出
	
	// 初始化图形窗口
	initgraph(1280, 810);
	BeginBatchDraw(); //开始批量绘图
	setbkcolor(RGB(55, 61, 53)); //背景颜色
	cleardevice();

	/*wchar_t paper_name[200];
	wchar_t journal_or_conference_name[200];
	wchar_t author[200];
	wchar_t date[200];
	wchar_t volume_num[200];
	wchar_t issue_num[200];
	wchar_t page[200];
	double GPA_bonus;

	getText(paper_name);
	getText(journal_or_conference_name);
	getText(author);
	getText(date);
	getText(volume_num);
	getText(issue_num);
	getText(page);
	GPA_bonus = getDouble(10);

	List Stu = readStu(STU_FILE);
	wchar_t pn[20] = L"paper1";
	Rnode* tar = searchRnode(&Stu, pn);
	modifyQuality_rlist(tar, paper_name,
		journal_or_conference_name,
		author,
		date,
		volume_num,
		issue_num,
		page,
		GPA_bonus
	);

	printStu(Stu);
	*/

	allQualityUI();



	EndBatchDraw(); //结束批量绘图
	closegraph(); // 关闭图形窗口



	return 0;
}

void allQualityUI() {
	cleardevice();

	List allStuList = readStu(STU_FILE);
	
	vector<vector<std::wstring>> allQuality_Data;
	vector<vector<std::wstring>> Stu_Research_Data;

	ShowAllStu_with_quality(allStuList, allQuality_Data, L"");

	Table allQuality_Table(310, 90, 940, 700, allQuality_Data);

	Text titleText(10, 100, L"素质类项目管理", 50);
	Text IDText(-500, 200, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	TextBox paper_nameBox(-500, 200, 290, L"论文名称", L"");
	TextBox journal_or_conference_nameBox(-500, 270, 290, L"发表的期刊/会议名称", L"");
	TextBox authorBox(-500, 340, 290, L"作者情况", L"");
	TextBox dateBox(-500, 410, 290, L"发表时间", L"");
	TextBox volume_numBox(-500, 480, 290, L"卷数", L"");
	TextBox issue_numBox(-500, 550, 290, L"刊号", L"");
	TextBox pageBox(-500, 620, 290, L"页码范围", L"");
	TextBox GPA_bonusBox(-500, 690, 290, L"绩点加分", L"");



	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);
	Button addBtn(-50, 200, 330, 60, L"   添加", 1);
	Button modifyBtn(-50, 280, 330, 60, L"   修改", 1);
	Button deleteBtn(-50, 360, 330, 60, L"   删除", 1);
	Button exportBtn(-50, 440, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 520, 330, 60, L"   导入", 1);
	Button backButton(-50, 600, 330, 60, L"   返回", 0);

	Button modify_Research_Btn(-500, 280, 330, 60, L"   科研成果修改", 1);
	Button addOKButton(-500, 580, 290, 60, L"确定添加", 1);
	Button modify_ResearchOK_Button(-500, 580, 290, 60, L"确定修改", 1);
	Button cancelButton(-500, 680, 290, 60, L"返回", 0);
	Button cancel_ModifyResearch_Button(-500, 720, 290, 60, L"取消", 0);

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->
		// 输入框绘制(必须)
		searchInputBox.draw();
		paper_nameBox.draw();
		journal_or_conference_nameBox.draw();
		authorBox.draw();
		dateBox.draw();
		volume_numBox.draw();
		issue_numBox.draw();
		pageBox.draw();
		GPA_bonusBox.draw();


		if (peekmessage(&msg, -1, true)) {

			// 鼠标点击事件
			if (searchBtn.mouseClick(msg)) {
				ShowAllStu_with_quality(allStuList, allQuality_Data, searchInputBox.text);
				allQuality_Table.setData(allQuality_Data);
			}

			if (addBtn.mouseClick(msg)) {
			}

			if (modifyBtn.mouseClick(msg)) {
				// 未选择学生
				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else {
					// 更改标题
					titleText.setText(L"修改素质类项目");
					//隐藏
					addBtn.move(-500,200);
					modifyBtn.move(-500, 280);
					deleteBtn.move(-500,360);
					exportBtn.move(-500, 440);
					inportBtn.move(-500, 520);
					backButton.move(-500, 600);
					searchInputBox.move(-1500, 20);
					searchBtn.move(-500, 20);


					//显示
					modify_Research_Btn.move(-50, 280);
					cancelButton.move(-50, 680);


					// 获取当前行并精确搜索学生节点
					int tempID;
					int selectedRow = allQuality_Table.getSelectedRow();
					getNumberInBox(99999999, &tempID, allQuality_Data[selectedRow][0].c_str());
					Node* modifyingStu = searchStu(&allStuList, (wchar_t*)allQuality_Data[selectedRow][1].c_str(), tempID);

					ShowStu_Research(modifyingStu, Stu_Research_Data);
					allQuality_Table.setData(Stu_Research_Data);

					
				
				}
			}

			if (modify_Research_Btn.mouseClick(msg)) {

				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个科研成果", L"错误!", MB_ICONERROR);
				}
				else {
					// 更改标题
					titleText.setText(L"修改此科研成果");
					titleText.move(10, 3);

					//隐藏
					modify_Research_Btn.move(-500, 280);
					cancelButton.move(-500, 680);



					// 使表格不可变化
					allQuality_Table.canChange = false;

					// 获取当前行
					int selectedRow = allQuality_Table.getSelectedRow();
					vector<std::wstring> selectedResearch_Data = Stu_Research_Data[selectedRow];

					// 文本框默认内容
					paper_nameBox.setText(selectedResearch_Data[0].c_str());
					journal_or_conference_nameBox.setText(selectedResearch_Data[1].c_str());
					authorBox.setText(selectedResearch_Data[2].c_str());
					dateBox.setText(selectedResearch_Data[3].c_str());
					volume_numBox.setText(selectedResearch_Data[4].c_str());
					issue_numBox.setText(selectedResearch_Data[5].c_str());
					pageBox.setText(selectedResearch_Data[6].c_str());
					GPA_bonusBox.setText(selectedResearch_Data[7].c_str());


					//显示
					paper_nameBox.move(10, 70);
					journal_or_conference_nameBox.move(10, 140);
					authorBox.move(10, 210);
					dateBox.move(10, 280);
					volume_numBox.move(10, 350);
					issue_numBox.move(10, 420);
					pageBox.move(10, 490);
					GPA_bonusBox.move(10, 560);
					modify_ResearchOK_Button.move(10, 640);
					cancel_ModifyResearch_Button.move(10, 720);


				}
			}
			
			if (modify_ResearchOK_Button.mouseClick(msg)) {
					
				wchar_t paper_name[200];//论文名称
				wchar_t journal_or_conference_name[200];//所发表的期刊或会议名称
				wchar_t author[200];// 作者情况（是否为通讯作者及作者排序）
				wchar_t date[200];// 发表年月
				wchar_t volume_num[200];// 卷数
				wchar_t issue_num[200];// 刊号
				wchar_t page[200];// 页码范围
				double GPA_bonus;

				// 精确搜索素质类项目节点
					wchar_t temp[200];
					int selectedRow = allQuality_Table.getSelectedRow();
					getTextInBox(temp, Stu_Research_Data[selectedRow][0].c_str());
					Node* modifyingStu = searchStu_with_thisRnode(&allStuList, temp);
					Rnode* modifying_Rnode = searchRnode_in_thisStu(modifyingStu, temp);
				
				// 判断输入格式
				//if (
					getTextInBox(paper_name, paper_nameBox.text);
					getTextInBox(journal_or_conference_name, journal_or_conference_nameBox.text);
					getTextInBox(author, authorBox.text);
					getTextInBox(date, dateBox.text);
					getTextInBox(volume_num, volume_numBox.text);
					getTextInBox(issue_num, issue_numBox.text);
					getTextInBox(page, pageBox.text);

					getDoubleInBox(10, &GPA_bonus, GPA_bonusBox.text);
					//) {

					// 修改
					modifyQuality_rlist(modifying_Rnode, paper_name, journal_or_conference_name, author, date, volume_num, issue_num, page, GPA_bonus);

					// 保存
					saveStu(allStuList, STU_FILE);

					// 使表格可变化
					allQuality_Table.canChange = true;

					// 刷新表格
					ShowStu_Research(modifyingStu, Stu_Research_Data);
					allQuality_Table.setData(Stu_Research_Data);

					// 清除输入框内容
					paper_nameBox.clear();
					journal_or_conference_nameBox.clear();
					authorBox.clear();
					dateBox.clear();
					volume_numBox.clear();
					issue_numBox.clear();
					pageBox.clear();
					GPA_bonusBox.clear();


					// 更改标题
					titleText.setText(L"修改素质类项目");
					titleText.move(10, 100);

					//隐藏
					paper_nameBox.move(-500, 70);
					journal_or_conference_nameBox.move(-500, 140);
					authorBox.move(-500, 210);
					dateBox.move(-500, 280);
					volume_numBox.move(-500, 350);
					issue_numBox.move(-500, 420);
					pageBox.move(-500, 490);
					GPA_bonusBox.move(-500, 560);
					modify_ResearchOK_Button.move(-500, 640);
					cancel_ModifyResearch_Button.move(-500, 720);

					//显示
					modify_Research_Btn.move(-50, 280);
					cancelButton.move(-50, 680);



				//}
				// 输入错误
				/*else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}*/

			}

			if (cancel_ModifyResearch_Button.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"修改素质类项目");
				titleText.move(10, 100);

				// 清除输入框内容
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				// 表格可变化
				allQuality_Table.canChange = true;

				//隐藏
				paper_nameBox.move(-500,70);
				journal_or_conference_nameBox.move(-500, 140);
				authorBox.move(-500, 210);
				dateBox.move(-500, 280);
				volume_numBox.move(-500, 350);
				issue_numBox.move(-500, 420);
				pageBox.move(-500, 490);
				GPA_bonusBox.move(-500, 560);
				modify_ResearchOK_Button.move(-500, 640);
				cancel_ModifyResearch_Button.move(-500, 720);


				//显示
				modify_Research_Btn.move(-50, 280);
				cancelButton.move(-50, 680);


			}
			
			if (cancelButton.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"素质类项目管理");

				//隐藏
				modify_Research_Btn.move(-500, 280);
				cancelButton.move(-500, 680);

				//显示
				addBtn.move(-50, 200);
				modifyBtn.move(-50, 280);
				deleteBtn.move(-50, 360);
				exportBtn.move(-50, 440);
				inportBtn.move(-50, 520);
				backButton.move(-50, 600);
				searchInputBox.move(310, 20);
				searchBtn.move(1150, 20);

				ShowAllStu_with_quality(allStuList, allQuality_Data, L"");
				allQuality_Table.setData(allQuality_Data);

			
			}


			if (deleteBtn.mouseClick(msg)) {
			}

			if (backButton.mouseClick(msg)) {
				menuUI();
			}

			
			//表格鼠标滑动与点击
			allQuality_Table.onMouse(msg);

			// 文本框输入
			searchInputBox.onMessage(msg);
			paper_nameBox.onMessage(msg);
			journal_or_conference_nameBox.onMessage(msg);
			authorBox.onMessage(msg);
			dateBox.onMessage(msg);
			volume_numBox.onMessage(msg);
			issue_numBox.onMessage(msg);
			pageBox.onMessage(msg);
			GPA_bonusBox.onMessage(msg);
		
		}
		
		
		//showxy(msg);



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



