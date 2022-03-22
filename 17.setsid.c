///父进程fork子进程，然后父进程退出
//目的是子进程不是组长进程，然后调用setsid函数提供了条件
///子进程调用setsid创建会话
//1.该子进程成为会长
//2.成为组长进程
//3.不受控制终端影响
///核心操作
//编写一个守护进程，每两秒获取一次系统时间，并将这个时间写入磁盘中
//每隔两秒，使用setitimer函数设置时钟，该函数发送SIGALRM信号
//注册signal或sigaction函数
//获取系统时间time函数的使用ctime函数的使用，还有open，write，close             

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/stat.h>
void myfunc(int signo)
{
	int fd = open ("",O_RDWE | o_CREAT) ;


time_t t ;
time(&t) ;
char *p = ctime(&t) ;

write(fd,p,strlen(p)) ;

close (fd) ;

return ;
}

sys_err(const char *str)
{
	perror(str);
	exit(1);
}
int main(int argv,int *argv[])
{
	pid_t pid=fork();
	if(pid>0)
		break;
	
	setsid();
	//chdir("");
	//umask(0000);
	//close(STDIN_FILENO);
	//close(STDOUT_FILENO);
	//close(STDERR_FILENO);

	struct sigaction act;
	act.sa_handler=myfunc;
	act.sa_flags=0;
	sigempyset(&act.sa_mask);
	sigaction(SIGALAM,&act,NULL);
	
	struct itimerval tm;
	tm.it_interval.tv_sec=2;
	tm.it_interval.tv_usec=0;
	tm.it_value.tv_sec=3;
	tm.it_value.tv_usec=0;

	setitimer(ITIMER_REAL,&tm, NULL) ;
	while(1)
	{}

}








                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
