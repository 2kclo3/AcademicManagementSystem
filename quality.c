#pragma warning(disable:4996)
#include"quality.h"
#include"student.h"
#include"io.h"
#include"ui.h"
#include<stdbool.h>
//遗留问题：1.为每个学生的r/clist链表加入哨兵节点 (OK
//			2.searchR/Cnode()函数的实现  (OK

int Research_num = 0;
int Competition_num = 0;

Node* searchStuInQuality(List phead) { // 在素质类项目中搜索学生
	printf("请输入学生姓名\n");
	char str[30];
	getText(str);
	Node* ptmp = phead->next;//别忘了考虑哨兵节点
	while (ptmp!=NULL)
	{
		if (strcmp(str, ptmp->item.data.name) == 0)
			break;
		ptmp = ptmp->next;
	}
	if (ptmp==NULL){
		printf("查无此人\n");
		return NULL;
	}
	return ptmp;
}


void Initialize_Quality_List(List phead){// 初始化素质类项目的链表（为每个学生的r/clist链表加入哨兵节点）
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
	Rnode* rtmp = rhead->rnext;//素质类rlist链表亦有哨兵节点
	while (rtmp->rnext != NULL)
		rtmp = rtmp->rnext;//尾插法
	Rnode* rnew = (Rnode*)malloc(sizeof(Rnode));
	if (rnew == NULL)
		return false;//节点空间分配失败
	rnew->rnext = NULL;
	printf("请输入你所需要申请添加的科研成果的相关信息:\n ");
	
	printf("1.论文名称（必填）：\n");
	getText(rnew->research.paper_name);
	
	printf("2.期刊/会议名称（必填）：\n");
	getText(rnew->research.journal_or_conference_name);
	
	printf("3.作者情况（仅需本人情况即可 必填）：\n");
	getText(rnew->research.author);
	
	printf("4.发表时间（年月 必填）：\n");
	getText(rnew->research.date);
	
	printf("5.卷数（若无可不填）：\n");
	getText(rnew->research.volume_num);
	
	printf("6.刊号（若无可不填）：\n");
	getText(rnew->research.issue_num);
	
	printf("7.页码范围（必填）：\n");
	getText(rnew->research.page);

	printf("8.应得绩点加分（必填）：\n");
	scanf("%lf", &rnew->research.GPA_bonus);
	
	rtmp->rnext = rnew;
	return true;
}
bool addQuality_clist(List* plist) {
	Node* ptmp = searchStu(plist);
	Cnode* chead = ptmp->item.rlist;
	Cnode* ctmp = chead->cnext;//素质类clist链表亦有哨兵节点
	while (ctmp->cnext != NULL)
		ctmp = ctmp->cnext;//尾插法
	Cnode* cnew = (Cnode*)malloc(sizeof(Cnode));
	if (cnew == NULL)
		return false;//节点空间分配失败
	cnew->cnext = NULL;
	printf("请输入你所需要申请添加的竞赛类获奖的相关信息:\n ");

	printf("1.竞赛名称（必填）：\n");
	getText(cnew->competition.competition_name);

	printf("2.举办单位（必填）：\n");
	getText(cnew->competition.organizer);

	printf("3.获奖类别（必填）：\n");
	getText(cnew->competition.category);

	printf("4.获奖时间（年月 必填）：\n");
	getText(cnew->competition.date);

	printf("8.应得绩点加分（必填）：\n");
	scanf("%lf", &cnew->competition.GPA_bonus);

	ctmp->cnext = cnew;
	return true;
}


void show_Research_menu(char* title ,Rnode* rhead) {//方便修改函数确认所需处理的科研项目节点
		printf("%s\n\n", title);
		Rnode* rtmp = rhead->rnext;
		while (rtmp != NULL) {
			Research_num++;
			printf("%2d:%s\n", Research_num, rtmp->research.paper_name);
			rtmp = rtmp->rnext;
		}
}
void show_Competition_menu(char* title, Cnode* chead) {//方便修改函数确认所需处理的竞赛获奖节点
	printf("%s\n\n", title);
	Cnode* ctmp = chead->cnext;
	while (ctmp != NULL) {
		Competition_num++;
		printf("%2d:%s\n", Competition_num, ctmp->competition.competition_name);
		ctmp = ctmp->cnext;
	}
}


Rnode* searchRnode(Rnode* rhead) {//找出待修改的素质类项目节点
	show_Research_menu("确认所需修改/删除的科研成果", rhead);
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
	show_Competition_menu("确认所需修改/删除的竞赛获奖", chead);
	int option = getNumber(Competition_num);
	int count = 1;
	Cnode* ctmp = chead->cnext;
	while (count < option) {
		ctmp = ctmp->cnext;
		count++;
	}
	return ctmp;
}


