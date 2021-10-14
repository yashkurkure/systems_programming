#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	//This call will create a new process same as this
	//The newly created process is the "child process"
	fork();

	//both processes would print Hello world!
	printf("Hello world!\n");
	return 0;
}
