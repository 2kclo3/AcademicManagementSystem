#pragma warning(disable:4996)
#include"quality.h"
//�������⣺1.Ϊÿ��ѧ����r/clist��������ڱ��ڵ� (OK
//			2.searchR/Cnode()������ʵ��  (OK

int Research_num = 0;
int Competition_num = 0;

Node* searchStuInQuality(List phead,wchar_t* str) { // ����������Ŀ������ѧ��
	Node* ptmp = phead->next;//�����˿����ڱ��ڵ�
	while (ptmp!=NULL)
	{
		if (_tcscmp(str, ptmp->item.data.name) == 0)
			break;
		ptmp = ptmp->next;
	}
	if (ptmp == NULL)	return NULL;
	return ptmp;
}

 
bool addQuality_rlist(Node* Stu,wchar_t* paper_name,
	wchar_t * journal_or_conference_name,
	wchar_t* author, 
	wchar_t* date, 
	wchar_t* volume_num, 
	wchar_t* issue_num,
	wchar_t* page,
	double GPA_bonus){
	Rnode* rhead = Stu->item.rlist;
	Rnode* rtmp = rhead->rnext;//������rlist���������ڱ��ڵ�
	while (rtmp->rnext != NULL)
		rtmp = rtmp->rnext;//β�巨
	Rnode* rnew = (Rnode*)malloc(sizeof(Rnode));
	if (rnew == NULL)
		return false;//�ڵ�ռ����ʧ��

	wcscpy(rnew->research.paper_name, paper_name);
	wcscpy(rnew->research.journal_or_conference_name, journal_or_conference_name);
	wcscpy(rnew->research.author, author);
	wcscpy(rnew->research.date, date);
	wcscpy(rnew->research.volume_num, volume_num);
	wcscpy(rnew->research.issue_num, issue_num);
	wcscpy(rnew->research.page, page);
	rnew->research.GPA_bonus = GPA_bonus;

	rnew->rnext = NULL;
	rtmp->rnext = rnew;
	return true;
}

bool addQuality_clist(Node* Stu,
	wchar_t* competition_name,
	wchar_t* organizer, 
	wchar_t* category,
	wchar_t* date,
	double GPA_bonus) {
	Cnode* chead = Stu->item.clist;
	Cnode* ctmp = chead->cnext;//������clist���������ڱ��ڵ�
	while (ctmp->cnext != NULL)
		ctmp = ctmp->cnext;//β�巨
	Cnode* cnew = (Cnode*)malloc(sizeof(Cnode));
	if (cnew == NULL)
		return false;//�ڵ�ռ����ʧ��
	cnew->cnext = NULL;
	
	wcscpy(cnew->competition.competition_name, competition_name);
	wcscpy(cnew->competition.organizer, organizer);
	wcscpy(cnew->competition.category, category);
	wcscpy(cnew->competition.date, date);
	cnew->competition.GPA_bonus = GPA_bonus;

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


void modifyQuality_rlist(Node* Stu) { // �޸���������Ŀ֮���гɹ�
	Rnode* rhead = Stu->item.rlist;
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
void modifyQuality_clist(Node* Stu) { // �޸���������Ŀ֮������
	Cnode* chead = Stu->item.clist;
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


void deleteQuality_rlist(Node* Stu) {	// ɾ����������Ŀ֮���гɹ�
	Rnode* rhead = Stu->item.rlist;
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
void deleteQuality_clist(Node* Stu) {	// ɾ����������Ŀ֮������
	Cnode* chead = Stu->item.clist;
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




