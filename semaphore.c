#include <stdio.h>
#include "type.h"
PROC proc[NPROC], *freeList, *sleepList, *readyQueue, *running;
#include "queue.c" 
#include "wait.c"

#define NBUF 4
#define N    8
int buf[NBUF], head, tail;  // buffers for producer-consumer 

typedef struct{
   int value;
   PROC *queue;
}SEMAPHORE;
SEMAPHORE full, empty, mutex; // semaphores 

int P(SEMAPHORE *s)
{  // implement P function }
int V(SEMAPHORE *s)
{  // implement V function }

void producer()             // produce task code 
{
   int i;
   printf("producer %d start\n", running->pid);
   for (i=0, i<N; i++){
      P(&empty);
      P(&mutex);
       buf[head++] = i+1;
       printf("producer %d: item = %d\n", running->pid, i+1);
       head %= NBUF;
      V(&mutex);
      V(&full);
   }
   printf("producer %d exit\n", running->pid);
}

void consumer()            // consumer task void
{
   int i, c;
   printf("consumer %d start\n", running->pid);
   for (i=0; i<N; i++) {
      P(&full);
      P(&mutex);
        c = buf[tail++];
	tail %= NBUF;
	printf("consumer %d: got item = %d\n", running->pid, c);
      V(&mutex);
      V(&empty);
   }
   printf("consumer %d exit\n", running->pid);
}

int init()
{
   int i, j;
   PROC *p;
   for (i=0; i<NPROC; i++){
      p = &proc[i];
      p->pid = i;
      p->ppid = 1;
      p->priority = 0;
      p->status = FREE,
      p->event = 0;
      p->next = p+1;
   }
   proc[NPROC-1].next = 0;
   freeList = &proc[0];
   readyQueue = 0;
   sleepList = 0;
   p = running = dequeue(&freeList);
   p->status = READY;
   p->priority = 0;
   printList("freeList", freeList);

   // initialize semaphores full, empty, mutex
   head = tail = 0;
   full.value = 0; full.queue = 0;
   empty.value=NBUF; empty.queue = 0;
   mutex.value = 1; mutex.queue = 0;
   printf("init complete\n");
}
int myexit(){ texit(0); }

int task1()
{
   int status;
   printf("task %d creates producer-consumer tasks\n", running->pid);
   create((void *)producer, 0);
   create((void *)consumer, 0);
   join(2, &status);
   join(3, &status);
   printf("task %d exit\n", running->pid);
}

int create(void (*f)(), void *parm)
{
   int i;
   PROC *p = dequeue(&freeList);
   if (!p){
      printf("fork failed\n");
      return -1;
   }
   p->pid = running->pid;
   p->status = READY;
   p->priority = 1;
   p->joinPid = 0;
   for (i=1; i<12; i++){
      p->stack[SSIZE-i] = 0;
      p->stack[SSIZE-1] = (int)parm;
      p->stack[SSIZE-2] = (int)myexit;
      p->stack[SSIZE-3] = (int)f;
      p->ksp = &p->stack[SSIZE-12];
   }
   enqueue(&readyQueue, p);
   return p->pid;
}

int main()
{
   printf("Welcome to the MT User-Level Threads System\n")
   init();
   create((void *)task1, 0);
   printf("P0 switch to P1\n");
   tswitch();
   printf("all task ended: P0 loops\n");
   while(1);
}

int scheduler()
{
   if (running->status == READY)
      enqueue(&readyQueue, running);
   running = dequeue(&readyQueue);
}


