#include"course.h"
//֮��GPA���øĸģ������ǰٷֱȻ���
//������Σ�ʵ�ֶ����ε�ά��
//ɸѡ����������Ĳ��ң���߳ɼ�����ͳɼ�������Щ���ܿ��Լ���


////���γ�����ͷ�ڵ�
//Cpnode showAllCrs(Cpnode phead)// ��ʾ���пγ̣�������ѧ���ɼ���
//{
//	return phead;
//}������������ˣ�ɾȥ
// 
////��ĳ�γ���ѧ������ͷ�ڵ�
//Cpnode showCrs(Cpnode phead) // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
//{
//	Cpnode p = searchCrs(phead);
//	if (!p)
//	{
//		system("pause");
//		return NULL;
//	}
//	return p;
//}
////��ָ����ѧ���ڵ�
//Spnode showStuInCrs(Cpnode phead) // ������ʾ�����γ̵�ĳѧ��
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
//��Щ�����������ˣ���ʾ���������Ҹ���

void menu()
{
	Cpnode cphead = (Cpnode)malloc(sizeof(_Cnode));
	cphead->next = NULL;
	while(1)
	{
		fflush(stdin);
		system("CLS");
		showMenu(L"��ѡ����", 8, L"�˳�", L"�鿴", L"��ӿγ�", L"Ϊĳ�γ����ĳѧ���ɼ�", L"�޸Ŀγ�", L"�޸�ĳ���γ̵�ĳѧ���ɼ�", L"ɾ���γ�", L"ɾ��ĳ���γ̵�ĳѧ���ɼ�");
		int op = getNumber(10);
		switch (op)
		{
		case 1://�˳�
			return;
		case 2://�鿴
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"�γ����ƣ�";wcin >> Cname;
			wcout <<endl;
			wcout << L"�γ̺ţ�";wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead,Cname, Cnum);
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			look(cplist);

			break;
		}
		case 3://��ӿγ�
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wchar_t Character[10];
			wcout << L"�γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"�γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			wcout << L"�γ����ʣ�"; wcin >> Character;
			wcout << endl;

			int flag=addCrs(cphead,Cname,Cnum,Character);
			if (flag == -1)
			{
				wcout << L"���д˿γ�" << endl;
				system("pause");
				break;
			}
			else if (flag == 0)
			{
				wcout << L"�ڴ����ʧ��" << endl;
				system("pause");
				exit(0);
			}
			else if (flag == 1)
			{
				wcout << L"��ӳɹ�" << endl;
				system("pause");
				break;
			}
		}
		case 4://Ϊĳ�γ����ĳѧ���ɼ�
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"�γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"�γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);        
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			double Score;
			wcout << L"ѧ��������"; wcin >> Sname;
			wcout <<endl;
			wcout << L"ѧ�ţ�"; wcin >> Snum;
			wcout << endl;
			wcout << L"�ɼ���"; wcin >> Score;
			wcout << endl;

			int flag=addStuToCrs(cplist,Sname,Snum,Score);
			if (flag == -1)
			{
				wcout << L"���д���" << endl;
				system("pause");
				break;
			}
			else if (flag == 0)
			{
				wcout << L"�ڴ����ʧ��" << endl;
				system("pause");
				exit(0);
			}
			else if (flag == 1)
			{
				wcout << L"��ӳɹ�" << endl;
				system("pause");
				break;
			}
		}
		case 5://�޸Ŀγ�
		{
			system("CLS");
			wchar_t original_Cname[10];
			int original_Cnum;
			wcout << L"ԭ�γ����ƣ�"; wcin >> original_Cname;
			wcout << endl;
			wcout << L"ԭ�γ̺ţ�"; wcin >> original_Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, original_Cname, original_Cnum);
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			wchar_t Cname[10];
			int Cnum;
			wchar_t Character[10];
			wcout <<L"ԭ�γ����ƣ�"<< cplist->cname;
			wcout << endl;
			wcout << L"�¿γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"ԭ�γ̺ţ�" << cplist->cnum;
			wcout << endl;
			wcout << L"�¿γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			wcout << L"ԭ�γ����ʣ�" << cplist->character;
			wcout << endl;
			wcout << L"�¿γ����ʣ�"; wcin >> Character;
			wcout << endl;

			modifyCrs(cplist,Cname,Cnum,Character);

			wcout << L"�޸ĳɹ�" << endl;
			system("pause");
			break;
		}
		case 6://�޸�ĳ���γ̵�ĳѧ���ɼ�
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"�γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"�γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			wchar_t original_Sname[10];
			int original_Snum;
			wcout << L"ԭѧ��������"; wcin >> original_Sname;
			wcout << endl;
			wcout << L"ԭѧ�ţ�"; wcin >> original_Snum;
			wcout << endl;
			Spnode splist = searchStuInCrs(cplist, original_Sname, original_Snum);
			if (!splist)
			{
				wcout << L"���޴���" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			double Score;
			wcout << L"ԭѧ��������" << splist->sname;
			wcout << endl;
			wcout << L"��ѧ��������"; wcin >> Sname;
			wcout << endl;
			wcout << L"ԭѧ�ţ�" << splist->snum;
			wcout << endl;
			wcout << L"��ѧ�ţ�"; wcin >> Snum;
			wcout << endl;
			wcout << L"ԭ�ɼ���" << splist->score;
			wcout << endl;
			wcout << L"�³ɼ���"; wcin >> Score;
			wcout << endl;

			modifyStuInCrs(cplist,splist,Sname,Snum,Score);

			wcout << L"�޸ĳɹ�" << endl;
			system("pause");
			break;
		}
		case 7://ɾ���γ�
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"�γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"�γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			deleteCrs(cphead,cplist);

			wcout << L"ɾ���ɹ�" << endl;
			system("pause");
			break;
		}
		case 8://ɾ��ĳ���γ̵�ĳѧ���ɼ�
		{
			system("CLS");
			wchar_t Cname[10];
			int Cnum;
			wcout << L"�γ����ƣ�"; wcin >> Cname;
			wcout << endl;
			wcout << L"�γ̺ţ�"; wcin >> Cnum;
			wcout << endl;
			Cpnode cplist = searchCrs(cphead, Cname, Cnum);
			if (!cplist)
			{
				wcout << L"���޴˿γ�" << endl;
				system("pause");
				break;
			}

			wchar_t Sname[10];
			int Snum;
			wcout << L"ѧ��������"; wcin >> Sname;
			wcout << endl;
			wcout << L"ѧ�ţ�"; wcin >> Snum;
			wcout << endl;
			Spnode splist = searchStuInCrs(cplist, Sname,Snum);
			if (!splist)
			{
				wcout << L"���޴���" << endl;
				system("pause");
				break;
			}

			deleteStuInCrs(cplist,splist);

			wcout << L"ɾ���ɹ�" << endl;
			system("pause");
			break;
		}
		}
	}
}


