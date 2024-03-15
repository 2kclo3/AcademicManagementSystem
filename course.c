#include"course.h"
///要判断内存是否分配正确
//注意以后要考虑内存泄露问题
//最后要在添加学生成绩时维护一门成绩的平均值
//对于课程性质，如果只有两个不如让他选择而非输入
//初步先不对getNumber的参数做过多要求

void showAllCrs(); // 显示所有课程（不包含学生成绩）
void showCrs(); // 显示单个课程信息（包含该课程所有学生的成绩）
void showStuInCrs(); // 具体显示单个课程的某学生



void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(Cnode));
	phead->next = NULL;
	while(1)
	{
		system("cls");
		showMenu("请选择功能", 5, "退出", "查看", "添加课程","为某课程添加某学生成绩", "修改课程");
		int op = getNumber(10);
		switch (op)
		{
		case 1:
			return 0;
		case 2:
			look(phead);
			break;
		case 3:
			addCrs(phead);
			break;
		case 4:
			addStuToCrs(phead);
			break;
		case 5:
			modifyCrs(phead);
			break;
		}
	}
}

int look(Cpnode phead)
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}
	
	printf("课程名称:%s\t课程号:%d\t课程性质:%s\n",p->cname,p->cnum,p->character);
	Spnode pp = p->sphead->next;
	while (pp)
	{
		printf("姓名:%s\t学号:%d\t成绩:%.2f\tGPA:%.3f\n",pp->sname,pp->snum,pp->score,pp->GPA);
		pp = pp->next;
	}
	system("pause");
	return 1;
}

int addCrs(Cpnode phead) // 添加课程（不包含成绩）
{
	Cpnode pnode = (Cpnode)malloc(sizeof(Cnode));
	pnode->sphead = (Spnode)malloc(sizeof(Snode));
	pnode->sphead->next = NULL;
	pnode->headcount = 0;
	pnode->totGPA = 0;
	pnode->totscore = 0;
	//初始化

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

//以后可以用双向链表+递归来实现名次的维护
int addStuToCrs(Cpnode phead) // 为某课程添加某学生成绩
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}
	Spnode pnode = (Spnode)malloc(sizeof(Snode));
	pnode->next = p->sphead->next;
	p->sphead->next = pnode;

	printf("请输入学生姓名:");
	getText(pnode->sname);
	printf("\n");
	printf("请输入学生学号\n");
	pnode->snum = getNumber(10);
	printf("\n");
	printf("请输入学生成绩\n");
	pnode->score = (double)getNumber(10);///那个double函数有问题
	printf("\n");
	pnode->GPA = pnode->score / 100 * 4;

	p->headcount++;//注意优先级
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;

	printf("添加成功\n");
	system("pause");
	return 1;
}

int modifyCrs(Cpnode phead) // 修改课程信息（不修改成绩）
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}
	while (1)
	{
		system("cls");
		showMenu("请选择功能", 4, "返回", "修改课程名称", "修改课程号", "修改课程性质");
		int op = getNumber(10);
		switch (op)
		{
		case 1:
			return 1;
		case 2:
		{
			system("cls");
			printf("旧的课程名称:%s", p->cname);
			printf("\n请输入新的课程名称:");
			getText(p->cname);
			printf("\n修改成功\n");
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			printf("旧的课程号:%d", p->cnum);
			printf("\n请输入新的课程号:");
			p->cnum = getNumber(10);
			printf("\n修改成功\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			printf("旧的课程性质:%s", p->character);
			printf("\n请输入新的课程性质:");
			getText(p->character);
			printf("\n修改成功\n");
			system("pause");
			break;
		}
		}
	}
	return 1;
}

int modifyStuInCrs(Cpnode phead); // 修改某个课程的某学生成绩


int deleteCrs(Cpnode phead); // 删除课程


int deleteStuInCrs(Cpnode phead); // 删除某个课程的某学生成绩



Cpnode searchCrs(Cpnode phead)// 在总课程链表中搜索课程
{
	printf("请输入课程名称\n");
	char str[30];
	getText(str);
	Cpnode p = phead->next;
	while (p)
	{
		if (strcmp(str, p->cname) == 0)
			break;
		p = p->next;
	}
	if (!p)
	{
		printf("没有此课程\n");
		return NULL;
	}
	return p;
}
Spnode searchStuInCrs(Spnode phead); // 在单个课程中搜索其下的学生