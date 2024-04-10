#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student0.txt"
#define CRS_FILE ".\\data\\Course.txt"


void loginUI();
void Modify_Password_UI(wchar_t* account, Node* Stu);
void QualityUI(Node* Stu, List allStuList);
void allQualityUI();

int mainLin() {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����
	
	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
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

	loginUI();



	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���



	return 0;
}


void loginUI() {
	cleardevice();

	//drawLine();

	List StuList = readStu(STU_FILE);
	Node* Stu = StuList->next;


	Text titleText(200, 100, L"��ã����¼!", 64);
	TextBox accountBox(200, 300, 880, L"�˺�", L"");
	TextBox passwordBox(200, 400, 880, L"����", L"");
	Button loginButton(200, 500, 420, 60, L"��¼", 1);
	Button exitButton(660, 500, 420, 60, L"�˳�", 0);
	Button modify_password_Button(860, 600, 220, 50, L"�޸�����", 1);

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		
		accountBox.draw();
		passwordBox.draw();

		if (peekmessage(&msg, -1, true)) {
			
			if (loginButton.mouseClick(msg)) {

				wstring tmp_password;

				while (Stu != NULL) {
					if (wcscmp((to_wstring(Stu->item.data.ID)).c_str(), accountBox.text) == 0) {
						tmp_password = Stu->item.data.password;
						break;
					}
					Stu = Stu->next;
				}

				if (Stu == NULL) { //û��ѧ��ID��֮��Ӧ
					MessageBox(GetHWnd(), L"����������˺ţ����������룡", L"����!", MB_ICONWARNING);
					accountBox.clear();
					passwordBox.clear();
				}
				else if (wcscmp(tmp_password.c_str(), passwordBox.text) == 0) {//�����ѧ����Ӧ����ȷ����������������бȽ�
					menuUI();
				}
				else {
					MessageBox(GetHWnd(), L"����������������룡", L"����!", MB_ICONWARNING);
					passwordBox.clear();
				}
			}
			
			if (exitButton.mouseClick(msg)) {
				exit(0);
			}

			if (modify_password_Button.mouseClick(msg)) {
				
				wstring tmp_password;

				while (Stu != NULL) {
					if (wcscmp((to_wstring(Stu->item.data.ID)).c_str(), accountBox.text) == 0) {
						tmp_password = Stu->item.data.password;
						break;
					}
					Stu = Stu->next;
				}

					if (Stu == NULL) {
						MessageBox(GetHWnd(), L"����������˺ţ��޷��޸����룡", L"����", MB_ICONWARNING);
						accountBox.clear();
						passwordBox.clear();
					}
					else if (wcscmp(tmp_password.c_str(), passwordBox.text) == 0)//�����ѧ����Ӧ����ȷ����������������бȽ�
						Modify_Password_UI(accountBox.text, Stu);

					else {
						MessageBox(GetHWnd(), L"ԭ��������޷��޸����룡", L"����", MB_ICONWARNING);
						passwordBox.clear();
					}
				}
			
			// �ı�������
			accountBox.onMessage(msg);
			passwordBox.onMessage(msg);
		
		}

		//showxy(msg);



		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}
	}

}

