#ifndef _GET_XY_H
#define _GET_XY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>//""编译器优先在当前路径下寻找头文件 <>编译器去系统默认路径下寻找头文件

int TS_init(void);
void get_xy(int ts_fd,int *ts_x, int *ts_y);

#endif