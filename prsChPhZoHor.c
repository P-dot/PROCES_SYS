#include <unistd.h>
#include <stdio.h>

int var = 22;

int main(void)
{
    pid_t pidC;
    int getpid();

    printf("*** proc. PID = %d begins ** \n", getpid());
    pidC = fork();

    printf("process . PID = %d , pidC = %d running \n", getpid(), pidC);

    if(pidC > 0)
    {
       var = 44;
    }
    else if(pidC == 0)
    {
       var = 33;
    }
    else
    {
    
    }

    while(1)
    {
       sleep(2);
       printf("proc. PID = %d, var = %d running \n", getpdid(), var);
    }
    return 0;
    
}
