#pragma warning(disable:4996)
#include"quality.h"
//�������⣺1.Ϊÿ��ѧ����r/clist��������ڱ��ڵ� (OK
//			2.searchR/Cnode()������ʵ��  (OK

int Research_num = 0;
int Competition_num = 0;

Node* searchStuInQuality(List phead) { // ����������Ŀ������ѧ��
	wprintf(L"������ѧ������\n");
	wchar_t str[30];
	getText(str);
	Node* ptmp = phead->next;//�����˿����ڱ��ڵ�
	while (ptmp!=NULL)
	{
		if (_tcscmp(str, ptmp->item.data.name) == 0)
			break;
		ptmp = ptmp->next;
	}
	if (ptmp==NULL){
		wprintf(L"���޴���\n");
		return NULL;
	}
	return ptmp;
}


bool Initialize_Quality_List(List phead){// ��ʼ����������Ŀ������Ϊÿ��ѧ����r/clist��������ڱ��ڵ㣩
	List Ltmp = phead->next;
	while (Ltmp != NULL) {
		
		Rnode* rhead = (Rnode*)malloc(sizeof(Rnode));
		if (rhead == NULL)
			return false;
		rhead->rnext = NULL;
		Ltmp->item.rlist = rhead;

		Cnode* chead = (Cnode*)malloc(sizeof(Cnode));
		if (chead == NULL)
			return false;
		chead->cnext = NULL;
		Ltmp->item.clist = chead;

		Ltmp = Ltmp->next;
	}
	return true;
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
	wprintf(L"������������Ҫ������ӵĿ��гɹ��������Ϣ:\n ");
	
	wprintf(L"1.�������ƣ������\n");
	getText(rnew->research.paper_name);
	
	wprintf(L"2.�ڿ�/�������ƣ������\n");
	getText(rnew->research.journal_or_conference_name);
	
	wprintf(L"3.������������豾��������� �����\n");
	getText(rnew->research.author);
	
	wprintf(L"4.����ʱ�䣨���� �����\n");
	getText(rnew->research.date);
	
	wprintf(L"5.���������޿ɲ����\n");
	getText(rnew->research.volume_num);
	
	wprintf(L"6.���ţ����޿ɲ����\n");
	getText(rnew->research.issue_num);
	
	wprintf(L"7.ҳ�뷶Χ�������\n");
	getText(rnew->research.page);

	wprintf(L"8.Ӧ�ü���ӷ֣������\n");
	wscanf(L"%lf", &rnew->research.GPA_bonus);
	
	rtmp->rnext = rnew;
	return true;
}
bool addQuality_clist(List* plist) {
	Node* ptmp = searchStu(plist);
	Cnode* chead = ptmp->item.clist;
	Cnode* ctmp = chead->cnext;//������clist���������ڱ��ڵ�
	while (ctmp->cnext != NULL)
		ctmp = ctmp->cnext;//β�巨
	Cnode* cnew = (Cnode*)malloc(sizeof(Cnode));
	if (cnew == NULL)
		return false;//�ڵ�ռ����ʧ��
	cnew->cnext = NULL;
	wprintf(L"������������Ҫ������ӵľ�����񽱵������Ϣ:\n ");

	wprintf(L"1.�������ƣ������\n");
	getText(cnew->competition.competition_name);

	wprintf(L"2.�ٰ쵥λ�������\n");
	getText(cnew->competition.organizer);

	wprintf(L"3.����𣨱����\n");
	getText(cnew->competition.category);

	wprintf(L"4.��ʱ�䣨���� �����\n");
	getText(cnew->competition.date);

	wprintf(L"8.Ӧ�ü���ӷ֣������\n");
	wscanf(L"%lf", &cnew->competition.GPA_bonus);

	ctmp->cnext = cnew;
	return true;
}


void show_Research_menu(const wchar_t* title ,Rnode* rhead) {//�����޸ĺ���ȷ�����账��Ŀ�����Ŀ�ڵ�
		wprintf(L"%s\n\n", title);
		Rnode* rtmp = rhead->rnext;
		while (rtmp != NULL) {
			Research_num++;
			wprintf(L"%2d:%s\n", Research_num, rtmp->research.paper_name);
			rtmp = rtmp->rnext;
		}
}
void show_Competition_menu(const wchar_t* title, Cnode* chead) {//�����޸ĺ���ȷ�����账��ľ����񽱽ڵ�
	wprintf(L"%s\n\n", title);
	Cnode* ctmp = chead->cnext;
	while (ctmp != NULL) {
		Competition_num++;
		wprintf(L"%2d:%s\n", Competition_num, ctmp->competition.competition_name);
		ctmp = ctmp->cnext;
	}
}


Rnode* searchRnode(Rnode* rhead) {//�ҳ����޸ĵ���������Ŀ�ڵ�
	show_Research_menu(L"ȷ�������޸�/ɾ���Ŀ��гɹ�", rhead);
	int option = getNumber(Research_num);
	int count = 1;
	Rnode* rtmp = rhead->rnext;
	while (count < option) {
		rtmp = rtmp->rnext;	
		count++;
	}
	return rtmp;
}
Cnode* searchCnode(Cnode* chead) {
	show_Competition_menu(L"ȷ�������޸�/ɾ���ľ�����", chead);
	int option = getNumber(Competition_num);
	int count = 1;
	Cnode* ctmp = chead->cnext;
	while (count < option) {
		ctmp = ctmp->cnext;
		count++;
	}
	return ctmp;
}


