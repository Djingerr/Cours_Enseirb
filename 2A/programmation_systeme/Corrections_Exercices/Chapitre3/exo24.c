#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = -1;

  fprintf(stdout,"P: je suis : %i\n", getpid());
  
  child = fork();

  if( child > 0){
    fprintf(stdout,"P: Child : %i\n", child);
  } else if (0 == child){
    fprintf(stdout,"E: je suis : %i\n", getpid());
    fprintf(stdout,"E: Parent : %i\n", getppid());
  }
  
  exit(EXIT_SUCCESS);
}
	 
