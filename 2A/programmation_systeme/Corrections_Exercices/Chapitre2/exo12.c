#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  FILE *fd = NULL;

  fprintf(stdout,"Coucou\n");
  
  fd = freopen("output.txt","w+",stdout);

  fprintf(stdout,"Coucou2\n");

  fclose(fd);
  
  fprintf(stdout,"Coucou3\n");


  exit(EXIT_SUCCESS);
}
