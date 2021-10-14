#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


//This method will be run when the parent recieves the SIGCHLD signal
void handler()
{
	//Although we know the child process has exited we call waitpid()
	//This way the entry of the child preocess in the preocess table
	//	is gauranteed to be removed. Thus, we wont have any zombie preocess. 
	waitpid((-1), 0, WNOHANG);

	//We use wait() instead of printf() here because printf() is not async safe.
	//Keep in mind that signal handlers run asynchronously, therefore any function calls you 
	//	make inside a signal handler must be async safe.
	//You can find a list of async signal safe functions here:
	//			https://man7.org/linux/man-pages/man7/signal-safety.7.html
	write(1, "Completed wait in handler", 25);
}

int main()
{
    //Register a signal handler for SIGCHLD
    //This signal is sent to the parent process when a child process exits
    signal(SIGCHLD, handler);

    if(!fork())
    {
	    //in child
	    for(int i = 0; i < 5; i++)
	    {
		    printf("In child\n");
	    }
    }
    else
    {
	    printf("In parent\n");
	    while(1);
    }
}
