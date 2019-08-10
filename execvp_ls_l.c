#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	pid_t pid;
	char *arguments[3];
	pid_t fork();
	int execvp();

	arguments[0] = "ls";
	arguments[1] = "l";
	arguments[2] = NULL;

	pid = fork();
	switch(pid) {
	   case -1: // error from the fork
	      exit(-1);
	   case 0: /* Child process*/
	      execvp(arguments[0], arguments);
	      perror("exec");
	      break;
	   default:  // Father 
	      printf("Father process\n");
	}

}