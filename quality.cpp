#pragma warning(disable:4996)

#include"quality.h"



bool ShowAllStu_with_quality(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm) {
	List pStu_Current = StuList->next;
	Rnode* pR_Current;
	Cnode* pC_Current;//����ѧ���������Լ���������������ڱ��ڵ�

	data.clear(); // �������
	data.push_back(vector<wstring>(6, L"")); //����һ��(ÿ��6��)

	//��ʼ����ͷ
	data[0][0] = L"ѧ��";
	data[0][1] = L"����";
	data[0][2] = L"�Ա�";
	data[0][3] = L"�꼶";
	data[0][4] = L"ѧԺ";
	data[0][5] = L"רҵ";


	int row = 1;

	while (pStu_Current != NULL) { //��������
		
		pR_Current = pStu_Current->item.rlist->rnext;
		pC_Current = pStu_Current->item.clist->cnext;

		if (((pR_Current != NULL) || (pC_Current != NULL)) && (wcsstr(std::to_wstring(pStu_Current->item.data.ID).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pStu_Current->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pStu_Current->item.data.grade).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pStu_Current->item.data.college, searchTerm) != NULL
			|| wcsstr(pStu_Current->item.data.major, searchTerm) != NULL
			)) {

			data.push_back(vector<std::wstring>(6, L"")); //����һ��(ÿ��6��)

			//ÿ�е�����
			data[row][0] = std::to_wstring(pStu_Current->item.data.ID); //����תΪ�ַ���
			data[row][1] = pStu_Current->item.data.name;
			data[row][2] = (pStu_Current->item.data.gender) ? L"��" : L"Ů";
			data[row][3] = std::to_wstring(pStu_Current->item.data.grade); //����תΪ�ַ���
			data[row][4] = pStu_Current->item.data.college;
			data[row][5] = pStu_Current->item.data.major;

			row++; // ����+1
		}

		pStu_Current = pStu_Current->next; // ������һ���ڵ�

	}

	return true;

}

bool ShowStu_Research(const Node* Stu, vector<vector<wstring>>& data) {

	Rnode* pR_Current = Stu->item.rlist->rnext;

	data.clear(); // �������
	data.push_back(vector<wstring>(8, L"")); //����һ��(ÿ��8��)

	//��ʼ����ͷ
	data[0][0] = L"��������";
	data[0][1] = L"������ڿ�/��������";
	data[0][2] = L"�������";
	data[0][3] = L"����ʱ��";
	data[0][4] = L"����";
	data[0][5] = L"����";
	data[0][6] = L"ҳ�뷶Χ";
	data[0][7] = L"����ӷ�";

	int row = 1;

	while (pR_Current != NULL) { //��������֧����

		data.push_back(vector<std::wstring>(8, L"")); //����һ��(ÿ��8��)

		//ÿ�е�����
		data[row][0] = pR_Current->research.paper_name;
		data[row][1] = pR_Current->research.journal_or_conference_name;
		data[row][2] = pR_Current->research.author;
		data[row][3] = pR_Current->research.date;
		data[row][4] = pR_Current->research.volume_num;
		data[row][5] = pR_Current->research.issue_num;
		data[row][6] = pR_Current->research.page;
		data[row][7] = to_wstring(pR_Current->research.GPA_bonus);

		row++; // ����+1

		pR_Current = pR_Current->rnext; // ������һ���ڵ�

	}

	return true;

}



