#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int grgc,char *argv[])
{
	link(argv[1],argv[2]);//给文件改名
	unlink(argv[1]);//删除文件1，并隐式回收

	return 0;
}
