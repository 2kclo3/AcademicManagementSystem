#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainZhang(void) {
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


void allCrsUI() {
	cleardevice();


	Text titleText(40, 50, L"���пγ�", 64);
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
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}

}


void CrsUI() {
}






