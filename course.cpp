#include"course.h"
//之后GPA还得改改，他不是百分比换算
//添加名次，实现对名次的维护
//筛选、排序、特殊的查找（最高成绩、最低成绩），这些功能可以加上


////传课程链表头节点
//Cpnode showAllCrs(Cpnode phead)// 显示所有课程（不包含学生成绩）
//{
//	return phead;
//}这个函数多余了，删去
// 
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
//这些函数都多余了，显示操作不归我负责

void menu()
{
	Cpnode cphead = (Cpnode)malloc(sizeof(_Cnode));
	cphead->next = NULL;
	while(1)
	{
		fflush(stdin);
		system("CLS");
		showMenu(L"请选择功能", 8, L"退出", L"查看", L"添加课程", L"为某课程添加某学生成绩", L"修改课程", L"修改某个课程的某学生成绩", L"删除课程", L"删除某个课程的某学生成绩");
		int op = getNumber(10);
		switch (op)
		{
		case 1://退出
			return;
		case 2://查看
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"课程名称：";wcin >> Cname;
			wcout <<endl;
			wcout << L"课程号：";wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead,Cname, Cnum);
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			look(cplist);

			break;
		}
		case 3://添加课程
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wchar_t Character[10];
			wcout << L"课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"课程号："; wcin >> Cnum;
			wcout << endl;
			wcout << L"课程性质："; wcin >> Character;
			wcout << endl;

			int flag=addCrs(cphead,Cname,Cnum,Character);
			if (flag == -1)
			{
				wcout << L"已有此课程" << endl;
				system("pause");
				break;
			}
			else if (flag == 0)
			{
				wcout << L"内存分配失败" << endl;
				system("pause");
				exit(0);
			}
			else if (flag == 1)
			{
				wcout << L"添加成功" << endl;
				system("pause");
				break;
			}
		}
		case 4://为某课程添加某学生成绩
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"课程号："; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);        
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			double Score;
			wcout << L"学生姓名："; wcin >> Sname;
			wcout <<endl;
			wcout << L"学号："; wcin >> Snum;
			wcout << endl;
			wcout << L"成绩："; wcin >> Score;
			wcout << endl;

			int flag=addStuToCrs(cplist,Sname,Snum,Score);
			if (flag == -1)
			{
				wcout << L"已有此人" << endl;
				system("pause");
				break;
			}
			else if (flag == 0)
			{
				wcout << L"内存分配失败" << endl;
				system("pause");
				exit(0);
			}
			else if (flag == 1)
			{
				wcout << L"添加成功" << endl;
				system("pause");
				break;
			}
		}
		case 5://修改课程
		{
			system("CLS");
			wchar_t original_Cname[10];
			int original_Cnum;
			wcout << L"原课程名称："; wcin >> original_Cname;
			wcout << endl;
			wcout << L"原课程号："; wcin >> original_Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, original_Cname, original_Cnum);
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			wchar_t Cname[10];
			int Cnum;
			wchar_t Character[10];
			wcout <<L"原课程名称："<< cplist->cname;
			wcout << endl;
			wcout << L"新课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"原课程号：" << cplist->cnum;
			wcout << endl;
			wcout << L"新课程号："; wcin >> Cnum;
			wcout << endl;
			wcout << L"原课程性质：" << cplist->character;
			wcout << endl;
			wcout << L"新课程性质："; wcin >> Character;
			wcout << endl;

			modifyCrs(cplist,Cname,Cnum,Character);

			wcout << L"修改成功" << endl;
			system("pause");
			break;
		}
		case 6://修改某个课程的某学生成绩
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"课程号："; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			wchar_t original_Sname[10];
			int original_Snum;
			wcout << L"原学生姓名："; wcin >> original_Sname;
			wcout << endl;
			wcout << L"原学号："; wcin >> original_Snum;
			wcout << endl;
			Spnode splist = searchStuInCrs(cplist, original_Sname, original_Snum);
			if (!splist)
			{
				wcout << L"查无此人" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			double Score;
			wcout << L"原学生姓名：" << splist->sname;
			wcout << endl;
			wcout << L"新学生姓名："; wcin >> Sname;
			wcout << endl;
			wcout << L"原学号：" << splist->snum;
			wcout << endl;
			wcout << L"新学号："; wcin >> Snum;
			wcout << endl;
			wcout << L"原成绩：" << splist->score;
			wcout << endl;
			wcout << L"新成绩："; wcin >> Score;
			wcout << endl;

			modifyStuInCrs(cplist,splist,Sname,Snum,Score);

			wcout << L"修改成功" << endl;
			system("pause");
			break;
		}
		case 7://删除课程
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"课程号："; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			deleteCrs(cphead,cplist);

			wcout << L"删除成功" << endl;
			system("pause");
			break;
		}
		case 8://删除某个课程的某学生成绩
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"课程名称："; wcin >> Cname;
			wcout << endl;
			wcout << L"课程号："; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"查无此课程" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			wcout << L"学生姓名："; wcin >> Sname;
			wcout << endl;
			wcout << L"学号："; wcin >> Snum;
			wcout << endl;
			Spnode splist = searchStuInCrs(cplist, Sname,Snum);
			if (!splist)
			{
				wcout << L"查无此人" << endl;
				system("pause");
				break;
			}

			deleteStuInCrs(cplist,splist);

			wcout << L"删除成功" << endl;
			system("pause");
			break;
		}
		}
	}
}


