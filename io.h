#pragma once

#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//如果真的要规定学号为8位，这个也要改，毕竟小于8位的学号也不对
int getNumber(int max); //输入数字

double getDouble(double max);

void getText(char* str); //输入文字









#endif
