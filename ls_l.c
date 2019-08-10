#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   pid_t pid;
   int status;

   pid = fork();
   switch(pid){
      case -1: /* error in fork function */
	 exit(-1);
      case 0: /* child process */
	 execlp("ls","ls","-l",NULL);
	 perror("exec");
	 break;
      default: /* father */
	 printf("Father process\n");
   }
}
