#include "student.h"
#include "io.h"


#pragma warning(disable:4996)




//初始化链表
void InitializeList(List* plist) {
	//plist = (List**)malloc(sizeof(Node*));
	//*plist = (List*)malloc(sizeof(Node));
	//if (*plist == NULL) {
	//	printf("内存分配失败！");
	//	exit(EXIT_FAILURE);
	//}
	(*plist)->next = NULL;
}

// 显示所有学生信息（不包含课程）返回一个链表
void showAllStu();
	
void showStu(); // 显示单个学生信息（包含其课程成绩）

void showCrsInStu();// 具体显示单个学生的某课程



//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。已编辑，存在getNumber只能返回int但是成绩等数据为float的问题；


// 排序总学生链表(按照学号来排序）
void sortStu(List* plist) {
	Node* p, * p0, * r, * r0, * q;
	p = p0 = r = r0 = q = NULL;
	p = *plist;
	while (p) {
		r = *plist;
		while (r->item.data.ID < p->item.data.ID && r != p) {
			r0 = r;
			r = r->next;
		}//找位置

		if (r != p) {
			q = p;
			p0->next = p->next;
			p = p0;
			if (r != *plist) {
				r0->next = q;
				q->next = r;
			}
			else {
				q->next = *plist;
				*plist = q;
			}
		}
	}
}

//初始化每个学生的课程链表并添加哨兵节点
bool Initialize_Stu_Crslist(List phead) {
		List Ltmp = phead->next;
		while (Ltmp != NULL) {
			Crsnode* crs_head = (Crsnode*)malloc(sizeof(Crsnode));
			if (crs_head == NULL)
				return false;
			crs_head->crs_next = NULL;
			Ltmp->item.crslist = crs_head;
			Ltmp = Ltmp->next;
		}
		return true;
}

// 添加学生（不包含课程）
bool addStu(List* plist){
	Node* ptmp = *plist;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	Node* pnew = (Node*)malloc(sizeof(Node));//创建新节点
	int choice;
	for (int i = 0; i < 7; i++) {//录入新节点信息
		printf("选择你要录入的学生信息(输入1-5）：\n1.name 2.ID 3.gender 4.grade 5.college 6.major 7.结束录入");
		scanf("%d", &choice);
		if (choice > 7 || choice < 1)
			printf(" 您的选择无效");
		if (choice == 1)
			getText(pnew->item.data.name);
		if (choice == 2)
			getNumber(pnew->item.data.ID);
		if (choice == 3)
			getNumber(pnew->item.data.gender);
		if (choice == 4)
			getNumber(pnew->item.data.grade);
		if (choice == 5)
			getText(pnew->item.data.college);
		if (choice == 6)
			getText(pnew->item.data.major);
		if (choice == 7)
			break;
	}
	ptmp->next = pnew;
	return true;
}
	

// 为某个学生添加某课程及成绩
bool addCrsToStu(List* plist) {
	Node* ptmp= searchStu(plist);//通过搜索函数找到待修改学生
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_tmp = crs_head->crs_next;//课程链表需要有哨兵节点
	while (crs_tmp->crs_next != NULL)
		crs_tmp = crs_tmp->crs_next;
	Crsnode* crs_new = (Crsnode*)malloc(sizeof(Crsnode));//创建新节点
	if (crs_new == NULL)
		return false;
	crs_new->crs_next = NULL;
	int choice;
	for (int i = 0; i < 9; i++) {//录入新节点信息
		printf("选择你要录入的成绩信息(输入1-5）：\n 1.course_id 2.course_name 3.score 4.semester 5.course_nature 6.credit 7.credit 8.结束录入");
		scanf("&d", &choice);
		if (choice > 8 || choice < 1)
			printf(" 您的选择无效");
		if (choice == 1)
			getText(crs_new->score.course_id);
		if (choice == 2)
			getText(crs_new->score.course_name);
		if (choice == 3)
			getNumber(crs_new->score.score);
		if (choice == 4)
			getNumber(crs_new->score.semester);
		if (choice == 5)
			getNumber(crs_new->score.course_nature);
		if (choice == 6)
			getNumber(crs_new->score.credit);
		if (choice == 7)
			getNumber(crs_new->score.grid);
		if (choice == 8)
			break;
	}
	crs_tmp->crs_next = crs_new;//添加新节点
	return true;
}

// 修改学生信息（不修改课程）
bool modifyStu(List* plist){
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	int choice;
	for (int i = 0; i < 7; i++) {
		printf("选择你要录入的学生信息(输入1-5）：\n1.name 2.ID 3.gender 4.grade 5.college 6.major 7.结束录入");
		scanf("%d", &choice);
		if (choice > 7 || choice < 1)
			printf(" 您的选择无效");
		if (choice == 1)
			getText(ptmp->item.data.name);
		if (choice == 2)
			getNumber(ptmp->item.data.ID);
		if (choice == 3)
			getNumber(ptmp->item.data.gender);
		if (choice == 4)
			getNumber(ptmp->item.data.grade);
		if (choice == 5)
			getText(ptmp->item.data.college);
		if (choice == 6)
			getText(ptmp->item.data.major);
		if (choice == 7)
			break;
	}
}


// 修改某个学生的某课程及成绩
bool modifyCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_mod = searchCrsInStu(crs_head); //找到待修改的课程
	//......

}

// 删除学生
bool deleteStu(List* plist) {
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	Node* ptmpp = *plist;
	while (ptmpp->next != ptmp)
		ptmpp = ptmpp->next;
	ptmpp->next = ptmp->next;
	return true;
}


// 删除某个学生的某课程及成绩
bool deleteCrsInStu(List* plist) {
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	Crsnode* crs_head = ptmp->item.crslist;
	Crsnode* crs_del = searchCrsInStu(crs_head);
	Crsnode* crs_tmp = crs_head;//下面是寻找被删除课程节点的前继节点
	while (crs_tmp!=NULL && crs_tmp->crs_next != crs_del) {
		crs_tmp = crs_tmp->crs_next;
	}
	crs_tmp->crs_next = crs_del->crs_next;
	free(crs_del);
	printf("\n删除成功！");
}

// 在总学生链表中通过学号和名字搜索学生
Node* searchStu(List* plist) {
	Node* ptmp = *plist;
	int pid;
	pid=getNumber(99999999); //输入学号
	char pname[16];
	getText(pname);
	while (ptmp->item.data.ID != pid && strcmp(ptmp->item.data.name,pname) != 0 )//通过姓名或学号来检索
		ptmp = ptmp->next;
	return (ptmp);//返回这个学生信息的节点地址
}
	
// 在单个学生中搜索待删除/修改的课程
Crsnode* searchCrsInStu(Crsnode* crs_head) {
	char pcourse_id[10];
	char pcourse_name[100];
	getText(pcourse_id);
	getText(pcourse_name);//输入待查找课程的编号和名称；
	Crsnode* crs_aim = crs_head->crs_next;
	while (strcmp(crs_aim->score.course_id, pcourse_id) != 0 && strcmp(crs_aim->score.course_name, pcourse_name) != 0)//通过课程编号或课程名来检索
		crs_aim = crs_aim->crs_next;
	return crs_aim;
}