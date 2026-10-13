#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{

  fprintf(stdout,"Hello World");

  fork();
  
  fprintf(stdout,"Hello World\n");
  
  exit(EXIT_SUCCESS);
}
	 
