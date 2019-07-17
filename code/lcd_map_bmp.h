#ifndef _LCD_MAP_BMP_H_
#define _LCD_MAP_BMP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define  LCD_SIZE 800*480*4

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#pragma pack(1)   			//取消字节对齐 

typedef struct {			//bmp图片文件头信息封装 
	// 位图文件头 
	u8  bit_file_type[2];	//位图文件类型:'BM'->0x4d42 
	u32 file_size;	  		//整个文件大小 
	u16 reserved1;	  		//保留 
	u16 reserved2;	  		//保留 
	u32 offset;		  		//文件头到位图数据之间的偏移量 

	// 位图信息头 
	u32 head_size;			//位图信息头长度 
	u32 width;		  		//位图宽度 
	u32 height;		  		//位图高度 
	u16 bit_planes;	  		//位图位面数 
	u16 bits_per_pixel; 	//每个像素的位数 
	u32 compression;		//压缩说明 
	u32 image_size;			//位图数据大小 
	u32 h_res;				//水平分辨率 
	u32 v_res;				//垂直分辨率 
	u32 color_palette;		//位图使用的颜色索引数 
	u32 vip_color;			//重要的颜色索引数目 

}bmp_head;

#pragma pack() 	//恢复字节对齐 

//函数声明
char *lcd_init(void);
void show_bmp(int x_offset, int y_offset,char *lcd_map,char *bmppath);

#endif