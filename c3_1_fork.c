/*int pid = fork();
if (pid){
	// parent executes this part 
}
else {
   // child executes this part
} */

#include <stdio.h>
int main()
{
	int pid;
	printf("THIS IS %d MY PARENT=%d\n", getpid(), getppid);
	pid = fork(); // fork syscall; parent returns child pid,
	if (pid){ // PARENT EXECUTES THIS PART
	   printf("THIS IS PROCESS %d CHILD PID=%d\n", getpid(), pid);
	} 
	else{
	   printf("This is process %d parent=%d\n", getpid(), getppid());
	}
}
