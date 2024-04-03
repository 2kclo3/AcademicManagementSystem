#include "student.h"


#pragma warning(disable:4996)


// 显示所有学生信息（不包含课程）返回一个链表
void showAllStu();
	
void showStu(); // 显示单个学生信息（包含其课程成绩）

void showCrsInStu();// 具体显示单个学生的某课程



//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。已编辑，存在getNumber只能返回int但是成绩等数据为float的问题；


// 排序总学生链表(按照学号来排序）
/*void sortStu(List* plist) {
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
*/

//初始化每个学生的课程链表并添加哨兵节点
/*bool Initialize_Stu_Crslist(List phead) {
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
*/

// 添加学生（不包含课程）
bool addStu(List* plist,wchar_t* pname, int pID, int pgender, int pgrade, wchar_t* pcollege, wchar_t* pmajor) {
	Node* ptmp = *plist;
	while (ptmp->next != NULL) {
		if (ptmp->item.data.ID == pID)
			return false;
		ptmp = ptmp->next;
	}

	Node* pnew = (Node*)malloc(sizeof(Node));
	pnew->next = NULL;
	pnew->item.crslist = (Crsnode*)malloc(sizeof(Crsnode));
	pnew->item.crslist->crs_next = NULL;
	pnew->item.rlist= (Rnode*)malloc(sizeof(Rnode));
	pnew->item.rlist->rnext = NULL;
	pnew->item.clist = (Cnode*)malloc(sizeof(Cnode));
	pnew->item.clist->cnext = NULL;

	wcscpy(pnew->item.data.name, pname);
	pnew->item.data.ID = pID;
	pnew->item.data.gender = pgender;
	pnew->item.data.grade = pgrade;
	wcscpy(pnew->item.data.college, pcollege);
	wcscpy(pnew->item.data.major, pmajor);

	ptmp->next = pnew;
	return true;
}

 //为某个学生添加某课程及成绩
bool addCrsToStu(Node* chastu, wchar_t* pcourse_id, wchar_t* pcourse_name, double pscore, int psemester, int pcourse_nature, double pcredit, double pgrid) {
	Crsnode* crs_tmp = chastu->item.crslist;//课程链表头节点
	while (crs_tmp->crs_next != NULL)
		crs_tmp = crs_tmp->crs_next;
	Crsnode* crs_new = (Crsnode*)malloc(sizeof(Crsnode));//创建新节点
	if (crs_new == NULL)
		return false;
	crs_new->crs_next = NULL;

	wcscpy(crs_new->score.course_id, pcourse_id);
	wcscpy(crs_new->score.course_name, pcourse_name);
	crs_new->score.score = pscore;
	crs_new->score.semester = psemester;
	crs_new->score.course_nature = pcourse_nature;
	crs_new->score.credit = pcredit;
	crs_new->score.grid = pgrid;

	crs_tmp->crs_next = crs_new;//添加新节点
	return true;
}


 //修改学生信息（不修改课程）
bool modifyStu(List* plist , Node* chastu ,wchar_t* pname ,int pID ,int pgender,int pgrade,wchar_t* pcollege,wchar_t* pmajor) {
	Node* ptmp = *plist;
	while (ptmp != chastu)
		ptmp = ptmp->next;

	wcscpy(ptmp->item.data.name,pname);
	ptmp->item.data.ID = pID;
	ptmp->item.data.gender = pgender;
	ptmp->item.data.grade = pgrade;
	wcscpy(ptmp->item.data.college,pcollege);
	wcscpy(ptmp->item.data.major, pmajor);
	return true;
}

// 修改某个学生的某课程及成绩
bool modifyCrsInStu(Crsnode* chacrs, wchar_t* pcourse_id,wchar_t* pcourse_name,double pscore, int psemester, int pcourse_nature, double pcredit, double pgrid) {
	wcscpy(chacrs->score.course_id, pcourse_id);
	wcscpy(chacrs->score.course_name, pcourse_name);
	chacrs->score.score = pscore;
	chacrs->score.semester = psemester;
	chacrs->score.course_nature = pcourse_nature;
	chacrs->score.credit = pcredit;
	chacrs->score.grid = pgrid;

	return true; //不加这行会报错没有返回值
}

// 删除学生
bool deleteStu(List* plist, Node* delstu) {
	Node* ptmp = *plist;
	while (ptmp->next != delstu)
		ptmp = ptmp->next;
	ptmp->next = delstu->next;
	free(delstu);
	return true;
}

// 删除某个学生的某课程及成绩
bool deleteCrsInStu(Node* delstu, Crsnode* delcrs) {
	Node* ptmp = delstu;//学生节点
	Crsnode* crs_tmp = ptmp->item.crslist;//课程头节点
	while (crs_tmp!=NULL && crs_tmp->crs_next != delcrs) {//寻找被删除课程节点的前节点
		crs_tmp = crs_tmp->crs_next;
	}
	crs_tmp->crs_next = delcrs->crs_next;
	free(delcrs);
	return true;
}


// 在总学生链表中通过学号和名字搜索学生 
Node* searchStu(List* plist, wchar_t* pname, int pID) {
	Node* ptmp = *plist;
	while (ptmp->item.data.ID != pID || _tcscmp(ptmp->item.data.name, pname) != 0 )//通过姓名或学号来检索
		ptmp = ptmp->next;
	return (ptmp);//返回这个学生信息的节点地址
}
	
// 在单个学生中搜索的课程
Crsnode* searchCrsInStu(Node* stu, wchar_t* pcourse_id, wchar_t* pcourse_name) {
	Crsnode* crstmp = stu->item.crslist->crs_next;
	while (_tcscmp(crstmp->score.course_id, pcourse_id) != 0 || _tcscmp(crstmp->score.course_name, pcourse_name) != 0)//通过课程编号he课程名来检索
		crstmp = crstmp->crs_next;
	return crstmp;
}
