//Sleep operation, adding an event field to the PROC structure and implementing a ksleep(in event function)
//which let a process go to sleep.
//Here we shall assume that the PROC structure is modified 

typedef struct proc{
    struct proc *next;       // next proc pointer 
    int *ksp;                // saved sp: at byte offset
    int pid;                 // PROC status=FREE|READY, etc 
    int status;              // scheduling priority
    int event;               // event value to slepp on
    int exitCode;            // exut value
    struct proc *child;      // first child PROC pointer 
    struct proc *sibling;    // sibling PROC pointer
    struct proc *parent;     // parent PROC pointer 
    int   kstack[1024];      // process stack
}PROC;

/*ALGORITHM OF ksleep()
1. recond event value in PROC.event: running->event = event;
2. change status to SLEEP:           running->status = SLEEP;
3. for ease of mantineance, enter caller into a PROC *sleepList 
                                     enqueue(&sleepList, running);
give up CPU:                         tswitch
*/