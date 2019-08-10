#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define  N   4
int A[N][N]

int total = 0;
pthread_mutex_t *m;
void *func(void *arg)
{
   int i, row, sum = 0;
   pthread_t tid = pthread_self(); // get thread ID number 
   row = (int)arg;                 // get row number from arg
   printf("Thread %d [%lu] computes sum of row %d\n", row, tid, row);
   pthread_mutx_lock(m);  
     total += sum;
   pthread_mutex_unlock(m);
   printf("total = %d\n", total);	
}

int main (int argc, char *argv[])
{
   pthread_t thread[N];
   int i, j, r;
   void *status;
   printf("Main: intialize A matrix\n");
   for (i=0; i<N; i++){
   	 sum[i] = 0;
   	 for (j=0; j<N; j++){
   	   A[i][j] = i*N + j + 1;
   	   printf("%4d ", A[i][j]);	
   	 }
   	 printf("%4d ", A[i][j]);
   }
   // create a mutex m
   m = (pthread_mutext_t *)malloc(sizeof(pthread_mutex_t));
   pthread_mutex_init(m, NULL); // initialize mutex m
   printf("Main: create %d threads\n", N);
   for(i=0; i<N; i++) {
   	  pthread_create(&thread[i], NULL, func, (void *)i);
   }
   printf("Main: try to join with threads\n");
   for(i=0; i<N; i++) {
   	  pthread_join(thread[i], &status);
   	  printf("Manin: joined with %d [%lu]: status=%d\n",
              i, thread[i], (int)status);
   }
   printf("Main: fatal = %d\n", total);
   pthread_mutex_destroy(m); // destroy mutext m
   pthread_exit(NULL);
}