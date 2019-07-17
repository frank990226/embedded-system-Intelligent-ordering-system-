#include "get_xy.h"

int TS_init(void)
{
	//打开触摸屏设备
	int ts_fd = open("/dev/input/event0", O_RDONLY);
	if(ts_fd == -1)
	{
		perror("open TOUCH failed");
		exit(-1);
	}
	return ts_fd;
}

void get_xy(int ts_fd,int *ts_x, int *ts_y)//址传递
{
	struct input_event myevent;
	//读取内容
	while(1)
	{
		read(ts_fd, &myevent, sizeof(myevent));
		//打印内容到终端
		//printf("type:%d code:%d value:%d\n",myevent.type, myevent.code, myevent.value);
		if(myevent.type == EV_ABS)
		{
			if(myevent.code == ABS_X)
			{
				*ts_x = myevent.value;
			}
			if(myevent.code == ABS_Y)
			{
				*ts_y = myevent.value;
			}
		}
		if(myevent.type==EV_KEY && myevent.code==BTN_TOUCH && myevent.value==0)
		{
			break;
		}
	}

}
