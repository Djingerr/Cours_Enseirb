#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char **argv)
{
  assert( 3 == argc);
  
  pid_t  pid, pid2;    
  int    fd;
  size_t map_size = (size_t)sysconf(_SC_PAGE_SIZE);
  
  fd = open(argv[1],O_RDWR|O_CREAT|O_EXCL,S_IRUSR|S_IWUSR);
  if (fd != -1) ftruncate(fd,map_size);
  close(fd);
  
  pid = fork();
  
  if(pid > 0){
    pid2 = fork();
    if (pid2 == 0){	
      execlp("./reader","reader",
	     argv[1],argv[2],NULL);
    } else if (pid2 > 0){
      waitpid(pid,NULL,0);
      waitpid(pid2,NULL,0);
    }
  } else if (pid == 0){
    execlp("./writer","writer",argv[1],argv[2],NULL);
  }
  
  unlink(argv[1]);
  exit(EXIT_SUCCESS);
}

  
