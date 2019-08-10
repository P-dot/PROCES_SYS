#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* We use "execl", to create a new process that substitute the program in the execution
   the process child not return at father process.*/

int main()
{
	if(execl("/usr/bin/ls","ls","-l", 0) == -1){
		puts ("error en /usr/bin/ls");
		exit(1);
	}
else
	printf("Esto no se imprime nunca");
}