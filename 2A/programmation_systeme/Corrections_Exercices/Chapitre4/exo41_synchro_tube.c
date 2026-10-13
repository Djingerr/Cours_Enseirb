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
#include <sys/wait.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  assert(2 == argc);

  char  *base_addr = NULL;
  char  *curr_addr = NULL;
  size_t map_size  = sysconf(_SC_PAGE_SIZE);
  int    str_len   = strlen(argv[1])+1;
  int    tube[2];
  
  base_addr = (char *)mmap(NULL, map_size ,
			   PROT_READ | PROT_WRITE,
			   MAP_SHARED | MAP_ANONYMOUS,
			   -1 , 0);
  assert(base_addr != MAP_FAILED);
  
  curr_addr = base_addr;
  
  pipe(tube);
  
  pid_t child = fork();
  
  if(0 == child){
    char c = 0;
    
    close(tube[1]);
    
    read(tube[0],&c, sizeof(char)); //synchro    
    fprintf(stdout,"Lecture = %s\n", curr_addr);
    
    close(tube[0]);
    
  } else if (child > 0){
    char c = 'a';
    
    close(tube[0]);
    
    memset(curr_addr,0, map_size); 
    
    memcpy(curr_addr,argv[1],str_len+1);
    write(tube[1], &c, sizeof(char)); //synchro
    
    close(tube[1]);
    waitpid(child, NULL, 0);
  }
  
  munmap((void *)base_addr,map_size);
  return 0;
}

  