int look(Cpnode cplist)
{
	system("CLS");
	wprintf(L"课程名称:%s\t课程号:%d\t课程性质:%s\n", cplist->cname, cplist->cnum, cplist->character);
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
//正常返回1；如果内存分配失败，返回0;如果已经有了该课程,返回-1
int addCrs(Cpnode cphead,const wchar_t * Cname,int Cnum,const wchar_t*Character) // 添加课程
{
	if (searchCrs(cphead, Cname, Cnum))
		return -1; 
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
//正常返回1;如果内存分配失败，返回0;如果已经有了该学生,返回-1
int addStuToCrs(Cpnode cplist,const wchar_t* Sname,int Snum,double Score)// 为某课程添加某学生成绩
{
	if (searchStuInCrs(cplist, Sname, Snum))
		return -1;
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


//参数列表：目标课程的节点地址，课程名称，课程号，课程性质
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
int modifyStuInCrs(Cpnode cplist,Spnode splist, const wchar_t *Sname,int Snum, double Score) // 修改某个课程的某学生信息
{
	cplist->totscore -= splist->score;
	cplist->totGPA -= splist->GPA;

	wcscpy(splist->sname, Sname);
	splist->snum = Snum;
	splist->score = Score;
	splist->GPA = splist->score / 100 * 4;

	cplist->totscore += splist->score;
	cplist->totGPA += splist->GPA;
	cplist->averscore = cplist->totscore / cplist->headcount;
	cplist->averGPA = cplist->totGPA / cplist->headcount;

	return 1;
}


//参数列表：课程链表的头节点地址，目标课程的节点地址
//正常返回1
int deleteCrs(Cpnode cphead,Cpnode target_cplist) // 删除课程
{
	Cpnode pre_cplist = cphead;
	Cpnode cplist = pre_cplist->next;

	while (cplist)
	{
		if (cplist == target_cplist)
			break;
		pre_cplist = pre_cplist->next;
		cplist = cplist->next;
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


//参数列表：目标课程的节点地址，目标学生的节点地址
//正常返回1
int deleteStuInCrs(Cpnode cplist,Spnode target_splist) // 删除某个课程的某学生成绩
{
	Spnode pre_splist = cplist->sphead;
	Spnode splist = pre_splist->next;
	while (splist)
	{
		if (splist== target_splist)
				break;
		pre_splist = pre_splist->next;
		splist = splist->next;
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


//参数列表：课程链表的头节点地址，课程名称，课程号
//找到了返回目标课程的节点地址，没找到返回NULL
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