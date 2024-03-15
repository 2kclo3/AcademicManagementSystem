#pragma once

#ifndef _COURSE_H_
#define _COURSE_H_

#include <stdio.h>

void showAllCrs(); // 显示所有课程（不包含学生成绩）


void showCrs(); // 显示单个课程信息（包含该课程所有学生的成绩）


void showStuInCrs(); // 具体显示单个课程的某学生


bool addCrs(); // 添加课程（不包含成绩）


bool addStuToCrs(); // 为某课程添加某学生成绩


bool modifyCrs(); // 修改课程信息（不修改成绩）


bool modifyStuInCrs(); // 修改某个课程的某学生成绩


bool deleteCrs(); // 删除课程


bool deleteStuInCrs(); // 删除某个课程的某学生成绩


size_t searchCrs(); // 在总课程链表中搜索课程


size_t searchStuInCrs(); // 在单个课程中搜索其下的学生











#endif
