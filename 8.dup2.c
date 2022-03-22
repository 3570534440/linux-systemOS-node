233456-----------123nclude<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
int main(int argc ,char *argv[])
{

int fd1=open(argv[1],O_RDWR);
printf("fd1:%d\n");

int fd2=open(argv[2],O_RDWR);
printf("fd2:%d\n");

int fdret=dup2(fd1,fd2);
printf("fdret:%d\n",fdret);

int ret=write(fd2,"1233456",7);
printf("ret:%d\n",ret);

dup2(fd1,1);//将屏幕重定向到fd1，1是屏幕
printf("-----------123");//在文件1中
return 0;
}
