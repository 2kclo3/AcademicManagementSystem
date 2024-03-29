#include"course.h"
//ע���ڴ�й¶����
//֮��GPA���øĸģ������ǰٷֱȻ���
//������Σ�ʵ�ֶ����ε�ά��
//ע��������ѧ�ŵȵĹ淶���ж�

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
		showMenu("��ѡ����", 8, "�˳�", "�鿴", "��ӿγ�", "Ϊĳ�γ����ĳѧ���ɼ�", "�޸Ŀγ�", "�޸�ĳ���γ̵�ĳѧ���ɼ�","ɾ���γ�","ɾ��ĳ���γ̵�ĳѧ���ɼ�");
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
	
	printf("�γ�����:%s\t�γ̺�:%d\t�γ�����:%s\n",p->cname,p->cnum,p->character);
	printf("������:%d\t�ܳɼ�:%.2f\tƽ���ɼ�:%.2f\t��GPA:%.3f\tƽ��GPA:%.3f\n", p->headcount, p->totscore, p->averscore,p->totGPA,p->averGPA);
	Spnode pp = p->sphead->next;
	while (pp)
	{
		printf("����:%s\tѧ��:%d\t�ɼ�:%.2f\tGPA:%.3f\n",pp->sname,pp->snum,pp->score,pp->GPA);
		pp = pp->next;
	}
	system("pause");
	return 1;
}

int addCrs(Cpnode phead) // ��ӿγ̣��������ɼ���
{
	Cpnode p = (Cpnode)malloc(sizeof(_Cnode));
	if (p == NULL)//�ж��ڴ��Ƿ������ȷ�����п��޵ĸо�
	{
		printf("�ڴ����ʧ��\n");
		exit(0);
	}

	p->sphead = (Spnode)malloc(sizeof(Snode));
	if (p->sphead == NULL)//�ж��ڴ��Ƿ������ȷ�����п��޵ĸо�
	{
		printf("�ڴ����ʧ��\n");
		exit(0);
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
	printf("������γ���:");
	getText(p->cname);
	printf("\n");
	printf("������γ̺�:");//��λ���֣�����0��ͷ
	while(1)
	{
		p->cnum = getNumber(1e5 - 1);
		if (p->cnum < 1e4)
		{
			printf("�������ݲ��Ϸ������������룡\n");
			continue;
		}
		break;
	}
	printf("\n");
	showMenu("��ѡ��γ�����", 2, "����", "ѡ��");
	int op = 0;
	while (1)
	{
		op = getNumber(2);
		if (op == 0)
		{
			printf("�������ݲ��Ϸ������������룡\n");
			continue;
		}
		break;
	}
	switch (op)
	{
	case 1:
		strcpy(p->character, "����");
		break;
	case 2:
		strcpy(p->character, "ѡ��");
		break;
	}
	printf("\n");
	printf("��ӳɹ�\n");
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
	if (pnode == NULL)//�ж��ڴ��Ƿ������ȷ�����п��޵ĸо�
	{
		printf("�ڴ����ʧ��\n");
		exit(0);
	}

	printf("������ѧ������:");///////////////////////////////////////////�Ժ�Ҫ��
	getText(pnode->sname);
	printf("\n");
	printf("������ѧ��ѧ��\n");//��λ������0��ͷ
	while (1)
	{
		pnode->snum  = getNumber(1e8 - 1);
		if (pnode->snum < 1e7)
		{
			printf("�������ݲ��Ϸ������������룡\n");
			continue;
		}
		break;
	}
	printf("\n");
	printf("������ѧ���ɼ�\n");
	pnode->score = getDouble(100);////////////��ʵ�����ҲҪ�ģ�01���ǶԵ�
	printf("\n");
	pnode->GPA = pnode->score / 100 * 4;

	p->headcount++;//ע�����ȼ�
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;


	pnode->next = p->sphead->next;
	p->sphead->next = pnode;



	printf("��ӳɹ�\n");
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
		showMenu("��ѡ����", 4, "����", "�޸Ŀγ�����", "�޸Ŀγ̺�", "�޸Ŀγ�����");
		int op = 0;
		while(1)
		{
			int op = getNumber(4);
			if (op == 0)
			{
				printf("�������ݲ��Ϸ������������룡\n");
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
			printf("�ɵĿγ�����:%s", p->cname);
			printf("\n�������µĿγ�����:");
			getText(p->cname);
			printf("\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			printf("�ɵĿγ̺�:%d", p->cnum);
			printf("\n�������µĿγ̺�:");
			while (1)
			{
				p->cnum = getNumber(1e5 - 1);
				if (p->cnum < 1e4)
				{
					printf("�������ݲ��Ϸ������������룡\n");
					continue;
				}
				break;
			}
			printf("\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			printf("�ɵĿγ�����:%s", p->character);
			showMenu("��ѡ���µĿγ�����", 2, "����", "ѡ��");
			int op = 0;
			while (1)
			{
				op = getNumber(2);
				if (op == 0)
				{
					printf("�������ݲ��Ϸ������������룡\n");
					continue;
				}
				break;
			}
			switch (op)
			{
			case 1:
				strcpy(p->character, "����");
				break;
			case 2:
				strcpy(p->character, "ѡ��");
				break;
			}
			printf("\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		}
	}
	return 1;
}

//��������Σ�������������
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

	printf("�ɵ�ѧ���ɼ�:%f", pnode->score);
	printf("\n�������µ�ѧ���ɼ�:");
	pnode->score = getDouble(100);
	printf("\n�޸ĳɹ�\n");
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

	printf("������γ�����\n");
	char str[30];
	getText(str);
	Cpnode p = phead;
	while (p->next)
	{
		Cpnode pp = p->next;//��ɶ�󲡣���ǵ���������д
		if (strcmp(str, pp->cname) == 0)
			break;
		p = p->next;
	}
	if (!p->next)
	{
		printf("û�д˿γ�\n");
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

	printf("ɾ���ɹ�\n");
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

	printf("������ѧ������\n");
	char str[30];
	getText(str);
	Spnode pnode = p->sphead;
	while (pnode->next)
	{
		if (strcmp(str, pnode->next->sname) == 0)
			break;
		pnode = pnode->next;
	}


	if (!pnode->next)
	{
		printf("���޴���\n");
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
	printf("ɾ���ɹ�\n");
	system("pause");
	return 1;
}


Cpnode searchCrs(Cpnode phead)// ���ܿγ������������γ�
{
	printf("������γ�����\n");
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
		printf("û�д˿γ�\n");
		return NULL;
	}
	return p;
}
Spnode searchStuInCrs(Spnode phead) // �ڵ����γ����������µ�ѧ��
{
	printf("������ѧ��ѧ��\n");
	int snum = 0;
	while (1)
	{
		snum = getNumber(1e8 - 1);
		if (snum < 1e7)
		{
			printf("�������ݲ��Ϸ������������룡\n");
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
		printf("���޴���\n");
		return NULL;
	}
	return pnode;
}