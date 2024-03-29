#pragma warning(disable:4996)
#include"quality.h"
//遗留问题：1.为每个学生的r/clist链表加入哨兵节点 (OK
//			2.searchR/Cnode()函数的实现  (OK

int Research_num = 0;
int Competition_num = 0;

Node* searchStuInQuality(List phead,wchar_t* str) { // 在素质类项目中搜索学生
	Node* ptmp = phead->next;//别忘了考虑哨兵节点
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
	Rnode* rtmp = rhead->rnext;//素质类rlist链表亦有哨兵节点
	while (rtmp->rnext != NULL)
		rtmp = rtmp->rnext;//尾插法
	Rnode* rnew = (Rnode*)malloc(sizeof(Rnode));
	if (rnew == NULL)
		return false;//节点空间分配失败

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
	Cnode* ctmp = chead->cnext;//素质类clist链表亦有哨兵节点
	while (ctmp->cnext != NULL)
		ctmp = ctmp->cnext;//尾插法
	Cnode* cnew = (Cnode*)malloc(sizeof(Cnode));
	if (cnew == NULL)
		return false;//节点空间分配失败
	cnew->cnext = NULL;
	
	wcscpy(cnew->competition.competition_name, competition_name);
	wcscpy(cnew->competition.organizer, organizer);
	wcscpy(cnew->competition.category, category);
	wcscpy(cnew->competition.date, date);
	cnew->competition.GPA_bonus = GPA_bonus;

	ctmp->cnext = cnew;
	return true;
}


void show_Research_menu(const wchar_t* title ,Rnode* rhead) {//方便修改函数确认所需处理的科研项目节点
		wprintf(L"%s\n\n", title);
		Rnode* rtmp = rhead->rnext;
		while (rtmp != NULL) {
			Research_num++;
			wprintf(L"%2d:%s\n", Research_num, rtmp->research.paper_name);
			rtmp = rtmp->rnext;
		}
}
void show_Competition_menu(const wchar_t* title, Cnode* chead) {//方便修改函数确认所需处理的竞赛获奖节点
	wprintf(L"%s\n\n", title);
	Cnode* ctmp = chead->cnext;
	while (ctmp != NULL) {
		Competition_num++;
		wprintf(L"%2d:%s\n", Competition_num, ctmp->competition.competition_name);
		ctmp = ctmp->cnext;
	}
}


Rnode* searchRnode(Rnode* rhead) {//找出待修改的素质类项目节点
	show_Research_menu(L"确认所需修改/删除的科研成果", rhead);
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
	show_Competition_menu(L"确认所需修改/删除的竞赛获奖", chead);
	int option = getNumber(Competition_num);
	int count = 1;
	Cnode* ctmp = chead->cnext;
	while (count < option) {
		ctmp = ctmp->cnext;
		count++;
	}
	return ctmp;
}


void modifyQuality_rlist(Node* Stu) { // 修改素质类项目之科研成果
	Rnode* rhead = Stu->item.rlist;
	Rnode* rmod = searchRnode(rhead);//找到待修改的科研成果节点
	while (1) {
		showMenu(L"请选择要修改的科研成果的相关信息：", 9, L"1.论文名称", L"2.期刊/会议名称", L"3.作者情况", L"4.发表时间", L"5.卷数", L"6.刊号", L"7.页码范围", L"8.应得绩点加分","9.退出");
		int option = getNumber(9);
		switch (option) {
		case 1:
			wprintf(L"原来的的论文名称:%s", rmod->research.paper_name);
			wprintf(L"\n请输入新的论文名称:");
			getText(rmod->research.paper_name);
			break;

		case 2:
			wprintf(L"原来的期刊/会议名称:%s", rmod->research.journal_or_conference_name);
			wprintf(L"\n请输入新的期刊/会议名称:");
			getText(rmod->research.journal_or_conference_name);
			break;

		case 3:
			wprintf(L"原来的作者情况:%s", rmod->research.author);
			wprintf(L"\n请输入新的作者情况:");
			getText(rmod->research.author);
			break;

		case 4:
			wprintf(L"原来的发表时间:%s", rmod->research.date);
			wprintf(L"\n请输入新的发表时间:");
			getText(rmod->research.date);
			break;

		case 5:
			wprintf(L"原来的卷数:%s", rmod->research.volume_num);
			wprintf(L"\n请输入新的卷数:");
			getText(rmod->research.volume_num);
			break;

		case 6:
			wprintf(L"原来的刊号:%s", rmod->research.issue_num);
			wprintf(L"\n请输入新的刊号:");
			getText(rmod->research.issue_num);
			break;

		case 7:
			wprintf(L"原来的页码范围:%s", rmod->research.page);
			wprintf(L"\n请输入新的页码范围:");
			getText(rmod->research.page);
			break;

		case 8:
			wprintf(L"原来的应得绩点加分:%lf", rmod->research.GPA_bonus);
			wprintf(L"\n请输入新的应得绩点加分:");
			wscanf(L"%lf", &rmod->research.GPA_bonus);
			break;

		case 9:
			return ;

		}
	
	}

}
void modifyQuality_clist(Node* Stu) { // 修改素质类项目之竞赛获奖
	Cnode* chead = Stu->item.clist;
	Cnode* cmod = searchCnode(chead);
	while (1) {
		showMenu(L"请选择要修改的竞赛获奖的相关信息：", 6, L"1.竞赛名称", L"2.举办单位", L"3.获奖类别", L"4.获奖时间", L"5.应得绩点加分","6.退出");
		int option = getNumber(6);
		switch (option) {
		case 1:
			wprintf(L"原来的竞赛名称:%s", cmod->competition.competition_name);
			wprintf(L"\n请输入新的竞赛名称:");
			getText(cmod->competition.competition_name);
			break;

		case 2:
			wprintf(L"原来的举办单位:%s", cmod->competition.organizer);
			wprintf(L"\n请输入新的举办单位:");
			getText(cmod->competition.organizer);
			break;

		case 3:
			wprintf(L"原来的获奖类别:%s", cmod->competition.category);
			wprintf(L"\n请输入新的获奖类别:");
			getText(cmod->competition.category);
			break;

		case 4:
			wprintf(L"原来的获奖时间:%s", cmod->competition.date);
			wprintf(L"\n请输入新的获奖时间:");
			getText(cmod->competition.date);
			break;

		case 5:
			wprintf(L"原来的应得绩点加分:%lf", cmod->competition.GPA_bonus);
			wprintf(L"\n请输入新的应得绩点加分:");
			wscanf(L"%lf", &cmod->competition.GPA_bonus);
			break;
		
		case 6:
			return ;

		}

	}

}


void deleteQuality_rlist(Node* Stu) {	// 删除素质类项目之科研成果
	Rnode* rhead = Stu->item.rlist;
	Rnode* r_del = searchRnode(rhead);//找到待删除的科研成果节点
	Rnode* rtmp = rhead;
	while (rtmp->rnext != r_del) {
		rtmp = rtmp->rnext;
	}
	rtmp->rnext = r_del->rnext;
	free(r_del);
	wprintf(L"\n删除成功！");
	Research_num--;
}
void deleteQuality_clist(Node* Stu) {	// 删除素质类项目之竞赛获奖
	Cnode* chead = Stu->item.clist;
	Cnode* c_del = searchCnode(chead);//找到待删除的科研成果节点
	Cnode* ctmp = chead;
	while (ctmp->cnext != c_del) {
		ctmp = ctmp->cnext;
	}
	ctmp->cnext = c_del->cnext;
	free(c_del);
	wprintf(L"\n删除成功！");
	Competition_num--;
}




