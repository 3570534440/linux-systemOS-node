#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	printf("before fork-1-\n");
	printf("before fork-2-\n");
	printf("before fork-3-\n");
	printf("before fork-4-\n");
	
	pid_t pid = fork();//fork函数，父进程返回子进程pid，子进程返回0

	if(pid==-1)
	{
		perror("fork error");
		exit(1);
	}
	if(pid==0)
	{
		printf("----child is created\n");
	}

	if(pid>0)
	{
		printf("parent process:my child is %d\n",pid);
	}

	printf("==========end of file\n");

	return 0;
	}
