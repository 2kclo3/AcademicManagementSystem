#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainLiu(void) {
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


void allQualityUI() {
	cleardevice();


	Text titleText(20, 50, L"��������Ŀ", 64);
	Button searchBtn(-50, 190, 330, 60, L"   ��ѯ", 1);
	Button addBtn(-50, 280, 330, 60, L"   ���", 1);
	Button modifyBtn(-50, 370, 330, 60, L"   �޸�", 1);
	Button deleteBtn(-50, 460, 330, 60, L"   ɾ��", 1);
	Button backButton(-50, 550, 330, 60, L"   ����", 0);


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
		if (end_time - start_time < 1) {
			Sleep(1);
		}

	}


}


void QualityUI() {
}

