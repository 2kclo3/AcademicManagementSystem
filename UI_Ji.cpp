#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainJi(void) {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����
	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();

	//testUI();

	//------------
	allStuUI();
	//------------



	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���
	return 0;
}


void allStuUI() {
	cleardevice();

	//drawLine();


	List allStuList = readStu(STU_FILE);

	vector<vector<std::wstring>> allStuData;
	showAllStu(allStuList, allStuData, L"");

	Table allStuTable(310, 90, 940, 700, allStuData);

	Text titleText(40, 50, L"����ѧ��", 64);
	Text IDText(-500, 150, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox IDBox(-500, 150, 290, L"ѧ�� ( ��Ӻ󲻿ɸ��ģ�)", L"");
	TextBox nameBox(-500, 220, 290, L"����", L"");
	TextBox genderBox(-500, 290, 290, L"�Ա� ( Ů:0, ��:1 )", L"");
	TextBox gradeBox(-500, 360, 290, L"�꼶", L"");
	TextBox collegeBox(-500, 430, 290, L"ѧԺ", L"");
	TextBox majorBox(-500, 500, 290, L"רҵ", L"");

	Button searchBtn(1150, 20, 100, 50, L"����", 1);
	Button addBtn(-50, 150, 330, 60, L"   ���", 1);
	Button modifyBtn(-50, 230, 330, 60, L"   �޸�", 1);
	Button deleteBtn(-50, 310, 330, 60, L"   ɾ��", 1);
	Button sortBtn(-50, 390, 330, 60, L"   ����", 1);
	Button exportBtn(-50, 470, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 550, 330, 60, L"   ����", 1);
	Button backButton(-50, 650, 330, 60, L"   ����", 0);
	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", 0);

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
				showAllStu(allStuList, allStuData, searchInputBox.text);
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
						showAllStu(allStuList, allStuData, L"");
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
					showAllStu(allStuList, allStuData, searchInputBox.text);
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

		showxy(msg); // ��ʾ����



		//-------------------------------------------------
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}
}


void StuUI() {
}

