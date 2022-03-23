//信号练习
//此程序没设置error
//此程序屏蔽信号SIGINT SIGQUIT SIGBUS SIGKILL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
void print_set(sigset_t* set)
{

	int i=0;
	for(i=1;i<32;++i){
		if(sigismember(set,i))
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}

int main(int argc,char* argv[])
{
	sigset_t set,oldset,pedset;//定义信号
	int ret=0;

	sigemptyset(&set);//将信号集至空
	/*屏蔽掉Ctrl+c*/
	sigaddset(&set,SIGINT);//添加信号到信号集
	/*屏蔽掉Ctrl+\*/
	sigaddset(&set,SIGQUIT);
    /*屏蔽掉SIGBUS*/
	sigaddset(&set,SIGBUS);
    /*屏蔽掉SIGKILL-不灵*/
	sigaddset(&set,SIGKILL);
	/*设置到内核*/
	sigprocmask(SIG_BLOCK,&set,&oldset);//设置阻塞，屏蔽信号
	if(ret==-1)
		perr_exit("sigpending error");

	while(1)
	{
		ret=sigpending(&pedset);
		if(ret==-1)
			perr_exit("sigpending error");

		print_set(&pedset);//打印信号集
		sleep(1);
	}
	return 0;
}

