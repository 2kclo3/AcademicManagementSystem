#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"



int mainAAA(void) {
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����



	// ��ʼ��ͼ�δ���
	initgraph(1280, 810);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();




	//testUI();


	allStuUI();
	//loginUI();







	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���





	return 0;
}














