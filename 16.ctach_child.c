#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>
void sys_err(const char *str)
{
	perror(str);
	exit(1);
}
void catch_child()
{
	pid_t wpid;
	wpid=wait(NULL);
	printf("--------------catch child id %d\n",wpid);
	return ;
}

int main(int argc ,char *argv[])
{
pid_t pid;
int i;
for(i=0;i<15;i++)
{
	pid=fork();
	if(pid==0)
	break;
	if(pid==-1)
	sys_err("fork error");
}
	if(15==i)
	{
		struct sigaction act;
		act.sa_handler=catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags=0;

		sigaction(SIGCHLD,&act, NULL);//注册了一个信号捕捉函数
		printf("i am parent,pid=%d\n",getppid());

		while(1);
	}
	else
	{
		printf("i am child,pid=%d\n",getpid());
	}
	return 0;
	}