void Modify_Password_UI(wchar_t* account,Node* Stu) {

	cleardevice();


	//drawLine();

	List StuList = readStu(STU_FILE);//�����޸����������ļ����б���


	Text titleText(200, 100, L"���޸��������", 64);

	TextBox accountBox(500, 300, 880, L"�˺�", L"");
	TextBox old_passwordBox(500, 400, 880, L"ԭ����", L"");
	TextBox new_passwordBox(500, 500, 880, L"������", L"");
	TextBox confirm_passwordBox(500, 500, 880, L"ȷ��������", L"");
	Button modify_OK_Button(500, 550, 880, 60, L"ȷ���޸�", 1);
	Button backButton(660, 500, 420, 60, L"����", 0);

	Text IDText(500, 45, L"", 32);
	wstring show_ID = L"ѧ�ţ�" + to_wstring(Stu->item.data.ID);
	IDText.setText(show_ID.c_str());

	Text nameText(500, 90, L"", 32);
	wstring tmp_name = Stu->item.data.name;
	wstring show_name = L"������" + tmp_name;
	nameText.setText(show_name.c_str());

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();

		accountBox.draw();
		old_passwordBox.draw();
		new_passwordBox.draw();
		confirm_passwordBox.draw();
		
		//�ı���Ĭ������
		accountBox.setText(account);
		old_passwordBox.setText(Stu->item.data.password);

		if (peekmessage(&msg, -1, true)) {

			if (modify_OK_Button.mouseClick(msg)) {
				if (wcscmp(new_passwordBox.text, confirm_passwordBox.text) == 0) {
					wcscpy(Stu->item.data.password, new_passwordBox.text);
					saveStu(StuList, STU_FILE);

					// ������������
					accountBox.clear();
					old_passwordBox.clear();
					new_passwordBox.clear();
					confirm_passwordBox.clear();

					//�Զ�����
					loginUI();

				}
				else {
					MessageBox(GetHWnd(), L"������������벻һ�£�", L"����!", MB_ICONWARNING);
					confirm_passwordBox.clear();
				}

			}
		
			if (backButton.mouseClick(msg)) {
				loginUI();
			}


			// �ı�������
			new_passwordBox.onMessage(msg);
			confirm_passwordBox.onMessage(msg);

		}

		showxy(msg);



		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}
	}

}

void allQualityUI() {
	
	cleardevice();

	List allStuList = readStu(STU_FILE);
	
	vector<vector<std::wstring>> allQuality_Data;
	//vector<vector<std::wstring>> Stu_Research_Data;

	showAllStu(allStuList, allQuality_Data, L"");

	Table allQuality_Table(310, 90, 940, 700, allQuality_Data);

	Text titleText(10, 100, L"��������Ŀ����", 50);
	//Text IDText(-500, 200, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"����", L"");

	Button searchBtn(1150, 20, 100, 50, L"����", 1);
	Button search_for_quality_Btn(-50, 360, 330, 60, L"   ��ѯ", 1);
	Button exportBtn(-50, 440, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 520, 330, 60, L"   ����", 1);
	Button backButton(-50, 600, 330, 60, L"   ����", 0);

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->
		// ��������(����)
		searchInputBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// ������¼�
			if (searchBtn.mouseClick(msg)) {
				showAllStu(allStuList, allQuality_Data, searchInputBox.text);
				allQuality_Table.setData(allQuality_Data);
			}

			if (search_for_quality_Btn.mouseClick(msg)) {
				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else {
					// ��ȷ����ѧ���ڵ�
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

			
			//�����껬������
			allQuality_Table.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
		
		}
		
		
		//showxy(msg);



		//<-
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}

}


