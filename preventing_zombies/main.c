#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void signal_handler(int sig)
{
	printf("In signal_handler");
	wait(NULL);
}

int main()
{
	int i;
	int pid = fork();
	if(pid == 0)
	{
		printf("I am the child\n");
		return 0;
	}
	else
	{
		signal(SIGCHLD, signal_handler);
		printf("I am the parent\n");
		while(1);
	}
	printf("Exiting...\n");

	return 0;
}
