#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> //for using the wait call


//Recall that the order of execution can be arbitrary among the parent and the child process.
//This example will teach you how to make the parent proecess wait for the child to complete.


int main()
{
	int pid = fork();

	if(pid == 0)
	{
		printf("[Child] I am the Child with pid = %d, of the parent with pid = %d\n", getpid(), getppid());
		//We are in the child process
		for(int i = 0; i < 3; i++)
		{
			printf("[Child] In the child process %d\n", i);
		}
	}
	else
	{
		//Code for the parent process
		printf("[Parent] I am the parent with pid = %d\n", getpid());
		printf("[Parent] I will wait for the child to finish...\n");
		wait(NULL); //waits for the child to finish and exit
		printf("[Parent] The child has finished.\n");
		
	}

	return 0;
}
