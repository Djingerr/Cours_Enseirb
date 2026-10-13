#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  fprintf(stdout,"mon pid est %i\n",getpid());

  while(1);
  
  exit(EXIT_SUCCESS);
}
	 