void modifyQuality_rlist(List* plist) { // �޸���������Ŀ֮���гɹ�
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Rnode* rhead = ptmp->item.rlist;
	Rnode* rmod = searchRnode(rhead);//�ҵ����޸ĵĿ��гɹ��ڵ�
	while (1) {
		showMenu(L"��ѡ��Ҫ�޸ĵĿ��гɹ��������Ϣ��", 9, L"1.��������", L"2.�ڿ�/��������", L"3.�������", L"4.����ʱ��", L"5.����", L"6.����", L"7.ҳ�뷶Χ", L"8.Ӧ�ü���ӷ�","9.�˳�");
		int option = getNumber(9);
		switch (option) {
		case 1:
			wprintf(L"ԭ���ĵ���������:%s", rmod->research.paper_name);
			wprintf(L"\n�������µ���������:");
			getText(rmod->research.paper_name);
			break;

		case 2:
			wprintf(L"ԭ�����ڿ�/��������:%s", rmod->research.journal_or_conference_name);
			wprintf(L"\n�������µ��ڿ�/��������:");
			getText(rmod->research.journal_or_conference_name);
			break;

		case 3:
			wprintf(L"ԭ�����������:%s", rmod->research.author);
			wprintf(L"\n�������µ��������:");
			getText(rmod->research.author);
			break;

		case 4:
			wprintf(L"ԭ���ķ���ʱ��:%s", rmod->research.date);
			wprintf(L"\n�������µķ���ʱ��:");
			getText(rmod->research.date);
			break;

		case 5:
			wprintf(L"ԭ���ľ���:%s", rmod->research.volume_num);
			wprintf(L"\n�������µľ���:");
			getText(rmod->research.volume_num);
			break;

		case 6:
			wprintf(L"ԭ���Ŀ���:%s", rmod->research.issue_num);
			wprintf(L"\n�������µĿ���:");
			getText(rmod->research.issue_num);
			break;

		case 7:
			wprintf(L"ԭ����ҳ�뷶Χ:%s", rmod->research.page);
			wprintf(L"\n�������µ�ҳ�뷶Χ:");
			getText(rmod->research.page);
			break;

		case 8:
			wprintf(L"ԭ����Ӧ�ü���ӷ�:%lf", rmod->research.GPA_bonus);
			wprintf(L"\n�������µ�Ӧ�ü���ӷ�:");
			wscanf(L"%lf", &rmod->research.GPA_bonus);
			break;

		case 9:
			return ;

		}
	
	}

}
void modifyQuality_clist(List* plist) { // �޸���������Ŀ֮������
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Cnode* chead = ptmp->item.clist;
	Cnode* cmod = searchCnode(chead);
	while (1) {
		showMenu(L"��ѡ��Ҫ�޸ĵľ����񽱵������Ϣ��", 6, L"1.��������", L"2.�ٰ쵥λ", L"3.�����", L"4.��ʱ��", L"5.Ӧ�ü���ӷ�","6.�˳�");
		int option = getNumber(6);
		switch (option) {
		case 1:
			wprintf(L"ԭ���ľ�������:%s", cmod->competition.competition_name);
			wprintf(L"\n�������µľ�������:");
			getText(cmod->competition.competition_name);
			break;

		case 2:
			wprintf(L"ԭ���ľٰ쵥λ:%s", cmod->competition.organizer);
			wprintf(L"\n�������µľٰ쵥λ:");
			getText(cmod->competition.organizer);
			break;

		case 3:
			wprintf(L"ԭ���Ļ����:%s", cmod->competition.category);
			wprintf(L"\n�������µĻ����:");
			getText(cmod->competition.category);
			break;

		case 4:
			wprintf(L"ԭ���Ļ�ʱ��:%s", cmod->competition.date);
			wprintf(L"\n�������µĻ�ʱ��:");
			getText(cmod->competition.date);
			break;

		case 5:
			wprintf(L"ԭ����Ӧ�ü���ӷ�:%lf", cmod->competition.GPA_bonus);
			wprintf(L"\n�������µ�Ӧ�ü���ӷ�:");
			wscanf(L"%lf", &cmod->competition.GPA_bonus);
			break;
		
		case 6:
			return ;

		}

	}

}


void deleteQuality_rlist(List* plist) {	// ɾ����������Ŀ֮���гɹ�
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Rnode* rhead = ptmp->item.rlist;
	Rnode* r_del = searchRnode(rhead);//�ҵ���ɾ���Ŀ��гɹ��ڵ�
	Rnode* rtmp = rhead;
	while (rtmp->rnext != r_del) {
		rtmp = rtmp->rnext;
	}
	rtmp->rnext = r_del->rnext;
	free(r_del);
	wprintf(L"\nɾ���ɹ���");
	Research_num--;
}
void deleteQuality_clist(List* plist) {	// ɾ����������Ŀ֮������
	Node* ptmp = searchStu(plist);//�ҵ����޸�ѧ��
	Cnode* chead = ptmp->item.clist;
	Cnode* c_del = searchCnode(chead);//�ҵ���ɾ���Ŀ��гɹ��ڵ�
	Cnode* ctmp = chead;
	while (ctmp->cnext != c_del) {
		ctmp = ctmp->cnext;
	}
	ctmp->cnext = c_del->cnext;
	free(c_del);
	wprintf(L"\nɾ���ɹ���");
	Competition_num--;
}




