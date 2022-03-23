//设置定时器（闹钟），在指定时间后，内核会给当前进程发送
//14）SIGALRM信号，默认动作终止
//取消定时器用alarm（0），函数返回闹钟剩余秒数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int i=0;
	int j=0;
    /*设置闹钟为1s,1s后自动结束进程*/
	alarm(1);
	/*死循环打印计数*/
	while(1){
		printf("i=%d,j=%d\n",i,j);
		++i;
		j++;
	}
	return 0;
}

