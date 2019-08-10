#include <sys/types.h>
#include <stdio.h>

int main()
{
   pid_t pid;
   pid_t fork();
   pid_t getpid(void);
   pid_t getppid(void);

   int i;
   int n = 10;

   for (i = 0; i < n; i++){
      pid = fork();
      if (pid != 0)
	 break;
   }
   printf("The father of the process %d is %d\n", getpid(), getppid());
}
