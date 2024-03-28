#include"course.h"
///Ҫ�ж��ڴ��Ƿ������ȷ
//ע���ڴ�й¶����
//�����Ȳ���getNumber�Ĳ���������Ҫ��
//֮��GPA���øĸģ������ǰٷֱȻ���
//������Σ�ʵ�ֶ����ε�ά��

//���γ�����ͷ�ڵ�
Cpnode showAllCrs(Cpnode phead)// ��ʾ���пγ̣�������ѧ���ɼ���
{
	return phead;
}
//��ĳ�γ���ѧ������ͷ�ڵ�
Cpnode showCrs(Cpnode phead) // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
{
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return NULL;
	}
	return p;
}
//��ָ����ѧ���ڵ�
Spnode showStuInCrs(Cpnode phead) // ������ʾ�����γ̵�ĳѧ��
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
		showMenu(L"��ѡ����", 8, L"�˳�", L"�鿴", L"��ӿγ�", L"Ϊĳ�γ����ĳѧ���ɼ�", L"�޸Ŀγ�", L"�޸�ĳ���γ̵�ĳѧ���ɼ�","ɾ���γ�","ɾ��ĳ���γ̵�ĳѧ���ɼ�");
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
	
	wprintf(L"�γ�����:%s\t�γ̺�:%d\t�γ�����:%d\n",p->cname,p->cnum,p->character);
	wprintf(L"������:%d\t�ܳɼ�:%.2f\tƽ���ɼ�:%.2f\t��GPA:%.3f\tƽ��GPA:%.3f\n", p->headcount, p->totscore, p->averscore,p->totGPA,p->averGPA);
	Spnode pp = p->sphead->next;
	while (pp)
	{
		wprintf(L"����:%s\tѧ��:%d\t�ɼ�:%.2f\tGPA:%.3f\n",pp->sname,pp->snum,pp->score,pp->GPA);
		pp = pp->next;
	}
	system("pause");
	return 1;
}

int addCrs(Cpnode phead) // ��ӿγ̣��������ɼ���
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
	//��ʼ��

	p->next = phead->next;
	phead->next = p;//ͷ��

	system("cls");
	wprintf(L"������γ���:");
	getText(p->cname);
	wprintf(L"\n");
	wprintf(L"������γ̺�:");//��λ���֣�����0��ͷ
	while(1)
	{
		p->cnum = getNumber((int)(1e5 - 1));
		if (p->cnum < 1e4)
		{
			wprintf(L"�������ݲ��Ϸ������������룡\n");
			continue;
		}
		break;
	}
	wprintf(L"\n");
	showMenu(L"��ѡ��γ�����", 2, L"����", L"ѡ��");
	int op = 0;
	while (1)
	{
		op = getNumber(2);
		if (op == 0)
		{
			wprintf(L"�������ݲ��Ϸ������������룡\n");
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
	wprintf(L"��ӳɹ�\n");
	system("pause");
	return 1;
}

//�Ժ������˫������+�ݹ���ʵ�����ε�ά��
int addStuToCrs(Cpnode phead) // Ϊĳ�γ����ĳѧ���ɼ�
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

	wprintf(L"������ѧ������:");///////////////////////////////////////////�Ժ�Ҫ��
	getText(pnode->sname);
	wprintf(L"\n");
	wprintf(L"������ѧ��ѧ��\n");//��λ������0��ͷ
	while (1)
	{
		pnode->snum  = getNumber((int)(1e8 - 1));
		if (pnode->snum < 1e7)
		{
			wprintf(L"�������ݲ��Ϸ������������룡\n");
			continue;
		}
		break;
	}
	wprintf(L"\n");
	wprintf(L"������ѧ���ɼ�\n");
	pnode->score = getDouble(100);////////////��ʵ�����ҲҪ�ģ�01���ǶԵ�
	wprintf(L"\n");
	pnode->GPA = pnode->score / 100 * 4;

	p->headcount++;//ע�����ȼ�
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;

	wprintf(L"��ӳɹ�\n");
	system("pause");
	return 1;
}

int modifyCrs(Cpnode phead) // �޸Ŀγ���Ϣ�����޸ĳɼ���
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
		showMenu(L"��ѡ����", 4, L"����", L"�޸Ŀγ�����", L"�޸Ŀγ̺�", L"�޸Ŀγ�����");
		int op = 0;
		while(1)
		{
			int op = getNumber(4);
			if (op == 0)
			{
				wprintf(L"�������ݲ��Ϸ������������룡\n");
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
			wprintf(L"�ɵĿγ�����:%s", p->cname);
			wprintf(L"\n�������µĿγ�����:");
			getText(p->cname);
			wprintf(L"\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			wprintf(L"�ɵĿγ̺�:%d", p->cnum);
			wprintf(L"\n�������µĿγ̺�:");
			while (1)
			{
				p->cnum = getNumber((int)(1e5 - 1));
				if (p->cnum < 1e4)
				{
					wprintf(L"�������ݲ��Ϸ������������룡\n");
					continue;
				}
				break;
			}
			wprintf(L"\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			wprintf(L"�ɵĿγ�����:%d", p->character);
			showMenu(L"��ѡ���µĿγ�����", 2, L"����", L"ѡ��");
			int op = 0;
			while (1)
			{
				op = getNumber(2);
				if (op == 0)
				{
					wprintf(L"�������ݲ��Ϸ������������룡\n");
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
			wprintf(L"\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		}
	}
	return 1;
}

int modifyStuInCrs(Cpnode phead) // �޸�ĳ���γ̵�ĳѧ���ɼ�
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

	wprintf(L"�ɵ�ѧ���ɼ�:%f", pnode->score);
	wprintf(L"\n�������µ�ѧ���ɼ�:");
	pnode->score = getDouble(100);
	wprintf(L"\n�޸ĳɹ�\n");
	pnode->GPA = pnode->score / 100 * 4;
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;
	system("pause");

	return 1;
}

int deleteCrs(Cpnode phead) // ɾ���γ�
{
	system("cls");

	wprintf(L"������γ�����\n");
	wchar_t str[30];
	getText(str);
	Cpnode p = phead;
	while (p->next)
	{
		Cpnode pp = p->next;//��ɶ�󲡣���ǵ���������д
		if (_tcscmp(str, pp->cname) == 0)
			break;
		p = p->next;
	}
	if (!p->next)
	{
		wprintf(L"û�д˿γ�\n");
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

	wprintf(L"ɾ���ɹ�\n");
	system("pause");
	return 1;
}

int deleteStuInCrs(Cpnode phead) // ɾ��ĳ���γ̵�ĳѧ���ɼ�
{
	system("cls");
	Cpnode p = searchCrs(phead);
	if (!p)
	{
		system("pause");
		return 0;
	}

	wprintf(L"������ѧ������\n");
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
		wprintf(L"���޴���\n");
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
	wprintf(L"ɾ���ɹ�\n");
	system("pause");
	return 1;
}


Cpnode searchCrs(Cpnode phead)// ���ܿγ������������γ�
{
	wprintf(L"������γ�����\n");
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
		wprintf(L"û�д˿γ�\n");
		return NULL;
	}
	return p;
}
Spnode searchStuInCrs(Spnode phead) // �ڵ����γ����������µ�ѧ��
{
	wprintf(L"������ѧ��ѧ��\n");
	int snum = 0;
	while (1)
	{
		snum = getNumber((int)(1e8 - 1));
		if (snum < 1e7)
		{
			wprintf(L"�������ݲ��Ϸ������������룡\n");
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
		wprintf(L"���޴���\n");
		return NULL;
	}
	return pnode;
}