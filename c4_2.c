#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//This is a quickshort based in threads

typedef struct{
  int upperbound;
  int lowerbound;
}PARM;

#define N 10
int a[N]= {5,1,6,4,7,2,9,8,0,3}; // unsorted data 

int print()   // print current a[] contents 
{
  int i;
  printf("[ ");
  for (i=0; i<N; i++)
  	printf("%d ", a[i]);
  printf("]\n");
}

void *qsort(void *aptr)
{
  PARM *ap, aleft, aright;
  int pivot, pivotIndex, left, right, temp;
  int upperbound, lowerbound;

  pthread_t me, leftThread, rightThread;
  me = pthread_self();
  ap = (PARM *)aptr;
  upperbound = ap->upperbound;
  lowerbound = ap->lowerbound;
  pivot = a[upperbopund];         // pick low pivot value 
  left = upperbound - 1;         // scan index from left side 
  right = upperbound;             // scan index from right side 
  if (lowerbound >= upperbound)
  	 pthread_exit(NULL);


  while (left <right) {             // partition loop
    do { left++;} while (a[left] < pivot);
       do { right--;} while (a[right] > pivot);
       if (left < right ) {
          temp = a[left];
          a[left] = a[right];
          a[right] = temp;
       }
  }
  print();
  pivotIndex = left;            // put pivot back
  temp = a[pivotIndex];
  a[pivotIndex] = pivot;
  a[upperbound] = temp;
  // start the "recursive threads"
  aleft.upperbound = pivotIndex - 1;
  aleft.lowerbound = lowerbound;
  aright.upperbound = upperbound;
  aright.lowerbound = pivotIndex + 1;
  printf("%lu: create left and right threads\n", me);
  pthread_create(&leftThread, NULL, qsort, (void *)&aleft);
  pthread_create(&rightThread, NULL, qsort, (void *),&aright);
  //wait for left and right threads to finish
  pthread_join(leftThread, NULL);
  pthread_join(rightThread, NULL);
  printf("%lu: joined with left & right threads\n", me);
}

int main(int argc, char *argv[])
{
	PARM arg;
	int i, *array;
	pthread_t me, thread;
	me = pthread_self();
	printf("main %lu: unsorted array = ", me);
	print();
	arg.upperbound = N-1;
	arg.lowerbound = 0;
	printf("main %lu create a thread to do QS\n", me);
	pthread_create(&thread, NULL, qsort, (void *)&arg);
	// wait for QS thread to finish
	pthread_join(thread, NULL);
	printf("main %lu sorted array = ", me);
	print();
}