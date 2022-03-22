//此程序实现递归遍历目录的功能功能
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

void isFile(char *name);

void read_dir(char *dir)//读目录
{
	char path[256];
	DIR *dp;
	struct dirent *sdp;
	dp=opendir(dir);//打开目录函数返回DIR指针，失败返回NULL
	if(dp==NULL)
	{
	perror("open error");
	}

while((sdp=readdir(dp))!=NULL)//先打开，在读目录//目录流到结尾时会返回NULL
	//循环读目录，一次读一个返回一个结构体
{
if(strcmp(sdp->d_name,".")==0 || strcmp(sdp->d_name,"..")==0)
{
continue;
}
//拼凑路径
sprintf(path, "%s/%s", dir ,sdp->d_name);
isFile(path);//要传绝对路径
}

closedir(dp);
	return ;
}


void isFile(char *name)//判断目录，文件


{
struct stat sb;
int ret=0;

ret=stat(name , &sb);//得到文件的属性

	if(ret==-1)
	{
	perror("stat error");
	return ;
	}

	if(S_ISDIR(sb.st_mode))//dir判断是否是目录
	{
	read_dir(name);//如果是目录，则读目录
	}
	
printf("%s\t%10ld\n",name,sb.st_size);//不是目录则打印
return ;
}


int main(int argc ,char *argv[])
{
if(argc==1)
	{
	isFile(".");//如果是1的话，说明没指定参数传一个 . ，则表明递归本目录


	}
	else
	{
	isFile(argv[1]);
	}	


return 0;
}
