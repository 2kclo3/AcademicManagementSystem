#include"course.h"
///要判断内存是否分配正确
//注意内存泄露问题
//初步先不对getNumber的参数做过多要求
//之后GPA还得改改，他不是百分比换算
//添加名次，实现对名次的维护

//传课程链表头节点
Cpnode showAllCrs(Cpnode phead)// 显示所有课程（不包含学生成绩）
{
	return phead;
}
//传某课程下学生链表头节点
Cpnode showCrs(Cpnode phead) // 显示单个课程信息（包含该课程所有学生的成绩）
{
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return NULL;
	}
	return p;
}
//传指定的学生节点
Spnode showStuInCrs(Cpnode phead) // 具体显示单个课程的某学生
{
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return NULL;
	}
	Spnode pnode = searchStuInCrs(p->sphead);
	if (!pnode)
	{
		system("pause");
		return NULL;
	}
	return pnode;

}



void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(_Cnode));
	phead->next = NULL;
	while(1)
	{
		system("cls");
		showMenu(L"请选择功能", 8, L"退出", L"查看", L"添加课程", L"为某课程添加某学生成绩", L"修改课程", L"修改某个课程的某学生成绩","删除课程","删除某个课程的某学生成绩");
		int op = getNumber(10);
		switch (op)
		{
		case 1:
			return;
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
		case 6:
			modifyStuInCrs(phead);
			break;
		case 7:
			deleteCrs(phead);
			break;
		case 8:
			deleteStuInCrs(phead);
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
	
	wprintf(L"课程名称:%s\t课程号:%d\t课程性质:%d\n",p->cname,p->cnum,p->character);
	wprintf(L"总人数:%d\t总成绩:%.2f\t平均成绩:%.2f\t总GPA:%.3f\t平均GPA:%.3f\n", p->headcount, p->totscore, p->averscore,p->totGPA,p->averGPA);
	Spnode pp = p->sphead->next;
	while (pp)
	{
		wprintf(L"姓名:%s\t学号:%d\t成绩:%.2f\tGPA:%.3f\n",pp->sname,pp->snum,pp->score,pp->GPA);
		pp = pp->next;
	}
	system("pause");
	return 1;
}

int addCrs(Cpnode phead) // 添加课程（不包含成绩）
{
	Cpnode p = (Cpnode)malloc(sizeof(_Cnode));
	if (p == NULL) {
		wprintf(L"error!");
		return 0;
	}
	p->sphead = (Spnode)malloc(sizeof(Snode));
	if (p->sphead == NULL) {
		wprintf(L"error!");
		return 0;
	}
	p->sphead->next = NULL;
	p->headcount = 0;
	p->totGPA = 0;
	p->totscore = 0;
	p->averGPA = 0;
	p->averscore = 0;
	//初始化

	p->next = phead->next;
	phead->next = p;//头插

	system("cls");
	wprintf(L"请输入课程名:");
	getText(p->cname);
	wprintf(L"\n");
	wprintf(L"请输入课程号:");//五位数字，不以0开头
	while(1)
	{
		p->cnum = getNumber((int)(1e5 - 1));
		if (p->cnum < 1e4)
		{
			wprintf(L"输入数据不合法，请重新输入！\n");
			continue;
		}
		break;
	}
	wprintf(L"\n");
	showMenu(L"请选择课程性质", 2, L"必修", L"选修");
	int op = 0;
	while (1)
	{
		op = getNumber(2);
		if (op == 0)
		{
			wprintf(L"输入数据不合法，请重新输入！\n");
			continue;
		}
		break;
	}
	switch (op)
	{
	case 1:
		p->character = 1;
		break;
	case 2:
		p->character = 2;
		break;
	}
	wprintf(L"\n");
	wprintf(L"添加成功\n");
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
	if (pnode == NULL) {
		wprintf(L"error!");
		return 0;
	}
	pnode->next = p->sphead->next;
	p->sphead->next = pnode;

	wprintf(L"请输入学生姓名:");///////////////////////////////////////////以后要改
	getText(pnode->sname);
	wprintf(L"\n");
	wprintf(L"请输入学生学号\n");//八位，不以0开头
	while (1)
	{
		pnode->snum  = getNumber((int)(1e8 - 1));
		if (pnode->snum < 1e7)
		{
			wprintf(L"输入数据不合法，请重新输入！\n");
			continue;
		}
		break;
	}
	wprintf(L"\n");
	wprintf(L"请输入学生成绩\n");
	pnode->score = getDouble(100);////////////其实，这个也要改，01还是对的
	wprintf(L"\n");
	pnode->GPA = pnode->score / 100 * 4;

	p->headcount++;//注意优先级
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;

	wprintf(L"添加成功\n");
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
		showMenu(L"请选择功能", 4, L"返回", L"修改课程名称", L"修改课程号", L"修改课程性质");
		int op = 0;
		while(1)
		{
			int op = getNumber(4);
			if (op == 0)
			{
				wprintf(L"输入数据不合法，请重新输入！\n");
				continue;
			}
			break;
		}
		switch (op)
		{
		case 1:
			return 1;
		case 2:
		{
			system("cls");
			wprintf(L"旧的课程名称:%s", p->cname);
			wprintf(L"\n请输入新的课程名称:");
			getText(p->cname);
			wprintf(L"\n修改成功\n");
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			wprintf(L"旧的课程号:%d", p->cnum);
			wprintf(L"\n请输入新的课程号:");
			while (1)
			{
				p->cnum = getNumber((int)(1e5 - 1));
				if (p->cnum < 1e4)
				{
					wprintf(L"输入数据不合法，请重新输入！\n");
					continue;
				}
				break;
			}
			wprintf(L"\n修改成功\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			wprintf(L"旧的课程性质:%d", p->character);
			showMenu(L"请选择新的课程性质", 2, L"必修", L"选修");
			int op = 0;
			while (1)
			{
				op = getNumber(2);
				if (op == 0)
				{
					wprintf(L"输入数据不合法，请重新输入！\n");
					continue;
				}
				break;
			}
			switch (op)
			{
			case 1:
				p->character = 1;
				break;
			case 2:
				p->character = 2;
				break;
			}
			wprintf(L"\n修改成功\n");
			system("pause");
			break;
		}
		}
	}
	return 1;
}

int modifyStuInCrs(Cpnode phead) // 修改某个课程的某学生成绩
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}
	Spnode pnode = searchStuInCrs(p->sphead);
	if (!pnode)
	{
		system("pause");
		return 0;
	}
	p->totscore -= pnode->score;
	p->totGPA -= pnode->GPA;

	wprintf(L"旧的学生成绩:%f", pnode->score);
	wprintf(L"\n请输入新的学生成绩:");
	pnode->score = getDouble(100);
	wprintf(L"\n修改成功\n");
	pnode->GPA = pnode->score / 100 * 4;
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;
	system("pause");

	return 1;
}

