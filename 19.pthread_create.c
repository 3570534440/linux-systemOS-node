#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}
void *tif(void *arg)//回调函数//子线程
{
	int i = (int)arg;//强转为整形

	if(i == 2)
	{
		exit(0);//表示退出进程
		return NULL;//表示返回到调用者哪里去，也就是退出当前线程
		pthread_exit(NULL);//退出当前线程
	}

	printf("main pid=%d,tid=%lu",getpid(),pthread_self());//
	return NULL;
}
int main(int argc ,char *argv[])
{
	pthread_t tid;
	
	int ret;
	for(int i=0 ;i<5 ;i++)//循环创建子线程
	{
	ret = pthread_create(&tid, NULL, tif ,(void *)i);//主线程
	if(ret != 0)
	perror("pthread_create error");
	printf("main pid=%d,tid=%lu\n",getpid(),pthread_self());
	}
	sleep(1);//因为共享同一个地址空间，所以等待所有子线程结束后在return


	return 0;
}



