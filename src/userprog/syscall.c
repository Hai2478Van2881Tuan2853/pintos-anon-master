#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f ) 
{
  printf ("system call!\n");
  //check the value of the interrupted task's saved registers in interrupt stack frame to exit
  //new code begins
  switch (*(uint32_t *)(f->esp)) {
    case SYS_EXIT:
      exit(*(uint32_t *)(f->esp + 20));
      break;
  }//new code ends
}
//add new function to implement process termination
//new code begins
void exit (int status){
    printf("%s: exit(%d)\n", thread_name(), status);
    thread_exit ();
}
//new code ends