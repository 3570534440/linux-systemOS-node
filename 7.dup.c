-----------123.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
int main(int argc ,char *argv[])
{

int fd=open(argv[1],O_RDONLY);

int newfd=dup(fd);
printf("newfd:%d\n",newfd);
return 0;
}

