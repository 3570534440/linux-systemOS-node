//父子进程wc -l ls
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd[2];
	pid_t pid;
	int ret=0;

	ret=pipe(fd);//创建并打开管道
	if(ret==-1)
		perr_exit("pipe error");

	pid=fork();
	if(pid==-1)
		perr_exit("fork error");
	if(pid>0)
	{
        /*父进程先读管道,如果子进程还没起来,他就会阻塞,这样子进程就会先于父进程结束*/
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
		perr_exit("execlp wc error");
	}else if(pid==0)
	{
        /*子进程写管道*/
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
		perr_exit("execlp ls error");
	}

	return 0;
}

