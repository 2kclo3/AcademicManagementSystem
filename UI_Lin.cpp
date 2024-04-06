#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int main() {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����
	
	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();

	

	allQualityUI();




	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���



	return 0;
}

void allQualityUI() {
	cleardevice();

	List allStuList = readStu(STU_FILE);
	
	vector<vector<std::wstring>> allQuality_Data;
	vector<vector<std::wstring>> Stu_Research_Data;

	ShowAllStu_with_quality(allStuList, allQuality_Data, L"");

	Table allQuality_Table(310, 90, 940, 700, allQuality_Data);

	Text titleText(10, 100, L"��������Ŀ����", 50);
	Text IDText(-500, 200, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox paper_nameBox(-500, 200, 290, L"��������", L"");
	TextBox journal_or_conference_nameBox(-500, 270, 290, L"������ڿ�/��������", L"");
	TextBox authorBox(-500, 340, 290, L"�������", L"");
	TextBox dateBox(-500, 410, 290, L"����ʱ��", L"");
	TextBox volume_numBox(-500, 480, 290, L"����", L"");
	TextBox issue_numBox(-500, 550, 290, L"����", L"");
	TextBox pageBox(-500, 620, 290, L"ҳ�뷶Χ", L"");
	TextBox GPA_bonusBox(-500, 690, 290, L"����ӷ�", L"");



	Button searchBtn(1150, 20, 100, 50, L"����", 1);
	Button addBtn(-50, 200, 330, 60, L"   ���", 1);
	Button modifyBtn(-50, 280, 330, 60, L"   �޸�", 1);
	Button deleteBtn(-50, 360, 330, 60, L"   ɾ��", 1);
	Button exportBtn(-50, 440, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 520, 330, 60, L"   ����", 1);
	Button backButton(-50, 600, 330, 60, L"   ����", 0);

	Button modify_Research_Btn(-500, 280, 330, 60, L"   ���гɹ��޸�", 1);
	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 680, 290, 60, L"ȡ��", 0);
	Button cancel_ModifyResearch_Button(-500, 680, 290, 60, L"ȡ��", 0);

	// ��������¼�
	ExMessage msg;
	while (!_kbhit()) {
		ULONGLONG start_time = GetTickCount();
		//->
		// ��������(����)
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

			// ������¼�
			if (searchBtn.mouseClick(msg)) {
				ShowAllStu_with_quality(allStuList, allQuality_Data, searchInputBox.text);
				allQuality_Table.setData(allQuality_Data);
			}

			if (addBtn.mouseClick(msg)) {
			}

			if (modifyBtn.mouseClick(msg)) {
				// δѡ��ѧ��
				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ��ѧ��", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"�޸���������Ŀ");
					//����
					addBtn.move(-500,200);
					modifyBtn.move(-500, 280);
					deleteBtn.move(-500,360);
					exportBtn.move(-500, 440);
					inportBtn.move(-500, 520);
					backButton.move(-500, 600);

					//��ʾ
					modify_Research_Btn.move(-50, 280);

					// ��ȡ��ǰ�в���ȷ����ѧ���ڵ�
					int tempID;
					int selectedRow = allQuality_Table.getSelectedRow();
					getNumberInBox(99999999, &tempID, allQuality_Data[selectedRow][0].c_str());
					Node* modifyingStu = searchStu(&allStuList, (wchar_t*)allQuality_Data[selectedRow][1].c_str(), tempID);

					ShowStu_Research(modifyingStu, Stu_Research_Data);
					allQuality_Table.setData(Stu_Research_Data);

					//����
					searchInputBox.move(-1500, 20);
					searchBtn.move(-500, 20);

				
				}
			}

			if (modify_Research_Btn.mouseClick(msg)) {

				if (allQuality_Table.getSelectedRow() == 0) {
					MessageBox(GetHWnd(), L"��ѡ��һ�����гɹ�", L"����!", MB_ICONERROR);
				}
				else {
					// ���ı���
					titleText.setText(L"�޸Ĵ˿��гɹ�");
					titleText.move(20, 3);

					//����
					modify_Research_Btn.move(-500, 280);

					// ʹ��񲻿ɱ仯
					allQuality_Table.canChange = false;

					// ��ȡ��ǰ��
					int selectedRow = allQuality_Table.getSelectedRow();
					vector<std::wstring> selectedResearch_Data = Stu_Research_Data[selectedRow];

					// �ı���Ĭ������
					paper_nameBox.setText(selectedResearch_Data[0].c_str());
					journal_or_conference_nameBox.setText(selectedResearch_Data[1].c_str());
					authorBox.setText(selectedResearch_Data[2].c_str());
					dateBox.setText(selectedResearch_Data[3].c_str());
					volume_numBox.setText(selectedResearch_Data[4].c_str());
					issue_numBox.setText(selectedResearch_Data[5].c_str());
					pageBox.setText(selectedResearch_Data[6].c_str());
					GPA_bonusBox.setText(selectedResearch_Data[7].c_str());


					//��ʾ
					paper_nameBox.move(10, 70);
					journal_or_conference_nameBox.move(10, 140);
					authorBox.move(10, 210);
					dateBox.move(10, 280);
					volume_numBox.move(10, 350);
					issue_numBox.move(10, 420);
					pageBox.move(10, 490);
					GPA_bonusBox.move(10, 560);
					modifyOKButton.move(10, 640);
					cancel_ModifyResearch_Button.move(10, 720);


				}
			}

			if (cancel_ModifyResearch_Button.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"�޸���������Ŀ");

				// ������������
				paper_nameBox.clear();
				journal_or_conference_nameBox.clear();
				authorBox.clear();
				dateBox.clear();
				volume_numBox.clear();
				issue_numBox.clear();
				pageBox.clear();
				GPA_bonusBox.clear();


				// ʹ���ɱ仯
				allQuality_Table.canChange = true;

				//����
				paper_nameBox.move(-500,70);
				journal_or_conference_nameBox.move(-500, 140);
				authorBox.move(-500, 210);
				dateBox.move(-500, 280);
				volume_numBox.move(-500, 350);
				issue_numBox.move(-500, 420);
				pageBox.move(-500, 490);
				GPA_bonusBox.move(-500, 560);
				modifyOKButton.move(-500, 640);
				cancel_ModifyResearch_Button.move(-500, 720);


				//��ʾ
				modify_Research_Btn.move(-50, 280);

			}


			if (deleteBtn.mouseClick(msg)) {
			}

			if (backButton.mouseClick(msg)) {
				menuUI();
			}

			
			//�����껬������
			allQuality_Table.onMouse(msg);

			// �ı�������
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
		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}

}


void QualityUI() {
}



