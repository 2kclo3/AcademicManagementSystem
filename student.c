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
void showAllStu();
	
void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���

void showCrsInStu();// ������ʾ����ѧ����ĳ�γ�



//���������������������������������������������������������������������ѱ༭������getNumberֻ�ܷ���int���ǳɼ�������Ϊfloat�����⣻


// ������ѧ������(����ѧ��������
void sortStu(List* plist) {
	Node* p, * p0, * r, * r0, * q;
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


// ���ѧ�����������γ̣�
bool addStu(List* plist){
	Node* ptmp = *plist;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	Node* pnew;//�����½ڵ�
	int choice;
	for (int i = 0; i < 7; i++) {//¼���½ڵ���Ϣ
		printf("ѡ����Ҫ¼���ѧ����Ϣ(����1-5����\n1.name 2.ID 3.gender 4.grade 5.college 6.major 7.����¼��");
		scanf("%d", &choice);
		if (choice > 7 || choice < 1)
			printf(" ����ѡ����Ч");
		if (choice == 1)
			getText(pnew->item.data.name);
		if (choice == 2)
			getNumber(pnew->item.data.ID);
		if (choice == 3)
			getNumber(pnew->item.data.gender);
		if (choice == 4)
			getNumber(pnew->item.data.grade);
		if (choice == 5)
			getText(pnew->item.data.college);
		if (choice == 6)
			getText(pnew->item.data.major);
		if (choice == 7)
			break;
	}
	ptmp->next = pnew;
	return true;
}
	

// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�
bool addCrsToStu(List* plist) {
	Node* ptmp= searchStu(plist);//ͨ�����������ҵ����޸�ѧ��
	Course* pcou = &(ptmp->item.course);
	if (pcou->next != NULL)
		pcou = pcou->next;
	Course* pnew;//�����½ڵ�
	int choice;
	for (int i = 0; i < 9; i++) {//¼���½ڵ���Ϣ
		printf("ѡ����Ҫ¼��ĳɼ���Ϣ(����1-5����\n 1.course_id 2.course_name 3.score 4.semester 5.course_nature 6.credit 7.credit 8.����¼��");
		scanf("&d", &choice);
		if (choice > 8 || choice < 1)
			printf(" ����ѡ����Ч");
		if (choice == 1)
			getText(pnew->score.course_id);
		if (choice == 2)
			getText(pnew->score.course_name);
		if (choice == 3)
			getNumber(pnew->score.score);
		if (choice == 4)
			getNumber(pnew->score.semester);
		if (choice == 5)
			getNumber(pnew->score.course_nature);
		if (choice == 6)
			getNumber(pnew->score.credit);
		if (choice == 7)
			getNumber(pnew->score.grid);
		if (choice == 8)
			break;
	}
	pcou->next = pnew;//����½ڵ�
	return true;
}

// �޸�ѧ����Ϣ�����޸Ŀγ̣�
bool modifyStu(List* plist){
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	int choice;
	for (int i = 0; i < 7; i++) {
		printf("ѡ����Ҫ¼���ѧ����Ϣ(����1-5����\n1.name 2.ID 3.gender 4.grade 5.college 6.major 7.����¼��");
		scanf("%d", &choice);
		if (choice > 7 || choice < 1)
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
		if (choice == 7)
			break;
	}
}


// �޸�ĳ��ѧ����ĳ�γ̼��ɼ�
bool modifyCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Score* pcou = searchCrsInStu(ptmp);
	getNumber(pcou->score.score);//���⣡����������������������������������������������������
}

// ɾ��ѧ��
bool deleteStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Node* ptmpp = *plist;
	while (ptmpp->next != ptmp)
		ptmpp = ptmpp->next;
	ptmpp->next = ptmp->next;
	return true;
}


// ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�
bool deleteCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Course* pcou = searchCrsInStu(ptmp);//ͨ�����������ҵ����޸Ŀγ̣�
	Course* ppcou = &(ptmp->item.course);//С����
	while (ppcou->next != pcou)
		ppcou = ppcou->next;
	ppcou->next = pcou->next;
	return true;
}
// ����ѧ��������ͨ��ѧ�ź���������ѧ��
Node* searchStu(List* plist) {
	Node* ptmp = *plist;
	int pid;
	getNumber(pid); //����ѧ��
	char pname[16];
	getText(pname);
	while (ptmp->item.data.ID != pid && strcmp(ptmp->item.data.name,pname) != 0 )//ͨ��������ѧ��������
		ptmp = ptmp->next;
	return (ptmp);//�������ѧ����Ϣ�Ľڵ��ַ
}
	
// �ڵ���ѧ����������γ�
Course* searchCrsInStu(Node* pstu) {
	char pcourse_id[10];
	char pcourse_name[100];
	getText(pcourse_id);
	getText(pcourse_name);//��������ҿγ̵ı�ź����ƣ�
	Course* pcou = &(pstu->item.course);//С����
	while (strcmp(pcou->score.course_id, pcourse_id) != 0 && strcmp(pcou->score.course_name, pcourse_name) != 0)//ͨ���γ̱�Ż�γ���������
		pcou = pcou->next;
	return (pcou);
}