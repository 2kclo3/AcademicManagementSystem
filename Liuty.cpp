#pragma warning(disable:4996)

#include "main.h"
#define STU_FILE ".\\data\\Student.txt"
#define CRS_FILE ".\\data\\Course.txt"


int mainAAAAA(void){ 
	setlocale(LC_ALL, ""); //ʹ����̨֧�ֿ��ַ����



	Cpnode  crs = readCrs(CRS_FILE);
	List stu = readStu(STU_FILE);


	// ��ʼ��ͼ�δ���
	initgraph(1280, 820);
	BeginBatchDraw(); //��ʼ������ͼ
	setbkcolor(RGB(55, 61, 53)); //������ɫ
	cleardevice();




	testUI();


	//loginUI();







	EndBatchDraw(); //����������ͼ
	closegraph(); // �ر�ͼ�δ���
	



	saveStu(stu, STU_FILE);
	saveCrs(crs, CRS_FILE);


	

	return 0;
}













