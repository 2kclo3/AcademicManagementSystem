#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



bool showAllMajor(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm);

int mainLLLL(void) {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����



	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();




	//testUI();


	//allStuUI();
	loginUI();







	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���





	return 0;
}


// ��ʾתרҵ����רҵ
bool showAllMajor(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm) {
	List pCurrent = StuList->next; //�ӵ�һ�������ݽڵ㿪ʼ
	data.clear(); // �������
	data.push_back(vector<wstring>(8, L"")); //����һ��(ÿ��8��)

	//��ʼ����ͷ
	data[0][0] = L"ѧ��";
	data[0][1] = L"����";
	data[0][2] = L"�Ա�";
	data[0][3] = L"�꼶";
	data[0][4] = L"ѧԺ";
	data[0][5] = L"רҵ";
	//data[0][6] = L"ԭѧԺ";
	data[0][7] = L"ԭרҵ";



	int row = 1;
	while (pCurrent != NULL) { //��������

		// ����Ƿ���������
		if (wcsstr(std::to_wstring(pCurrent->item.data.ID).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pCurrent->item.data.grade).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.major, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.original_college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.original_major, searchTerm) != NULL
			) {

			data.push_back(vector<std::wstring>(8, L"")); //����һ��(ÿ��8��)

			//ÿ�е�����
			data[row][0] = std::to_wstring(pCurrent->item.data.ID); //����תΪ�ַ���
			data[row][1] = pCurrent->item.data.name;
			data[row][2] = (pCurrent->item.data.gender) ? L"��" : L"Ů";
			data[row][3] = std::to_wstring(pCurrent->item.data.grade); //����תΪ�ַ���
			data[row][4] = pCurrent->item.data.college;
			data[row][5] = pCurrent->item.data.major;
			if (wcscmp(pCurrent->item.data.college, pCurrent->item.data.original_college) != 0 ||
				wcscmp(pCurrent->item.data.major, pCurrent->item.data.original_major) != 0) {
				//data[row][6] = pCurrent->item.data.original_college;
				data[row][7] = pCurrent->item.data.original_major;
			}

			row++; // ����+1
		}

		pCurrent = pCurrent->next; // ������һ���ڵ�

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

	Text titleText(25, 50, L"תרҵ����", 64);
	Text IDText(-500, 150, L"", 32);
	Text nameText(-500, 220, L"", 32);
	Text genderText(-500, 290, L"", 32);
	Text gradeText(-500, 360, L"", 32);
	Text collegeText(-500, 430, L"", 32);
	Text majorText(-500, 500, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox gradeBox(-500, 360, 290, L"�꼶", L"");
	TextBox collegeBox(-500, 430, 290, L"ѧԺ", L"");
	TextBox majorBox(-500, 500, 290, L"רҵ", L"");

	Button searchBtn(1150, 20, 100, 50, L"����", 1);
	Button modifyBtn(-50, 190, 330, 60, L"   תרҵ", 1);
	Button sortBtn(-50, 280, 330, 60, L"   ����", 1);
	Button exportBtn(-50, 370, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 460, 330, 60, L"   ����", 1);
	Button backButton(-50, 580, 330, 60, L"   ����", 0);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", 0);

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//-------------------------------------------------

		// ��������(����)
		searchInputBox.draw();
		gradeBox.draw();
		collegeBox.draw();
		majorBox.draw();

		if (peekmessage(&msg, -1, true)) {

			// ������¼�
			if (searchBtn.mouseClick(msg)) {
				showAllMajor(allStuList, allStuData, searchInputBox.text);
				allStuTable.setData(allStuData);
			}


			if (cancelButton.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"תרҵ����");

				// ������������
				gradeBox.clear();
				collegeBox.clear();
				majorBox.clear();

				// ʹ���ɱ仯
				allStuTable.canChange = true;

				// ����
				IDText.move(-500, 150);
				nameText.move(-500, 220);
				genderText.move(-500, 290);
				IDText.move(-500, 150);
				gradeBox.move(-500, 360);
				collegeBox.move(-500, 430);
				majorBox.move(-500, 500);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// ��ʾ
				modifyBtn.move(-50, 190);
				sortBtn.move(-50, 280);
				exportBtn.move(-50, 370);
				inportBtn.move(-50, 460);
				backButton.move(-50, 580);

			}


			if (modifyBtn.mouseClick(msg)) {
				// ��ȡ��ǰ��
				int selectedRow = allStuTable.getSelectedRow();
				vector<std::wstring> selectedData = allStuData[selectedRow];

				// δѡ��ѧ��
				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else if (selectedData[7] != L"") {
					MessageBox(GetHWnd(), L"ÿλѧ�����תһ��רҵ����ѧ���Ѵ����תרҵ������", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"תרҵ����");
					// ����
					modifyBtn.move(-500, 310);
					sortBtn.move(-500, 470);
					exportBtn.move(-500, 550);
					inportBtn.move(-500, 630);
					backButton.move(-500, 730);


					// ʹ��񲻿ɱ仯
					allStuTable.canChange = false;


					//// ��ȡ��ǰ�� //����д��
					//int selectedRow = allStuTable.getSelectedRow();
					//vector<std::wstring> selectedData = allStuData[selectedRow];


					// �ı���Ĭ������
					IDText.setText((L"ѧ��: " + selectedData[0]).c_str()); // C++�﷨
					nameText.setText((L"����: " + selectedData[1]).c_str());
					genderText.setText((L"�Ա�: " + selectedData[2]).c_str());
					gradeBox.setText(selectedData[3].c_str());
					collegeBox.setText(selectedData[4].c_str());
					majorBox.setText(selectedData[5].c_str());

					// ��ʾ
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
					getNumberInBox(9999, &grade, gradeBox.text) &&
					getTextInBox(college, collegeBox.text) &&
					getTextInBox(major, majorBox.text) &&
					(grade > 1970 && grade <= Current_year)
					) {
					if (MessageBox(GetHWnd(), (wstring(L"ȷ�������ѧ����רҵ��\"") + modifyingStu->item.data.original_college + L"\"��\"" + modifyingStu->item.data.original_major + L"\"תΪ\"" + college + L"\"��\"" + major + L"\"��").c_str(), L"תרҵȷ��", MB_YESNO | MB_ICONQUESTION) == IDYES) {
						// �޸�
						modifyStu(&allStuList, modifyingStu, modifyingStu->item.data.name, tempID, modifyingStu->item.data.gender, grade, college, major);

						// ����
						saveStu(allStuList, STU_FILE);

						// ʹ���ɱ仯
						allStuTable.canChange = true;

						// ˢ�±��
						showAllMajor(allStuList, allStuData, searchInputBox.text);
						allStuTable.setData(allStuData);

					}

					// ʹ���ɱ仯
					allStuTable.canChange = true;

					// ������������
					gradeBox.clear();
					collegeBox.clear();
					majorBox.clear();


					// ���ı���
					titleText.setText(L"תרҵ����");

					// ����
					IDText.move(-500, 150);
					nameText.move(-500, 220);
					genderText.move(-500, 290);
					gradeBox.move(-500, 360);
					collegeBox.move(-500, 430);
					majorBox.move(-500, 500);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// ��ʾ
					modifyBtn.move(-50, 190);
					sortBtn.move(-50, 280);
					exportBtn.move(-50, 370);
					inportBtn.move(-50, 460);
					backButton.move(-50, 580);



				}
				// �������
				else {
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}


			if (sortBtn.mouseClick(msg)) {
				sortStu(&allStuList);

				// ����
				saveStu(allStuList, STU_FILE);

				// ˢ�±��
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


			//�����껬������
			allStuTable.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
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


