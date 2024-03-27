#pragma once

#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"
#include "course.h"


List readStu(char* file_name); //读取学生文件


Cpnode readCrs(char* file_name); //读取课程文件


bool saveStu(List StuList, char* file_name); //保存学生文件


bool saveCrs(Cpnode CrsList, char* file_name); //保存课程文件


bool readQuality(); //读取素质类项目文件


bool exportStu(); //导出学生信息


bool importStu(); //导入学生信息


bool exportCrs(); //导出课程信息


bool importCrs(); //导入课程信息










#endif
