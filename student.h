#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>


void showAllStu(); // ��ʾ����ѧ����Ϣ���������γ̣�


void showStu(); // ��ʾ����ѧ����Ϣ��������γ̳ɼ���


void showCrsInStu(); // ������ʾ����ѧ����ĳ�γ�


bool addStu(); // ���ѧ�����������γ̣�


bool addCrsToStu();// Ϊĳ��ѧ�����ĳ�γ̼��ɼ�


void sortStu();// ������ѧ������


bool modifyStu();// �޸�ѧ����Ϣ�����޸Ŀγ̣�


bool modifyCrsInStu(); // �޸�ĳ��ѧ����ĳ�γ̼��ɼ�


bool deleteStu(); // ɾ��ѧ��


bool deleteCrsInStu(); // ɾ��ĳ��ѧ����ĳ�γ̼��ɼ�


size_t searchStu(); // ����ѧ������������ѧ��


size_t searchCrsInStu(); // �ڵ���ѧ����������γ�











#endif
