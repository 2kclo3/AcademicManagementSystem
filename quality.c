#include"quality.h"
#include"student.h"
#include"io.h"
#include"ui.h"
#include<stdbool.h>
//遗留问题：1.为每个学生的r/clist链表加入哨兵节点
//			2.searchR/Cnode()函数的实现

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
	
	printf("1.论文名称（必填）：");
	getText(rnew->research.paper_name);
	
	printf("2.期刊/会议名称（必填）：");
	getText(rnew->research.journal_or_conference_name);
	
	printf("3.作者情况（仅需本人情况即可 必填）：");
	getText(rnew->research.author);
	
	printf("4.发表时间（年月 必填）：");
	getText(rnew->research.date);
	
	printf("5.卷数（若无可不填）：");
	getText(rnew->research.volume_num);
	
	printf("6.刊号（若无可不填）：");
	getText(rnew->research.issue_num);
	
	printf("7.页码范围（必填）：");
	getText(rnew->research.page);

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

	printf("1.竞赛名称（必填）：");
	getText(cnew->competition.competition_name);

	printf("2.举办单位（必填）：");
	getText(cnew->competition.organizer);

	printf("3.获奖类别（必填）：");
	getText(cnew->competition.category);

	printf("4.获奖时间（年月 必填）：");
	getText(cnew->competition.date);

	ctmp->cnext = cnew;
	return true;
}



void modifyQuality_rlist(List* plist) { // 修改素质类项目之科研成果
	Node* ptmp = searchStu(plist);//找到待修改学生
	Rnode* rhead = ptmp->item.rlist;
	Rnode rmod = searchRnode(rhead);
	while (1) {
		showMenu("请选择要修改的科研成果的相关信息：", 8, "1.论文名称", "2.期刊/会议名称", "3.作者情况", "4.发表时间", "5.卷数", "6.刊号", "7.页码范围", "8.退出");
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



void modifyQuality_clist(List* plist) { // 修改素质类项目之竞赛获奖
	Node* ptmp = searchStu(plist);//找到待修改学生
	Cnode* chead = ptmp->item.clist;
	Cnode cmod = searchCnode(chead);
	while (1) {
		showMenu("请选择要修改的竞赛获奖的相关信息：", 5, "1.竞赛名称", "2.举办单位", "3.获奖类别", "4.获奖时间", "5.退出");
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


bool deleteQuality(); // 删除素质类项目


