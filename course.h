#pragma once

#ifndef _COURSE_H_
#define _COURSE_H_

#include <stdio.h>

void showAllCrs(); // ��ʾ���пγ̣�������ѧ���ɼ���


void showCrs(); // ��ʾ�����γ���Ϣ�������ÿγ�����ѧ���ĳɼ���


void showStuInCrs(); // ������ʾ�����γ̵�ĳѧ��


bool addCrs(); // ��ӿγ̣��������ɼ���


bool addStuToCrs(); // Ϊĳ�γ����ĳѧ���ɼ�


bool modifyCrs(); // �޸Ŀγ���Ϣ�����޸ĳɼ���


bool modifyStuInCrs(); // �޸�ĳ���γ̵�ĳѧ���ɼ�


bool deleteCrs(); // ɾ���γ�


bool deleteStuInCrs(); // ɾ��ĳ���γ̵�ĳѧ���ɼ�


size_t searchCrs(); // ���ܿγ������������γ�


size_t searchStuInCrs(); // �ڵ����γ����������µ�ѧ��











#endif
