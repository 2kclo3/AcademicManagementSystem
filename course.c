#include"course.h"
///要判断内存是否分配正确
//注意以后要考虑内存泄露问题
//最后要在添加学生成绩时维护一门成绩的平均值
//对于课程性质，如果只有两个不如让他选择而非输入

void showAllCrs(); // 显示所有课程（不包含学生成绩）
void showCrs(); // 显示单个课程信息（包含该课程所有学生的成绩）
void showStuInCrs(); // 具体显示单个课程的某学生





void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(Cnode));
	phead->next = NULL;
	showMenu("请选择功能",3,"222", "","");
	int op = getNumber(10);

	return 0;
}


int addCrs(Cpnode phead) // 添加课程（不包含成绩）
{
	Cpnode pnode = (Cpnode)malloc(sizeof(Cnode));
	pnode->sphead = (Spnode)malloc(sizeof(Snode));
	pnode->sphead->next = NULL;//初始化

	pnode->next = phead->next;
	phead->next = pnode;//头插

	system("cls");
	printf("请输入课程名:");
	getText(pnode->cname);
	printf("\n");
	printf("请输入课程号:");/////////这玩意是啥来着
	pnode->cnum = getNumber(10);
	printf("\n");
	printf("请输入课程性质:");
	getText(pnode->character);
	printf("\n");

	printf("添加成功\n");
	system("pause");
	return 1;
}

int addStuToCrs(Cpnode phead) // 为某课程添加某学生成绩
{

	return 1;
}

int modifyCrs(Cpnode phead); // 修改课程信息（不修改成绩）


int modifyStuInCrs(Cpnode phead); // 修改某个课程的某学生成绩


int deleteCrs(Cpnode phead); // 删除课程


int deleteStuInCrs(Cpnode phead); // 删除某个课程的某学生成绩


size_t searchCrs(); // 在总课程链表中搜索课程


size_t searchStuInCrs(); // 在单个课程中搜索其下的学生