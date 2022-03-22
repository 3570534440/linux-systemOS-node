#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,int *argv[])
{
	char buf[1024];
	int f1,f2;
	int n=-1;
	f1=open("cp1.txt",O_RDONLY);
	//O_RDONLY 只读   O_RDWR 读写  O_WRONLY 只写  O_APPEND 追加  O_CREAT创建
	if(f1==-1)
	{
		perror("open argv1 error");
		exit(1);
	}
	f2=open("c",O_RDWR|O_CREAT|O_TRUNC,0644);
	//如果文件存在，以读写方式打开，
	//如果不存在，则创建，权限为 rw-r--r--
	if(f2==-1)
	{
		perror("open argv2 error");
		exit(1);
	}
	while(((n=read(f1,buf,1024))!=0))//读到buf里面，buf是文件缓冲区，缓冲区大小为1024
	{
	if(n<0)//如果返回-1，可能是以非阻塞的方式读一个设备文件
	{

		perror("read error");
		break;
	}
		write(f2,buf,n);//在buf里面读到的数据写道第二个文件里面
	}
	close(f1);
	close(f2);
	//文件描述符0/1/2.....1023
	//0-STDIN-FILENO
	//1-STDOUT-FILENO
	//2-STDERR-FILENO

return 0;
}

