//父进程调用wait函数可以回收子进程终止信息, 该函数有三个功能:

   // 阻塞等待子进程退出
  //  回收子进程残留资源
//    获取子进程结束状态(退出原因)
/*wait回收子进程
int status;
pid_t wpid=wait(&status);	//阻塞等待子进程退出
WIFEXITED(status);			//判断是否正常退出
WIFSIGNALED(status);		//判断是否被信号终止
WEXITSTATUS(status)			//获取退出值
WTERMSIG(status)			//获取凶手信号值

*/

#include<stdio.h>
#include<string>
#include<unistd.h>//fork
#include<sys/wait.h>//wait
perr_exit(char *str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[]){
	pid_t pid,wpid;
	int status=0;

	pid=fork();
	if(pid==-1)
		perr_exit("fork error");

	if(pid==0)
	{
		printf("I'm child:%d,my parent is %d,I'm going to sleep 10s\n",getpid(),getppid());
		sleep(10);
		printf("I'm child,I'm going to die\n");
		return 73;
	}
	else if(pid>0)//父进程回收子进程
	{
		//wpid=wait(NULL);		//不关心子进程退出原因
		wpid=wait(&status);
		if(wpid==-1)
			perr_exit("wait error");
		/*如果子进程正常终止,则可获取它的退出值*/
		if(WIFEXITED(status))
			printf("My child exited with:%d\n",WEXITSTATUS(status));
        /*如果子进程被信号终止,可获取结束它的信号*/
		else if(WIFSIGNALED(status))
			printf("My child killed by:%d\n",WTERMSIG(status));
		/*提示回收完成*/
		printf("I'm parent,wait %d finish\n",wpid);
	}
	return 0;
}



