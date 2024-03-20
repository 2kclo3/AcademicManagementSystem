#include"quality.h"
#include"student.h"
#include"io.h"
#include"ui.h"
#include<stdbool.h>
//�������⣺1.Ϊÿ��ѧ����r/clist��������ڱ��ڵ� (OK
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


void Initialize_Quality_List(List phead){// ��ʼ����������Ŀ������Ϊÿ��ѧ����r/clist��������ڱ��ڵ㣩
	List Ltmp = phead->next;
	while (Ltmp != NULL) {
		
		Rnode* rhead = (Rnode*)malloc(sizeof(Rnode));
		if (rhead == NULL)
			return NULL;
		rhead->rnext = NULL;
		Ltmp->item.rlist = rhead;

		Cnode* chead = (Cnode*)malloc(sizeof(Cnode));
		if (chead == NULL)
			return NULL;
		chead->cnext = NULL;
		Ltmp->item.clist = chead;

		Ltmp = Ltmp->next;
	}
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
	
	printf("1.�������ƣ������\n");
	getText(rnew->research.paper_name);
	
	printf("2.�ڿ�/�������ƣ������\n");
	getText(rnew->research.journal_or_conference_name);
	
	printf("3.������������豾��������� �����\n");
	getText(rnew->research.author);
	
	printf("4.����ʱ�䣨���� �����\n");
	getText(rnew->research.date);
	
	printf("5.���������޿ɲ����\n");
	getText(rnew->research.volume_num);
	
	printf("6.���ţ����޿ɲ����\n");
	getText(rnew->research.issue_num);
	
	printf("7.ҳ�뷶Χ�������\n");
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

	printf("1.�������ƣ������\n");
	getText(cnew->competition.competition_name);

	printf("2.�ٰ쵥λ�������\n");
	getText(cnew->competition.organizer);

	printf("3.����𣨱����\n");
	getText(cnew->competition.category);

	printf("4.��ʱ�䣨���� �����\n");
	getText(cnew->competition.date);

	ctmp->cnext = cnew;
	return true;
}


Rnode searchRnode(Rnode* rhead) {//�ҳ����޸ĵ���������Ŀ�ڵ�


}
Cnode searchCnode(Cnode* chead) {

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
			printf("ԭ���ĵ���������:%s", rmod.research.paper_name);
			printf("\n�������µ���������:");
			getText(rmod.research.paper_name);
			break;

		case 2:
			printf("ԭ�����ڿ�/��������:%s", rmod.research.journal_or_conference_name);
			printf("\n�������µ��ڿ�/��������:");
			getText(rmod.research.journal_or_conference_name);
			break;

		case 3:
			printf("ԭ�����������:%s", rmod.research.author);
			printf("\n�������µ��������:");
			getText(rmod.research.author);
			break;

		case 4:
			printf("ԭ���ķ���ʱ��:%s", rmod.research.date);
			printf("\n�������µķ���ʱ��:");
			getText(rmod.research.date);
			break;

		case 5:
			printf("ԭ���ľ���:%s", rmod.research.volume_num);
			printf("\n�������µľ���:");
			getText(rmod.research.volume_num);
			break;

		case 6:
			printf("ԭ���Ŀ���:%s", rmod.research.issue_num);
			printf("\n�������µĿ���:");
			getText(rmod.research.issue_num);
			break;

		case 7:
			printf("ԭ����ҳ�뷶Χ:%s", rmod.research.page);
			printf("\n�������µ�ҳ�뷶Χ:");
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
			printf("ԭ���ľ�������:%s", cmod.competition.competition_name);
			printf("\n�������µľ�������:");
			getText(cmod.competition.competition_name);
			break;

		case 2:
			printf("ԭ���ľٰ쵥λ:%s", cmod.competition.organizer);
			printf("\n�������µľٰ쵥λ:");
			getText(cmod.competition.organizer);
			break;

		case 3:
			printf("ԭ���Ļ����:%s", cmod.competition.category);
			printf("\n�������µĻ����:");
			getText(cmod.competition.category);
			break;

		case 4:
			printf("ԭ���Ļ�ʱ��:%s", cmod.competition.date);
			printf("\n�������µĻ�ʱ��:");
			getText(cmod.competition.date);
			break;

		case 5:
			return 0;

		}

	}

}


bool deleteQuality(); // ɾ����������Ŀ


