#include"quality.h"
#include"student.h"
#include"io.h"
#include<stdbool.h>

Node* searchStuInQuality(List phead) { // 在素质类项目中搜索学生
	printf("请输入学生姓名\n");
	char str[30];
	getText(str);
	List ptmp = phead->next;//别忘了考虑哨兵节点
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

bool addQuality(); // 添加素质类项目


bool modifyQuality(); // 修改素质类项目


bool deleteQuality(); // 删除素质类项目


