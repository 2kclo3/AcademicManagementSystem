#include"course.h"
///Ҫ�ж��ڴ��Ƿ������ȷ
//ע���Ժ�Ҫ�����ڴ�й¶����
//���Ҫ�����ѧ���ɼ�ʱά��һ�ųɼ���ƽ��ֵ
//���ڿγ����ʣ����ֻ��������������ѡ���������

void showAllCrs(); // ��ʾ���пγ̣�������ѧ���ɼ���
void showCrs(); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���
void showStuInCrs(); // ������ʾ�����γ̵�ĳѧ��





void menu()
{
	Cpnode phead = (Cpnode)malloc(sizeof(Cnode));
	phead->next = NULL;
	showMenu("��ѡ����",3,"222", "","");
	int op = getNumber(10);

	return 0;
}


int addCrs(Cpnode phead) // ��ӿγ̣��������ɼ���
{
	Cpnode pnode = (Cpnode)malloc(sizeof(Cnode));
	pnode->sphead = (Spnode)malloc(sizeof(Snode));
	pnode->sphead->next = NULL;//��ʼ��

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

int addStuToCrs(Cpnode phead) // Ϊĳ�γ����ĳѧ���ɼ�
{

	return 1;
}

int modifyCrs(Cpnode phead); // �޸Ŀγ���Ϣ�����޸ĳɼ���


int modifyStuInCrs(Cpnode phead); // �޸�ĳ���γ̵�ĳѧ���ɼ�


int deleteCrs(Cpnode phead); // ɾ���γ�


int deleteStuInCrs(Cpnode phead); // ɾ��ĳ���γ̵�ĳѧ���ɼ�


size_t searchCrs(); // ���ܿγ������������γ�


size_t searchStuInCrs(); // �ڵ����γ����������µ�ѧ��