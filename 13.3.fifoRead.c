//FIFO实现非血缘关系进程间通信
//读进程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])i
{
	int fd=0;
	int i=0;
	int len=0;
	char buf[4096];
	/*同样要依靠已经创建好的FIFO,从命令行参数中指定*/
	if(argc<2)
	{
		printf("Enter like this:./a.out fifoname\n");
		return -1;
	}
	/*以只读方式打开FIFO文件,拿到fd*/
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
		perr_exit("open error");
	/*从fd中读取数据,并写到标准输出上*/
	while(1)
	{
		len=read(fd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,len);
		sleep(1);
	}
	close(fd);
	return 0;
}

