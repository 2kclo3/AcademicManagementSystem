#pragma warning(disable:4996)
#include "ui.h"
#define PAGE_FILE "Page.txt"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



void printStu(const List StuList) {

	List pStu = StuList->next; // ��ͷ������һ���ڵ㿪ʼ
	while (pStu != NULL) {
		wprintf(L"ѧ����Ϣ:\n%d\t%s\t%d\t%d\t%s\t%s\n\n�γ̣�\n",
			pStu->item.data.ID,
			pStu->item.data.name,
			pStu->item.data.gender,
			pStu->item.data.grade,
			pStu->item.data.college,
			pStu->item.data.major);

		Crsnode* pcrs = pStu->item.crslist->crs_next; // ����һ���γ̽ڵ㿪ʼ
		while (pcrs != NULL) {
			wprintf(L"%s\t%s\t%.1lf\t%d\t%d\t%.1lf\t%.1lf\n",
				pcrs->score.course_id,
				pcrs->score.course_name,
				pcrs->score.score,
				pcrs->score.semester,
				pcrs->score.course_nature,
				pcrs->score.credit,
				pcrs->score.grid);

			pcrs = pcrs->crs_next; // �ƶ�����һ���ڵ�
		}

		wprintf(L"\n���гɹ���\n");
		Rnode* pres = pStu->item.rlist->rnext; // ����һ�����гɹ��ڵ㿪ʼ
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

			pres = pres->rnext; // �ƶ�����һ���ڵ�
		}


		wprintf(L"\n�����񽱣�\n");
		Cnode* pcpt = pStu->item.clist->cnext; // ����һ�������񽱽ڵ㿪ʼ
		while (pcpt != NULL) {
			wprintf(L"%s\t%s\t%s\t%s\t%.2lf\n",
				pcpt->competition.competition_name,
				pcpt->competition.organizer,
				pcpt->competition.category,
				pcpt->competition.date,
				pcpt->competition.GPA_bonus);

			pcpt = pcpt->cnext; // �ƶ�����һ���ڵ�
		}


		wprintf(L"\n--------------------------------------------------------------------------\n\n");
		pStu = pStu->next; // �ƶ�����һ���ڵ�
	}


}
void printCrs(const Cpnode CrsList) {
	Cpnode pCrs = CrsList->next; // ��ͷ������һ���ڵ㿪ʼ
	while (pCrs != NULL) {
		wprintf(L"�γ���Ϣ:\n%d\t%s\t%s\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\nѧ����\n",
			pCrs->cnum,
			pCrs->cname,
			pCrs->character,
			pCrs->headcount,
			pCrs->totscore,
			pCrs->averscore,
			pCrs->totGPA,
			pCrs->averGPA); // д��

		Spnode pstu = pCrs->sphead->next; // ����һ��ѧ���ڵ㿪ʼ
		while (pstu != NULL) {
			wprintf(L"%d\t%s\t%.1lf\t%.1lf\n",
				pstu->snum,
				pstu->sname,
				pstu->score,
				pstu->GPA); // д��

			pstu = pstu->next; // �ƶ�����һ���ڵ�
		}
		wprintf(L"\n--------------------------------------------------------------------------\n\n");
		pCrs = pCrs->next; // �ƶ�����һ���ڵ�
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
	settextstyle(32, 0, L"΢���ź�");
	outtextxy(0, 0, text);



}


void testUI() {
	//drawLine();


	// ������ť���󲢻���
	//Button button1(-50, 100, 300, 50, L"���԰�ť", 0x00009688, WHITE);
	//Text text1(100, 0, L"���� Test", 50, BLACK);
	//Button button2(-50, 160, 300, 50, L"���԰�ť", 0x123456, WHITE);
	Button exitButton(50, 500, 200, 60, L"�˳�", LIGHTBLUE, WHITE);
	Button selectRowBtn1(350, 500, 300, 60, L"ѡ�������", 0x123456, WHITE);

	//TextBox box1(50, 250, 500, L"����1", L"ceshi");
	//TextBox box2(90, 400, 800, L"����2", L"");


	TextBox selectBox(280, 400, 300, L"�ĸ����", L"");

	Table table1(360, 100, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"1ѧ��",L"����",L"�Ա�",L"�ɼ�"},
			{L"2023001",L"����",L"��",L"6000"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023003",L"����",L"��",L"90"},
			{L"2023004",L"С��",L"Ů",L"80"},
			{L"2023005",L"С��",L"��",L"70"},
			{L"2023006",L"С��",L"��",L"60"},
			{L"2023007",L"С��",L"��",L"70"},
			{L"2023008",L"����",L"��",L"60"},
			{L"2023009",L"����",L"Ů",L"40"},
			{L"2023010",L"����666",L"��",L"30"},
			{L"2023011",L"����",L"��",L"20"},
			{L"2023012",L"����",L"Ů",L"10"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023012",L"����",L"Ů",L"10"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����777",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����888",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����999",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"Last",L"Ů",L"100"},
		}
	);

	Table table3(30, 150, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"3ѧ��",L"����",L"�Ա�",L"�ɼ�"},
			{L"2023001",L"����",L"��",L"6000"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023003",L"����",L"��",L"90"},
			{L"2023015",L"Last",L"Ů",L"100"},
		}
	);

	Table table2(700, 50, 450, 720, RGB(55, 61, 53), WHITE,
		{
			{L"2ѧ��",L"����",L"�Ա�",L"�ɼ�", L"test1", L"test0333"},
			{L"2023001",L"����",L"��",L"6000", L"test222"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023003",L"����",L"��",L"90"},
			{L"2023004",L"С��",L"Ů",L"80"},
			{L"2023005",L"С��",L"��",L"70"},
			{L"2023006",L"С��",L"��",L"60"},
			{L"2023007",L"С��",L"��",L"70"},
			{L"2023008",L"����",L"��",L"60"},
			{L"2023009",L"����",L"Ů",L"40"},
			{L"2023010",L"����666",L"��",L"30"},
			{L"2023011",L"����",L"��",L"20"},
			{L"2023012",L"����",L"Ů",L"10"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023012",L"����",L"Ů",L"10"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����777",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����888",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����999",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023013",L"����",L"��",L"80"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023014",L"����",L"Ů",L"90"},
			{L"2023015",L"����",L"Ů",L"100"},
			{L"2023001",L"����",L"��",L"60"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023015",L"Last",L"Ů",L"100"},
		}
	);



	// ��������¼�
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


		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}
	}





}


