#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  int fd    = -1;
  off_t pos = 2;
  char val  = 0;

  assert(3 == argc); 
  
  //unlink(argv[1]);
  
  fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

  for(int i = 1 ; i <= atoi(argv[2]) ; i++ , pos *= 2)
    {
      val = 'a';
      lseek(fd, pos, SEEK_SET);
      fprintf(stdout,"Write %c at pos %li\n",val,pos);
      write(fd, &val, sizeof(char));
    }

  close(fd);
  
  return 0;
}
