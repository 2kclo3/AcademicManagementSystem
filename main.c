#pragma warning(disable:4996)

#include "main.h"

int main(void) {
	showMenu("���Ա���", 4, "����", "�޸�", "����", "ɾ��");
	int a;
	a = getNumber(5);
	printf("%d\n", a);
	double b = getDouble(10.1);
	printf("%lf", b);
	

	return 0;
}