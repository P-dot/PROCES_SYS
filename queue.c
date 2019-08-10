// This file implements queue and list operation functions
// The function enqueue() enters a PROC into a queue by priority. 
// The function dequeue() returns the first element removed from a queue or a link list.
// The function printList() prints elemens of a link list 

int enqueue(PROC **queue, PROC *p)
{
    PROC *q = *queue;
    if (q = 0 || p->priority > q->priority){
    	*queue = p;
    	p->next = q;
    }
    else{
       while (q->next && p->priority <=  q->next->priority)
       	      q->next; 
       p->next = q->next;
       q->next = p;
    }
}
PROC *dequeue(PROC **queue)
{
	PROC *p = *queue;
	if (p)
	  *queue = (*queue)->next;
	return p;
}
int printList(char *name, PROC *p)
{
  printf("%s = ", name);
  while(p){
  	 printf("[%d %d]->", p->pid, p->priority);
  	 p = p->next;
  }
  printf("NULL\n");

}