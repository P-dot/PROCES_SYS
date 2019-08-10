#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	pid_t fork(); 
	execlp("ls", "ls", "-l", NULL);
	
	pid = fork();
	switch(pid){
		case -1: /* error from fork () */
	       exit(-1);
        case 0:  /* child process */
	       execlp("ls", "ls", "-l", NULL);
	       perror("exec");
	       break;
	    default: /* father */
	       printf("Father Process\n");
	}
}