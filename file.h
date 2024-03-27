#pragma once

#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"
#include "course.h"


List readStu(char* file_name); //��ȡѧ���ļ�


Cpnode readCrs(char* file_name); //��ȡ�γ��ļ�


bool saveStu(List StuList, char* file_name); //����ѧ���ļ�


bool saveCrs(Cpnode CrsList, char* file_name); //����γ��ļ�


bool readQuality(); //��ȡ��������Ŀ�ļ�


bool exportStu(); //����ѧ����Ϣ


bool importStu(); //����ѧ����Ϣ


bool exportCrs(); //�����γ���Ϣ


bool importCrs(); //����γ���Ϣ










#endif
