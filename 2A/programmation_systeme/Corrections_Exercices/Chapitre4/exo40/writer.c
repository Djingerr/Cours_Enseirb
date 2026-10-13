#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdatomic.h>
#include <assert.h>

int main(int argc, char **argv)
{
  assert(3 == argc);

  char  *base_addr = NULL;
  char  *curr_addr = NULL;
  char  *filename  = argv[1];
  size_t map_size  = sysconf(_SC_PAGE_SIZE);
  int    fd;
  
  fprintf(stdout,"[%i] === Writer launched\n",getpid());
  
  fd = open(filename,O_RDWR);
  base_addr = (char *)mmap(NULL, map_size ,
			   PROT_READ | PROT_WRITE,
			   MAP_SHARED , fd , 0);
  close(fd);   

  memset(base_addr,0,map_size);


  curr_addr = base_addr + sizeof(int);
  memcpy(curr_addr, argv[2], strlen(argv[2])+1);
  
  // Solutions with explicit barrier:
  
  //1- __sync_synchronize();
  // GCC built-in memory barrier (CPU and Compiler).
  // Not portable. 
  
  //2-  Portable Memory barrier (since C11) :
  atomic_thread_fence(memory_order_seq_cst);   
  // Note: Sequential consistency (seq_cst) is
  //       the default memory order in C  
  *( volatile int *)base_addr = 666;
  
  //3-  Solution with implicit barrier:
  //*(volatile _Atomic int *)base_addr = 666;
  //_Atomic (C11) enforces portably
  // memory (sequential) consistency 
  
  munmap((void *)base_addr,map_size);
  return 0;
}

  
