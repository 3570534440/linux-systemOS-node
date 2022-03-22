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

	printf("main pid=%d,tid=%lu",getpid(),pthread_self());//
	return NULL;
}
int main(int argc, const char *argv[])
{
	pthread_t tid;

	int ret = pthread_create(&tid, NULL, tif ,NULL);
	if(ret != 0)
	perror("pthread_create error");
	printf("main pid=%d,tid=%lu",getpid(),pthread_self());
	sleep(1);


	return 0;
}



