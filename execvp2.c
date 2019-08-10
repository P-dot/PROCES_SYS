#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    pid_t pid; 

    pid = fork();

    switch(pid) {
        case -1: /* Fork error */
            exit(-1);
	case 0:  /* Child process */
	    if (execvp(argv[1], &argv[1]<0)
	    perror("exec");
	default: /* Father */
	    printf("Father process\n");
    }
}
