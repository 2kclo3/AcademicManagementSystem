#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


void QualityUI(Node* Stu, List allStuList);
void allQualityUI();


int main() {
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
	//vector<vector<std::wstring>> Stu_Research_Data;

	showAllStu(allStuList, allQuality_Data, L"");

	Table allQuality_Table(310, 90, 940, 700, allQuality_Data);

	Text titleText(10, 100, L"素质类项目管理", 50);
	//Text IDText(-500, 200, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"搜索", L"");

	Button searchBtn(1150, 20, 100, 50, L"搜索", 1);
	Button search_for_quality_Btn(-50, 360, 330, 60, L"   查询", 1);
	Button exportBtn(-50, 440, 330, 60, L"   导出", 1);
	Button inportBtn(-50, 520, 330, 60, L"   导入", 1);
	Button backButton(-50, 600, 330, 60, L"   返回", 0);

	// 处理鼠标事件
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->
		// 输入框绘制(必须)
		searchInputBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// 鼠标点击事件
			if (searchBtn.mouseClick(msg)) {
				showAllStu(allStuList, allQuality_Data, searchInputBox.text);
				allQuality_Table.setData(allQuality_Data);
			}

			if (search_for_quality_Btn.mouseClick(msg)) {
				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个学生", L"错误!", MB_ICONERROR);
				}
				else {
					// 精确搜索学生节点
					int tempID;
					int selectedRow = allQuality_Table.getSelectedRow();
					getNumberInBox(99999999, &tempID, allQuality_Data[selectedRow][0].c_str());
					Node* modifyingStu = searchStu(&allStuList, (wchar_t*)allQuality_Data[selectedRow][1].c_str(), tempID);
					QualityUI(modifyingStu, allStuList);
				}

			}

			if (backButton.mouseClick(msg)) {
				menuUI();
			}

			
			//表格鼠标滑动与点击
			allQuality_Table.onMouse(msg);

			// 文本框输入
			searchInputBox.onMessage(msg);
		
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


