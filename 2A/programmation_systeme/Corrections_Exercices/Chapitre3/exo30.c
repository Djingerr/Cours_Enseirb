#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = -1;

  fprintf(stdout,"Parent: je suis : %i\n", getpid());
  
  child = fork();

  if( child > 0){
    fprintf(stdout,"Parent: Child : %i\n", child);
  } else if (0 == child){
    fprintf(stdout,"Enfant: je suis : %i\n", getpid());
    sleep(3);    
    fprintf(stdout,"Enfant: Parent : %i\n", getppid());
  }
  
  exit(EXIT_SUCCESS);
}
