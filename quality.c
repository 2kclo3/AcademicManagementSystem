#include"quality.h"
#include"student.h"
#include"io.h"
#include<stdbool.h>

Node* searchStuInQuality(List phead) { // ����������Ŀ������ѧ��
	printf("������ѧ������\n");
	char str[30];
	getText(str);
	List ptmp = phead->next;//�����˿����ڱ��ڵ�
	while (ptmp!=NULL)
	{
		if (strcmp(str, ptmp->item.data.name) == 0)
			break;
		ptmp = ptmp->next;
	}
	if (ptmp==NULL){
		printf("���޴���\n");
		return NULL;
	}
	return ptmp;
}

bool addQuality(); // �����������Ŀ


bool modifyQuality(); // �޸���������Ŀ


bool deleteQuality(); // ɾ����������Ŀ


