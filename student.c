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
void showAllStu();
	


void showStu(); // 显示单个学生信息（包含其课程成绩）


void showCrsInStu();// 具体显示单个学生的某课程

// 添加学生（不包含课程）
bool addStu(Node* node, List* plist) {
	Node* ptmp = *plist;
	node->next = NULL;
	while (ptmp->next != NULL)
		ptmp = ptmp->next;
	ptmp->next = node;
	return true;
}
	


bool addCrsToStu();// 为某个学生添加某课程及成绩


void sortStu();// 排序总学生链表


bool modifyStu();// 修改学生信息（不修改课程）


bool modifyCrsInStu(); // 修改某个学生的某课程及成绩

// 删除学生
bool deleteStu(List* plist, Node* node) {
	Node* ptmp = *plist;
	while (ptmp->next != node)
		ptmp = ptmp->next;
	ptmp->next = node->next;
	free(node);
	return true;
}


bool deleteCrsInStu(); // 删除某个学生的某课程及成绩


Node*  searchStu(); // 在总学生链表中搜索学生


Node* searchCrsInStu(); // 在单个学生中搜索其课程