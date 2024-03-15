#pragma warning(disable:4996)

#include "main.h"

int main(void) {
	showMenu("测试标题", 4, "增加", "修改", "查找", "删除");
	int a;
	a = getNumber(5);
	printf("%d\n", a);
	double b = getDouble(10.1);
	printf("%lf", b);
	

	return 0;
}