int deleteCrs(Cpnode phead) // 删除课程
{
	system("cls");

	wprintf(L"请输入课程名称\n");
	wchar_t str[30];
	getText(str);
	Cpnode p = phead;
	while (p->next)
	{
		Cpnode pp = p->next;//犯啥大病，这非得让我这样写
		if (_tcscmp(str, pp->cname) == 0)
			break;
		p = p->next;
	}
	if (!p->next)
	{
		wprintf(L"没有此课程\n");
		system("pause");
		return 0;
	}
	Cpnode pp = p;
	p = p->next;

	Spnode tmp;
	while (p->sphead->next)
	{
		tmp = p->sphead->next->next;
		free(p->sphead->next);
		p->sphead->next = tmp;
	}
	free(p->sphead);
	pp->next = p->next;
	free(p);

	wprintf(L"删除成功\n");
	system("pause");
	return 1;
}

int deleteStuInCrs(Cpnode phead) // 删除某个课程的某学生成绩
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}

	wprintf(L"请输入学生姓名\n");
	wchar_t str[30];
	getText(str);
	Spnode pnode = p->sphead;
	while (pnode->next)
	{
		if (_tcscmp(str, pnode->next->sname) == 0)
			break;
		pnode = pnode->next;
	}


	if (!pnode->next)
	{
		wprintf(L"查无此人\n");
		system("pause");
		return 0;
	}
	Spnode tmp = pnode->next;

	p->headcount--;
	p->totscore -= tmp->score;
	p->totGPA -= tmp->GPA;
	if(p->headcount)
	{
		p->averscore = p->totscore / p->headcount;
		p->averGPA = p->totGPA / p->headcount;
	}
	else
	{
		p->averscore = 0;
		p->averGPA = 0;
	}

	pnode->next = tmp->next;
	free(tmp);
	wprintf(L"删除成功\n");
	system("pause");
	return 1;
}


Cpnode searchCrs(Cpnode phead)// 在总课程链表中搜索课程
{
	wprintf(L"请输入课程名称\n");
	wchar_t str[30];
	getText(str);
	Cpnode p = phead->next;
	while (p)
	{
		if (_tcscmp(str, p->cname) == 0)
			break;
		p = p->next;
	}
	if (!p)
	{
		wprintf(L"没有此课程\n");
		return NULL;
	}
	return p;
}
Spnode searchStuInCrs(Spnode phead) // 在单个课程中搜索其下的学生
{
	wprintf(L"请输入学生学号\n");
	int snum = 0;
	while (1)
	{
		snum = getNumber((int)(1e8 - 1));
		if (snum < 1e7)
		{
			wprintf(L"输入数据不合法，请重新输入！\n");
			continue;
		}
		break;
	}
	Spnode pnode = phead->next;
	while (pnode)
	{
		if (snum==pnode->snum)
			break;
		pnode = pnode->next;
	}
	if (!pnode)
	{
		wprintf(L"查无此人\n");
		return NULL;
	}
	return pnode;
}