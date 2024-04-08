#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"

//�޸����ҲҪ����,������ְ������˵�ѧ�Ÿ����˻��߿γ̸�����

int main0(void) 
{
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����

	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();


	//testUI();


	loginUI();







	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���





	return 0;
}


void allCrsUI()
{
	cleardevice();
	Cpnode allCrsList = readCrs(CRS_FILE);
	vector<vector<std::wstring>> allCrsData;
	showAllCrs(allCrsList, allCrsData, L"");

	Table allCrsTable(310, 90, 940, 700, allCrsData);

	Text titleText(40, 50, L"���пγ�", 64);

	TextBox searchInputBox(310, 20, 820, L"����", L"");
	TextBox cnameBox(-500, 150, 290, L"�γ�����", L"");
	TextBox cnumBox(-500, 220, 290, L"�γ̺�", L"");
	TextBox characterBox(-500, 290, 290, L"�γ�����", L"");

	Button searchBtn(1150, 20, 100, 50, L"����", 1);

	Button inquireCrsBtn(-50, 140, 330, 60, L"   ��ѯ�γ�", 1);
	Button addCrsBtn(-50, 220, 330, 60, L"   ��ӿγ�", 1);
	Button modifyCrsBtn(-50, 300, 330, 60, L"   �޸�", 1);
	Button deleteCrsBtn(-50, 380, 330, 60, L"   ɾ��", 1);
	Button statisticBtn(-50, 460, 330, 60, L"   ͳ��", 1);//�������ɶ�ģ�
	Button exportBtn(-50, 540, 330, 60, L"   ����", 1);
	Button inportBtn(-50, 620, 330, 60, L"   ����", 1);
	Button backButton(-50, 700, 330, 60, L"   ����", 0);

	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", 0);


	// ��������¼�
	ExMessage msg;
	while (!_kbhit())
	{
		ULONGLONG start_time = GetTickCount();
		//->

		searchInputBox.draw();
		cnameBox.draw();
		cnumBox.draw();
		characterBox.draw();

		if (peekmessage(&msg, -1, true))
		{
			if (searchBtn.mouseClick(msg))
			{
				showAllCrs(allCrsList, allCrsData, searchInputBox.text);
				allCrsTable.setData(allCrsData);
			}

			if (inquireCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					// ��ȡ�γ̽ڵ���Ϣ
					wchar_t cname[30];
					int cnum;
					int selectedRow = allCrsTable.getSelectedRow(); // ��ȡ��ǰ��
					getTextInBox(cname, allCrsData[selectedRow][0].c_str());
					getNumberInBox(99999, &cnum, allCrsData[selectedRow][1].c_str());
					Cpnode cplist = searchCrs(allCrsList, cname, cnum);
					CrsUI(allCrsList, cplist);

				}
			}
			////////////////////////////////////////////
			if (addCrsBtn.mouseClick(msg))
			{
				// ���ı���
				titleText.setText(L"��ӿγ�");
				// ����
				inquireCrsBtn.move(-500, 140);
				addCrsBtn.move(-500, 220);
				modifyCrsBtn.move(-500, 300);
				deleteCrsBtn.move(-500, 380);
				statisticBtn.move(-500, 460);
				exportBtn.move(-500, 540);
				inportBtn.move(-500, 620);
				backButton.move(-500, 700);

				// ��ʾ
				cnameBox.move(10, 140);
				cnumBox.move(10, 220);
				characterBox.move(10, 300);
				addOKButton.move(10, 380);
				cancelButton.move(10, 460);
			}

			if (addOKButton.mouseClick(msg))
			{
				wchar_t cname[30];
				int cnum;
				wchar_t character[5];

				// �ж������ʽ
				if (
					getTextInBox(cname, cnameBox.text) &&
					getNumberInBox(99999, &cnum, cnumBox.text) &&
					getTextInBox(character, characterBox.text) &&
					cnum > 9999
					)
				{

					// �γ���ͬ�����,��������
					if (!addCrs(allCrsList, cname, cnum, character))
					{
						MessageBox(GetHWnd(), L"�ÿγ��Ѿ�����,�����ظ����!", L"����!", MB_ICONERROR);
					}
					else
					{
						// ����
						saveCrs(allCrsList, CRS_FILE);

						// ˢ�±��
						showAllCrs(allCrsList, allCrsData, L"");
						allCrsTable.setData(allCrsData);

						// ������������
						cnameBox.clear();
						cnumBox.clear();
						characterBox.clear();


						// ���ı���
						titleText.setText(L"���пγ�");

						// ����
						cnameBox.move(-500, 140);
						cnumBox.move(-500, 220);
						characterBox.move(-500, 300);
						addOKButton.move(-500, 380);
						cancelButton.move(-500, 460);

						// ��ʾ
						inquireCrsBtn.move(-50, 140);
						addCrsBtn.move(-50, 220);
						modifyCrsBtn.move(-50, 300);
						deleteCrsBtn.move(-50, 380);
						statisticBtn.move(-50, 460);
						exportBtn.move(-50, 540);
						inportBtn.move(-50, 620);
						backButton.move(-50, 700);

					}


				}
				// �������
				else
				{
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (cancelButton.mouseClick(msg)) {
				// ���ı���
				titleText.setText(L"���пγ�");

				// ������������
				cnameBox.clear();
				cnumBox.clear();
				characterBox.clear();

				// ʹ���ɱ仯
				allCrsTable.canChange = true;

				// ����
				cnameBox.move(-500, 150);
				cnumBox.move(-500, 220);
				characterBox.move(-500, 290);
				addOKButton.move(-500, 580);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// ��ʾ
				inquireCrsBtn.move(-50, 140);
				addCrsBtn.move(-50, 220);
				modifyCrsBtn.move(-50, 300);
				deleteCrsBtn.move(-50, 380);
				statisticBtn.move(-50, 460);
				exportBtn.move(-50, 540);
				inportBtn.move(-50, 620);
				backButton.move(-50, 700);

			}

			if (modifyCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					// ���ı���
					titleText.setText(L"�޸Ŀγ�");
					// ����
					inquireCrsBtn.move(-500, 140);
					addCrsBtn.move(-500, 220);
					modifyCrsBtn.move(-500, 300);
					deleteCrsBtn.move(-500, 380);
					statisticBtn.move(-500, 460);
					exportBtn.move(-500, 540);
					inportBtn.move(-500, 620);
					backButton.move(-500, 700);


					// ʹ��񲻿ɱ仯
					allCrsTable.canChange = false;


					// ��ȡ��ǰ��
					int selectedRow = allCrsTable.getSelectedRow();
					vector<std::wstring> selectedData = allCrsData[selectedRow];


					// �ı���Ĭ������
					cnameBox.setText(selectedData[0].c_str());
					cnumBox.setText(selectedData[1].c_str());
					characterBox.setText(selectedData[2].c_str());


					// ��ʾ
					cnameBox.move(10, 140);
					cnumBox.move(10, 220);
					characterBox.move(10, 300);
					modifyOKButton.move(10, 380);
					cancelButton.move(10, 460);
				}

			}

			if (modifyOKButton.mouseClick(msg))
			{
				wchar_t cname[30];
				int cnum;
				wchar_t character[5];


				// ��ȷ�����γ̽ڵ�
				wchar_t original_cname[30];
				int original_cnum;
				int selectedRow = allCrsTable.getSelectedRow(); // ��ȡ��ǰ��
				getTextInBox(original_cname, allCrsData[selectedRow][0].c_str());
				getNumberInBox(99999, &original_cnum, allCrsData[selectedRow][1].c_str());
				Cpnode modifyingCrs = searchCrs(allCrsList, original_cname, original_cnum);
				

				// �ж������ʽ
				if (
					getTextInBox(cname, cnameBox.text) &&
					getNumberInBox(99999, &cnum, cnumBox.text) &&
					getTextInBox(character, characterBox.text) &&
					cnum > 9999
					)
				{

					// �޸�
					modifyCrs(modifyingCrs, cname, cnum, character);

					// ����
					saveCrs(allCrsList, CRS_FILE);

					// ʹ���ɱ仯
					allCrsTable.canChange = true;

					// ˢ�±��
					//showAllCrs(allCrsList, allCrsData, searchInputBox.text);//�����ô��searchInputBox.text
					showAllCrs(allCrsList, allCrsData, L"");
					allCrsTable.setData(allCrsData);

					// ������������
					cnameBox.clear();
					cnumBox.clear();
					characterBox.clear();


					// ���ı���
					titleText.setText(L"���пγ�");

					// ����
					cnameBox.move(-500, 150);
					cnumBox.move(-500, 220);
					characterBox.move(-500, 290);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// ��ʾ
					inquireCrsBtn.move(-50, 140);
					addCrsBtn.move(-50, 220);
					modifyCrsBtn.move(-50, 300);
					deleteCrsBtn.move(-50, 380);
					statisticBtn.move(-50, 460);
					exportBtn.move(-50, 540);
					inportBtn.move(-50, 620);
					backButton.move(-50, 700);



				}
				// �������
				else
				{
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (deleteCrsBtn.mouseClick(msg))
			{
				if (allCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ�����ſγ���?", L"ɾ���γ�", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES)
					{ // ���ȷ��

						// ��ȡ�γ̽ڵ���Ϣ
						wchar_t cname[30];
						int cnum;
						int selectedRow = allCrsTable.getSelectedRow(); // ��ȡ��ǰ��
						getTextInBox(cname, allCrsData[selectedRow][0].c_str());
						getNumberInBox(99999, &cnum, allCrsData[selectedRow][1].c_str());

						// ɾ��
						deleteCrs(allCrsList, cname, cnum);

						// ����
						saveCrs(allCrsList, CRS_FILE);


						// ˢ�±��
						showAllCrs(allCrsList, allCrsData, searchInputBox.text);
						allCrsTable.setData(allCrsData);
					}
				}
			}

			if (statisticBtn.mouseClick(msg)) {
			}
			if (exportBtn.mouseClick(msg)) {
			}
			if (inportBtn.mouseClick(msg)) {
			}
			if (backButton.mouseClick(msg))
			{
				//return;����ֱ��return
				menuUI();
			}

			//�����껬������
			allCrsTable.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
			cnameBox.onMessage(msg);
			cnumBox.onMessage(msg);
			characterBox.onMessage(msg);
		}

		showxy(msg);





		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1)
		{
			Sleep(1);
		}

	}

}


void CrsUI(Cpnode cphead, Cpnode cplist)
{
	cleardevice();
	Spnode allStuInCrsList = cplist->sphead;
	vector<vector<std::wstring>>allStuInCrsData;
	showAllStuInCrs(cplist, allStuInCrsData, L"");

	Table allStuInCrsTable(310, 90, 940, 700, allStuInCrsData);

	Text GPAText(-500, 370, L"", 32);

	TextBox searchInputBox(310, 20, 820, L"����", L"");

	TextBox snameBox(-500, 150, 290, L"ѧ������", L"");
	TextBox snumBox(-500, 220, 290, L"ѧ��", L"");
	TextBox scoreBox(-500, 290, 290, L"�ɼ�", L"");


	Button searchBtn(1150, 20, 100, 50, L"����", 1);

	Button addStuInCrsBtn(-50, 140, 330, 60, L"   ���ѧ��", 1);
	Button modifyStuInCrsBtn(-50, 220, 330, 60, L"   �޸�ѧ��", 1);
	Button deleteStuInCrsBtn(-50, 300, 330, 60, L"   ɾ��ѧ��", 1);
	Button backButton(-50, 380, 330, 60, L"   ����", 0);

	Button addOKButton(-500, 580, 290, 60, L"ȷ�����", 1);
	Button modifyOKButton(-500, 580, 290, 60, L"ȷ���޸�", 1);
	Button cancelButton(-500, 660, 290, 60, L"ȡ��", 0);

	// ��������¼�
	ExMessage msg;
	while (!_kbhit())
	{
		ULONGLONG start_time = GetTickCount();
		//->

		searchInputBox.draw();
		snameBox.draw();
		snumBox.draw();
		scoreBox.draw();

		if (peekmessage(&msg, -1, true))
		{
			if (searchBtn.mouseClick(msg))
			{
				showAllStuInCrs(cplist, allStuInCrsData, searchInputBox.text);
				allStuInCrsTable.setData(allStuInCrsData);
			}


			if (addStuInCrsBtn.mouseClick(msg))
			{
				// ����
				addStuInCrsBtn.move(-500, 220);
				modifyStuInCrsBtn.move(-500, 300);
				deleteStuInCrsBtn.move(-500, 380);
				backButton.move(-500, 700);

				// ��ʾ
				snameBox.move(10, 140);
				snumBox.move(10, 220);
				scoreBox.move(10, 300);

				addOKButton.move(10, 380);
				cancelButton.move(10, 460);
			}

			if (addOKButton.mouseClick(msg))
			{
				wchar_t sname[30];
				int snum;
				double score;

				// �ж������ʽ

				if (
					getTextInBox(sname, snameBox.text) &&
					getNumberInBox(99999999, &snum, snumBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					snum > 9999999 && score >= 0
					)
				{


					if (!addStuInCrs(cplist, sname, snum, score))
					{
						MessageBox(GetHWnd(), L"��ѧ���Ѿ�����,�����ظ����!", L"����!", MB_ICONERROR);
					}
					else
					{
						// ����
						saveCrs(cphead, CRS_FILE);

						// ˢ�±��
						showAllStuInCrs(cplist, allStuInCrsData, L"");
						allStuInCrsTable.setData(allStuInCrsData);

						// ������������
						snameBox.clear();
						snumBox.clear();
						scoreBox.clear();




						// ����
						snameBox.move(-500, 140);
						snumBox.move(-500, 220);
						scoreBox.move(-500, 300);
						addOKButton.move(-500, 380);
						cancelButton.move(-500, 460);

						// ��ʾ
						addStuInCrsBtn.move(-50, 220);
						modifyStuInCrsBtn.move(-50, 300);
						deleteStuInCrsBtn.move(-50, 380);
						backButton.move(-50, 460);

					}


				}
				// �������
				else
				{
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (cancelButton.mouseClick(msg)) 
			{

				// ������������
				snameBox.clear();
				snumBox.clear();
				scoreBox.clear();

				// ʹ���ɱ仯
				allStuInCrsTable.canChange = true;

				// ����
				snameBox.move(-500, 150);
				snumBox.move(-500, 220);
				scoreBox.move(-500, 290);
				addOKButton.move(-500, 580);
				modifyOKButton.move(-500, 580);
				cancelButton.move(-500, 660);

				// ��ʾ
				addStuInCrsBtn.move(-50, 220);
				modifyStuInCrsBtn.move(-50, 300);
				deleteStuInCrsBtn.move(-50, 380);
				backButton.move(-50, 460);

			}

			if (modifyStuInCrsBtn.mouseClick(msg))
			{
				if (allStuInCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��γ�", L"����!", MB_ICONERROR);
				}
				else
				{
					// ����
					addStuInCrsBtn.move(-500, 220);
					modifyStuInCrsBtn.move(-500, 300);
					deleteStuInCrsBtn.move(-500, 380);
					backButton.move(-500, 700);


					// ʹ��񲻿ɱ仯
					allStuInCrsTable.canChange = false;


					// ��ȡ��ǰ��
					int selectedRow = allStuInCrsTable.getSelectedRow();
					vector<std::wstring> selectedData = allStuInCrsData[selectedRow];


					// �ı���Ĭ������
					snameBox.setText(selectedData[0].c_str());
					snumBox.setText(selectedData[1].c_str());
					scoreBox.setText(selectedData[2].c_str());


					// ��ʾ
					snameBox.move(10, 140);
					snumBox.move(10, 220);
					scoreBox.move(10, 300);
					modifyOKButton.move(10, 380);
					cancelButton.move(10, 460);
				}

			}

			if (modifyOKButton.mouseClick(msg))
			{
				wchar_t sname[30];
				int snum;
				double score;


				// ��ȷ�����γ̽ڵ�
				wchar_t original_sname[30];
				int original_snum;
				int selectedRow = allStuInCrsTable.getSelectedRow(); // ��ȡ��ǰ��
				getTextInBox(original_sname, allStuInCrsData[selectedRow][0].c_str());
				getNumberInBox(99999999, &original_snum, allStuInCrsData[selectedRow][1].c_str());
				Spnode modifyingStu = searchStuInCrs(cplist, original_sname, original_snum);

				// �ж������ʽ
				if (
					getTextInBox(sname, snameBox.text) &&
					getNumberInBox(99999999, &snum, snumBox.text) &&
					getDoubleInBox(100, &score, scoreBox.text) &&
					snum > 9999999&&score>=0
					)
				{

					// �޸�
					modifyStuInCrs(cplist, modifyingStu, sname, snum, score);

					// ����
					saveCrs(cphead, CRS_FILE);

					// ʹ���ɱ仯
					allStuInCrsTable.canChange = true;

					// ˢ�±��
					showAllStuInCrs(cplist, allStuInCrsData, L"");
					allStuInCrsTable.setData(allStuInCrsData);

					// ������������
					snameBox.clear();
					snumBox.clear();
					scoreBox.clear();



					// ����
					snameBox.move(-500, 150);
					snumBox.move(-500, 220);
					scoreBox.move(-500, 290);
					modifyOKButton.move(-500, 580);
					cancelButton.move(-500, 660);

					// ��ʾ
					addStuInCrsBtn.move(-50, 220);
					modifyStuInCrsBtn.move(-50, 300);
					deleteStuInCrsBtn.move(-50, 380);
					backButton.move(-50, 460);



				}
				// �������
				else
				{
					MessageBox(GetHWnd(), L"�����������������������ݼ���ʽ", L"����!", MB_ICONWARNING);
				}

			}

			if (deleteStuInCrsBtn.mouseClick(msg))
			{
				if (allStuInCrsTable.getSelectedRow() == 0)
				{
					MessageBox(GetHWnd(), L"��ѡ��ѧ��", L"����!", MB_ICONERROR);
				}
				else
				{
					int result = MessageBox(GetHWnd(), L"ȷ��ɾ������ѧ����?", L"ɾ��ѧ��", MB_YESNO | MB_ICONQUESTION);

					if (result == IDYES)
					{ // ���ȷ��

						wchar_t sname[30];
						int snum;
						int selectedRow = allStuInCrsTable.getSelectedRow(); // ��ȡ��ǰ��
						getTextInBox(sname, allStuInCrsData[selectedRow][0].c_str());
						getNumberInBox(99999999, &snum, allStuInCrsData[selectedRow][1].c_str());

						// ɾ��
						deleteStuInCrs(cplist, sname, snum);

						// ����
						saveCrs(cphead, CRS_FILE);


						// ˢ�±��
						showAllStuInCrs(cplist, allStuInCrsData, searchInputBox.text);
						allStuInCrsTable.setData(allStuInCrsData);
					}
				}
			}

			if (backButton.mouseClick(msg))
			{
				//return;����ֱ��return
				allCrsUI();
			}

			//�����껬������
			allStuInCrsTable.onMouse(msg);

			// �ı�������
			searchInputBox.onMessage(msg);
			snameBox.onMessage(msg);
			snumBox.onMessage(msg);
			scoreBox.onMessage(msg);
		}

		showxy(msg);





		FlushBatchDraw(); //������ͼ

		ULONGLONG end_time = GetTickCount();
		if (end_time - start_time < 1)
		{
			Sleep(1);
		}

	}
	return;
}






