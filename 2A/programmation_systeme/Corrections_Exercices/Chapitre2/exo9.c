#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  int fd = -1;

  fd = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
  assert(fd != -1);

  close(STDOUT_FILENO);
  dup(fd);
  
  fprintf(stdout,"Hello World!\n");
  fprintf(stdout,"Coucou\n");

  close(fd);
  exit(EXIT_SUCCESS);
}
	 
