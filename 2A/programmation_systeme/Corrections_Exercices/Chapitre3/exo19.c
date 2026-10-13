#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t pid = -1;
  
  pid = getpid();

  fprintf(stdout,"Mon pid est = %i\n",pid);
  
  exit(EXIT_SUCCESS);
}
	 
