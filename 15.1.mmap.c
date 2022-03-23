//储映射I/O使一个磁盘文件与存储空间中的一个缓冲区相映射, 于是当从缓冲区中取数据, 就相当于读文件中的相应字节
//于此类似, 将数据存入缓冲区, 则相应的字节就自动写入文件, 这样就可以在不使用read和write函数的情况下, 使用指针完成I/O操作
//使用这种方法, 首先应通知内核, 将一个文件映射到存储区域中, 这个映射工作可以通过mmap函数来实现

//void* mmap(void* addr, size_t length, int prot, int flags,int fd, off_t offset);

/*addr:指定映射区的首地址, 通常传NULL, 表示让系统自动分配
length:共享内存映射区大小(<=文件的实际大小)
 prot:共享内存映射区的读写属性, PROT_READ, PROT_WRITE及PROT_READ|PROT_WRITE
 flags:标注共享内存的共享属性, MAP_SHARED或MAP_PRIVATE(shared内存的变化会反映到文件上, private不会反映到文件上)
 fd:用于创建共享内存映射区的那个文件描述符
 offset:偏移位置, 需是4k的整数倍. 默认0, 表示映射文件全部
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	char* p=NULL;
	int fd=0;
	int len=0;
	int ret=0;

	fd=open("./testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1)
		perr_exit("open error");
	/*
	lseek(fd,10,SEEK_END);
	write(fd,"\0",1);
	*/
	ret=ftruncate(fd,20);//改变文件大小为20
	if(ret==-1)
		perr_exit("ftruncate error");

	len=lseek(fd,0,SEEK_END);//获取文件大小，从起始位置偏移到最后

	p=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//建立映射区
	if(p==MAP_FAILED)
		perr_exit("mmap error");
	/*内存的写操作,会被映射到文件的写操作*/
	strcpy(p,"11111\n");
	/*内存的读操作,会被映射到文件的读操作*/
	printf("----%s\n",p);
	/*与malloc一样,申请的内存要还回去*/
	ret=munmap(p,len);
	if(ret==-1)
		perr_exit("munmap error");
	return 0;
}

