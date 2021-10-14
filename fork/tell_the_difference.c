#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	//fork returns a process id, but what does this number mean?
	int pid = fork();

	//As you already know when you fork, two separate processes get created
	//The return value for fork in both of this processes is different
	//We can use this to identify the process in which our code is running
	
	//If the pid is 0 then we are in th child process
	if(pid == 0)
	{
		//Here we can add code that we want only the
		//child process to run
		printf("I am the child process.\n");
	}

	//If the process is the parent, then the return value is always non-zero
	else
	{
		//Add code here which you want to execute in the parent process
		printf("I am the parent process.\n");

	}

	//IMPORTANT: Do not assume that the parent process executes first and then the child.
	//		The order of execution can be arbitrary, although it may seem that
	//		the parent executes first almost everytime.



	return 0;
}
