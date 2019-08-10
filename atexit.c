#include <stdio.h>
#include <stdlib.h>

void end(void)
{   
	pid_t getpid(void);
	
	printf("End of the process execution %d \n", getpid());
	return;
}

void main(void)
{
   int atexit(void(*func)(void));

   if (atexit(end) != 0) {
   	  perror("atexit");
   	  exit(1);
   }
   exit(0);
}