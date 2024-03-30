#pragma warning(disable:4996)
#include"quality.h"
//遗留问题：1.为每个学生的r/clist链表加入哨兵节点 (OK
//			2.searchR/Cnode()函数的实现  (OK

int Research_num = 0;
int Competition_num = 0;

Node* searchStu_InQuality(List phead,wchar_t* str) { // 在总链表中搜索学生(lzy调试专用
	Node* ptmp = phead->next;//别忘了考虑哨兵节点
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
	
	wcscpy(cnew->competition.competition_name, competition_name);
	wcscpy(cnew->competition.organizer, organizer);
	wcscpy(cnew->competition.category, category);
	wcscpy(cnew->competition.date, date);
	cnew->competition.GPA_bonus = GPA_bonus;

	cnew->cnext = NULL;
	ctmp->cnext = cnew;
	return true;
}

/*void show_Research_menu(const wchar_t* title, Rnode* rhead) {//方便修改函数确认所需处理的科研项目节点
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
}*/
Rnode* searchRnode(Node* Stu,wchar_t* paper_name) {//找出待修改的素质类项目节点
	Rnode* rhead = Stu->item.rlist;//别忘了考虑哨兵节点
	Rnode* rtmp = rhead->rnext;
	while (rtmp != NULL)
	{
		if (wcscmp(paper_name, rtmp->research.paper_name) == 0)
			break;
		rtmp = rtmp->rnext;
	}
	if (rtmp == NULL)	return NULL;
	return rtmp;
}// 找出此学生待修改的素质类项目节点
Cnode* searchCnode(Node* Stu,wchar_t* competition_name) {
	Cnode* chead = Stu->item.clist;//别忘了考虑哨兵节点
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

bool modifyQuality_rlist(Rnode* rmod,	// 添加素质类项目
	wchar_t* paper_name,
	wchar_t* journal_or_conference_name,
	wchar_t* author,
	wchar_t* date,
	wchar_t* volume_num,
	wchar_t* issue_num,
	wchar_t* page,
	double GPA_bonus){ // 修改素质类项目之科研成果

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
	double GPA_bonus) { // 修改素质类项目之竞赛获奖

	wcscpy(cmod->competition.competition_name, competition_name);
	wcscpy(cmod->competition.organizer, organizer);
	wcscpy(cmod->competition.category , category);
	wcscpy(cmod->competition.date, date);
	cmod->competition.GPA_bonus = GPA_bonus;
	
	return true;
}


bool deleteQuality_rlist(Node* Stu, wchar_t* paper_name) {	// 删除素质类项目之科研成果
	Rnode* rhead = Stu->item.rlist;
	
	Rnode* rpre = rhead;
	Rnode* rtmp = rhead->rnext;
	
	while (rtmp != NULL) {
		if (wcscmp(rtmp->research.paper_name, paper_name) == 0) {
			rpre->rnext = rtmp->rnext;
			free(rtmp);
		}
		else {
			rpre = rtmp;
			rtmp = rtmp->rnext;
		}
	}

	return true;

}
bool deleteQuality_clist(Node* Stu, wchar_t* competition_name) {	// 删除素质类项目之竞赛获奖
	Cnode* chead = Stu->item.clist;

	Cnode* cpre = chead;
	Cnode* ctmp = chead->cnext;

	while (ctmp != NULL) {
		if (wcscmp(ctmp->competition.competition_name, competition_name) == 0) {
			cpre->cnext = ctmp->cnext;
			free(ctmp);
		}
		else {
			cpre = ctmp;
			ctmp = ctmp->cnext;
		}
	}

	return true;

}



