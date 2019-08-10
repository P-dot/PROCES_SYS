#include <sys/types.h>
#include <stdio.h>

int main()
{
   pid_t id_process;
   pid_t id_father;

   pid_t getpid(void);
   pid_t getppid(void); 

   id_process = getpid();
   id_father = getppid();

   printf("Process identifier: %d\n", id_process);
   printf("Parent process identifier: %d\n", id_father);

   return 0;
}
