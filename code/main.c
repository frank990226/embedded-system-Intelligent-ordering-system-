#include "get_xy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>
#include "lcd_map_bmp.h"
#include <stdlib.h>
#include<time.h>
#include "lcd_show_font.h"
int NY,NYJ,SX,SXJ,QY,QYJ,JT,JTJ,ZJ=0;
int GY,GYJ,BY,BYJ,HH,HHJ,HN,HNJ,ZJ2=0;
int TD,TDJ,ZS,ZSJ,SC,SCJ,DF,DFJ,ZJ3=0;
int SR,SRJ,YX,YXJ,ZJ4=0;
int SN,SNJ,MJ,MJJ,WH,WHJ,HDL,HDLJ,ZJ5=0;
int n=0;
int ts_fd;
int x,y;

//çº¿ç¨‹æ‰§è¡Œå‡½æ•°
void *ts_fun(void *arg)
{
	while(1)
	{
		get_xy(ts_fd,&x,&y);

	}
}

int main(void)
{
    time_t t;//½«tÉùÃ÷ÎªÊ±¼ä±äÁ¿
    struct tm *p;//struct tmÊÇÒ»¸ö½á¹¹Ìå£¬ÉùÃ÷Ò»¸ö½á¹¹ÌåÖ¸Õë
    time(&t);
    p=localtime(&t);//»ñµÃµ±µØµÄÊ±¼ä
	ts_fd = TS_init();
	int FD = TS_init();
	char *lcd_ptr = lcd_init();
	//åˆ›å»ºçº¿ç¨‹ä¸“é—¨èŽ·å–è§¦æ‘¸å±åæ ‡
	pthread_t ts_id; //å®šä¹‰çº¿ç¨‹å·
	pthread_create(&ts_id,NULL,ts_fun,NULL);
	system("mplayer -loop 1 -slave -quiet -geometry 0:0 -zoom -x 800 -y 480 huoguo.avi end");
	show_bmp(0, 0, lcd_ptr,"/root/kaishi.bmp");
	
	while(1)
	{
		while(1)
   	 {
	    if(x>0&&x<80&&y>0&&y<60)
        { 
	        show_bmp(0, 0, lcd_ptr,"/root/caidan1.bmp");
			x=-1;y=-1;
    	    n=1;
    	}
    	if(x>0&&x<80&&y>60&&y<120)
    	{
    		ts_fd = TS_init();
	        int FD = TS_init();
    		show_bmp(0, 0, lcd_ptr,"/root/caidan2.bmp");
			x=-1;y=-1;
    	    n=2;
			
	    }
    	if(x>0&&x<80&&y>120&&y<180)
    	{
    	    n=3;
            show_bmp(0, 0, lcd_ptr,"/root/caidan3.bmp");
			x=-1;y=-1;
	    }
    	if(x>0&&x<80&&y>180&&y<240)
    	{
    		show_bmp(0, 0, lcd_ptr,"/root/caidan5.bmp");
			x=-1;y=-1;
		    n=4;
		}
    	    
    	if(x>0&&x<80&&y>240&&y<300)
    	{
    		show_bmp(0, 0, lcd_ptr,"/root/caidan4.bmp");
			x=-1;y=-1;
    	    n=5;    		
		}

        switch(n)
		{
        	case 2:
        		while(1)
				{
            	if(x>320&&x<440&&y>0&&y<120)
            	{
            	    GYJ=GYJ-100;
			        GY--;
			        x=-1;y=-1;

		            printf("²ÝÔ­¸áÑòÈâ¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",GY,GYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>320&&x<440&&y>120&&y<240)
            	{
            	    GYJ=GYJ+100;
			        GY++;
			        x=-1;y=-1;
		            printf("²ÝÔ­¸áÑòÈâ¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",GY,GYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>320&&x<440&&y>240&&y<360)
				{
			        BYJ=BYJ-100;
			        BY--;
			        x=-1;y=-1;
		            printf("Å£°ÙÒ¶¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",BY,BYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>320&&x<440&&y>360&&y<480)
				{
			        BYJ=BYJ+100;
			        BY++;
			        x=-1;y=-1;
		            printf("Å£°ÙÒ¶¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",BY,BYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>680&&x<800&&y>0&&y<120)
				{
			        HHJ=HHJ-100;
			        HH--;
			        x=-1;y=-1;
		            printf("ÀÌÅÉ»Æºí¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",HH,HHJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>120&&y<240)
				{
			        HHJ=HHJ+100;
			        HH++;
			        x=-1;y=-1;
		            printf("ÀÌÅÉ»Æºí¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",HH,HHJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>240&&y<360)
				{
			        HNJ=HNJ-100; 
			        HN--;
			        x=-1;y=-1;
		            printf("ÀÌÅÉ»¬Å£¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",HN,HNJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>360&&y<480)
				{
		    	    HNJ=HNJ+100; 
		    	    HN++;
		    	    x=-1;y=-1;
		            printf("ÀÌÅÉ»¬Å£¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",HN,HNJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>0&&x<80&&y>360&&y<420)
		        {
		        	GY=0;
				    GYJ=0;
			    	BY=0;
			    	BYJ=0;
			    	HH=0;
			    	HHJ=0;
			    	HN=0;
			    	HN=0;
			    	x=-1;y=-1;
			    	printf("³·ÏúËùÓÐÑ¡Ïî");
				}
				if(y>420&&x>0&&x<80)
				{
		    	    ZJ1=NYJ+SXJ+QYJ+JTJ+GYJ+BYJ+HHJ+HNJ+TDJ+ZSJ+SCJ+DFJ+SRJ+YXJ+SNJ+MJJ+WHJ+HDLJ;
		    	    x=-1;y=-1;
				    printf("¹²¼Æ%dÔª\n %d-%d-%d %d:%d:%d \n",ZJ1,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
			    }
				if(x>0&&x<80&&y>300&&y<360)
				{
					n=0;
					x=-1;y=-1;
					printf("·µ»ØÉÏÒ»²ã"); 
				    break;
		    	}
		        }
        	case 1:
        		while(1)
				{
        		if(x>320&&x<440&&y>0&&y<120)
            	{
            	    NYJ=NYJ-100;
			        NY--;
			        x=-1;y=-1;

		            printf("Å£ÓÍÂéÀ±¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",NY,NYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>320&&x<440&&y>120&&y<240)
            	{
            	    NYJ=NYJ+100;
			        NY++;
			        x=-1;y=-1;
//					show_xy_string(320,60,"1",0x00ffffff);
		            printf("Å£ÓÍÂéÀ±¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",NY,NYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>320&&x<440&&y>240&&y<360)
				{
			        SXJ=SXJ-100;
			        SX--;
			        x=-1;y=-1;
		            printf("ÈýÏÊ¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",SX,SXJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>320&&x<440&&y>360&&y<480)
				{
			        SXJ=SXJ+100;
			        SX++;
			        x=-1;y=-1;
		            printf("ÈýÏÊ¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",SX,SXJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>680&&x<800&&y>0&&y<120)
				{
			        QYJ=QYJ-100;
			        QY--;
			        x=-1;y=-1;
		            printf("ÇåÓÍÂéÀ±¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",QY,QYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>120&&y<240)
				{
			        QYJ=QYJ+100;
			        QY++;
			        x=-1;y=-1;
		            printf("ÇåÓÍÂéÀ±¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",QY,QYJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>240&&y<360)
				{
			        JTJ=JTJ-100; 
			        JT--;
			        x=-1;y=-1;
		            printf("¾úÌÀ¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",JT,JTJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>360&&y<480)
				{
		    	    JTJ=JTJ+100; 
		    	    JT++;
		    	    x=-1;y=-1;
		            printf("¾úÌÀ¹øµ×¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",JT,JTJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>0&&x<80&&y>360&&y<420)
		        {
			    	NY=0;
				    NYJ=0;
			    	SX=0;
			    	SXJ=0;
			    	QY=0;
			    	QYJ=0;
			    	JT=0;
			    	JTJ=0;
			    	x=-1;y=-1;
			    	printf("³·ÏúËùÓÐÑ¡Ïî");
				}
				if(y>420&&x>0&&x<80)
				{
		    	    ZJ2=NYJ+SXJ+QYJ+JTJ+GYJ+BYJ+HHJ+HNJ+TDJ+ZSJ+SCJ+DFJ+SRJ+YXJ+SNJ+MJJ+WHJ+HDLJ;
		    	    x=-1;y=-1;
				    printf("¹²¼Æ%dÔª\n %d-%d-%d %d:%d:%d \n",ZJ2,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
			    }
				if(x>0&&x<80&&y>300&&y<360)
				{
					n=0;
					x=-1;y=-1;
					printf("·µ»ØÉÏÒ»²ã"); 
				    break;
		    	}
		        }
        	case 3:
        		while(1)
        		{
        		if(x>320&&x<440&&y>120&&y<240)
            	{
            	    TDJ=TDJ+100;
			        TD++;
			        x=-1;y=-1;
//					show_xy_string(320,60,"1",0x00ffffff);
		            printf("ÍÁ¶¹¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",TD,TDJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
                if(x>320&&x<440&&y>360&&y<480)
				{
			        ZSJ=ZSJ+100;
			        ZS++;
			        x=-1;y=-1;
		            printf("ÖñËñ¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",ZS,ZSJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>680&&x<800&&y>120&&y<240)
				{
			        DFJ=DFJ+100;
			        DF++;
			        x=-1;y=-1;
		            printf("ÓÍ¶¹¸¯Æ¤¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",DF,DFJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>360&&y<480)
				{
		    	    SCJ=SCJ+100; 
		    	    SC++;
		    	    x=-1;y=-1;
		            printf("°üÐÄÉú²Ë¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",SC,SCJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>0&&x<80&&y>360&&y<420)
		        {
			    	TD=0;
				    TDJ=0;
			    	DF=0;
			    	DFJ=0;
			    	ZS=0;
			    	ZSJ=0;
			    	SC=0;
			    	SCJ=0;
			    	x=-1;y=-1;
			    	printf("³·ÏúËùÓÐÑ¡Ïî");
				}
				if(x>0&&x<80&&y>300&&y<360)
				{
					n=0;
					x=-1;y=-1;
					printf("·µ»ØÉÏÒ»²ã"); 
				    break;
			    }
			    if(y>420&&x>0&&x<80)
				{
		    	    ZJ3=NYJ+SXJ+QYJ+JTJ+GYJ+BYJ+HHJ+HNJ+TDJ+ZSJ+SCJ+DFJ+SRJ+YXJ+SNJ+MJJ+WHJ+HDLJ;
		    	    x=-1;y=-1;
				    printf("¹²¼Æ%dÔª\n %d-%d-%d %d:%d:%d \n",ZJ3,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
			    }
			    }
        	case 4:
        		while(1)
        		{
                if(x>320&&x<440&&y>120&&y<240)
            	{
            	    SRJ=SRJ+100;
			        SR++;
			        x=-1;y=-1;
//					show_xy_string(320,60,"1",0x00ffffff);
		            printf("Ð¡ËÖÈâ¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",SR,SRJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>320&&x<440&&y>360&&y<480)
            	{
            	    YXJ=YXJ+100;
			        YX++;
			        x=-1;y=-1;
//					show_xy_string(320,60,"1",0x00ffffff);
		            printf("ÓÍÐý¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",YX,YXJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>0&&x<80&&y>300&&y<360)
				{
					n=0;
					x=-1;y=-1;
					printf("·µ»ØÉÏÒ»²ã"); 
				    break;
			    }
			    if(x>0&&x<80&&y>360&&y<420)
		        {
			    	SR=0;
			    	SRJ=0;
			    	YX=0;
			    	YXJ=0;
			    	x=-1;y=-1;
			    	printf("³·ÏúËùÓÐÑ¡Ïî");
				}
				if(y>420&&x>0&&x<80)
				{
		    	    ZJ4=NYJ+SXJ+QYJ+JTJ+GYJ+BYJ+HHJ+HNJ+TDJ+ZSJ+SCJ+DFJ+SRJ+YXJ+SNJ+MJJ+WHJ+HDLJ;
		    	    x=-1;y=-1;
				    printf("¹²¼Æ%dÔª\n %d-%d-%d %d:%d:%d \n",ZJ4,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
			    }
		        }

        	case 5:
        		while(1)
        		{
                if(x>320&&x<440&&y>120&&y<240)
            	{
            	    SNJ=SNJ+100;
			        SN++;
			        x=-1;y=-1;
//					show_xy_string(320,60,"1",0x00ffffff);
		            printf("ËâÄàÏãÓÍ¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",SN,SNJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
                if(x>320&&x<440&&y>360&&y<480)
				{
			        MJJ=MJJ+100;
			        MJ++;
			        x=-1;y=-1;
		            printf("Âé½«¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",MJ,MJJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		    	}
		    	if(x>680&&x<800&&y>120&&y<240)
				{
			        WHJ=WHJ+100;
			        WH++;
			        x=-1;y=-1;
		            printf("Íè»¬Î¶µú¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",WH,WHJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		        if(x>680&&x<800&&y>360&&y<480)
				{
		    	    HDLJ=HDLJ+100; 
		    	    HDL++;
		    	    x=-1;y=-1;
		            printf("º£µ×ÀÌÎ¶µú¹²¼Æ%d·Ý×Ü¼Û%d\n %d-%d-%d %d:%d:%d \n",HDL,HDLJ,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		        }
		          if(x>0&&x<80&&y>360&&y<420)
		        {
			    	SN=0;
				    SNJ=0;
			    	MJ=0;
			    	MJJ=0;
			    	WH=0;
			    	WHJ=0;
			    	HDL=0;
			    	HDLJ=0;
			    	x=-1;y=-1;
			    	printf("³·ÏúËùÓÐÑ¡Ïî");
				}
				if(x>0&&x<80&&y>300&&y<360)
				{
					n=0;
					x=-1;y=-1;
					printf("·µ»ØÉÏÒ»²ã"); 
				    break;
			    }
			    if(y>420&&x>0&&x<80)
				{
		    	    ZJ5=NYJ+SXJ+QYJ+JTJ+GYJ+BYJ+HHJ+HNJ+TDJ+ZSJ+SCJ+DFJ+SRJ+YXJ+SNJ+MJJ+WHJ+HDLJ;
		    	    x=-1;y=-1;
				    printf("¹²¼Æ%dÔª\n %d-%d-%d %d:%d:%d \n",ZJ5,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
			    }
			    }
			default:
        		break;
		}
	}
		
	}
	
}
