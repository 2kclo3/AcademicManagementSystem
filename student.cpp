#include "student.h"


#pragma warning(disable:4996)


// ��ʾ����ѧ����Ϣ���������γ̣�����һ������
void showAllStu();
	
void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���

void showCrsInStu();// ������ʾ����ѧ����ĳ�γ�



//���������������������������������������������������������������������ѱ༭������getNumberֻ�ܷ���int���ǳɼ�������Ϊfloat�����⣻


// ������ѧ������(����ѧ��������
/*void sortStu(List* plist) {
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
*/

//��ʼ��ÿ��ѧ���Ŀγ���������ڱ��ڵ�
/*bool Initialize_Stu_Crslist(List phead) {
		List Ltmp = phead->next;
		while (Ltmp != NULL) {
			Crsnode* crs_head = (Crsnode*)malloc(sizeof(Crsnode));
			if (crs_head == NULL)
				return false;
			crs_head->crs_next = NULL;
			Ltmp->item.crslist = crs_head;
			Ltmp = Ltmp->next;
		}
		return true;
}
*/

// ���ѧ�����������γ̣�
/*bool addStu(List* plist) {
	Node* ptmp = *plist;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	Node* pnew = (Node*)malloc(sizeof(Node));//�����½ڵ�
	int choice;
	for (int i = 0; i < 7; i++) {//¼���½ڵ���Ϣ
		wprintf(L"ѡ����Ҫ¼���ѧ����Ϣ(����1-5����\n1.name 2.ID 3.gender 4.grade 5.college 6.major 7.����¼��");
		wscanf(L"%d", &choice);
		if (choice > 7 || choice < 1)
			wprintf(L" ����ѡ����Ч");
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
*/	

// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�
/*bool addCrsToStu(List* plist) {
	Node* ptmp= searchStu(plist);//ͨ�����������ҵ����޸�ѧ��
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_tmp = crs_head->crs_next;//�γ�������Ҫ���ڱ��ڵ�
	while (crs_tmp->crs_next != NULL)
		crs_tmp = crs_tmp->crs_next;
	Crsnode* crs_new = (Crsnode*)malloc(sizeof(Crsnode));//�����½ڵ�
	if (crs_new == NULL)
		return false;
	crs_new->crs_next = NULL;
	int choice;
	for (int i = 0; i < 9; i++) {//¼���½ڵ���Ϣ
		wprintf(L"ѡ����Ҫ¼��ĳɼ���Ϣ(����1-5����\n 1.course_id 2.course_name 3.score 4.semester 5.course_nature 6.credit 7.credit 8.����¼��");
		wscanf(L"%d", &choice);
		if (choice > 8 || choice < 1)
			wprintf(L" ����ѡ����Ч");
		if (choice == 1)
			getText(crs_new->score.course_id);
		if (choice == 2)
			getText(crs_new->score.course_name);
		if (choice == 3)
			getNumber(crs_new->score.score);
		if (choice == 4)
			getNumber(crs_new->score.semester);
		if (choice == 5)
			getNumber(crs_new->score.course_nature);
		if (choice == 6)
			getNumber(crs_new->score.credit);
		if (choice == 7)
			getNumber(crs_new->score.grid);
		if (choice == 8)
			break;
	}
	crs_tmp->crs_next = crs_new;//����½ڵ�
	return true;
}
*/

// �޸�ѧ����Ϣ�����޸Ŀγ̣�
//bool modifyStu(List* plist , wchar_t* pname ,int pID ,int pgender,int pgrade,wchar_t* college,wchar_t major) {
//	Node* ptmp = *plist;
//	wcscpy(ptmp->item.data.name,pname);
//	ptmp->item.data.ID = pID;
//	ptmp->item.data.gender = pgender;
//	ptmp->item.data.grade = pgrade;
//	getText(ptmp->item.data.college);
//	getText(ptmp->item.data.major);
//}

// �޸�ĳ��ѧ����ĳ�γ̼��ɼ�
/*bool modifyCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_mod = searchCrsInStu(crs_head); //�ҵ����޸ĵĿγ�
	//......


	return true; //�������лᱨ��û�з���ֵ
}
*/

// ɾ��ѧ��
//����������ͷ�ڵ㣬��ɾ��ѧ���ڵ�
bool deleteStu(List* plist, Node* delstu) {
	Node* ptmp = *plist;
	while (ptmp->next != delstu)
		ptmp = ptmp->next;
	ptmp->next = delstu->next;
	free(delstu);
	return true;
}

/*// ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�
bool deleteCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//ͨ�����������ҵ����޸�ѧ��;
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_del = searchCrsInStu(crs_head);
	Crsnode* crs_tmp = crs_head;//������Ѱ�ұ�ɾ���γ̽ڵ��ǰ�̽ڵ�
	while (crs_tmp!=NULL && crs_tmp->crs_next != crs_del) {
		crs_tmp = crs_tmp->crs_next;
	}
	crs_tmp->crs_next = crs_del->crs_next;
	free(crs_del);
	wprintf(L"\nɾ���ɹ���");
	return true;
}
*/

// ����ѧ��������ͨ��ѧ�ź���������ѧ�� 
//������ͷ�ڵ㣬������ѧ�ź�����
Node* searchStu(List* plist, wchar_t* pname, int pID) {
	Node* ptmp = *plist;
	while (ptmp->item.data.ID != pID || _tcscmp(ptmp->item.data.name, pname) != 0 )//ͨ��������ѧ��������
		ptmp = ptmp->next;
	return (ptmp);//�������ѧ����Ϣ�Ľڵ��ַ
}
	
// �ڵ���ѧ����������ɾ��/�޸ĵĿγ�
/*Crsnode* searchCrsInStu(Crsnode* crs_head) {
	wchar_t pcourse_id[10];
	wchar_t pcourse_name[100];
	getText(pcourse_id);
	getText(pcourse_name);//��������ҿγ̵ı�ź����ƣ�
	Crsnode* crs_aim = crs_head->crs_next;
	while (_tcscmp(crs_aim->score.course_id, pcourse_id) != 0 && _tcscmp(crs_aim->score.course_name, pcourse_name) != 0)//ͨ���γ̱�Ż�γ���������
		crs_aim = crs_aim->crs_next;
	return crs_aim;
}
*/