Node* searchStu_InQuality(List phead,wchar_t* str) { // ��������������ѧ��(lzy����ר��
	Node* ptmp = phead->next;//�����˿����ڱ��ڵ�
	while (ptmp!=NULL)
	{
		if (wcscmp(str, ptmp->item.data.name) == 0)
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
	
	wcscpy(cnew->competition.competition_name, competition_name);
	wcscpy(cnew->competition.organizer, organizer);
	wcscpy(cnew->competition.category, category);
	wcscpy(cnew->competition.date, date);
	cnew->competition.GPA_bonus = GPA_bonus;

	cnew->cnext = NULL;
	ctmp->cnext = cnew;
	return true;
}

/*void show_Research_menu(const wchar_t* title, Rnode* rhead) {//�����޸ĺ���ȷ�����账��Ŀ�����Ŀ�ڵ�
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
}*/
Rnode* searchRnode(Node* Stu,wchar_t* paper_name) {//�ҳ����޸ĵ���������Ŀ�ڵ�
	Rnode* rhead = Stu->item.rlist;//�����˿����ڱ��ڵ�
	Rnode* rtmp = rhead->rnext;
	while (rtmp != NULL)
	{
		if (wcscmp(paper_name, rtmp->research.paper_name) == 0)
			break;
		rtmp = rtmp->rnext;
	}
	if (rtmp == NULL)	return NULL;
	return rtmp;
}// �ҳ���ѧ�����޸ĵ���������Ŀ�ڵ�
Cnode* searchCnode(Node* Stu,wchar_t* competition_name) {
	Cnode* chead = Stu->item.clist;//�����˿����ڱ��ڵ�
	Cnode* ctmp = chead->cnext;
	while (ctmp != NULL)
	{
		if (wcscmp(competition_name, ctmp->competition.competition_name) == 0)
			break;
		ctmp = ctmp->cnext;
	}
	if (ctmp == NULL)	return NULL;
	return ctmp;
}

bool modifyQuality_rlist(Rnode* rmod,	// �޸���������Ŀ�ڵ�
	wchar_t* paper_name,
	wchar_t* journal_or_conference_name,
	wchar_t* author,
	wchar_t* date,
	wchar_t* volume_num,
	wchar_t* issue_num,
	wchar_t* page,
	double GPA_bonus){ // �޸���������Ŀ֮���гɹ�

	wcscpy(rmod->research.paper_name, paper_name);
	wcscpy(rmod->research.journal_or_conference_name, journal_or_conference_name);
	wcscpy(rmod->research.author, author);
	wcscpy(rmod->research.date, date);
	wcscpy(rmod->research.volume_num, volume_num);
	wcscpy(rmod->research.issue_num, issue_num);
	wcscpy(rmod->research.page, page);
	rmod->research.GPA_bonus = GPA_bonus;
	 
	return true;
}
bool modifyQuality_clist(Cnode* cmod,
	wchar_t* competition_name,
	wchar_t* organizer,
	wchar_t* category,
	wchar_t* date,
	double GPA_bonus) { // �޸���������Ŀ֮������

	wcscpy(cmod->competition.competition_name, competition_name);
	wcscpy(cmod->competition.organizer, organizer);
	wcscpy(cmod->competition.category , category);
	wcscpy(cmod->competition.date, date);
	cmod->competition.GPA_bonus = GPA_bonus;
	
	return true;
}


bool deleteQuality_rlist(Node* Stu, wchar_t* paper_name) {	// ɾ����������Ŀ֮���гɹ�
	Rnode* rhead = Stu->item.rlist;
	
	Rnode* rpre = rhead;
	Rnode* rtmp = rhead->rnext;
	
	while (rtmp != NULL) {
		if (wcscmp(rtmp->research.paper_name, paper_name) == 0) {
			rpre->rnext = rtmp->rnext;
			free(rtmp);
			break;
		}
		else {
			rpre = rtmp;
			rtmp = rtmp->rnext;
		}
	}

	return true;

}
bool deleteQuality_clist(Node* Stu, wchar_t* competition_name) {	// ɾ����������Ŀ֮������
	Cnode* chead = Stu->item.clist;

	Cnode* cpre = chead;
	Cnode* ctmp = chead->cnext;

	while (ctmp != NULL) {
		if (wcscmp(ctmp->competition.competition_name, competition_name) == 0) {
			cpre->cnext = ctmp->cnext;
			free(ctmp);
			break;
		}
		else {
			cpre = ctmp;
			ctmp = ctmp->cnext;
		}
	}

	return true;

}



