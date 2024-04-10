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
	//Text text1(100, 0, L"���� Test", 50);
	//Button button2(-50, 160, 300, 50, L"���԰�ť", 0x123456, WHITE);
	Button exitButton(50, 500, 200, 60, L"�˳�", 1);
	Button selectRowBtn1(350, 500, 300, 60, L"ѡ�������", 0);

	//TextBox box1(50, 250, 500, L"����1", L"ceshi");
	//TextBox box2(90, 400, 800, L"����2", L"");


	TextBox selectBox(280, 400, 300, L"�ĸ����", L"");

	Table table1(360, 100, 300, 250,
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

	Table table3(30, 150, 300, 250,
		{
			{L"3ѧ��",L"����",L"�Ա�",L"�ɼ�"},
			{L"2023001",L"����",L"��",L"6000"},
			{L"2023002",L"����",L"��",L"50"},
			{L"2023003",L"����",L"��",L"90"},
			{L"2023015",L"Last",L"Ů",L"100"},
		}
	);

	Table table2(700, 50, 450, 720,
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
		if (end_time - start_time < 1) {
			Sleep(1);
		}
	}





}


void loginUI() {
	cleardevice();



	//drawLine();


	Text titleText(200, 100, L"��ã����¼!", 64);
	TextBox accountBox(200, 300, 880, L"�˺�", L"");
	TextBox passwordBox(200, 400, 880, L"����", L"");
	Button loginButton(200, 500, 420, 60, L"��¼", 1);
	Button exitButton(660, 500, 420, 60, L"�˳�", 0);
	std::cout << 1 << std::endl;
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
		if (end_time - start_time < 1) {
			Sleep(1);
		}
	}






}


void menuUI() {
	cleardevice();


	//drawLine();

	Text titleText(90, 50, L"��ӭ", 64);
	Button allStuButton(-50, 170, 350, 60, L"  �鿴ѧ��", 1);
	Button allCrsButton(-50, 250, 350, 60, L"  �鿴�γ�", 1);
	Button allQualityButton(-50, 330, 350, 60, L"  ��������Ŀ����", 1);
	Button changeMajorButton(-50, 410, 350, 60, L"  תרҵ����", 1);
	Button settingsButton(-50, 490, 350, 60, L"  ����", 1);
	Button exitButton(-50, 580, 350, 60, L"  �˳���¼", 0);

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
		if (end_time - start_time < 1) {
			Sleep(1);
		}
	}







}



void changeMajorUI() {

}




void settingsUI() {

	cleardevice();

	drawLine();


	Text titleText(90, 50, L"����", 64);
	Button searchBtn(-50, 140, 330, 60, L"   ��ѯ�γ�", 1);
	Button addBtn(-50, 220, 330, 60, L"   ��ӿγ�", 1);
	Button modifyBtn(-50, 300, 330, 60, L"   �޸�", 1);
	Button deleteBtn(-50, 380, 330, 60, L"   ɾ��", 1);
	Button statisticBtn(-50, 460, 330, 60, L"   ͳ��", 1);
	Button exportBtn(-50, 540, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 620, 330, 60, L"   ����", 1);
	Button backButton(-50, 700, 330, 60, L"   ����", 0);


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
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}


}



//int abc(){
//	int a[100];
//
//	vector<int> b;
//	b.push_back(1);
//	b[0];
//	b.pop_back();
//	b.clear();
//}