void QualityUI(Node* Stu, List allStuList) {

	cleardevice();

	vector<vector<std::wstring>>ResearchData;
	ShowStu_Research(Stu, ResearchData);
	
	Table Stu_Rtable(310, 90, 940, 350, ResearchData);

	//TextBox searchInputBox(310, 20, 820, L"搜索", L"");
	Text titleText(10, 100, L"该学生素质类项目管理", 50);

	TextBox paper_nameBox(-500, 200, 290, L"论文名称", L"");
	TextBox journal_or_conference_nameBox(-500, 270, 290, L"发表的期刊/会议名称", L"");
	TextBox authorBox(-500, 340, 290, L"作者情况", L"");
	TextBox dateBox(-500, 410, 290, L"发表时间", L"");
	TextBox volume_numBox(-500, 480, 290, L"卷数", L"");
	TextBox issue_numBox(-500, 550, 290, L"刊号", L"");
	TextBox pageBox(-500, 620, 290, L"页码范围", L"");
	TextBox GPA_bonusBox(-500, 690, 290, L"绩点加分", L"");
	
	//进入单个学生的素质类界面后 一开始显示的
	Button add_Research_Btn(-50, 200, 330, 60, L"   科研成果添加", 1);
	Button modify_Research_Btn(-50, 280, 330, 60, L"   科研成果修改", 1);
	Button delete_Research_Btn(-50, 360, 330, 60, L"   科研成果删除", 1);
	Button backButton(-50, 680, 290, 60, L"返回", 0);

	
	Button modify_ResearchOK_Btn(-500, 580, 290, 60, L"确定修改", 1);
	Button add_ResearchOK_Btn(-500, 640, 290, 60, L"确定添加", 1);
	
	Button cancel_modifyResearch_Btn(-500, 720, 290, 60, L"取消修改", 0);
	Button cancel_addResearch_Btn(-500, 720, 290, 60, L"取消添加", 0);


	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();

		// 输入框绘制(必须)
		paper_nameBox.draw();
		journal_or_conference_nameBox.draw();
		authorBox.draw();
		dateBox.draw();
		volume_numBox.draw();
		issue_numBox.draw();
		pageBox.draw();
		GPA_bonusBox.draw();

		if (peekmessage(&msg, -1, true)) {

			if (add_Research_Btn.mouseClick(msg)) {

				titleText.setText(L"科研成果添加");
				titleText.move(10, 3);
				//隐藏
				add_Research_Btn.move(-500, 200);
				modify_Research_Btn.move(-500, 280);
				delete_Research_Btn.move(-500, 360);
				backButton.move(-500, 600);

				//显示
				add_ResearchOK_Btn.move(-50, 640);
				cancel_addResearch_Btn.move(-50, 720);

				paper_nameBox.move(10, 70);
				journal_or_conference_nameBox.move(10, 140);
				authorBox.move(10, 210);
				dateBox.move(10, 280);
				volume_numBox.move(10, 350);
				issue_numBox.move(10, 420);
				pageBox.move(10, 490);
				GPA_bonusBox.move(10, 560);

			}

			if (add_ResearchOK_Btn.mouseClick(msg)) {

				wchar_t paper_name[200];//论文名称
				wchar_t journal_or_conference_name[200];//所发表的期刊或会议名称
				wchar_t author[200];// 作者情况（是否为通讯作者及作者排序）
				wchar_t date[200];// 发表年月
				wchar_t volume_num[200];// 卷数
				wchar_t issue_num[200];// 刊号
				wchar_t page[200];// 页码范围
				double GPA_bonus;

				// 判断输入格式
				if (
					getTextInBox(paper_name, paper_nameBox.text) &&
					getTextInBox(journal_or_conference_name, journal_or_conference_nameBox.text) &&
					getTextInBox(author, authorBox.text) &&
					getTextInBox(date, dateBox.text) &&
					getTextInBox(volume_num, volume_numBox.text) &&
					getTextInBox(issue_num, issue_numBox.text) &&
					getTextInBox(page, pageBox.text) &&
					getDoubleInBox(10, &GPA_bonus, GPA_bonusBox.text)
					) {

					if (!addQuality_rlist(Stu, paper_name,
						journal_or_conference_name, author, date,
						volume_num, issue_num, page, GPA_bonus)) {
						MessageBox(GetHWnd(), L"该科研成果已经存在,请勿重复添加!", L"错误!", MB_ICONERROR);
					}
					else {
						// 保存
						saveStu(allStuList, STU_FILE);

						// 使表格可变化
						Stu_Rtable.canChange = true;

						// 刷新表格
						ShowStu_Research(Stu, ResearchData);
						Stu_Rtable.setData(ResearchData);

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
						titleText.setText(L"该学生素质类项目管理");

						//隐藏
						paper_nameBox.move(-500, 70);
						journal_or_conference_nameBox.move(-500, 140);
						authorBox.move(-500, 210);
						dateBox.move(-500, 280);
						volume_numBox.move(-500, 350);
						issue_numBox.move(-500, 420);
						pageBox.move(-500, 490);
						GPA_bonusBox.move(-500, 560);
						add_ResearchOK_Btn.move(-500, 640);
						cancel_addResearch_Btn.move(-500, 720);

						//显示
						add_Research_Btn.move(-50, 200);
						modify_Research_Btn.move(-50, 280);
						delete_Research_Btn.move(-50, 360);
						backButton.move(-50, 600);
						titleText.move(10, 100);

					}
				}
				// 输入错误
				else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}
			}

			if (cancel_addResearch_Btn.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"该学生素质类项目管理");

				// 清除输入框内容
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				//隐藏
				paper_nameBox.move(-500, 70);
				journal_or_conference_nameBox.move(-500, 140);
				authorBox.move(-500, 210);
				dateBox.move(-500, 280);
				volume_numBox.move(-500, 350);
				issue_numBox.move(-500, 420);
				pageBox.move(-500, 490);
				GPA_bonusBox.move(-500, 560);
				add_ResearchOK_Btn.move(-500, 640);
				cancel_addResearch_Btn.move(-500, 720);

				//显示
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				backButton.move(-50, 600);
				titleText.move(10, 100);


			}

			if (modify_Research_Btn.mouseClick(msg)) {
				//选择一个要更改的科研成果
				if (Stu_Rtable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个科研成果", L"错误!", MB_ICONERROR);
				}
				else {
					// 更改标题
					titleText.setText(L"修改素质类项目");
					titleText.move(10, 3);

					//隐藏
					add_Research_Btn.move(-500, 200);
					modify_Research_Btn.move(-500, 280);
					delete_Research_Btn.move(-500, 360);
					backButton.move(-500, 600);

					//显示
					modify_ResearchOK_Btn.move(-50, 640);
					cancel_modifyResearch_Btn.move(-50, 720);

					paper_nameBox.move(10, 70);
					journal_or_conference_nameBox.move(10, 140);
					authorBox.move(10, 210);
					dateBox.move(10, 280);
					volume_numBox.move(10, 350);
					issue_numBox.move(10, 420);
					pageBox.move(10, 490);
					GPA_bonusBox.move(10, 560);

					// 使表格不可变化
					Stu_Rtable.canChange = false;

					// 获取当前行
					int selectedRow = Stu_Rtable.getSelectedRow();
					vector<std::wstring> selectedResearch_Data = ResearchData[selectedRow];

					// 文本框默认内容
					paper_nameBox.setText(selectedResearch_Data[0].c_str());
					journal_or_conference_nameBox.setText(selectedResearch_Data[1].c_str());
					authorBox.setText(selectedResearch_Data[2].c_str());
					dateBox.setText(selectedResearch_Data[3].c_str());
					volume_numBox.setText(selectedResearch_Data[4].c_str());
					issue_numBox.setText(selectedResearch_Data[5].c_str());
					pageBox.setText(selectedResearch_Data[6].c_str());
					GPA_bonusBox.setText(selectedResearch_Data[7].c_str());

				}
			}

			if (modify_ResearchOK_Btn.mouseClick(msg)) {

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
				int selectedRow = Stu_Rtable.getSelectedRow();
				getTextInBox(temp, ResearchData[selectedRow][0].c_str());
				Rnode* modifying_Rnode = searchRnode_in_thisStu(Stu, temp);

				// 判断输入格式
				if (
					getTextInBox(paper_name, paper_nameBox.text) &&
					getTextInBox(journal_or_conference_name, journal_or_conference_nameBox.text) &&
					getTextInBox(author, authorBox.text) &&
					getTextInBox(date, dateBox.text) &&
					getTextInBox(volume_num, volume_numBox.text) &&
					getTextInBox(issue_num, issue_numBox.text) &&
					getTextInBox(page, pageBox.text) &&
					getDoubleInBox(10, &GPA_bonus, GPA_bonusBox.text)
					) {

					// 修改
					modifyQuality_rlist(modifying_Rnode, paper_name, journal_or_conference_name, author, date, volume_num, issue_num, page, GPA_bonus);

					// 保存
					saveStu(allStuList, STU_FILE);

					// 使表格可变化
					Stu_Rtable.canChange = true;

					// 刷新表格
					ShowStu_Research(Stu, ResearchData);
					Stu_Rtable.setData(ResearchData);

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
					titleText.setText(L"该学生素质类项目管理");

					//隐藏
					paper_nameBox.move(-500, 70);
					journal_or_conference_nameBox.move(-500, 140);
					authorBox.move(-500, 210);
					dateBox.move(-500, 280);
					volume_numBox.move(-500, 350);
					issue_numBox.move(-500, 420);
					pageBox.move(-500, 490);
					GPA_bonusBox.move(-500, 560);
					modify_ResearchOK_Btn.move(-500, 640);
					cancel_modifyResearch_Btn.move(-500, 720);

					//显示
					add_Research_Btn.move(-50, 200);
					modify_Research_Btn.move(-50, 280);
					delete_Research_Btn.move(-50, 360);
					backButton.move(-50, 600);
					titleText.move(10, 100);


				}
				// 输入错误
				else {
					MessageBox(GetHWnd(), L"输入内容有误，请检查输入内容及格式", L"错误!", MB_ICONWARNING);
				}

			}

			if (cancel_modifyResearch_Btn.mouseClick(msg)) {
				// 更改标题
				titleText.setText(L"该学生素质类项目管理");

				// 清除输入框内容
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				//隐藏
				paper_nameBox.move(-500, 70);
				journal_or_conference_nameBox.move(-500, 140);
				authorBox.move(-500, 210);
				dateBox.move(-500, 280);
				volume_numBox.move(-500, 350);
				issue_numBox.move(-500, 420);
				pageBox.move(-500, 490);
				GPA_bonusBox.move(-500, 560);
				modify_ResearchOK_Btn.move(-500, 640);
				cancel_modifyResearch_Btn.move(-500, 720);

				//显示
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				backButton.move(-50, 600);
				titleText.move(10, 100);

				// 使表格可变化
				Stu_Rtable.canChange = true;
			}

			if (delete_Research_Btn.mouseClick(msg)) {
				if (Stu_Rtable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"请选择一个科研成果", L"错误!", MB_ICONERROR);
				}
				else {
					int result = MessageBox(GetHWnd(), L"确定删除这个科研成果吗?", L"删除科研成果", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) { // 点击确定

						// 精确搜索素质类项目节点
						wchar_t temp[200];
						int selectedRow = Stu_Rtable.getSelectedRow();
						getTextInBox(temp, ResearchData[selectedRow][0].c_str());
						Rnode* modifying_Rnode = searchRnode_in_thisStu(Stu, temp);

						// 删除
						deleteQuality_rlist(Stu, temp);

						// 保存
						saveStu(allStuList, STU_FILE);


						// 刷新表格
						ShowStu_Research(Stu, ResearchData);
						Stu_Rtable.setData(ResearchData);
					}
				}
			}

			if (backButton.mouseClick(msg)) {
				allQualityUI();
			}

			//表格鼠标滑动与点击
			Stu_Rtable.onMouse(msg);

			// 文本框输入
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

			
			FlushBatchDraw(); //批量绘图

			ULONGLONG end_time = GetTickCount();
			if (end_time - start_time < 1) {
				Sleep(1);
			}
	}
}