void QualityUI(Node* Stu, List allStuList) {

	cleardevice();

	vector<vector<std::wstring>>ResearchData;
	vector<vector<std::wstring>>CompetitionData;

	ShowStu_Research(Stu, ResearchData);
	ShowStu_Competition(Stu, CompetitionData);

	Table Stu_Rtable(310, 90, 940, 350, ResearchData);
	Table Stu_Ctable(310, 450, 940, 350, CompetitionData);


	//TextBox searchInputBox(310, 20, 820, L"����", L"");
	Text titleText(5, 30, L"��ѧ����������Ŀ", 50);
	Text IDText(500, 45, L"", 32);
	wstring show_ID = L"ѧ�ţ�" + to_wstring(Stu->item.data.ID);
	IDText.setText(show_ID.c_str());
	
	Text nameText(850, 45, L"", 32);
	wstring tmp_name = Stu->item.data.name;
	wstring show_name = L"������" + tmp_name;
	nameText.setText(show_name.c_str());

	TextBox paper_nameBox(-500, 200, 290, L"��������", L"");
	TextBox journal_or_conference_nameBox(-500, 270, 290, L"������ڿ�/��������", L"");
	TextBox authorBox(-500, 340, 290, L"�������", L"");
	TextBox dateBox(-500, 410, 290, L"����ʱ��", L"");
	TextBox volume_numBox(-500, 480, 290, L"����", L"");
	TextBox issue_numBox(-500, 550, 290, L"����", L"");
	TextBox pageBox(-500, 620, 290, L"ҳ�뷶Χ", L"");
	TextBox GPA_bonusBox(-500, 690, 290, L"����ӷ�", L"");

	TextBox competition_nameBox(-500, 200, 290, L"��������", L"");
	TextBox organizerBox(-500, 270, 290, L"�ٰ쵥λ", L"");
	TextBox categoryBox(-500, 340, 290, L"�����", L"");
	TextBox C_dateBox(-500, 410, 290, L"��ʱ��", L"");
	TextBox C_GPA_bonusBox(-500, 690, 290, L"����ӷ�", L"");


	
	//���뵥��ѧ�������������� һ��ʼ��ʾ��
	Button add_Research_Btn(-50, 200, 330, 60, L"   ���гɹ����", 1);
	Button modify_Research_Btn(-50, 280, 330, 60, L"   ���гɹ��޸�", 1);
	Button delete_Research_Btn(-50, 360, 330, 60, L"   ���гɹ�ɾ��", 1);
	Button add_Competition_Btn(-50, 460, 330, 60, L"   ���������", 1);
	Button modify_Competition_Btn(-50, 540, 330, 60, L"   �������޸�", 1);
	Button delete_Competition_Btn(-50, 620, 330, 60, L"   ������ɾ��", 1);


	Button backButton(-50, 700, 290, 60, L"����", 0);

	
	Button modify_ResearchOK_Btn(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button add_ResearchOK_Btn(-500, 640, 290, 60, L"ȷ�����", 1);
	Button modify_CompetitionOK_Btn(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button add_CompetitionOK_Btn(-500, 640, 290, 60, L"ȷ�����", 1);
	
	Button cancel_modifyResearch_Btn(-500, 720, 290, 60, L"ȡ���޸�", 0);
	Button cancel_addResearch_Btn(-500, 720, 290, 60, L"ȡ�����", 0);
	Button cancel_modifyCompetition_Btn(-500, 720, 290, 60, L"ȡ���޸�", 0);
	Button cancel_addCompetition_Btn(-500, 720, 290, 60, L"ȡ�����", 0);


	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();

		// ��������(����)
		paper_nameBox.draw();
		journal_or_conference_nameBox.draw();
		authorBox.draw();
		dateBox.draw();
		volume_numBox.draw();
		issue_numBox.draw();
		pageBox.draw();
		GPA_bonusBox.draw();

		competition_nameBox.draw();
		organizerBox.draw();
		categoryBox.draw();
		C_dateBox.draw();
		C_GPA_bonusBox.draw();



		if (peekmessage(&msg, -1, true)) {

			if (add_Research_Btn.mouseClick(msg)) {

				titleText.setText(L"  ���гɹ����");
				titleText.move(10, 3);
				//����
				add_Research_Btn.move(-500, 200);
				modify_Research_Btn.move(-500, 280);
				delete_Research_Btn.move(-500, 360);
				add_Competition_Btn.move(-500, 460);
				modify_Competition_Btn.move(-500, 540);
				delete_Competition_Btn.move(-500, 620);
				backButton.move(-500, 700);

				//��ʾ
				add_ResearchOK_Btn.move(10, 640);
				cancel_addResearch_Btn.move(10, 720);

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

				wchar_t paper_name[200];//��������
				wchar_t journal_or_conference_name[200];//��������ڿ����������
				wchar_t author[200];// ����������Ƿ�ΪͨѶ���߼���������
				wchar_t date[200];// ��������
				wchar_t volume_num[200];// ����
				wchar_t issue_num[200];// ����
				wchar_t page[200];// ҳ�뷶Χ
				double GPA_bonus;

				// �ж������ʽ
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
						MessageBox(GetHWnd(), L"�ÿ��гɹ��Ѿ�����,�����ظ����!", L"����!", MB_ICONERROR);


						// ������������
						paper_nameBox.clear();
						journal_or_conference_nameBox.clear();
						authorBox.clear();
						dateBox.clear();
						volume_numBox.clear();
						issue_numBox.clear();
						pageBox.clear();
						GPA_bonusBox.clear();

					}
					else {
						// ����
						saveStu(allStuList, STU_FILE);

						// ʹ���ɱ仯
						Stu_Rtable.canChange = true;

						// ˢ�±��
						ShowStu_Research(Stu, ResearchData);
						Stu_Rtable.setData(ResearchData);

						// ������������
						paper_nameBox.clear();
						journal_or_conference_nameBox.clear();
						authorBox.clear();
						dateBox.clear();
						volume_numBox.clear();
						issue_numBox.clear();
						pageBox.clear();
						GPA_bonusBox.clear();

						// ���ı���
						titleText.setText(L"��ѧ����������Ŀ");

						//����
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

						//��ʾ
						add_Research_Btn.move(-50, 200);
						modify_Research_Btn.move(-50, 280);
						delete_Research_Btn.move(-50, 360);
						add_Competition_Btn.move(-50, 460);
						modify_Competition_Btn.move(-50, 540);
						delete_Competition_Btn.move(-50, 620);
						backButton.move(-50, 700);
						titleText.move(5, 30);

					}
				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}
			}

			if (cancel_addResearch_Btn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"��ѧ����������Ŀ");

				// ������������
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				//����
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

				//��ʾ
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				add_Competition_Btn.move(-50, 460);
				modify_Competition_Btn.move(-50, 540);
				delete_Competition_Btn.move(-50, 620);
				backButton.move(-50, 700);
				titleText.move(5, 30);


			}

			if (add_Competition_Btn.mouseClick(msg)) {

				titleText.setText(L" ���������");
				titleText.move(10,100);
				
				//����
				add_Research_Btn.move(-500, 200);
				modify_Research_Btn.move(-500, 280);
				delete_Research_Btn.move(-500, 360);
				add_Competition_Btn.move(-500, 460);
				modify_Competition_Btn.move(-500, 540);
				delete_Competition_Btn.move(-500, 620);
				backButton.move(-500, 700);

				//��ʾ
				add_CompetitionOK_Btn.move(10, 570);
				cancel_addCompetition_Btn.move(10, 650);

				competition_nameBox.move(10, 200);
				organizerBox.move(10, 270);
				categoryBox.move(10, 340);
				C_dateBox.move(10, 410);
				C_GPA_bonusBox.move(10, 480);

			}
			
			if (add_CompetitionOK_Btn.mouseClick(msg)) {

				wchar_t competition_name[200];//��������
				wchar_t organizer[200];//�ٰ쵥λ
				wchar_t category[200];//�����
				wchar_t C_date[200];//��ʱ�� ����
				double C_GPA_bonus;

				// �ж������ʽ
				if (
					getTextInBox(competition_name, competition_nameBox.text) &&
					getTextInBox(organizer, organizerBox.text) &&
					getTextInBox(category, categoryBox.text) &&
					getTextInBox(C_date, C_dateBox.text) &&
					getDoubleInBox(10, &C_GPA_bonus, C_GPA_bonusBox.text)
					) {

					if (!addQuality_clist(Stu, competition_name, organizer, category, C_date, C_GPA_bonus) ){
						MessageBox(GetHWnd(), L"�þ������Ѿ�����,�����ظ����!", L"����!", MB_ICONERROR);

						// ������������
						competition_nameBox.clear();
						organizerBox.clear();
						categoryBox.clear();
						C_dateBox.clear();
						C_GPA_bonusBox.clear();
						
					
					}
					else {
						// ����
						saveStu(allStuList, STU_FILE);

						// ʹ���ɱ仯
						Stu_Ctable.canChange = true;

						// ˢ�±��
						ShowStu_Competition(Stu, CompetitionData);
						Stu_Ctable.setData(CompetitionData);

						// ������������
						competition_nameBox.clear();
						organizerBox.clear();
						categoryBox.clear();
						C_dateBox.clear();
						C_GPA_bonusBox.clear();

						// ���ı���
						titleText.setText(L"��ѧ����������Ŀ");

						//����
						competition_nameBox.move(-500, 200);
						organizerBox.move(-500, 270);
						categoryBox.move(-500, 340);
						C_dateBox.move(-500, 410);
						C_GPA_bonusBox.move(-500, 690);
						add_CompetitionOK_Btn.move(-500, 640);
						cancel_addCompetition_Btn.move(-500, 720);

						//��ʾ
						add_Research_Btn.move(-50, 200);
						modify_Research_Btn.move(-50, 280);
						delete_Research_Btn.move(-50, 360);
						add_Competition_Btn.move(-50, 460);
						modify_Competition_Btn.move(-50, 540);
						delete_Competition_Btn.move(-50, 620);
						backButton.move(-50, 700);
						titleText.move(5, 30);

					}
				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}
			}
			
			if (cancel_addCompetition_Btn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"��ѧ����������Ŀ");

				// ������������
				competition_nameBox.clear();
				organizerBox.clear();
				categoryBox.clear();
				C_dateBox.clear();
				C_GPA_bonusBox.clear();


				//����
				competition_nameBox.move(-500, 200);
				organizerBox.move(-500, 270);
				categoryBox.move(-500, 340);
				C_dateBox.move(-500, 410);
				C_GPA_bonusBox.move(-500, 690);
				add_CompetitionOK_Btn.move(-500, 640);
				cancel_addCompetition_Btn.move(-500, 720);

				//��ʾ
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				add_Competition_Btn.move(-50, 460);
				modify_Competition_Btn.move(-50, 540);
				delete_Competition_Btn.move(-50, 620);
				backButton.move(-50, 700);
				titleText.move(5, 30);


			}
			
			if (modify_Research_Btn.mouseClick(msg)) {
				//ѡ��һ��Ҫ���ĵĿ��гɹ�
				if (Stu_Rtable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ�����гɹ�", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"�޸Ĵ˿��гɹ�");

					//����
					add_Research_Btn.move(-500, 200);
					modify_Research_Btn.move(-500, 280);
					delete_Research_Btn.move(-500, 360);
					add_Competition_Btn.move(-500, 460);
					modify_Competition_Btn.move(-500, 540);
					delete_Competition_Btn.move(-500, 620);
					backButton.move(-500, 700);

					//��ʾ
					modify_ResearchOK_Btn.move(10, 640);
					cancel_modifyResearch_Btn.move(10, 720);

					paper_nameBox.move(10, 70);
					journal_or_conference_nameBox.move(10, 140);
					authorBox.move(10, 210);
					dateBox.move(10, 280);
					volume_numBox.move(10, 350);
					issue_numBox.move(10, 420);
					pageBox.move(10, 490);
					GPA_bonusBox.move(10, 560);
					titleText.move(10, 3);


					// ʹ��񲻿ɱ仯
					Stu_Rtable.canChange = false;

					// ��ȡ��ǰ��
					int selectedRow = Stu_Rtable.getSelectedRow();
					vector<std::wstring> selectedResearch_Data = ResearchData[selectedRow];

					// �ı���Ĭ������
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

				wchar_t paper_name[200];//��������
				wchar_t journal_or_conference_name[200];//��������ڿ����������
				wchar_t author[200];// ����������Ƿ�ΪͨѶ���߼���������
				wchar_t date[200];// ��������
				wchar_t volume_num[200];// ����
				wchar_t issue_num[200];// ����
				wchar_t page[200];// ҳ�뷶Χ
				double GPA_bonus;

				// ��ȷ������������Ŀ�ڵ�
				wchar_t temp[200];
				int selectedRow = Stu_Rtable.getSelectedRow();
				getTextInBox(temp, ResearchData[selectedRow][0].c_str());
				Rnode* modifying_Rnode = searchRnode_in_thisStu(Stu, temp);

				// �ж������ʽ
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

					// �޸�
					modifyQuality_rlist(modifying_Rnode, paper_name, journal_or_conference_name, author, date, volume_num, issue_num, page, GPA_bonus);

					// ����
					saveStu(allStuList, STU_FILE);

					// ʹ���ɱ仯
					Stu_Rtable.canChange = true;

					// ˢ�±��
					ShowStu_Research(Stu, ResearchData);
					Stu_Rtable.setData(ResearchData);

					// ������������
					paper_nameBox.clear();
					journal_or_conference_nameBox.clear();
					authorBox.clear();
					dateBox.clear();
					volume_numBox.clear();
					issue_numBox.clear();
					pageBox.clear();
					GPA_bonusBox.clear();


					// ���ı���
					titleText.setText(L"��ѧ����������Ŀ");

					//����
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

					//��ʾ
					add_Research_Btn.move(-50, 200);
					modify_Research_Btn.move(-50, 280);
					delete_Research_Btn.move(-50, 360);
					add_Competition_Btn.move(-50, 460);
					modify_Competition_Btn.move(-50, 540);
					delete_Competition_Btn.move(-50, 620);
					backButton.move(-50, 700);
					titleText.move(5, 30);


				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (cancel_modifyResearch_Btn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"��ѧ����������Ŀ");

				// ������������
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				//����
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

				//��ʾ
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				add_Competition_Btn.move(-50, 460);
				modify_Competition_Btn.move(-50, 540);
				delete_Competition_Btn.move(-50, 620);
				backButton.move(-50, 700);
				titleText.move(5, 30);

				// ʹ���ɱ仯
				Stu_Rtable.canChange = true;
			}

			if (modify_Competition_Btn.mouseClick(msg)) {
				//ѡ��һ��Ҫ���ĵľ�����
				if (Stu_Ctable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��������", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"�޸Ĵ˾�����");

					//����
					add_Research_Btn.move(-500, 200);
					modify_Research_Btn.move(-500, 280);
					delete_Research_Btn.move(-500, 360);
					add_Competition_Btn.move(-500, 460);
					modify_Competition_Btn.move(-500, 540);
					delete_Competition_Btn.move(-500, 620);
					backButton.move(-500, 700);
					
					//��ʾ
					modify_CompetitionOK_Btn.move(10, 570);
					cancel_modifyCompetition_Btn.move(10, 650);

					competition_nameBox.move(10, 200);
					organizerBox.move(10, 270);
					categoryBox.move(10, 340);
					C_dateBox.move(10, 410);
					C_GPA_bonusBox.move(10, 480);
					titleText.move(10, 100);


					// ʹ��񲻿ɱ仯
					Stu_Ctable.canChange = false;

					// ��ȡ��ǰ��
					int selectedRow = Stu_Ctable.getSelectedRow();
					vector<std::wstring> selectedCompetition_Data = CompetitionData[selectedRow];

					// �ı���Ĭ������
					competition_nameBox.setText(selectedCompetition_Data[0].c_str());
					organizerBox.setText(selectedCompetition_Data[1].c_str());
					categoryBox.setText(selectedCompetition_Data[2].c_str());
					C_dateBox.setText(selectedCompetition_Data[3].c_str());
					C_GPA_bonusBox.setText(selectedCompetition_Data[4].c_str());

				}
			}

			if (modify_CompetitionOK_Btn.mouseClick(msg)) {
				wchar_t competition_name[200];//��������
				wchar_t organizer[200];//�ٰ쵥λ
				wchar_t category[200];//�����
				wchar_t C_date[200];//��ʱ�� ����
				double C_GPA_bonus;

				// ��ȷ������������Ŀ�ڵ�
				wchar_t temp[200];
				int selectedRow = Stu_Ctable.getSelectedRow();
				getTextInBox(temp, CompetitionData[selectedRow][0].c_str());
				Cnode* modifying_Cnode = searchCnode_in_thisStu(Stu, temp);

				// �ж������ʽ
				if (
					getTextInBox(competition_name, competition_nameBox.text) &&
					getTextInBox(organizer, organizerBox.text) &&
					getTextInBox(category, categoryBox.text) &&
					getTextInBox(C_date, C_dateBox.text) &&
					getDoubleInBox(10, &C_GPA_bonus, C_GPA_bonusBox.text)
					) {

					// �޸�
					modifyQuality_clist(modifying_Cnode, competition_name, organizer, category, C_date, C_GPA_bonus);

					// ����
					saveStu(allStuList, STU_FILE);

					// ʹ���ɱ仯
					Stu_Ctable.canChange = true;

					// ˢ�±��
					ShowStu_Competition(Stu, CompetitionData);
					Stu_Ctable.setData(CompetitionData);


					// ������������
					competition_nameBox.clear();
					organizerBox.clear();
					categoryBox.clear();
					C_dateBox.clear();
					C_GPA_bonusBox.clear();

					// ���ı���
					titleText.setText(L"��ѧ����������Ŀ");

					//����
					competition_nameBox.move(-500, 200);
					organizerBox.move(-500, 270);
					categoryBox.move(-500, 340);
					C_dateBox.move(-500, 410);
					C_GPA_bonusBox.move(-500, 690);
					modify_CompetitionOK_Btn.move(-500, 640);
					cancel_modifyCompetition_Btn.move(-500, 720);

					//��ʾ
					add_Research_Btn.move(-50, 200);
					modify_Research_Btn.move(-50, 280);
					delete_Research_Btn.move(-50, 360);
					add_Competition_Btn.move(-50, 460);
					modify_Competition_Btn.move(-50, 540);
					delete_Competition_Btn.move(-50, 620);
					backButton.move(-50, 700);
					titleText.move(5, 30);

				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (cancel_modifyCompetition_Btn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"��ѧ����������Ŀ");

				// ������������
				competition_nameBox.clear();
				organizerBox.clear();
				categoryBox.clear();
				C_dateBox.clear();
				C_GPA_bonusBox.clear();


				//����
				competition_nameBox.move(-500, 200);
				organizerBox.move(-500, 270);
				categoryBox.move(-500, 340);
				C_dateBox.move(-500, 410);
				C_GPA_bonusBox.move(-500, 690);
				modify_CompetitionOK_Btn.move(-500, 640);
				cancel_modifyCompetition_Btn.move(-500, 720);

				//��ʾ
				add_Research_Btn.move(-50, 200);
				modify_Research_Btn.move(-50, 280);
				delete_Research_Btn.move(-50, 360);
				add_Competition_Btn.move(-50, 460);
				modify_Competition_Btn.move(-50, 540);
				delete_Competition_Btn.move(-50, 620);
				backButton.move(-50, 700);
				titleText.move(5, 30);

				Stu_Ctable.canChange = true;


			}

			if (delete_Research_Btn.mouseClick(msg)) {
				if (Stu_Rtable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ�����гɹ�", L"����!", MB_ICONERROR);
				}
				else {
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ��������гɹ���?", L"ɾ�����гɹ�", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) { // ���ȷ��

						// ��ȷ������������Ŀ�ڵ�
						wchar_t temp[200];
						int selectedRow = Stu_Rtable.getSelectedRow();
						getTextInBox(temp, ResearchData[selectedRow][0].c_str());
						Rnode* modifying_Rnode = searchRnode_in_thisStu(Stu, temp);

						// ɾ��
						deleteQuality_rlist(Stu, temp);

						// ����
						saveStu(allStuList, STU_FILE);


						// ˢ�±��
						ShowStu_Research(Stu, ResearchData);
						Stu_Rtable.setData(ResearchData);
					}
				}
			}

			if (delete_Competition_Btn.mouseClick(msg)) {
				if (Stu_Ctable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��������", L"����!", MB_ICONERROR);
				}
				else {
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ�������������?", L"ɾ��������", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) { // ���ȷ��

						// ��ȷ������������Ŀ�ڵ�
						wchar_t temp[200];
						int selectedRow = Stu_Ctable.getSelectedRow();
						getTextInBox(temp, CompetitionData[selectedRow][0].c_str());
						Cnode* modifying_Cnode = searchCnode_in_thisStu(Stu, temp);

						// ɾ��
						deleteQuality_clist(Stu, temp);

						// ����
						saveStu(allStuList, STU_FILE);


						// ˢ�±��
						ShowStu_Competition(Stu,CompetitionData);
						Stu_Ctable.setData(CompetitionData);
					}
				}
			}

			if (backButton.mouseClick(msg)) {
				allQualityUI();
			}

			//�����껬������
			Stu_Rtable.onMouse(msg);
			Stu_Ctable.onMouse(msg);


			// �ı�������
			paper_nameBox.onMessage(msg);
			journal_or_conference_nameBox.onMessage(msg);
			authorBox.onMessage(msg);
			dateBox.onMessage(msg);
			volume_numBox.onMessage(msg);
			issue_numBox.onMessage(msg);
			pageBox.onMessage(msg);
			GPA_bonusBox.onMessage(msg);

			competition_nameBox.onMessage(msg);
			organizerBox.onMessage(msg);
			categoryBox.onMessage(msg);
			C_dateBox.onMessage(msg);
			C_GPA_bonusBox.onMessage(msg);


		
		}
			//showxy(msg);

			
			FlushBatchDraw(); //������ͼ

			ULONGLONG end_time = GetTickCount();
			if (end_time - start_time < 1) {
				Sleep(1);
			}
	}
}



