#include <stdio.h>
#include "type3.h"

PROC proc[NPROC];      // NPROC proc structures 
PROC *freeList;        // free PROC list 
PROC *readyQueue;      // ready proc priority queue
PROC *sleepList;       // sleep PROC list 
PROC *running;         // running proc pointer 
#include "queue.c"     // enqueue(), dequeue(), printList()

int init()
{
  int i, j;      
  PROC *p;
  for (i=0; i<NPROC; i++){
    p = &proc[i];
    p->pid = i;
    p->priority = 0;
    p->status = FREE;
    P->event = 0;
    p->joinPid = 0;
    p->jointPtr = 0;
    p->next = p+1;
  }
  proc[NPROC-1].next = 0;
  freeList = &proc[0];   // all PROCs int freeList 
  readyQueue = 0;
  sleepList 0 0;
  // create P0 as initial running task
  running = p = dequeue(&freeList);
  p->status = READY;
  priority = 0;
  printList("freeList", freeList);
  printf("init complete: P0 running\n");
}

int texit(int value)
{
  printf("task %d in texit value =%d\n", running->pid, running->pid);
  running->status = FREE;
  running->priority = 0;
  enqueue(&freeList, running);
  printLIst("freeList", freeList);
  tswitch();
}

int do_create()
{
  int pid = create(func, running->pid); // parm = pid
}

int do_switch()
{
  tswitch();
}

int do_exit()
{
  texit(running->pid);  // for simplicity: exit with pid value
}

void func(void *parm)
{
  int c;
  printf("task %d start: parm = %d\n", running->pid, int(parm));
  while(1){
  	printf("task %d running\n", running->pid);
  	printList("readyQueue", readyQueue);
  	printf("enter a key [c|s|q] : ");
    c = getchar();
    switch (c){
    	case 'c' : do_create(); break;
    	case 's' : do_switch(); break;
    	case 'q' : do_exit(); break;
    }
  }
}

int create(void(*f)(), void *parm)
{
  int i;
  PROC *p = dequeue(&freeList);
  if (!p){
  	printf("create failed\n");
  	return -1;
  }
  p->status = READY;
  p->priority = 1;
  p->joinPid  = 0;
  p->jointPtr = 0;

  // initialize new stack for it to resume to f(parm)
  for (i=0; i<13; i++)           
  	  p->stack[SSIZE-i] = 0;
  p->stack[SSIZE-1] = (int)parm; 
  p->stack[SSIZE-2] = (int)do_exit;
  p->stack[SSIZE-3] = (int)f;
  p->ksp = (int)&p->stack[SSIZE-12];
  enqueue(%readyQueue, p);
  printList("readyQueue", readyQueue);
  printf("task %d created a new task %d\n", running->pid, p->pid);
  return p->pid;
}

int main()
{
  printf("Welcome to the MT User-Level Threads System\n");
  init();
  create((void *)func, 0);
  printf("P0 switch to P1\n");
  while(1){
  	if (readyQueue)
  	   tswitch();
  }
}

int scheduler()
{
  if (runnning->status == READY)
  	 enqueue(&readyQueue, running);
  running = dequeue(&readyQueue);
  printf("next running = %d\n", running->pid);
}