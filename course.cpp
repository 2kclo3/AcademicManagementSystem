#include"course.h"
//֮��GPA���øĸģ������ǰٷֱȻ���
//������Σ�ʵ�ֶ����ε�ά��
//����������⣺ɾ���γ̻�ѧ��ʱ��Ҫչʾ��ɾ����Ŀ����Ϣ�����Ҫ����ô��ɾ����صĺ����Ͳ����Դ����ҹ���



////���γ�����ͷ�ڵ�
//Cpnode showAllCrs(Cpnode phead)// ��ʾ���пγ̣�������ѧ���ɼ���
//{
//	return phead;
//}
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


void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(_Cnode));
	phead->next = NULL;
	while(1)
	{
		showMenu(L"��ѡ����", 8, L"�˳�", L"�鿴", L"��ӿγ�", L"Ϊĳ�γ����ĳѧ���ɼ�", L"�޸Ŀγ�", L"�޸�ĳ���γ̵�ĳѧ���ɼ�", L"ɾ���γ�", L"ɾ��ĳ���γ̵�ĳѧ���ɼ�");
		int op = getNumber(10);
		switch (op)
		{
		case 1:
			return;
		case 2:
		{
			wchar_t Cname[10];
			int Cnum;
			wcout << "�γ����ƣ�";
			wcin >> Cname;
			cout << '\t';
			cout << "�γ̺ţ�";
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
	wprintf(L"�γ�����:%s\t�γ̺�:%d\t�γ�����:%d\n", cplist->cname, cplist->cnum, cplist->character);
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
//��������1������ڴ����ʧ�ܣ�����0;����Ѿ����˸ÿγ�,����2
int addCrs(Cpnode cphead,const wchar_t * Cname,int Cnum,const wchar_t*Character) // ��ӿγ�
{
	if (searchCrs(cphead, Cname, Cnum))
		return 2; //����Ѿ����˸ÿγ�, ����2
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
//��������1;����ڴ����ʧ�ܣ�����0;����Ѿ����˸�ѧ��,����2
int addStuToCrs(Cpnode cplist,const wchar_t* Sname,int Snum,double Score)// Ϊĳ�γ����ĳѧ���ɼ�
{
	if (searchStuInCrs(cplist, Sname, Snum))
		return 2;//����Ѿ����˸�ѧ��,����2
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


//�����б�Ҫ�޸ĵĿγ̽ڵ�ĵ�ַ���γ����ƣ��γ̺ţ��γ�����
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
int modifyStuInCrs(Cpnode cplist,Spnode splist, wchar_t Sname,int Snum, double Score) // �޸�ĳ���γ̵�ĳѧ����Ϣ
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



//�����б��γ������ͷ�ڵ��ַ���γ����ƣ��γ̺�
//��������1;������޴˿γ̣�����-1
int deleteCrs(Cpnode cphead,Cpnode target_cplist) // ɾ���γ�
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
		return -1;//NULL�ĳ�-1
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


//�����б�Ŀ��γ̵Ľڵ��ַ��ѧ��������ѧ��
//��������1;������޴��ˣ�����-1
int deleteStuInCrs(Cpnode cplist, const wchar_t* Sname, int Snum) // ɾ��ĳ���γ̵�ĳѧ���ɼ�
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