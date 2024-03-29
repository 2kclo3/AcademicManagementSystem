#pragma warning(disable:4996)
#include "ui.h"
#define PAGE_FILE "Page.txt"




//wchar_t* show_page(wchar_t* page_name)
//{
//	system("cls");//��տ���̨����
//	FILE* fp = NULL;
//	fp = fopen(PAGE_FILE, "r");//��ֻ����ʽ���ļ�
//	if (fp == NULL) {
//		wprintf(L"Read %s errer, please check and reboot the system!", PAGE_FILE);
//		exit(EXIT_FAILURE);
//	}
//	//����ȡʧ��ʱ��Ҫ�����������ϵͳ
//
//	wchar_t start_tag[30], end_tag[30];
//	swprintf(start_tag, L"%s<<<", page_name);
//	swprintf(end_tag, L">>>%s", page_name);//����Ѱ�ҵĿ�ʼ�ͽ�����ǩ
//
//	bool start_found = 0;
//	wchar_t line[512];
//	while (fgetws(line, sizeof(line), fp) != NULL) {//һ��һ��Ѱ�ұ�ǩ����ӡ
//		if (_tcsstr(line, start_tag) != NULL) {
//			start_found = 1;
//			continue;
//		}//�ҵ���ʼ��ǩ������������һ�п�ʼ��ӡ
//		if (_tcsstr(line, end_tag) != NULL) {
//			break;
//		}//�ҵ�������ǩ������ѭ��
//		if (start_found == 1) {
//			wprintf(L"%s", line);
//		}//��ӡ��ǰ��
//	}
//
//	fclose(fp);//�ر��ļ�
//	return page_name;
//
//}


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
		wprintf(L"�γ���Ϣ:\n%d\t%s\t%d\t%d\t%.1lf\t%.2lf\t%.1lf\t%.2lf\n\nѧ����\n",
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
	Button selectRowBtn1(350, 400, 300, 60, L"ѡ�������", 0x123456, WHITE);

	//TextBox box1(50, 250, 500, L"����1", L"ceshi");
	//TextBox box2(90, 400, 800, L"����2", L"");



	Table table1(300, 100, 300, 250, RGB(55, 61, 53), WHITE,
		{
			{L"ѧ��",L"����",L"�Ա�",L"�ɼ�"},
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

	Table table2(700, 50, 400, 720, RGB(55, 61, 53), WHITE,
		{
			{L"ѧ��",L"����",L"�Ա�",L"�ɼ�"},
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


	// ��������¼�
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

	drawLine();


	Text titleText(40, 50, L"����ѧ��", 64, RGB(228, 226, 223));
	Button searchBtn(-50, 140, 330, 60, L"   ��ѯѧ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button addBtn(-50, 220, 330, 60, L"   ���", RGB(191, 202, 185), RGB(42, 51, 40));
	Button modifyBtn(-50, 300, 330, 60, L"   �޸�", RGB(191, 202, 185), RGB(42, 51, 40));
	Button deleteBtn(-50, 380, 330, 60, L"   ɾ��", RGB(191, 202, 185), RGB(42, 51, 40));
	Button sortBtn(-50, 460, 330, 60, L"   ����", RGB(191, 202, 185), RGB(42, 51, 40));
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

				//// �������޸����뷽ʽ
				//wchar_t stuID[512];
				//InputBox(stuID, 512, L"������ѧ��", L"��ѯѧ��", L"", 0, 0, false);
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






