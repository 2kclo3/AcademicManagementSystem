#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ui.h"


int showMenu(char* title, int optNum, ...){
	printf("%s\n\n", title);

	va_list args;
	va_start(args, optNum);

	for (int i = 1; i <= optNum; i++) {
		printf("%2d:%s\n", i, va_arg(args, char*));
	}
	va_end(args);
}
