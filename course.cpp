#include"course.h"
//之后GPA还得改改，他不是百分比换算
//添加名次，实现对名次的维护
//待解决的问题：删除课程或学生时，要展示待删除项目的信息吗？如果要，那么和删除相关的函数就不能自带查找功能



////传课程链表头节点
//Cpnode showAllCrs(Cpnode phead)// 显示所有课程（不包含学生成绩）
//{
//	return phead;
//}
////传某课程下学生链表头节点
//Cpnode showCrs(Cpnode phead) // 显示单个课程信息（包含该课程所有学生的成绩）
//{
//	Cpnode p = searchCrs(phead);
//	if (!p)
//	{
//		system("pause");
//		return NULL;
//	}
//	return p;
//}
////传指定的学生节点
//Spnode showStuInCrs(Cpnode phead) // 具体显示单个课程的某学生
//{
//	Cpnode p = searchCrs(phead);
//	if (!p)
//	{
//		system("pause");
//		return NULL;
//	}
//	Spnode pnode = searchStuInCrs(p->sphead);
//	if (!pnode)
//	{
//		system("pause");
//		return NULL;
//	}
//	return pnode;
//
//}


void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(_Cnode));
	phead->next = NULL;
	while(1)
	{
		showMenu(L"请选择功能", 8, L"退出", L"查看", L"添加课程", L"为某课程添加某学生成绩", L"修改课程", L"修改某个课程的某学生成绩", L"删除课程", L"删除某个课程的某学生成绩");
		int op = getNumber(10);
		switch (op)
		{
		case 1:
			return;
		case 2:
		{
			wchar_t Cname[10];
			int Cnum;
			wcout << "课程名称：";
			wcin >> Cname;
			cout << '\t';
			cout << "课程号：";
			cin >> Cnum;
			look(phead,Cname,Cnum);
		}
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

int look(Cpnode cplist)
{
	wprintf(L"课程名称:%s\t课程号:%d\t课程性质:%d\n", cplist->cname, cplist->cnum, cplist->character);
	wprintf(L"总人数:%d\t总成绩:%.2f\t平均成绩:%.2f\t总GPA:%.3f\t平均GPA:%.3f\n", cplist->headcount, cplist->totscore, cplist->averscore, cplist->totGPA, cplist->averGPA);
	Spnode splist = cplist->sphead->next;
	while (splist)
	{
		wprintf(L"姓名:%s\t学号:%d\t成绩:%.2f\tGPA:%.3f\n", splist->sname, splist->snum, splist->score, splist->GPA);
		splist = splist->next;
	}
	system("pause");
	return 1;
}


//参数列表：课程链表的头节点地址，课程名称，课程号，课程性质
//正常返回1；如果内存分配失败，返回0;如果已经有了该课程,返回2
int addCrs(Cpnode cphead,const wchar_t * Cname,int Cnum,const wchar_t*Character) // 添加课程
{
	if (searchCrs(cphead, Cname, Cnum))
		return 2; //如果已经有了该课程, 返回2
	Cpnode cplist = (Cpnode)malloc(sizeof(_Cnode));
	if (cplist == NULL) 
	{
		return 0;
	}
	cplist->sphead = (Spnode)malloc(sizeof(Snode));
	if (cplist->sphead == NULL) 
	{
		return 0;
	}

	cplist->sphead->next = NULL;
	cplist->headcount = 0;
	cplist->totGPA = 0;
	cplist->totscore = 0;
	cplist->averGPA = 0;
	cplist->averscore = 0;
	//初始化

	cplist->next = cphead->next;
	cphead->next = cplist;//头插


	wcscpy(cplist->cname, Cname);
	cplist->cnum = Cnum;
	wcscpy(cplist->character, Character);
	return 1;
}


//参数列表：目标课程的节点地址，学生姓名，学号，成绩
//正常返回1;如果内存分配失败，返回0;如果已经有了该学生,返回2
int addStuToCrs(Cpnode cplist,const wchar_t* Sname,int Snum,double Score)// 为某课程添加某学生成绩
{
	if (searchStuInCrs(cplist, Sname, Snum))
		return 2;//如果已经有了该学生,返回2
	Spnode splist = (Spnode)malloc(sizeof(Snode));
	if (!splist)
	{
		return 0;
	}
	splist->next = cplist->sphead->next;
	cplist->sphead->next = splist;

	wcscpy(splist->sname, Sname);
	splist->snum = Snum;
	splist->score = Score;

	splist->GPA = splist->score / 100 * 4;///////////////////////////////////////以后要改

	cplist->headcount++;//注意优先级
	cplist->totscore += splist->score;
	cplist->totGPA += splist->GPA;
	cplist->averscore = cplist->totscore / cplist->headcount;
	cplist->averGPA = cplist->totGPA / cplist->headcount;

	return 1;
}
//可能对同一课程进行多次添加学生的操作。
//为避免重复查找同一课程，该函数选择将目标课程的节点地址作为参数，而非课程链表的头节点地址


//参数列表：要修改的课程节点的地址，课程名称，课程号，课程性质
//正常返回1
int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character) // 修改课程信息
{
	wcscpy(cplist->cname, Cname);
	cplist->cnum = Cnum;
	wcscpy(cplist->character, Character);
	return 1;
}


//参数列表：目标课程的节点地址，目标学生的节点地址,学生姓名，学号，成绩
//正常返回1
int modifyStuInCrs(Cpnode cplist,Spnode splist, wchar_t Sname,int Snum, double Score) // 修改某个课程的某学生信息
{
	cplist->totscore -= splist->score;
	cplist->totGPA -= splist->GPA;

	splist->score = getDouble(100);
	splist->GPA = splist->score / 100 * 4;

	cplist->totscore += splist->score;
	cplist->totGPA += splist->GPA;
	cplist->averscore = cplist->totscore / cplist->headcount;
	cplist->averGPA = cplist->totGPA / cplist->headcount;

	return 1;
}



//参数列表：课程链表的头节点地址，课程名称，课程号
//正常返回1;如果查无此课程，返回-1
int deleteCrs(Cpnode cphead,Cpnode target_cplist) // 删除课程
{
	Cpnode pre_cplist = cphead;
	Cpnode ctmp = cphead->next;

	while (ctmp)
	{
		if (ctmp == cplist)
			break;
		pre_cplist = pre_cplist->next;
		ctmp = ctmp->next;
	}
	if (!ctmp)
	{
		return -1;//NULL改成-1
	}

	Spnode sphead = cplist->sphead;
	Spnode splist=sphead->next;
	while (splist)
	{
		sphead->next = splist->next;
		free(splist);
		splist = sphead->next;
	}
	free(sphead);

	pre_cplist->next = cplist->next;
	free(cplist);

	return 1;
}


//参数列表：目标课程的节点地址，学生姓名，学号
//正常返回1;如果查无此人，返回-1
int deleteStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum) // 删除某个课程的某学生成绩
{
	Spnode pre_splist = cplist->sphead;
	Spnode splist = pre_splist->next;
	while (splist)
	{
		if (wcscmp(Sname, splist->sname) == 0)
			if (Snum == splist->snum)
				break;
		pre_splist = pre_splist->next;
		splist = splist->next;
	}
	if (!splist)
	{
		return -1;
	}

	cplist->headcount--;
	cplist->totscore -= splist->score;
	cplist->totGPA -= splist->GPA;
	if(cplist->headcount)
	{
		cplist->averscore = cplist->totscore / cplist->headcount;
		cplist->averGPA = cplist->totGPA / cplist->headcount;
	}
	else
	{
		cplist->averscore = 0;
		cplist->averGPA = 0;
	}

	pre_splist->next = splist->next;
	free(splist);

	return 1;
}




Cpnode searchCrs(Cpnode cphead,const wchar_t *Cname,int Cnum)// 在课程链表中搜索课程
{
	Cpnode cplist = cphead->next;
	while (cplist)
	{
		if (wcscmp(Cname, cplist->cname) == 0)
			if(Cnum==cplist->cnum)
				break;
		cplist = cplist->next;
	}
	if (!cplist)
	{
		return NULL;
	}
	return cplist;
}


//参数列表：目标课程的节点地址，学生姓名，学号
//找到了返回目标学生的节点地址，没找到返回NULL
Spnode searchStuInCrs(Cpnode cplist,const wchar_t *Sname,int Snum) // 在单个课程中搜索其下的学生
{
	Spnode splist = cplist->sphead->next;
	while (splist)
	{
		if (wcscmp(Sname, splist->sname) == 0)
			if (Snum==splist->snum)
				break;
		splist = splist->next;
	}
	if (!splist)
	{
		return NULL;
	}
	return splist;
}