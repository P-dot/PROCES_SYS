#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void main(int argc , char *argv)
{
   int i;
   
   printf("List of environment variables %s \n", argv[0]);
   for(i=0; environ[i] != NULL; i++)
       printf("environ[%d] = %s\n", i, environ[i]);
}
