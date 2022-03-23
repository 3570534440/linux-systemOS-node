//signal实现信号捕捉8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
/*定义回调函数类型,很不幸,函数类型限制死了*/
//typedef void (*sighandler_t)(int);
/*注册信号捕捉函数*/
//sighandler_t signal(int signum, sighandler_t handler);
//该函数由ANSI定义, 由于历史原因在不同版本的Unix和不同版本的Linux中可能有不同的行为, 因此应尽量避免使用它, 取而代之使用sigaction函数;


int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact);
//函数原型
struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);			//不用
	sigset_t   sa_mask;										//只工作于信号捕捉函数执行期间,相当于中断屏蔽
	int        sa_flags;									//本信号默认屏蔽
	void     (*sa_restorer)(void);							//废弃
};
void catch_signal(int signum){
	if(signum==SIGINT)
		printf("Catch you SIGINT:%d\n",signum);
	else if(signum==SIGQUIT)
		printf("Catch you SIGQUIT:%d\n",signum);
}

int main(int argc,char* argv[])
{
	int ret=0;
	/*前者传入,后者传出*/
	struct sigaction act,oldact;


/*设置回调函数*/
	act.sa_handler=catch_signal;
    /*设置回调函数的信号屏蔽字*/
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;


	/*捕捉SIGINT信号*/
	ret=sigaction(SIGINT,&act,&oldact);
	if(ret==-1)
		perr_exit("sigaction error");
	/*捕捉SIGQUIT信号*/
	ret=sigaction(SIGQUIT,&act,&oldact);
	if(ret==-1)
		perr_exit("sigaction error");

	while(1);
	return 0;
}
/*

    捕捉函数执行期间, 信号屏蔽字由mask变为sigaction结构体中的sa_mask, 捕捉函数执行结束后, 恢复回mask;
    捕捉函数执行期间, 本信号自动被屏蔽(sa_flags=0);
    捕捉函数执行期间, 若被屏蔽信号多次发送, 解除屏蔽后只响应一次;
    
*/




