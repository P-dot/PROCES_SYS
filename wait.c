#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
//Program thaht executes the information state of one process

int main(int argc, char **argv)
{
	pid_t pid;
	int value;
	pid_t fork();
	int execvp();
	pid_t wait(int *status);
	pid_t waitpid(pid_t pid, int *status, int options);

	pid = fork();
	switch(pid) {
		case -1: /* error del fork() */
		   exit(-1);
		case 0: /* Child process */
		   if (execvp(argv[1], &argv[1]) < 0)
		   perror("exec");
		default: /*Father*/
		   while (wait(&value) != pid)

		   	if (value == 0)
		   	   printf("The instruction was executed normally\n");
		   	else {
		   	   if (WIFEXITED(value))
		   	   	  printf("The child finished normally and its returned value was %d\n", WEXITEDSTATUS(value));

		   	   if (WIFSIGNALED(value))
		   	   	  printf("The son finished receiving the signal %d\n", WTERMSIG(value));
		   	}
	}
}
