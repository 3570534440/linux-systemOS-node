#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char *argv[])
{	
	pid_t pid ,wpid,repid;
	int i=0;
	for(;i<5;i++)
	{
		pid=fork();
		if(pid==-1)
		{
			perror("fork error");
			exit(1);
		}
		if(pid==0)
		{
			break;
		}
		if(i==2)
		{
			repid=pid;
		}
	}
	if(5==i)
	{	
		sleep(5);
		printf("my release %d\n",repid);
		wpid=waitpid(-1,NULL,0);//以阻塞方式回收指定进程
	//	wpid=waitpid(repid,NULL,0);//以阻塞方式回收指定进程
		if(wpid==-1)
		{	perror("waitpid error");
			exit(1);
		}
		printf("my release id %d \n",wpid);
		//printf("my release id %d \n",wpid);//当pid是-1时，和wait的作用一样，回收任意子进程
		//waitpid(pid,NULL,WNOHANG);//以非阻塞方式回收
	}
	else
	{
		printf("my is %d release,my pid is %d\n ",i+1,getpid());
		

	}
	return 0;
	
}

