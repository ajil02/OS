#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("child=>ppid %d,pid %d\n",getppid(),getpid());
		exit(EXIT_SUCCESS);
	}
	else if(pid>0)
	{
		printf("parent=>pid %d\n",getpid());
		printf("Waiting for child process\n");
		wait(NULL);
		printf("Child finish");
	}
	else
	{
		printf("Unable to create\n");
	}
}
