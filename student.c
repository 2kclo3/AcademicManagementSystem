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

// ���ѧ�����������γ̣�
bool addStu(Node* node, List* plist) {
	Node* ptmp = *plist;
	node->next = NULL;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	ptmp->next = node;
	return true;
}
	


bool addCrsToStu();// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�


void sortStu();// ������ѧ������


bool modifyStu();// �޸�ѧ����Ϣ�����޸Ŀγ̣�


bool modifyCrsInStu(); // �޸�ĳ��ѧ����ĳ�γ̼��ɼ�

// ɾ��ѧ��
bool deleteStu(List* plist, Node* node) {
	Node* ptmp = *plist;
	while (ptmp->next != node)
		ptmp = ptmp->next;
	ptmp->next = node->next;
	free(node);
	return true;
}


bool deleteCrsInStu(); // ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�


Node*  searchStu(); // ����ѧ������������ѧ��


Node* searchCrsInStu(); // �ڵ���ѧ����������γ