#include<stdio.h>//得到文件属性
#include<stdlib.h>
#include<unistd.h>//stat头文件
#include<sys/stat.h>
int main(int argc ,char *argv[])
{
	struct stat sbuf{};//

	int ret=stat(argv[1], &sbuf);//得到文件属性，储存到buf结构体中
	//从inode结构体中获取，他是磁盘与文件之间的一个桥梁
	if(ret==-1);
	{
		perror("stat error");
		exit(1);
	}
	printf("file size=%ld\n",sbuf.st_size);
	//sbuf.st_mode

	return 0;
}
//给文件改名
//nulink隐式回收，删除一个文件的目录项，删除时会被系统择机释放
//隐式回收是在程序运行结束时清理数据



