//fifoFIFO实现非血缘关系进程间通信
//写进程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int fd=0;
	int i=0;
	char buf[4096];
	/*靠已经创建好的FIFO,如果命令行参数没给指定,报错*/
	if(argc<2)
	{
		printf("Enter like this:./a.out fifoname\n");
		return -1;
	}
	/*以只写方式打开FIFO文件,拿到fd*/
	fd=open(argv[1],O_WRONLY);
	if(fd==-1)
		perr_exit("open error");

	while(1)
	{
        /*将数据写到buf中*/
		sprintf(buf,"fuckyou:%d\n",i++);
		write(fd,buf,strlen(buf));
		sleep(1);
	}
	close(fd);
	return 0;
}



