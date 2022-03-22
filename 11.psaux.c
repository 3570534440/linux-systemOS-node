#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,int argv)
{
int fd=open ("psaux1.c",O_WRONLY|O_CREAT|O_TRUNC,0644);
if(fd<0)
{
perror("open error");
exit(1);
}
dup2(fd,1);

execlp("ps","ps","aux",NULL);
perror("execlp error");

return 0;
}


