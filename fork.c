#include <sys/types.h>
#include <stdio.h>

int main(){
    
    pid_t pid;
    pid_t fork();
    pid_t getpid(void);
    pid_t getppid(void);

    pid = fork();
    switch(pid){
       case -1: /* error from fork() */
       perror("fork");
       break;
    case 0:    /* child process */
       printf("Process %d; father = %d \n", getpid(), getppid());
       break;
    default: /*Father*/
       printf("Process %d; father = %d \n", getpid(), getppid());
    }
}