int look(Cpnode cplist)
{
	system("CLS");
	wprintf(L"�γ�����:%s\t�γ̺�:%d\t�γ�����:%s\n", cplist->cname, cplist->cnum, cplist->character);
	wprintf(L"������:%d\t�ܳɼ�:%.2f\tƽ���ɼ�:%.2f\t��GPA:%.3f\tƽ��GPA:%.3f\n", cplist->headcount, cplist->totscore, cplist->averscore, cplist->totGPA, cplist->averGPA);
	Spnode splist = cplist->sphead->next;
	while (splist)
	{
		wprintf(L"����:%s\tѧ��:%d\t�ɼ�:%.2f\tGPA:%.3f\n", splist->sname, splist->snum, splist->score, splist->GPA);
		splist = splist->next;
	}
	system("pause");
	return 1;
}


//�����б��γ������ͷ�ڵ��ַ���γ����ƣ��γ̺ţ��γ�����
//��������1������ڴ����ʧ�ܣ�����0;����Ѿ����˸ÿγ�,����-1
int addCrs(Cpnode cphead,const wchar_t * Cname,int Cnum,const wchar_t*Character) // ��ӿγ�
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
	//��ʼ��

	cplist->next = cphead->next;
	cphead->next = cplist;//ͷ��


	wcscpy(cplist->cname, Cname);
	cplist->cnum = Cnum;
	wcscpy(cplist->character, Character);
	return 1;
}


//�����б�Ŀ��γ̵Ľڵ��ַ��ѧ��������ѧ�ţ��ɼ�
//��������1;����ڴ����ʧ�ܣ�����0;����Ѿ����˸�ѧ��,����-1
int addStuToCrs(Cpnode cplist,const wchar_t* Sname,int Snum,double Score)// Ϊĳ�γ����ĳѧ���ɼ�
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

	splist->GPA = splist->score / 100 * 4;///////////////////////////////////////�Ժ�Ҫ��

	cplist->headcount++;//ע�����ȼ�
	cplist->totscore += splist->score;
	cplist->totGPA += splist->GPA;
	cplist->averscore = cplist->totscore / cplist->headcount;
	cplist->averGPA = cplist->totGPA / cplist->headcount;

	return 1;
}
//���ܶ�ͬһ�γ̽��ж�����ѧ���Ĳ�����
//Ϊ�����ظ�����ͬһ�γ̣��ú���ѡ��Ŀ��γ̵Ľڵ��ַ��Ϊ���������ǿγ������ͷ�ڵ��ַ


//�����б�Ŀ��γ̵Ľڵ��ַ���γ����ƣ��γ̺ţ��γ�����
//��������1
int modifyCrs(Cpnode cplist, const wchar_t* Cname, int Cnum, const wchar_t* Character) // �޸Ŀγ���Ϣ
{
	wcscpy(cplist->cname, Cname);
	cplist->cnum = Cnum;
	wcscpy(cplist->character, Character);
	return 1;
}


//�����б�Ŀ��γ̵Ľڵ��ַ��Ŀ��ѧ���Ľڵ��ַ,ѧ��������ѧ�ţ��ɼ�
//��������1
int modifyStuInCrs(Cpnode cplist,Spnode splist, const wchar_t *Sname,int Snum, double Score) // �޸�ĳ���γ̵�ĳѧ����Ϣ
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


//�����б��γ������ͷ�ڵ��ַ��Ŀ��γ̵Ľڵ��ַ
//��������1
int deleteCrs(Cpnode cphead,Cpnode target_cplist) // ɾ���γ�
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


//�����б�Ŀ��γ̵Ľڵ��ַ��Ŀ��ѧ���Ľڵ��ַ
//��������1
int deleteStuInCrs(Cpnode cplist,Spnode target_splist) // ɾ��ĳ���γ̵�ĳѧ���ɼ�
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


//�����б��γ������ͷ�ڵ��ַ���γ����ƣ��γ̺�
//�ҵ��˷���Ŀ��γ̵Ľڵ��ַ��û�ҵ�����NULL
Cpnode searchCrs(Cpnode cphead,const wchar_t *Cname,int Cnum)// �ڿγ������������γ�
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


//�����б�Ŀ��γ̵Ľڵ��ַ��ѧ��������ѧ��
//�ҵ��˷���Ŀ��ѧ���Ľڵ��ַ��û�ҵ�����NULL
Spnode searchStuInCrs(Cpnode cplist,const wchar_t *Sname,int Snum) // �ڵ����γ����������µ�ѧ��
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