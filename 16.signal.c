//信号操作函数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
/*自定义信号集*/
sigset_t set;

/*全部清空*/
int sigemptyset(sigset_t* set);
/*全部置1*/
int sigfillset(sigset_t* set);
/*将一个信号添加到集合当中*/
int sigaddset(sigset_t* set, int signum);
/*将一个信号从集合中移除*/
int sigdelset(sigset_t* set, int signum);
/*判断某一信号是否在集合当中*/
int sigismember(const sigset_t* set, int signum);


int sigprocmask(int how, const sigset_t* set, sigset_t* oldset);
/*
用于屏蔽信号或解除屏蔽, 本质是读取或修改进程PCB中的信号屏蔽字;

屏蔽信号, 只是将信号处理延后执行(延至解除屏蔽);而忽略表示将该信号丢弃处理;

how:

    SIG_BLOCK:设置阻塞, set表示需要屏蔽的信号;
    SIG_UNBLOCK:设置非阻塞, set表示需要解除屏蔽的信号;
    SIG_SETMASK:用set替换原始屏蔽集;

set:传入参数, 是一个位图, set中哪位置1, 就表示当前进程屏蔽哪个信号;

oldset:传出参数, 保存旧的信号屏蔽集;



sigpending函数:读取当前进程的未决信号集
int sigpending(sigset_t* set);
set是传出参数;

返回值: 成功返回0, 失败返回-1并设置errno;

*/

/*创建一个自定义信号集*/
sigset_t set;
/*清空自定义信号集*/
sigemptyset(&set);
/*向自定义信号集添加信号*/
sigaddset(&set,SIGINT);
/*用自定义信号集操作内核信号集*/
sigprocmask(SIG_BLOCK,&set);
/*查看未决信号集*/
sigpending(&myset);


