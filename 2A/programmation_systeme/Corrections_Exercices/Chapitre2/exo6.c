#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  int fd = -1;
  int valeur = 33;
  int ret = -1;
  
  fd = open("mon_fichier", O_RDWR | O_CREAT , S_IRWXU);
  assert(fd > 0);
  
  ret = write(fd, &valeur, sizeof(valeur));
  assert(ret != -1);

  close(fd);
  
  exit(EXIT_SUCCESS);
}
	 
