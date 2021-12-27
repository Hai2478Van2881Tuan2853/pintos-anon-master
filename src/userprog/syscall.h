#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H
#include "lib/user/syscall.h"

void syscall_init (void);
void exit (int status);//add new function to implement process termination, add by students
#endif /* userprog/syscall.h */
