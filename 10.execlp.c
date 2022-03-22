#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

int main(int argc , char argv[])
{
pid_t pid =fork();
	if(-1==pid)
	{
	perror("execl error");
	exit(1);
	}
	if(0==pid)
    {
	execl("/bin/ls","ls",NULL);
	//execl("/bin/ls",NULL);//错误写法
	//execlp("ls","ls","-l",NULL);
	}
	if(pid>0)
	{
		sleep(1);
		printf("i am perint: %d",getpid());
		}
return 0;

