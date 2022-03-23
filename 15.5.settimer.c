//也是设置定时器
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

/*信号捕捉回调函数*/
void myfunc(int signo)
{
	printf("aaaaaaaOk\n");
	return;
}

int main(int argc,char* argv[])
{
    /*注册信号捕捉函数*/
	signal(SIGALRM,myfunc);
	int ret=0;
	/*这是一个传出参数*/
	struct itimerval oldit;
	/*传入参数,进行初始化*/
	struct itimerval it;
	it.it_value.tv_sec=2;//2秒0毫秒
	it.it_value.tv_usec=0;
	it.it_interval.tv_sec=5;//5秒0毫秒
	it.it_interval.tv_usec=0;
	/*设置闹钟*/
	ret=setitimer(ITIMER_REAL,&it,&oldit);//自然计时
	if(ret==-1)
		perr_exit("setitimer error");
	/*手动让程序阻塞*/
	while(1);
	return 0;
}

//int setitimer(int which, const struct itimerval* new_value, struct itimerval* old_value);
//struct itimerval 
//{
//	struct timeval it_interval; 	/* Interval for periodic timer */
//	struct timeval it_value;    	/* Time until next expiration */
//};

/*精确到us的时间结构体*/
//struct timeval 
//{
//	time_t	tv_sec;        		 /* seconds */
//	suseconds_t	tv_usec;        /* microseconds */
//};
/*
成功返回0, 失败返回-1并设置errno;

参1which指定定时方式:

    自然定时:ITIMER_REAL->SIGALRM;
    用户空间计时(只计算进程占用CPU的时间):ITIMER_VIRTUAL->SIGVTALARM;
    运行时计时(用户+内核):ITIMER_PROF->SIGPROF;

参2是传入参数;

参3是传出参数;

it_interval:设定两次定时任务之间的时间间隔;

it_value:定时的时长(等it_value秒后触发闹钟, 以后每隔it_interval触发一次);
*/

