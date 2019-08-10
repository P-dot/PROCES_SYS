#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid, status;
	pid = fork();
	if (pid){ // PARENT:
	   printf("PARENT %d WAITS FOR CHILD %d TO DIE\n", getpid(),pid);
       pid=wait(&status); // wait for ZOMBIE child process 
	}
	else{// child:
	   printf("child %d dies by exit(VALUE)\n", getpid());
	   exit(100);
	}
}