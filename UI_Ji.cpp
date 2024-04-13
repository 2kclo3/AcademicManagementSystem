#pragma warning(disable:4996)

#include "main.h"
#include<algorithm>
#include<string>
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainjjj(void) {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����
	// ��ʼ��ͼ�δ���
	initgraph(1500, 810);
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
	int i=0;


	Table allStuTable(430, 90, 940, 700, allStuData);

	Text titleText(40, 50, L"����ѧ��", 64);
	Text IDText(-500, 150, L"", 32);
	Text nameText(-500, 220, L"", 32);
	Text genderText(-500, 290, L"", 32);
	Text gradeText(-500, 360, L"", 32);
	Text collegeText(-500, 430, L"", 32);
	Text majorText(-500, 500, L"", 32);

	TextBox searchInputBox(430, 20, 820, L"����", L"");
	TextBox IDBox(-500, 150, 290, L"ѧ�� ( ��Ӻ󲻿ɸ��ģ�)", L"");
	TextBox nameBox(-500, 220, 290, L"����", L"");
	TextBox genderBox(-500, 290, 290, L"�Ա� ( Ů:0, ��:1 )", L"");
	TextBox gradeBox(-500, 360, 290, L"�꼶", L"");
	TextBox collegeBox(-500, 430, 290, L"ѧԺ", L"");
	TextBox majorBox(-500, 500, 290, L"רҵ", L"");

	Button searchBtn(1290, 20, 100, 50, L"����", 1);
	Button lookBtn(-50, 150, 330, 60, L"   ѧ���γ�", 1);//
	Button addBtn(-50, 230, 330, 60, L"   ���", 1);//
	Button modifyBtn(-50, 310, 330, 60, L"   �޸�", 1);
	Button deleteBtn(-50, 390, 330, 60, L"   ɾ��", 1);

	Button sortBtn(0, 470, 120, 60, L"����", 1);//////////////
	Button sortyearBtn(140, 470, 120, 60, L"�ɼ�����", 1);////////////////////
	Button exportBtn(-50, 550, 330, 60, L"   ����", 1);

	Button inportBtn(-50, 630, 330, 60, L"   ����", 1);
	Button backButton(-50, 730, 330, 60, L"   ����", 0);
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
				lookBtn.move(-500, 150);
				addBtn.move(-500, 230);
				modifyBtn.move(-500, 310);
				deleteBtn.move(-500, 390);
				sortBtn.move(-500, 470);
				sortyearBtn.move(-500, 470);
				exportBtn.move(-500, 550);
				inportBtn.move(-500, 630);
				backButton.move(-500, 730);

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

			if (lookBtn.mouseClick(msg)) {

				if (allStuTable.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else {
					wchar_t cname[30];
					int cid;
					int selectedRow = allStuTable.getSelectedRow();
					getNumberInBox(99999999,&cid, allStuData[selectedRow][0].c_str());
					getTextInBox(cname, allStuData[selectedRow][1].c_str());
					Node* Crs = searchStu(&allStuList, cname, cid);


					StuUI(Crs, allStuList,cname,&cid);

					//	// ����
					//	lookBtn.move(-500, 150);
					//	addBtn.move(-500, 230);
					//	modifyBtn.move(-500, 310);
					//	deleteBtn.move(-500, 390);
					//	sortBtn.move(-500, 470);
					//	exportBtn.move(-500, 550);
					//	inportBtn.move(-500, 630);
					//	backButton.move(-500, 730);

					//	// ��ȡ��ǰ��
					//	int selectedRow = allStuTable.getSelectedRow();
					//	vector<std::wstring> selectedData = allStuData[selectedRow];

					//	// ʹ��񲻿ɱ仯
					//	allStuTable.canChange = false;

					//	// �ı���Ĭ������
					//	IDText.setText((L"ѧ��:" + selectedData[0]).c_str()); // C++�﷨
					//	nameText.setText((L"����:"+ selectedData[1]).c_str());
					//	genderText.setText((L"�Ա�:"+selectedData[2]).c_str());
					//	gradeText.setText((L"�꼶:" + selectedData[3]).c_str());
					//	collegeText.setText((L"ѧԺ:" + selectedData[4]).c_str());
					//	majorText.setText((L"רҵ:" + selectedData[5]).c_str());

					//	//��ʾ
					//	IDText.move(10, 150);
					//	nameText.move(10, 220);
					//	genderText.move(10, 290);
					//	gradeText.move(10, 360);
					//	collegeText.move(10, 430);
					//	majorText.move(10, 500);
					//	lookcancelBtn.move(10, 570);
				}

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
				lookBtn.move(-50, 150);
				addBtn.move(-50, 230);
				modifyBtn.move(-50, 310);
				deleteBtn.move(-50, 390);
				sortBtn.move(0, 470);/////////
				sortyearBtn.move(140, 470);
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
						lookBtn.move(-50, 150);
						addBtn.move(-50, 230);
						modifyBtn.move(-50, 310);
						deleteBtn.move(-50, 390);
						sortBtn.move(0, 470);
						sortyearBtn.move(140, 470);
						exportBtn.move(-50, 550);
						inportBtn.move(-50, 630);
						backButton.move(-50, 730);

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
					lookBtn.move(-500, 150);
					addBtn.move(-500, 230);
					modifyBtn.move(-500, 310);
					deleteBtn.move(-500, 390);
					sortBtn.move(-500, 470);
					sortyearBtn.move(-500, 470);
					exportBtn.move(-500, 550);
					inportBtn.move(-500, 630);
					backButton.move(-500, 730);


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
					lookBtn.move(-50, 150);
					addBtn.move(-50, 230);
					modifyBtn.move(-50, 310);
					deleteBtn.move(-50, 390);
					sortBtn.move(0, 470);
					sortyearBtn.move(140, 470);
					exportBtn.move(-50, 550);
					inportBtn.move(-50, 630);
					backButton.move(-50, 730);



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
				if (i == 1) {
					sortStuaccID(&allStuList);
					i = 0;
				}
				else {
					sortStuaccyear(&allStuList);
					i = 1;
				}

				// ����
				saveStu(allStuList, STU_FILE);

				// ˢ�±��
				showAllStu(allStuList, allStuData, L"");
				allStuTable.setData(allStuData);
			}
	
			if (sortyearBtn.mouseClick(msg)) {

				RankUI(allStuList);

			}

			if (exportBtn.mouseClick(msg)) {
				//TODO
			}

			if (inportBtn.mouseClick(msg)) {
				importStu(allStuList, ".\\import\\Stu.csv");

				//// ����
				//saveStu(allStuList, STU_FILE);
				//�Ȳ����棬��Ȼ�����һ��֮�������ͬ����, �ڶ��ξ͵��벻����

				// ˢ�±��
				showAllStu(allStuList, allStuData, L"");
				allStuTable.setData(allStuData);

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



void StuUI(Node* Crs,List allStuList, wchar_t* pname,int* pid) {


	cleardevice();

	Cpnode allCrsList = readCrs(CRS_FILE);
	Crsnode* allCrsInStuList = Crs->item.crslist->crs_next;
	vector<vector<std::wstring>>allCrsINStuData;
	showStu(Crs, allCrsINStuData, L"");

	Table allCrsINStuTable(430, 90, 940, 700, allCrsINStuData);

	Text titleText(40, 20, L"���пγ�", 64);
	//�����
	//TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox searchInputBox(430, 20, 820, L"����", L"");


	TextBox course_idBox(-500, 100, 290, L"�γ̱��", L"");
	TextBox course_nameBox(-500, 150, 290, L"�γ�����", L"");
	TextBox scoreBox(-500, 220, 290, L"�ɼ�", L"");
	TextBox course_natureBox(-500, 250, 290, L"�γ�����", L"");
	TextBox creditBox(-500, 300, 290, L"ѧ��", L"");
	TextBox gridBox(-500, 350, 290, L"����(�Զ�ת��)", L"");
	TextBox semesterBox(-500, 400, 290, L"ѧ��", L"");

	TextBox allButton(-500, 330, 290, L"   ����", L"");
	TextBox mustButton(-500, 380, 290, L"   ����", L"");
	TextBox allsButton(-500, 430, 290, L"   ����", L"");
	TextBox mustsButton(-500, 480, 290, L"   ����", L"");


	//��ť
	//Button searchBtn(1150, 20, 100, 50, L"����", 1);
	Button searchBtn(1290, 20, 100, 50, L"����", 1);

	wchar_t aa[100];
	wchar_t bb[100];
	wchar_t cc[100];
	getTextInBox(cc, std::to_wstring(*pid).c_str());//��ֹ�����ת��
	getTextInBox(aa, (wstring(L"ѧ�ţ�") + cc).c_str());
	getTextInBox(bb, (wstring(L"������") + pname).c_str());

	Button idBtn(40, 100, 200, 50, aa, 1);
	Button nameBtn(40, 180, 200, 50, bb, 1);
	//(wstring(L"ѧ�ţ�")+aa).c_str()
	// (wstring(L"������") + pname).c_str()




	Button addCrsBtn(-50, 300, 330, 60, L"   ��ӿγ�", 1);
	Button modifyCrsBtn(-50, 380, 330, 60, L"   �޸Ŀγ�", 1);
	Button deleteCrsBtn(-50, 460, 330, 60, L"   ɾ���γ�", 1);
	Button GridCrsBtn(-50, 540, 330, 60, L"   �鿴����", 1);

	Button backButton(-50, 700, 330, 60, L"   ����", 0);


	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", 0);




	// ��������¼�
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
			//������¼�

			//����
			if (searchBtn.mouseClick(msg)) {
				showStu(Crs, allCrsINStuData, searchInputBox.text);
				allCrsINStuTable.setData(allCrsINStuData);
			}

			if (addCrsBtn.mouseClick(msg)) {


				// ���ı���
				titleText.setText(L"��ӿγ�");


				// ʹ��񲻿ɱ仯
				allCrsINStuTable.canChange = false;


				//����
				idBtn.move(-500, 100);
				nameBtn.move(-500, 180);

				addCrsBtn.move(-500, 300);
				modifyCrsBtn.move(-500, 380);
				deleteCrsBtn.move(-500, 460);
				GridCrsBtn.move(-500, 540);
				backButton.move(-500, 700);

				//��ʾ
				course_idBox.move(10, 100);
				course_nameBox.move(10, 180);
				scoreBox.move(10, 260);
				course_natureBox.move(10, 340);
				creditBox.move(10, 420);
				gridBox.move(10, 500);
				semesterBox.move(10, 580);

				addOKButton.move(10, 650);
				cancelButton.move(10, 730);

			}

			if (addOKButton.mouseClick(msg)) {
				wchar_t course_id[10];//�γ̺�
				wchar_t course_name[100];//�γ���
				double score;//�γ̳ɼ�
				int semester;//ѧ��ѧ��
				int course_nature;//�γ�����
				double credit;//ѧ��
				double grid;//����


				//�жϳ������ʽ
				if (
					getTextInBox(course_id, course_idBox.text) &&
					getTextInBox(course_name, course_nameBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					getNumberInBox(8, &semester, semesterBox.text) &&
					getNumberInBox(1, &course_nature, course_natureBox.text) &&
					getDoubleInBox(4, &credit, creditBox.text) &&
					credit >= 0 && score >= 0 && semester >= 0 && course_nature >= 0
					) {

					grid = CalculGPA(score);

;

					addCrsToStu(Crs, course_id, course_name, score, semester, course_nature, credit, grid);
					if (searchCrs(allCrsList, stoi(course_id),1) == NULL) {
						MessageBox(GetHWnd(), L"û�иÿγ�", L"����!", MB_ICONERROR);
					}
					else {
						addStuInCrs(searchCrs(allCrsList, stoi(course_id),1), pname, *pid, score);
					}


					// ����
					saveStu(allStuList, STU_FILE);
					saveCrs(allCrsList, CRS_FILE);


					allCrsINStuTable.canChange = true;

					// ˢ�±��
					showStu(Crs, allCrsINStuData, L"");

					allCrsINStuTable.setData(allCrsINStuData);


					//���
					course_idBox.clear();
					course_nameBox.clear();
					scoreBox.clear();
					course_natureBox.clear();
					semesterBox.clear();
					creditBox.clear();
					gridBox.clear();

					//����
					course_idBox.move(-500, 100);
					course_nameBox.move(-500, 180);
					scoreBox.move(-500, 260);
					course_natureBox.move(-500, 340);
					creditBox.move(-500, 420);
					gridBox.move(-500, 500);
					semesterBox.move(-500, 580);

					addOKButton.move(-500, 650);
					cancelButton.move(-500, 730);

					// ���ı���
					titleText.setText(L"ѧ���γ�");

					//��ʾ
					idBtn.move(40, 100);
					nameBtn.move(40, 180);


					addCrsBtn.move(-50, 300);
					modifyCrsBtn.move(-50, 380);
					deleteCrsBtn.move(-50, 460);
					GridCrsBtn.move(-500, 540);
					backButton.move(-50, 700);


				}
			}

			if (cancelButton.mouseClick(msg)) {

				// ʹ���ɱ仯
				allCrsINStuTable.canChange = true;


				//���
				course_idBox.clear();
				course_nameBox.clear();
				scoreBox.clear();
				course_natureBox.clear();
				semesterBox.clear();
				creditBox.clear();
				gridBox.clear();

				//����
				course_idBox.move(-500, 100);
				course_nameBox.move(-500, 180);
				scoreBox.move(-500, 260);
				course_natureBox.move(-500, 340);
				creditBox.move(-500, 420);
				gridBox.move(-500, 500);
				semesterBox.move(-500, 580);

				allButton.move(-500, 300);
				mustButton.move(-500, 380);
				allsButton.move(-500, 300);
				mustsButton.move(-500, 380);

				addOKButton.move(-500, 600);
				modifyOKButton.move(-500, 650);
				cancelButton.move(-500, 700);

				//��ʾ
				idBtn.move(40, 100);
				nameBtn.move(40, 180);


				addCrsBtn.move(-50, 300);
				modifyCrsBtn.move(-50, 380);
				deleteCrsBtn.move(-50, 460);
				GridCrsBtn.move(-50, 540);

				backButton.move(-50, 700);

				// ���ı���
				titleText.setText(L"ѧ���γ�");


			}

			if (modifyCrsBtn.mouseClick(msg)) {

				if (allCrsINStuTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					// ���ı���
					titleText.setText(L"�޸Ŀγ�");


					// ʹ��񲻿ɱ仯
					allCrsINStuTable.canChange = false;


					//����
					idBtn.move(-500, 100);
					nameBtn.move(-500, 180);

					addCrsBtn.move(-500, 300);
					modifyCrsBtn.move(-500, 380);
					deleteCrsBtn.move(-500, 460);
					GridCrsBtn.move(-500, 540);
					backButton.move(-500, 700);

					//��ʾ
					course_idBox.move(10, 100);
					course_nameBox.move(10, 180);
					scoreBox.move(10, 260);
					course_natureBox.move(10, 340);
					creditBox.move(10, 420);
					gridBox.move(10, 500);
					semesterBox.move(10, 580);

					modifyOKButton.move(10, 650);
					cancelButton.move(10, 730);

					// ��ȡ��ǰ��
					int selectedRow = allCrsINStuTable.getSelectedRow();
					vector<std::wstring> selectedData = allCrsINStuData[selectedRow];

					//�ı���Ĭ������
					course_idBox.setText(selectedData[0].c_str());
					course_nameBox.setText(selectedData[1].c_str());
					scoreBox.setText(selectedData[2].c_str());
					semesterBox.setText(selectedData[3].c_str());
					course_natureBox.setText(selectedData[6].c_str());
					creditBox.setText(selectedData[4].c_str());
					gridBox.setText(selectedData[5].c_str());


				}
			}

			if (modifyOKButton.mouseClick(msg)) {

				wchar_t course_id[10];//�γ̺�
				wchar_t course_name[100];//�γ���
				double score;//�γ̳ɼ�
				int semester;//ѧ��ѧ��
				int course_nature;//�γ�����
				double credit;//ѧ��
				double grid;//����

				wchar_t pcourse_id[10];//�������γ̺�
				wchar_t pcourse_name[30];//�������γ��� 
				int selectedRow = allCrsINStuTable.getSelectedRow(); // ��ȡ��ǰ��
				getTextInBox(pcourse_id, allCrsINStuData[selectedRow][0].c_str());
				getTextInBox(pcourse_name, allCrsINStuData[selectedRow][1].c_str());
				Crsnode* tmp = searchCrsInStu(Crs, pcourse_id, pcourse_name);

				//�жϳ������ʽ
				if (
					getTextInBox(course_id, course_idBox.text) &&
					getTextInBox(course_name, course_nameBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					getNumberInBox(8, &semester, semesterBox.text) &&
					getNumberInBox(1, &course_nature, course_natureBox.text) &&
					getDoubleInBox(4, &credit, creditBox.text) &&
					getDoubleInBox(4, &grid, gridBox.text) &&
					grid >= 0 && credit >= 0 && score >= 0 && semester >= 0 && course_nature >= 0
					) {

					modifyCrsInStu(tmp, course_id, course_name, score, semester, course_nature, credit, grid);

					// ����
					saveStu(allStuList, STU_FILE);


					//�γ̱仯
					allCrsINStuTable.canChange = true;

					// ˢ�±��
					showStu(Crs, allCrsINStuData, L"");
					allCrsINStuTable.setData(allCrsINStuData);

					//���
					course_idBox.clear();
					course_nameBox.clear();
					scoreBox.clear();
					course_natureBox.clear();
					semesterBox.clear();
					creditBox.clear();
					gridBox.clear();

					//����
					course_idBox.move(-500, 100);
					course_nameBox.move(-500, 180);
					scoreBox.move(-500, 260);
					course_natureBox.move(-500, 340);
					creditBox.move(-500, 420);
					gridBox.move(-500, 500);
					semesterBox.move(-500, 580);

					modifyOKButton.move(-500, 650);
					cancelButton.move(-500, 730);

					// ���ı���
					titleText.setText(L"ѧ���γ�");

					//��ʾ
					idBtn.move(40, 100);
					nameBtn.move(40, 180);


					addCrsBtn.move(-50, 300);
					modifyCrsBtn.move(-50, 380);
					deleteCrsBtn.move(-50, 460);
					GridCrsBtn.move(-500, 540);
					backButton.move(-50, 700);


				}
			}

			if (deleteCrsBtn.mouseClick(msg)) {
				if (allCrsINStuTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ�������γ���?", L"ɾ���γ�", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES) {
						wchar_t pcourse_id[10];//�������γ̺�
						wchar_t pcourse_name[30];//�������γ��� 
						int selectedRow = allCrsINStuTable.getSelectedRow(); // ��ȡ��ǰ��
						getTextInBox(pcourse_id, allCrsINStuData[selectedRow][0].c_str());
						getTextInBox(pcourse_name, allCrsINStuData[selectedRow][1].c_str());
						Crsnode* ttmp = searchCrsInStu(Crs, pcourse_id, pcourse_name);

						deleteCrsInStu(Crs, ttmp);

						// ����
						saveStu(allStuList, STU_FILE);

						// ˢ�±��
						showStu(Crs, allCrsINStuData, L"");
						allCrsINStuTable.setData(allCrsINStuData);

						//��ʾ
						idBtn.move(40, 100);
						nameBtn.move(40, 180);


						addCrsBtn.move(-50, 300);
						modifyCrsBtn.move(-50, 380);
						deleteCrsBtn.move(-50, 460);
						GridCrsBtn.move(-500, 540);
						backButton.move(-50, 700);

						//����
						course_idBox.move(-500, 100);
						course_nameBox.move(-500, 180);
						scoreBox.move(-500, 260);
						course_natureBox.move(-500, 340);
						creditBox.move(-500, 420);
						gridBox.move(-500, 500);
						semesterBox.move(-500, 580);

						addOKButton.move(-500, 650);
						cancelButton.move(-500, 730);
					}


				}
			}

			if (GridCrsBtn.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"���˳ɼ�");


				// ʹ��񲻿ɱ仯
				allCrsINStuTable.canChange = false;


				//����

				addCrsBtn.move(-500, 300);
				modifyCrsBtn.move(-500, 380);
				deleteCrsBtn.move(-500, 460);
				GridCrsBtn.move(-500, 540);

				backButton.move(-500, 700);

				//��ʾ

				allButton.move(0, 300);
				mustButton.move(0, 380);
				allsButton.move(0, 460);
				mustsButton.move(0, 540);

				cancelButton.move(10, 730);

				//���㼨��
				double all, must, alls, musts;

				all = AllGrid(Crs);
				must = MustGrid(Crs);
				alls = AllScore(Crs);
				musts = MustScore(Crs);




				allButton.setText((wstring(L"���пγ̼��㣺") + std::to_wstring(all)).c_str());
				mustButton.setText((wstring(L"���޿γ̼��㣺") + std::to_wstring(must)).c_str());
				allsButton.setText((wstring(L"���пγ̳ɼ���") + std::to_wstring(alls)).c_str());
				mustsButton.setText((wstring(L"���޿γ̳ɼ���") + std::to_wstring(musts)).c_str());


			}




			if (backButton.mouseClick(msg))
			{
				allStuUI();
			}



			//�����껬������
			allCrsINStuTable.onMouse(msg);


			// �ı�������
			searchInputBox.onMessage(msg);
			course_idBox.onMessage(msg);
			course_nameBox.onMessage(msg);
			scoreBox.onMessage(msg);
			course_natureBox.onMessage(msg);
			creditBox.onMessage(msg);
			//gridBox.onMessage(msg);
			semesterBox.onMessage(msg);
		}


		//-------------------------------------------------
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}


		
}



void RankUI(List StuList) {
	cleardevice();

	vector<vector<std::wstring>> RankData;
	int number;
	Rank(StuList, RankData, L"",L"", & number);

	Table RankTable(340, 90, 1100, 700, RankData);

	Text titleText(40, 50, L"ѧ������", 64);
	Text tipText(80, 170, L"������ʽ", 32);

	TextBox searchInputBox(340, 20, 420, L"רҵ����", L"");
	TextBox searchInput2Box(820, 20, 420, L"�꼶����", L"");

	Button searchBtn(1350, 20, 100, 50, L"����", 1);

	Button allscoreBtn(-50, 220, 330, 60, L"   ȫ����Ŀ�ɼ�", 1);
	Button allgridBtn(-50, 300, 330, 60, L"   ȫ����Ŀ����", 1);
	Button mustscoreBtn(-50, 380, 330, 60, L"   ���޿�Ŀ�ɼ�", 1);
	Button mustgridBtn(-50, 460, 330, 60, L"   ���޿�Ŀ����", 1);

	Button backButton(-50, 700, 330, 60, L"   ����", 0);

	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();

		searchInputBox.draw();
		searchInput2Box.draw();

		if (peekmessage(&msg, -1, true)) {

			if (searchBtn.mouseClick(msg)) {
				Rank(StuList, RankData, searchInputBox.text, searchInput2Box.text,&number);
				RankTable.setData(RankData);
			}
			
			if (allscoreBtn.mouseClick(msg)) {
				//for (vector<std::wstring>& a : RankData)
					//	//std::cout << stold(a[4]) << std::endl;
					//	//std::wcout << a[4]<<std::endl;
					//std::sort(RankData.begin(), RankData.end(), [](vector<std::wstring>& a, vector<std::wstring>& b)->bool {
					//	
					//	//return 1;
					//	return a[4]> b[4];
					//	});
					//for (vector<std::wstring>& a : RankData)
					//	std::wcout << a[4] << std::endl;

					///////////////////////////////////

				int R = number - 1;
				int L = 1;

				while (L < R) {
					for (int i = L; i < R; i++) {
						if (stof(RankData[i][4])< stof(RankData[i+1][4])) {
							swap(RankData[i], RankData[i + 1]);
						}

					}

					R--;
					for (int i = R; i > L; i--) {
						if (stof(RankData[i][4]) > stof(RankData[i-1][4])) {
							swap(RankData[i], RankData[i - 1]);
						}
					}

					L++;
				}



				RankTable.setData(RankData);

			}

			if (allgridBtn.mouseClick(msg)) {

				int R = number - 1;
				int L = 1;

				while (L < R) {
					for (int i = L; i < R; i++) {
						if (stof(RankData[i][5]) < stof(RankData[i + 1][5])) {
							swap(RankData[i], RankData[i + 1]);
						}

					}

					R--;
					for (int i = R; i > L; i--) {
						if (stof(RankData[i][5]) > stof(RankData[i - 1][5])) {
							swap(RankData[i], RankData[i - 1]);
						}
					}

					L++;
				}

				RankTable.setData(RankData);
			}

			if (mustscoreBtn.mouseClick(msg)) {

				int R = number - 1;
				int L = 1;

				while (L < R) {
					for (int i = L; i < R; i++) {
						if (stof(RankData[i][6]) < stof(RankData[i + 1][6])) {
							swap(RankData[i], RankData[i + 1]);
						}

					}

					R--;
					for (int i = R; i > L; i--) {
						if (stof(RankData[i][6]) > stof(RankData[i - 1][6])) {
							swap(RankData[i], RankData[i - 1]);
						}
					}

					L++;
				}

				RankTable.setData(RankData);
			}

			if (mustgridBtn.mouseClick(msg)) {

				int R = number - 1;
				int L = 1;

				while (L < R) {
					for (int i = L; i < R; i++) {
						if (stof(RankData[i][7]) < stof(RankData[i + 1][7])) {
							swap(RankData[i], RankData[i + 1]);
						}

					}

					R--;
					for (int i = R; i > L; i--) {
						if (stof(RankData[i][7]) > stof(RankData[i - 1][7])) {
							swap(RankData[i], RankData[i - 1]);
						}
					}

					L++;
				}

				RankTable.setData(RankData);
			}

			if (backButton.mouseClick(msg)) {
				allStuUI();
			}

			//�����껬������
			RankTable.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
			searchInput2Box.onMessage(msg);
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


void swap(vector<wstring>* a, vector<wstring>* b) {
	vector<wstring> c;
	c.push_back(L"");
	c = *a;
	*a = *b;
	*b = c;


}

