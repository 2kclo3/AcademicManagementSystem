#pragma once

#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include "course.h"


bool readStu(); //读取学生文件


Cpnode readCrs(); //读取课程文件


bool readQuality(); //读取素质类项目文件


bool exportStu(); //导出学生信息


bool importStu(); //导入学生信息


bool exportCrs(); //导出课程信息


bool importCrs(); //导入课程信息










#endif