void loginUI() {
	cleardevice();



	//drawLine();


	Text titleText(200, 100, L"��ã����¼!", 64, RGB(228, 226, 223));
	TextBox accountBox(200, 300, 880, L"�˺�", L"");
	TextBox passwordBox(200, 400, 880, L"����", L"");
	Button loginButton(200, 500, 420, 60, L"��¼", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exitButton(660, 500, 420, 60, L"�˳�", RGB(73, 78, 70), RGB(200, 198, 195));

	// ��������¼�
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



		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}
	}






}


void menuUI() {
	cleardevice();


	//drawLine();

	Text titleText(90, 50, L"��ӭ", 64, RGB(228, 226, 223));
	Button allStuButton(-50, 170, 350, 60, L"  �鿴ѧ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button allCrsButton(-50, 250, 350, 60, L"  �鿴�γ�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button allQualityButton(-50, 330, 350, 60, L"  ��������Ŀ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button changeMajorButton(-50, 410, 350, 60, L"  תרҵ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button settingsButton(-50, 490, 350, 60, L"  ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exitButton(-50, 580, 350, 60, L"  �˳���¼", RGB(73, 78, 70), RGB(200, 198, 195));

	// ��������¼�
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




		FlushBatchDraw(); //������ͼ

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

	Text titleText(40, 50, L"����ѧ��", 64, RGB(228, 226, 223));
	Text IDText(-500, 150, L"", 32, WHITE);

	TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox IDBox(-500, 150, 290, L"ѧ��(���ɸ���)", L"");
	TextBox nameBox(-500, 220, 290, L"����", L"");
	TextBox genderBox(-500, 290, 290, L"�Ա� (Ů:0,��:1)", L"");
	TextBox gradeBox(-500, 360, 290, L"�꼶", L"");
	TextBox collegeBox(-500, 430, 290, L"ѧԺ", L"");
	TextBox majorBox(-500, 500, 290, L"רҵ", L"");

	Button searchBtn(1150, 20, 100, 50, L"����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 150, 330, 60, L"   ���", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 230, 330, 60, L"   �޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 310, 330, 60, L"   ɾ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button sortBtn(-50, 390, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 470, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 550, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 650, 330, 60, L"   ����", RGB(73, 78, 70), RGB(200, 198, 195));
	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", RGB(73, 78, 70), RGB(200, 198, 195));

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//-------------------------------------------------

		// ��������(����)
		searchInputBox.draw();
		IDBox.draw();
		nameBox.draw();
		genderBox.draw();
		gradeBox.draw();
		collegeBox.draw();
		majorBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// ������¼�
			if (searchBtn.mouseClick(msg)) {
				showAllStuTest(allStuList, allStuData, searchInputBox.text);
				allStuTable.setData(allStuData);
			}

			if (addBtn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"���ѧ��");
				// ����
				addBtn.move(-500, 150);
				modifyBtn.move(-500, 230);
				deleteBtn.move(-500, 310);
				sortBtn.move(-500, 390);
				exportBtn.move(-500, 470);
				inportBtn.move(-500, 550);
				backButton.move(-500, 650);

				// ��ʾ
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
				// ���ı���
				titleText.setText(L"����ѧ��");

				// ������������
				IDBox.clear();
				nameBox.clear();
				genderBox.clear();
				gradeBox.clear();
				collegeBox.clear();
				majorBox.clear();

				// ʹ���ɱ仯
				allStuTable.canChange = true;

				// ����
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

				// ��ʾ
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

				// ��ȡ��ǰ���(�ж��꼶Ҫ��)
				time_t Current_time = time(NULL);
				int Current_year = localtime(&Current_time)->tm_year + 1900;

				// �ж������ʽ
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

					// ѧ����ͬ�����,��������
					if (!addStu(&allStuList, name, id, gender, grade, college, major)) {
						MessageBox(GetHWnd(), L"��ѧ���Ѿ�����,�����ظ����!", L"����!", MB_ICONERROR);
					}
					// ���򱣴�
					else {
						// ����
						saveStu(allStuList, STU_FILE);

						// ˢ�±��
						showAllStuTest(allStuList, allStuData, searchInputBox.text);
						allStuTable.setData(allStuData);

						// ������������
						IDBox.clear();
						nameBox.clear();
						genderBox.clear();
						gradeBox.clear();
						collegeBox.clear();
						majorBox.clear();


						// ���ı���
						titleText.setText(L"����ѧ��");

						// ����
						IDBox.move(-500, 150);
						nameBox.move(-500, 220);
						genderBox.move(-500, 290);
						gradeBox.move(-500, 360);
						collegeBox.move(-500, 430);
						majorBox.move(-500, 500);
						addOKButton.move(-500, 580);
						cancelButton.move(-500, 660);

						// ��ʾ
						addBtn.move(-50, 150);
						modifyBtn.move(-50, 230);
						deleteBtn.move(-50, 310);
						sortBtn.move(-50, 390);
						exportBtn.move(-50, 470);
						inportBtn.move(-50, 550);
						backButton.move(-50, 650);

					}


				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (modifyBtn.mouseClick(msg)) {
				// δѡ��ѧ��
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"�޸�ѧ��");
					// ����
					addBtn.move(-500, 150);
					modifyBtn.move(-500, 230);
					deleteBtn.move(-500, 310);
					sortBtn.move(-500, 390);
					exportBtn.move(-500, 470);
					inportBtn.move(-500, 550);
					backButton.move(-500, 650);


					// ʹ��񲻿ɱ仯
					allStuTable.canChange = false;


					// ��ȡ��ǰ��
					int selectedRow = allStuTable.getSelectedRow();
					vector<std::wstring> selectedData = allStuData[selectedRow];


					// �ı���Ĭ������
					IDText.setText((L"ѧ��:" + selectedData[0]).c_str()); // C++�﷨
					nameBox.setText(selectedData[1].c_str());
					genderBox.setText(wcscmp(selectedData[2].c_str(), L"��") ? L"0" : L"1");
					gradeBox.setText(selectedData[3].c_str());
					collegeBox.setText(selectedData[4].c_str());
					majorBox.setText(selectedData[5].c_str());

					// ��ʾ
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

				// ��ȡ��ǰ���(�ж��꼶Ҫ��)
				time_t Current_time = time(NULL);
				int Current_year = localtime(&Current_time)->tm_year + 1900;

				// ��ȷ����ѧ���ڵ�
				int tempID;
				int selectedRow = allStuTable.getSelectedRow(); // ��ȡ��ǰ��
				getNumberInBox(99999999, &tempID, allStuData[selectedRow][0].c_str());
				Node* modifyingStu = searchStu(&allStuList, (wchar_t*)allStuData[selectedRow][1].c_str(), tempID);

				// �ж������ʽ
				if (
					getTextInBox(name, nameBox.text) &&
					getNumberInBox(1, &gender, genderBox.text) &&
					getNumberInBox(9999, &grade, gradeBox.text) &&
					getTextInBox(college, collegeBox.text) &&
					getTextInBox(major, majorBox.text) &&
					(grade > 1970 && grade <= Current_year)
					) {

					// �޸�
					modifyStu(&allStuList, modifyingStu, name, tempID, gender, grade, college, major);

					// ����
					saveStu(allStuList, STU_FILE);

					// ʹ���ɱ仯
					allStuTable.canChange = true;

					// ˢ�±��
					showAllStuTest(allStuList, allStuData, searchInputBox.text);
					allStuTable.setData(allStuData);

					// ������������
					IDBox.clear();
					nameBox.clear();
					genderBox.clear();
					gradeBox.clear();
					collegeBox.clear();
					majorBox.clear();


					// ���ı���
					titleText.setText(L"����ѧ��");

					// ����
					IDBox.move(-500, 150);
					nameBox.move(-500, 220);
					genderBox.move(-500, 290);
					gradeBox.move(-500, 360);
					collegeBox.move(-500, 430);
					majorBox.move(-500, 500);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// ��ʾ
					addBtn.move(-50, 150);
					modifyBtn.move(-50, 230);
					deleteBtn.move(-50, 310);
					sortBtn.move(-50, 390);
					exportBtn.move(-50, 470);
					inportBtn.move(-50, 550);
					backButton.move(-50, 650);



				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (deleteBtn.mouseClick(msg)) {
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else {
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ�����ѧ����?", L"ɾ��ѧ��", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) { // ���ȷ��

						// ��ȡ��ǰ���(�ж��꼶Ҫ��)
						time_t Current_time = time(NULL);
						int Current_year = localtime(&Current_time)->tm_year + 1900;

						// ��ȷ����ѧ���ڵ�
						int tempID;
						int selectedRow = allStuTable.getSelectedRow(); // ��ȡ��ǰ��
						getNumberInBox(99999999, &tempID, allStuData[selectedRow][0].c_str());
						Node* deletingStu = searchStu(&allStuList, (wchar_t*)allStuData[selectedRow][1].c_str(), tempID);

						// ɾ��
						deleteStu(&allStuList, deletingStu);

						// ����
						saveStu(allStuList, STU_FILE);


						// ˢ�±��
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


			//�����껬������
			allStuTable.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
			IDBox.onMessage(msg);
			nameBox.onMessage(msg);
			genderBox.onMessage(msg);
			gradeBox.onMessage(msg);
			collegeBox.onMessage(msg);
			majorBox.onMessage(msg);
		}

		//showxy(msg); // ��ʾ����



		//-------------------------------------------------
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}
}


void allCrsUI() {
	cleardevice();

	drawLine();


	Text titleText(40, 50, L"���пγ�", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   ��ѯ�γ�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   ��ӿγ�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   �޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   ɾ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button statisticBtn(-50, 460, 330, 60, L"   ͳ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 540, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 620, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 700, 330, 60, L"   ����", RGB(73, 78, 70), RGB(200, 198, 195));


	// ��������¼�
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
		FlushBatchDraw(); //������ͼ

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


	Text titleText(20, 50, L"��������Ŀ", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 190, 330, 60, L"   ��ѯ", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 280, 330, 60, L"   ���", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 370, 330, 60, L"   �޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 460, 330, 60, L"   ɾ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 550, 330, 60, L"   ����", RGB(73, 78, 70), RGB(200, 198, 195));


	// ��������¼�
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
		FlushBatchDraw(); //������ͼ

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


	Text titleText(90, 50, L"����", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   ��ѯ�γ�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   ��ӿγ�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   �޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   ɾ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button statisticBtn(-50, 460, 330, 60, L"   ͳ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button exportBtn(-50, 540, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button inportBtn(-50, 620, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
	Button backButton(-50, 700, 330, 60, L"   ����", RGB(73, 78, 70), RGB(200, 198, 195));


	// ��������¼�
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
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1000 / 120) {
			Sleep((DWORD)(1000 / 120 - (end_time - start_time)));
		}

	}


}


void QualityUI() {
}









bool showAllStuTest(const List StuList, vector<vector<std::wstring>>& data, const wchar_t* searchTerm) {
	List pCurrent = StuList->next; //�ӵ�һ�������ݽڵ㿪ʼ
	data.clear(); // �������
	data.push_back(vector<std::wstring>(6, L"")); //����һ��(ÿ��6��)

	//��ʼ����ͷ
	data[0][0] = L"ѧ��";
	data[0][1] = L"����";
	data[0][2] = L"�Ա�";
	data[0][3] = L"�꼶";
	data[0][4] = L"ѧԺ";
	data[0][5] = L"רҵ";


	int row = 1;
	while (pCurrent != NULL) { //��������
		//if (searchTerm != NULL) {

		// ����Ƿ���������
		if (wcsstr(std::to_wstring(pCurrent->item.data.ID).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pCurrent->item.data.grade).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.major, searchTerm) != NULL
			) {

			data.push_back(vector<std::wstring>(6, L"")); //����һ��(ÿ��6��)

			//ÿ�е�����
			data[row][0] = std::to_wstring(pCurrent->item.data.ID); //����תΪ�ַ���
			data[row][1] = pCurrent->item.data.name;
			data[row][2] = (pCurrent->item.data.gender) ? L"��" : L"Ů";
			data[row][3] = std::to_wstring(pCurrent->item.data.grade); //����תΪ�ַ���
			data[row][4] = pCurrent->item.data.college;
			data[row][5] = pCurrent->item.data.major;

			row++; // ����+1
		}

		pCurrent = pCurrent->next; // ������һ���ڵ�

	}

	return true;
}





