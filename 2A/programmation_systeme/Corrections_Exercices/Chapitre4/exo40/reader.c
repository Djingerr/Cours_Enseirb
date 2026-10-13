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
#include <assert.h>

int main(int argc, char **argv)
{
  assert(3 == argc);
  char  *base_addr = NULL;
  char  *curr_addr = NULL;
  char  *filename  = argv[1];
  size_t map_size  = sysconf(_SC_PAGE_SIZE); 
  int    fd;
  pid_t  pid;
    
  pid = getpid();
  fprintf(stdout,"[%i] === Reader launched\n", pid);
  
  fd = open(filename, O_RDWR); 
  base_addr = (char *)mmap(NULL, map_size,
			   PROT_READ | PROT_WRITE,
			   MAP_SHARED , fd , 0);
  close(fd);
  
  curr_addr = base_addr + sizeof(int);
  
  //while( *(volatile _Atomic int *)base_addr != 666)
  // si utilisation d'une variable atomique 
  while( *(volatile int*)base_addr != 666)
    fprintf(stdout,"[%i] === Reader in active wait, %i\n",
	    pid, *(volatile int*)base_addr);
  
  fprintf(stdout,"[%i] === Reader string : %s\n", pid, curr_addr);
  fflush(stdout);
  
  munmap((void *)base_addr, map_size);
  return 0;
}

  
