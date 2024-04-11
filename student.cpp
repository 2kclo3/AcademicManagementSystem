#include "student.h"


#pragma warning(disable:4996)


// ��ʾ����ѧ����Ϣ���������γ̣�����һ������
bool showAllStu(const List StuList, vector<vector<wstring>>& data, const wchar_t* searchTerm) {
	List pCurrent = StuList->next; //�ӵ�һ�������ݽڵ㿪ʼ
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
	while (pCurrent != NULL) { //��������

		// ����Ƿ���������
		if (wcsstr(std::to_wstring(pCurrent->item.data.ID).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.name, searchTerm) != NULL
			|| wcsstr(std::to_wstring(pCurrent->item.data.grade).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(pCurrent->item.data.college, searchTerm) != NULL
			|| wcsstr(pCurrent->item.data.major, searchTerm) != NULL
			) {

			data.push_back(vector<std::wstring>(6, L"")); //����һ��(ÿ��7��)

			//ÿ�е�����
			data[row][0] = std::to_wstring(pCurrent->item.data.ID); //����תΪ�ַ���
			data[row][1] = pCurrent->item.data.name;
			data[row][2] = (pCurrent->item.data.gender) ? L"��" : L"Ů";
			data[row][3] = std::to_wstring(pCurrent->item.data.grade); //����תΪ�ַ���
			data[row][4] = pCurrent->item.data.college;
			data[row][5] = pCurrent->item.data.major;

			row++; // ����+1
		}

		pCurrent = pCurrent->next; // ������һ���ڵ�

	}

	return true;
}

// ��ʾ����ѧ����Ϣ��������γ̳ɼ���	
void showStu(const Node* stu, vector<vector<wstring>>& data, const wchar_t* searchTerm) {
	Crsnode* crstmp = stu->item.crslist->crs_next;
	data.clear(); // �������
	data.push_back(vector<wstring>(7, L"")); //����һ��(ÿ��7��)

	//��ʼ��
	data[0][0] = L"�γ̺�";
	data[0][1] = L"�γ���";
	data[0][2] = L"�ɼ�";
	data[0][3] = L"ѧ��";
	data[0][4] = L"ѧ��";
	data[0][5] = L"����";
	data[0][6] = L"�γ�����";

	int row = 1;
	while (crstmp != NULL) {
		data.push_back(vector<std::wstring>(7, L"")); //����һ��(ÿ��7��)

		// ����Ƿ���������
		if (wcsstr(crstmp->score.course_id, searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(crstmp->score.course_name,searchTerm) != NULL
			|| wcsstr(std::to_wstring(crstmp->score.score).c_str(), searchTerm) != NULL // ����תΪ�ַ�����תΪwchar_t�����бȽ�
			|| wcsstr(std::to_wstring(crstmp->score.semester).c_str(), searchTerm) != NULL
			|| wcsstr(std::to_wstring(crstmp->score.credit).c_str(), searchTerm) != NULL
			|| wcsstr(std::to_wstring(crstmp->score.grid).c_str(), searchTerm) != NULL
			|| wcsstr(std::to_wstring(crstmp->score.course_nature).c_str(), searchTerm) != NULL
			){
			//ÿ�е�����
			data[row][0] = crstmp->score.course_id;
			data[row][1] = crstmp->score.course_name;
			data[row][2] = std::to_wstring(crstmp->score.score); //����תΪ�ַ���
			data[row][3] = std::to_wstring(crstmp->score.semester); //����תΪ�ַ���
			data[row][4] = std::to_wstring(crstmp->score.credit);//����תΪ�ַ���
			data[row][5] = std::to_wstring(crstmp->score.grid);//����תΪ�ַ���
			data[row][6] = std::to_wstring(crstmp->score.course_nature); //����תΪ�ַ���

			row++; // ����+1
		}
		crstmp = crstmp->crs_next;
	}


}





// ������ѧ������(����ѧ��������
void sortStu(List* plist) {
	Node* p, * p0, * r, * r0, * q;
	p = p0 = r = r0 = q = NULL;
	p = *plist;
	while (p) {
		r = *plist;
		while (r->item.data.ID < p->item.data.ID && r != p) {
			r0 = r;
			r = r->next;
		}//��λ��

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
		p0 = p;
		p = p->next;
	}
}



// ���ѧ�����������γ̣�
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
	wcscpy(pnew->item.data.original_college, pcollege);
	wcscpy(pnew->item.data.original_major, pmajor);
	wcscpy(pnew->item.data.password, to_wstring(pnew->item.data.ID).c_str());


	ptmp->next = pnew;
	return true;
}

 //Ϊĳ��ѧ�����ĳ�γ̼��ɼ�
bool addCrsToStu(Node* chastu, wchar_t* pcourse_id, wchar_t* pcourse_name, double pscore, int psemester, int pcourse_nature, double pcredit, double pgrid) {
	Crsnode* crs_tmp = chastu->item.crslist;//�γ�����ͷ�ڵ�
	while (crs_tmp->crs_next != NULL)
		crs_tmp = crs_tmp->crs_next;
	Crsnode* crs_new = (Crsnode*)malloc(sizeof(Crsnode));//�����½ڵ�
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

	crs_tmp->crs_next = crs_new;//����½ڵ�
	return true;
}


 //�޸�ѧ����Ϣ�����޸Ŀγ̣�
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

// �޸�ĳ��ѧ����ĳ�γ̼��ɼ�
bool modifyCrsInStu(Crsnode* chacrs, wchar_t* pcourse_id,wchar_t* pcourse_name,double pscore, int psemester, int pcourse_nature, double pcredit, double pgrid) {
	wcscpy(chacrs->score.course_id, pcourse_id);
	wcscpy(chacrs->score.course_name, pcourse_name);
	chacrs->score.score = pscore;
	chacrs->score.semester = psemester;
	chacrs->score.course_nature = pcourse_nature;
	chacrs->score.credit = pcredit;
	chacrs->score.grid = pgrid;

	return true; //�������лᱨ��û�з���ֵ
}

// ɾ��ѧ��
bool deleteStu(List* plist, Node* delstu) {
	Node* ptmp = *plist;
	while (ptmp->next != delstu)
		ptmp = ptmp->next;
	ptmp->next = delstu->next;
	free(delstu);
	return true;
}

// ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�
bool deleteCrsInStu(Node* delstu, Crsnode* delcrs) {
	Node* ptmp = delstu;//ѧ���ڵ�
	Crsnode* crs_tmp = ptmp->item.crslist;//�γ�ͷ�ڵ�
	while (crs_tmp!=NULL && crs_tmp->crs_next != delcrs) {//Ѱ�ұ�ɾ���γ̽ڵ��ǰ�ڵ�
		crs_tmp = crs_tmp->crs_next;
	}
	crs_tmp->crs_next = delcrs->crs_next;
	free(delcrs);
	return true;
}


// ����ѧ��������ͨ��ѧ�ź���������ѧ�� 
Node* searchStu(List* plist, wchar_t* pname, int pID) {
	Node* ptmp = *plist;
	while (ptmp->item.data.ID != pID || _tcscmp(ptmp->item.data.name, pname) != 0 )//ͨ��������ѧ��������
		ptmp = ptmp->next;
	return (ptmp);//�������ѧ����Ϣ�Ľڵ��ַ
}
	
// �ڵ���ѧ���������Ŀγ�
Crsnode* searchCrsInStu(Node* stu, wchar_t* pcourse_id, wchar_t* pcourse_name) {
	Crsnode* crstmp = stu->item.crslist->crs_next;
	while (_tcscmp(crstmp->score.course_id, pcourse_id) != 0 || _tcscmp(crstmp->score.course_name, pcourse_name) != 0)//ͨ���γ̱��he�γ���������
		crstmp = crstmp->crs_next;
	return crstmp;
}

//��ʼ��ÿ��ѧ���Ŀγ���������ڱ��ڵ�
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

