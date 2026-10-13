#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  int fd = -1;
  FILE *file = fopen("output.txt","r");
  assert(file);

  fd = open("output.txt", O_RDONLY);
  assert(fd != -1);

  fprintf(stdout,"Valeur de fd = %i\n",fd);

  
  exit(EXIT_SUCCESS);
}
	 
