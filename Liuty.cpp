#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int mainAAAAAAAAAA(void){ 
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����




	// ��ʼ��ͼ�δ���
	initgraph(1280, 820);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();


	
	
	testUI();


	//loginUI();







	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���
	


	

	return 0;
}













