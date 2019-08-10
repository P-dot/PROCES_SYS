#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void MySignalHandler(int sig)
{
    printf("Signal number is %d \n", sig);
}

int main(void)
{   
    signal(SIGIO, &MySignalHandler);
    while(1)
    {
        printf("zzzzZZZzzz \n");
    }
    return 0;
}
