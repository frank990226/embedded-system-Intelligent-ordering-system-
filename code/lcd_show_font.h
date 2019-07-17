#ifndef _LCD_SHOW_FONT
#define _LCD_SHOW_FONT

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <sys/mman.h>//mmap
#include <stdlib.h>//malloc
#include <linux/input.h>//输入子系统


int show_xy_font(int X0,int Y0,char ch,unsigned int color);
void show_xy_string(int X0,int Y0,char *str,unsigned int color);


#endif
