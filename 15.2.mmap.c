//父子mmap通信

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int* p;
	pid_t pid;
	int fd=0;
	int ret=0;
	/*先打开(创建)一个文件*/
	fd=open("temp",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1)
		perr_exit("open error");
	ftruncate(fd,4);
	/*创建映射区*/
	p=(int*)mmap(NULL,4,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if(p==MAP_FAILED)
		perr_exit("mmap error");
	/*创建完就可以关闭文件了*/
	close(fd);
	/*创建子进程*/
	pid=fork();
	if(pid==-1)
		perr_exit("fork error");

	if(pid==0)
	{
        /*子进程写一个int*/
		*p=2000;
		var=1000;
		printf("child:*p=%d,var=%d\n",*p,var);
	}
	else if(pid>0)
	{
        /*父进程读出这个int*/
		sleep(1);
		printf("parent:*p=%d,var=%d\n",*p,var);
        /*回收子进程*/
		wait(NULL);
		/*归还映射区给内存池*/
		ret=munmap(p,4);
		if(ret==-1)
			perr_exit("munmap error");
	}
	return 0;
}

