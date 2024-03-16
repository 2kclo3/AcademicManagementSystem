#include "student.h"





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
void showAllStu() ；
	


void showStu(); // 显示单个学生信息（包含其课程成绩）





void showCrsInStu();// 具体显示单个学生的某课程

// 添加学生（不包含课程）
bool addStu(Node* node, List* plist){
	Node* ptmp = *plist;
	node->next = NULL;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	ptmp->next = node;
	return true;
}
	
// 排序总学生链表(按照学号来排序）
void sortStu(List* plist) {
	Node*p,*p0,*r,*r0,*q;
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

// 为某个学生添加某课程及成绩
bool addCrsToStu(List* plist) {
	Node* pmtp= searchStu(plist);//通过搜索函数找到待修改学生

	
}

// 修改学生信息（不修改课程）
bool modifyStu(List* plist) {
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	printf("选择你要修改的学生信息(输入1-5）：\n1.name 2.ID 3.gender 4.grade 5.college 6.major");
	int choice;
	scanf("%d", &choice);
	if (choice > 6 || choice < 1)
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
}



bool modifyCrsInStu(); // 修改某个学生的某课程及成绩


// 删除学生
bool deleteStu(List* plist) {
	Node* ptmp = searchStu(plist);//通过搜索函数找到待修改学生;
	Node* ptmpp = *plist;
	while (ptmpp->next != ptmp)
		ptmpp = ptmpp->next;
	ptmpp->next = ptmp->next;
	return true;
}


bool deleteCrsInStu(); // 删除某个学生的某课程及成绩

// 在总学生链表中通过学号和名字搜索学生
Node* searchStu(List* plist) {
	Node* ptmp = *plist;
	int id;
	getNumber(id); //输入学号
	char name[16];
	getTexe(name);
	while (ptmp->item.data.ID != id || strcmp(ptmp->item.data.name,name) != 0 )//通过姓名和学号来检索
		ptmp = ptmp->next;
	return (ptmp);//返回这个学生信息的节点地址
}
	


Node* searchCrsInStu(); // 在单个学生中搜索其课程