void modifyQuality_rlist(List* plist) { // 修改素质类项目之科研成果
	Node* ptmp = searchStu(plist);//找到待修改学生
	Rnode* rhead = ptmp->item.rlist;
	Rnode* rmod = searchRnode(rhead);//找到待修改的科研成果节点
	while (1) {
		showMenu("请选择要修改的科研成果的相关信息：", 9, "1.论文名称", "2.期刊/会议名称", "3.作者情况", "4.发表时间", "5.卷数", "6.刊号", "7.页码范围", "8.应得绩点加分","9.退出");
		int option = getNumber(9);
		switch (option) {
		case 1:
			printf("原来的的论文名称:%s", rmod->research.paper_name);
			printf("\n请输入新的论文名称:");
			getText(rmod->research.paper_name);
			break;

		case 2:
			printf("原来的期刊/会议名称:%s", rmod->research.journal_or_conference_name);
			printf("\n请输入新的期刊/会议名称:");
			getText(rmod->research.journal_or_conference_name);
			break;

		case 3:
			printf("原来的作者情况:%s", rmod->research.author);
			printf("\n请输入新的作者情况:");
			getText(rmod->research.author);
			break;

		case 4:
			printf("原来的发表时间:%s", rmod->research.date);
			printf("\n请输入新的发表时间:");
			getText(rmod->research.date);
			break;

		case 5:
			printf("原来的卷数:%s", rmod->research.volume_num);
			printf("\n请输入新的卷数:");
			getText(rmod->research.volume_num);
			break;

		case 6:
			printf("原来的刊号:%s", rmod->research.issue_num);
			printf("\n请输入新的刊号:");
			getText(rmod->research.issue_num);
			break;

		case 7:
			printf("原来的页码范围:%s", rmod->research.page);
			printf("\n请输入新的页码范围:");
			getText(rmod->research.page);
			break;

		case 8:
			printf("原来的应得绩点加分:%lf", rmod->research.GPA_bonus);
			printf("\n请输入新的应得绩点加分:");
			scanf("%lf", &rmod->research.GPA_bonus);
			break;

		case 9:
			return 0;

		}
	
	}

}
void modifyQuality_clist(List* plist) { // 修改素质类项目之竞赛获奖
	Node* ptmp = searchStu(plist);//找到待修改学生
	Cnode* chead = ptmp->item.clist;
	Cnode* cmod = searchCnode(chead);
	while (1) {
		showMenu("请选择要修改的竞赛获奖的相关信息：", 6, "1.竞赛名称", "2.举办单位", "3.获奖类别", "4.获奖时间", "5.应得绩点加分","6.退出");
		int option = getNumber(6);
		switch (option) {
		case 1:
			printf("原来的竞赛名称:%s", cmod->competition.competition_name);
			printf("\n请输入新的竞赛名称:");
			getText(cmod->competition.competition_name);
			break;

		case 2:
			printf("原来的举办单位:%s", cmod->competition.organizer);
			printf("\n请输入新的举办单位:");
			getText(cmod->competition.organizer);
			break;

		case 3:
			printf("原来的获奖类别:%s", cmod->competition.category);
			printf("\n请输入新的获奖类别:");
			getText(cmod->competition.category);
			break;

		case 4:
			printf("原来的获奖时间:%s", cmod->competition.date);
			printf("\n请输入新的获奖时间:");
			getText(cmod->competition.date);
			break;

		case 5:
			printf("原来的应得绩点加分:%lf", cmod->competition.GPA_bonus);
			printf("\n请输入新的应得绩点加分:");
			scanf("%lf", &cmod->competition.GPA_bonus);
			break;
		
		case 6:
			return 0;

		}

	}

}


void deleteQuality_rlist(List* plist) {	// 删除素质类项目之科研成果
	Node* ptmp = searchStu(plist);//找到待修改学生
	Rnode* rhead = ptmp->item.rlist;
	Rnode* r_del = searchRnode(rhead);//找到待删除的科研成果节点
	Rnode* rtmp = rhead;
	while (rtmp->rnext != r_del) {
		rtmp = rtmp->rnext;
	}
	rtmp->rnext = r_del->rnext;
	free(r_del);
	printf("\n删除成功！");
	Research_num--;
}
void deleteQuality_clist(List* plist) {	// 删除素质类项目之竞赛获奖
	Node* ptmp = searchStu(plist);//找到待修改学生
	Cnode* chead = ptmp->item.clist;
	Cnode* c_del = searchCnode(chead);//找到待删除的科研成果节点
	Cnode* ctmp = chead;
	while (ctmp->cnext != c_del) {
		ctmp = ctmp->cnext;
	}
	ctmp->cnext = c_del->cnext;
	free(c_del);
	printf("\n删除成功！");
	Competition_num--;
}




