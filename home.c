#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *getenv(const char *name);
   
   char *home = NULL;
   home = getenv("HOME");
   if (home == NULL)
      printf("HOME is not defined\n");
   else
      printf("The value of home is %s\n", home);
}
