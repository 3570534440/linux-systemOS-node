#include<stdio.h>//fcntl实现dup的功能
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>

int main(int argc,char *argv[])//
{
	int fd =open(argv[1],O_RDWR);
	printf("%d\n",fd);

	int newfd=fcntl(fd,F_DUPFD, 0);//0已经被占用，所以返回最小可用的文件描述符4
	printf("newfd=%d\n",newfd);

	int newfd1 = fcntl(fd,F_DUPFD.7)//7没有被占用，所以返回=7的文件描述符

}
