#include <sys/types.h>
#include <stdio.h>

int main()
{
   uid_t getuid(void);
   uid_t geteuid(void);
   gid_t getgid(void);
   gid_t getegid(void);

   printf("User identifier: %d\n", getuid());
   printf("User effective identifier: %d\n", getuid()); 
   printf("Group identifier: %d\n", getgid());
   printf("Group effective identifier: %d\n", getegid());
}
