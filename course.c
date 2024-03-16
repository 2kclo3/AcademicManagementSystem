#include"course.h"
///Ҫ�ж��ڴ��Ƿ������ȷ
//ע���Ժ�Ҫ�����ڴ�й¶����
//���Ҫ�����ѧ���ɼ�ʱά��һ�ųɼ���ƽ��ֵ
//���ڿγ����ʣ����ֻ��������������ѡ���������
//�����Ȳ���getNumber�Ĳ���������Ҫ��
//֮��GPA���øĸģ������ǰٷֱȻ���
//�ĳɰ�ѧ�Ų�

void showAllCrs(); // ��ʾ���пγ̣�������ѧ���ɼ���
void showCrs(); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
void showStuInCrs(); // ������ʾ�����γ̵�ĳѧ��



void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(Cnode));
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
	Cpnode pnode = (Cpnode)malloc(sizeof(Cnode));
	pnode->sphead = (Spnode)malloc(sizeof(Snode));
	pnode->sphead->next = NULL;
	pnode->headcount = 0;
	pnode->totGPA = 0;
	pnode->totscore = 0;
	pnode->averGPA = 0;
	pnode->averscore = 0;
	//��ʼ��

	pnode->next = phead->next;
	phead->next = pnode;//ͷ��

	system("cls");
	printf("������γ���:");
	getText(pnode->cname);
	printf("\n");
	printf("������γ̺�:");/////////��������ɶ����
	pnode->cnum = getNumber(10);
	printf("\n");
	printf("������γ�����:");
	getText(pnode->character);
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
	pnode->next = p->sphead->next;
	p->sphead->next = pnode;

	printf("������ѧ������:");
	getText(pnode->sname);
	printf("\n");
	printf("������ѧ��ѧ��\n");
	pnode->snum = getNumber(10);
	printf("\n");
	printf("������ѧ���ɼ�\n");
	pnode->score = (double)getNumber(10);///�Ǹ�double����������
	printf("\n");
	pnode->GPA = pnode->score / 100 * 4;

	p->headcount++;//ע�����ȼ�
	p->totscore += pnode->score;
	p->totGPA += pnode->GPA;
	p->averscore = p->totscore / p->headcount;
	p->averGPA = p->totGPA / p->headcount;

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
		int op = getNumber(10);
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
			p->cnum = getNumber(10);
			printf("\n�޸ĳɹ�\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			printf("�ɵĿγ�����:%s", p->character);
			printf("\n�������µĿγ�����:");
			getText(p->character);
			printf("\n�޸ĳɹ�\n");
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

	printf("�ɵ�ѧ���ɼ�:%f", pnode->score);
	printf("\n�������µ�ѧ���ɼ�:");
	pnode->score = getNumber(10);
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
		Cpnode pp = p->next;////��ɶ�󲡣���ǵ���������д
		if (strcmp(str,pp->cname) == 0)
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
	p = pp->next;////��ɶ�󲡣���ǵ���������д

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

	return 1;
}

//���Ժ����˫�������ĸ�
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
	printf("������ѧ������\n");
	char str[30];
	getText(str);
	Spnode pnode = phead->next;
	while (pnode)
	{
		if (strcmp(str, pnode->sname) == 0)
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