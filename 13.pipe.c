#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int ret;
	int fd[1];

	char *str="helld word\n";
	char buf[1024];

	pid_t pid;
	pipe(fd);
	pid=fork();
	if(pid==-1)
	{
		perror("fork error");
		exit(1);
	}
	if(pid>0)
	{
		close(fd[0]);//
		write(fd[1],str,strlen(str));
		printf("%ld\n",strlen(str));
	}
	if(pid==0)//
	{
		//printf("child\n");
		close(fd[1]);//
		ret=read(fd[0],buf,sizeof(buf));
		write(0,buf,ret);
		close(fd[0]);
	}

return 0;
}

