#include "lcd_map_bmp.h"

//初始化lcd，得到映射内存的地址
char *lcd_init(void)
{
	//打开lcd屏
	int lcd_fd = open("/dev/fb0", O_RDWR);
	if(lcd_fd == -1)
	{
		perror("open LCD failed");
		exit(-1);
	}
	//开启映射-->给lcd分配显存
	char *lcd_map = mmap(NULL,LCD_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,lcd_fd,0);
	if(lcd_map == MAP_FAILED)
	{
		perror("map failed");
		exit(-1);
	}
	return lcd_map;
}

//图片的宽和高像素点的个数必须是4的倍数
/**************************************
参数说明：
	x_offset，y_offset 起点坐标
	lcd_map lcd的虚拟显存地址
	bmppath 图片的路径名（在开发板中）
**************************************/
void show_bmp(int x_offset, int y_offset,char *lcd_map,char *bmppath)
{
	int i,j;
	
	//取像素点
	bmp_head myhead;//定义位图头部
	
	int bmp_fd = open(bmppath, O_RDONLY);
	if(bmp_fd == -1)
	{
		perror("open BMP failed");
		exit(-1);
	}
	//读取头部信息，并判断图片是否满足要求
	printf("read head:%d",sizeof(myhead));
	read(bmp_fd, &myhead, sizeof(myhead));
	printf("bmp width %d height %d\n", myhead.width, myhead.height);
	
	char bmp_buf[myhead.width*myhead.height*3];//bmp图片像素缓冲区
	char tmp_buf[myhead.width*myhead.height*4];//lcd显示数临时据缓冲区
	
	bzero(bmp_buf,sizeof(bmp_buf));//清空缓冲区
	bzero(tmp_buf,sizeof(tmp_buf));//清空缓冲区
	
	//读取像素点数据
	read(bmp_fd, bmp_buf, sizeof(bmp_buf));
	
	
	//处理数据。将24位像素变为32位并改变像素点排列
	for(i=0; i<myhead.height; i++)
		for(j=0; j<myhead.width; j++)
	{													//           y*800+x							
		tmp_buf[((myhead.height-1-i)*myhead.width+j)*4] =   bmp_buf[(i*myhead.width+j)*3];	//B 
		tmp_buf[((myhead.height-1-i)*myhead.width+j)*4+1] = bmp_buf[(i*myhead.width+j)*3+1];//G
		tmp_buf[((myhead.height-1-i)*myhead.width+j)*4+2] = bmp_buf[(i*myhead.width+j)*3+2];//R
		tmp_buf[((myhead.height-1-i)*myhead.width+j)*4+3] = 0x00;			//A
	}
	
	//将图片的扫描方式和lcd显示方式同步
	for(i=0; i<myhead.height; i++)
		for(j=0; j<myhead.width*4; j++)
		{
			//*(lcd_map+(479-i)*800*4+j)
			lcd_map[(i+y_offset)*800*4+(j+x_offset*4)]=tmp_buf[(i*myhead.width*4)+j];
		}

	//关闭
	close(bmp_fd);
}