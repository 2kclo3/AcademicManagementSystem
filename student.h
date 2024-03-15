#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>


void showAllStu(); // 显示所有学生信息（不包含课程）


void showStu(); // 显示单个学生信息（包含其课程成绩）


void showCrsInStu(); // 具体显示单个学生的某课程


bool addStu(); // 添加学生（不包含课程）


bool addCrsToStu();// 为某个学生添加某课程及成绩


void sortStu();// 排序总学生链表


bool modifyStu();// 修改学生信息（不修改课程）


bool modifyCrsInStu(); // 修改某个学生的某课程及成绩


bool deleteStu(); // 删除学生


bool deleteCrsInStu(); // 删除某个学生的某课程及成绩


size_t searchStu(); // 在总学生链表中搜索学生


size_t searchCrsInStu(); // 在单个学生中搜索其课程











#endif
