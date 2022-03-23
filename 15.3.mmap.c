//无血缘关系进程间MMAP通信
//写进程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	struct student stu={1,"xiaming",18};
	struct student* p;
	int fd=0;
    /*打开或创建一个文件*/
	fd=open("temp",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1)
		perr_exit("open error");
	ftruncate(fd,sizeof(stu));
	/*建立内存映射区*/
	p=(struct student*)mmap(NULL,sizeof(stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p==MAP_FAILED)
		perr_exit("mmap error");
	/*循环使用memcpy向内存映射区中写入数据,并修改stu的id值*/
	while(1)
	{
		memcpy(p,&stu,sizeof(stu));
		stu.id++;
		sleep(1);
	}
	/*归还内存映射区给内存池*/
	munmap(p,sizeof(stu));
	close(fd);
	return 0;
}



//读进程
int main(int argc,char* argv[])
{
	struct student stu;
	struct student* p;
	int fd=0;
	fd=open("temp",O_RDONLY);
	if(fd==-1)
		perr_exit("open error");
	/*建立内存映射区*/
	p=(struct student*)mmap(NULL,sizeof(stu),PROT_READ,MAP_SHARED,fd,0);
	if(p==MAP_FAILED)
		perr_exit("mmap error");
	/*循环读出内存映射区中的数据*/
	while(1)
	{
		printf("id=%d,name=%s,age=%d\n",p->id,p->name,p->age);
		sleep(1);
	}
	/*归还内存映射区给内存池*/
	munmap(p,sizeof(stu));
	close(fd);
	return 0;
}

