#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  fork();
  
  fprintf(stdout,"Mon pid est = %i\n",getpid());
    
  exit(EXIT_SUCCESS);
}
	 
