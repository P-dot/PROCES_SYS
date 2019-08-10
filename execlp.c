#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;
    
    pid = fork();
    switch(pid){
        case -1: /* fork error */
	   exit(-1);
	case 0: /* Child process */
	   execlp("ls","ls","-l",NULL);
	   perror("exec");
	   break;
        default: /* Father */
	   printf("Father process\n");
    }
    
}
