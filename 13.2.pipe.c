//兄弟进程间通信

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){

	int fd[2];
	pid_t pid;
	int ret=0;
	int i=0;
	/*创建管道*/
	ret=pipe(fd);
	if(ret==-1)
		perr_exit("pipe error");
	/*循环创建2个子进程*/
	for(i=0;i<2;++i)
	{
		pid=fork();
		if(pid==-1)
			perr_exit("fork error");
		if(pid==0)
			break;
	}
	/*父进程关闭管道读写两端*/
	if(i==2)
	{
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}else if(i==0)
	{
        /*兄进程关闭读端,将STDOUT指向fd[1]*/
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
		perr_exit("execlp ls error");
	}else if(i==1)
	{
        /*弟进程关闭写端,将STDIN指向fd[0]*/
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
		perr_exit("execlp wc error");
	}
	return 0;
}




