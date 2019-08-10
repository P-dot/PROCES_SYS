#include <stdio.h> 
#include <stdlib.h>

void end(void)
{   
    pid_t getpid(void);
    printf("End of process execution %d\n", getpid());
    return ;
}

void main(void)
{
     if (atexit(end) != 0) {
        perror("atexit");
	exit(-1);
     }

     exit(0); /*causes the execution of end function */
}
