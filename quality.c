#include"quality.h"
#include"student.h"
#include"io.h"
#include"ui.h"
#include<stdbool.h>
//�������⣺1.Ϊÿ��ѧ����r/clist��������ڱ��ڵ�
//			2.searchR/Cnode()������ʵ��

Node* searchStuInQuality(List phead) { // ����������Ŀ������ѧ��
	printf("������ѧ������\n");
	char str[30];
	getText(str);
	Node* ptmp = phead->next;//�����˿����ڱ��ڵ�
	while (ptmp!=NULL)
	{
		if (strcmp(str, ptmp->item.data.name) == 0)
			break;
		ptmp = ptmp->next;
	}
	if (ptmp==NULL){
		printf("���޴���\n");
		return NULL;
	}
	return ptmp;
}



bool addQuality_rlist(List* plist){
	Node* ptmp = searchStu(plist);
	Rnode* rhead = ptmp->item.rlist;
	Rnode* rtmp = rhead->rnext;//������rlist���������ڱ��ڵ�
	while (rtmp->rnext != NULL)
		rtmp = rtmp->rnext;//β�巨
	Rnode* rnew = (Rnode*)malloc(sizeof(Rnode));
	if (rnew == NULL)
		return false;//�ڵ�ռ����ʧ��
	rnew->rnext = NULL;
	printf("������������Ҫ������ӵĿ��гɹ��������Ϣ:\n ");
	
	printf("1.�������ƣ������");
	getText(rnew->research.paper_name);
	
	printf("2.�ڿ�/�������ƣ������");
	getText(rnew->research.journal_or_conference_name);
	
	printf("3.������������豾��������� �����");
	getText(rnew->research.author);
	
	printf("4.����ʱ�䣨���� �����");
	getText(rnew->research.date);
	
	printf("5.���������޿ɲ����");
	getText(rnew->research.volume_num);
	
	printf("6.���ţ����޿ɲ����");
	getText(rnew->research.issue_num);
	
	printf("7.ҳ�뷶Χ�������");
	getText(rnew->research.page);

	rtmp->rnext = rnew;
	return true;
}



bool addQuality_clist(List* plist) {
	Node* ptmp = searchStu(plist);
	Cnode* chead = ptmp->item.rlist;
	Cnode* ctmp = chead->cnext;//������clist���������ڱ��ڵ�
	while (ctmp->cnext != NULL)
		ctmp = ctmp->cnext;//β�巨
	Cnode* cnew = (Cnode*)malloc(sizeof(Cnode));
	if (cnew == NULL)
		return false;//�ڵ�ռ����ʧ��
	cnew->cnext = NULL;
	printf("������������Ҫ������ӵľ�����񽱵������Ϣ:\n ");

	printf("1.�������ƣ������");
	getText(cnew->competition.competition_name);

	printf("2.�ٰ쵥λ�������");
	getText(cnew->competition.organizer);

	printf("3.����𣨱����");
	getText(cnew->competition.category);

	printf("4.��ʱ�䣨���� �����");
	getText(cnew->competition.date);

	ctmp->cnext = cnew;
	return true;
}



void modifyQuality_rlist(List* plist) { // �޸���������Ŀ֮���гɹ�
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Rnode* rhead = ptmp->item.rlist;
	Rnode rmod = searchRnode(rhead);
	while (1) {
		showMenu("��ѡ��Ҫ�޸ĵĿ��гɹ��������Ϣ��", 8, "1.��������", "2.�ڿ�/��������", "3.�������", "4.����ʱ��", "5.����", "6.����", "7.ҳ�뷶Χ", "8.�˳�");
		int option = getNumber(8);
		switch (option) {
		case 1:
			getText(rmod.research.paper_name);
			break;

		case 2:
			getText(rmod.research.journal_or_conference_name);
			break;

		case 3:
			getText(rmod.research.author);
			break;

		case 4:
			getText(rmod.research.date);
			break;

		case 5:
			getText(rmod.research.volume_num);
			break;

		case 6:
			getText(rmod.research.issue_num);
			break;

		case 7:
			getText(rmod.research.page);
			break;

		case 8:
			return 0;

		}
	
	}

}



void modifyQuality_clist(List* plist) { // �޸���������Ŀ֮������
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Cnode* chead = ptmp->item.clist;
	Cnode cmod = searchCnode(chead);
	while (1) {
		showMenu("��ѡ��Ҫ�޸ĵľ����񽱵������Ϣ��", 5, "1.��������", "2.�ٰ쵥λ", "3.�����", "4.��ʱ��", "5.�˳�");
		int option = getNumber(5);
		switch (option) {
		case 1:
			getText(cmod.competition.competition_name);
			break;

		case 2:
			getText(cmod.competition.organizer);
			break;

		case 3:
			getText(cmod.competition.category);
			break;

		case 4:
			getText(cmod.competition.date);
			break;

		case 5:
			return 0;

		}

	}

}


bool deleteQuality(); // ɾ����������Ŀ


