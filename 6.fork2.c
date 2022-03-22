#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int main(int argc,char *argv[])
{
	int i=0;
	pid_t pid;
	for(i=0;i<5;i++)
	{
		if(fork()==0)//让子进程结束
			break;
	}
	if(5==i)
	{
		printf("i am perint\n");
	//	sleep(i);
	}
	//sleep(i);
	printf("i am %d create\n",i+1);
return 0;
 }//y进程创建出来后，去争夺cpu资源，然后打ppp印印，可以加上；sleep
 //刚fork之后:
//父子的相同之处: 全局变量, .data段, .text段, 栈, 堆, 环境变量, 用户ID, 宿主目录, 进程工作目录, 信号处理方式…;
//父子进程的不同之处: 进程ID, fork返回值, 父进程ID, 进程运行时间, 闹钟(定时器), 未决信号集;
//父子进程遵循，读时共享，写时复制
//但是子进程并不是把父进程0~3G地址空间完全cpoy一份, 然后映射到物理内存
//父子进程间遵循读时共享, 写时复制的原则, 这样设计, 无论子进程执行父进程的逻辑还是执行自己的逻辑都能节省内存开销
