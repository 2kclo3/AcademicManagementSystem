#include "student.h"





//��ʼ������
void InitializeList(List* plist) {
	//plist = (List**)malloc(sizeof(Node*));
	//*plist = (List*)malloc(sizeof(Node));
	//if (*plist == NULL) {
	//	printf("�ڴ����ʧ�ܣ�");
	//	exit(EXIT_FAILURE);
	//}
	(*plist)->next = NULL;
}

// ��ʾ����ѧ����Ϣ���������γ̣�����һ������
void showAllStu() ��
	


void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���





void showCrsInStu();// ������ʾ����ѧ����ĳ�γ�

// ���ѧ�����������γ̣�
bool addStu(Node* node, List* plist){
	Node* ptmp = *plist;
	node->next = NULL;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	ptmp->next = node;
	return true;
}
	
// ������ѧ������(����ѧ��������
void sortStu(List* plist) {
	Node*p,*p0,*r,*r0,*q;
	p = p0 = r = r0 = q = NULL;
	p = *plist;
	while (p) {
		r = *plist;
		while (r->item.data.ID < p->item.data.ID && r != p) {
			r0 = r;
			r = r->next;
		}//��λ��

		if (r != p) {
			q = p;
			p0->next = p->next;
			p = p0;
			if (r != *plist) {
				r0->next = q;
				q->next = r;
			}
			else {
				q->next = *plist;
				*plist = q;
			}
		}
	}
}

// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�
bool addCrsToStu(List* plist) {
	Node* pmtp= searchStu(plist);//ͨ�����������ҵ����޸�ѧ��

	
}

// �޸�ѧ����Ϣ�����޸Ŀγ̣�
bool modifyStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	printf("ѡ����Ҫ�޸ĵ�ѧ����Ϣ(����1-5����\n1.name 2.ID 3.gender 4.grade 5.college 6.major");
	int choice;
	scanf("%d", &choice);
	if (choice > 6 || choice < 1)
		printf(" ����ѡ����Ч");
	if (choice == 1)
		getText(ptmp->item.data.name);
	if (choice == 2)
		getNumber(ptmp->item.data.ID);
	if (choice == 3)
		getNumber(ptmp->item.data.gender);
	if (choice == 4)
		getNumber(ptmp->item.data.grade);
	if (choice == 5)
		getText(ptmp->item.data.college);
	if (choice == 6)
		getText(ptmp->item.data.major);
}



bool modifyCrsInStu(); // �޸�ĳ��ѧ����ĳ�γ̼��ɼ�


// ɾ��ѧ��
bool deleteStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Node* ptmpp = *plist;
	while (ptmpp->next != ptmp)
		ptmpp = ptmpp->next;
	ptmpp->next = ptmp->next;
	return true;
}


bool deleteCrsInStu(); // ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�

// ����ѧ��������ͨ��ѧ�ź���������ѧ��
Node* searchStu(List* plist) {
	Node* ptmp = *plist;
	int id;
	getNumber(id); //����ѧ��
	char name[16];
	getTexe(name);
	while (ptmp->item.data.ID != id || strcmp(ptmp->item.data.name,name) != 0 )//ͨ��������ѧ��������
		ptmp = ptmp->next;
	return (ptmp);//�������ѧ����Ϣ�Ľڵ��ַ
}
	


Node* searchCrsInStu(); // �ڵ���ѧ����������γ