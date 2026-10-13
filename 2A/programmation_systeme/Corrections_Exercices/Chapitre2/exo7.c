#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  int fd = -1;
  int fd2 = -1;
  int valeur = 33;
  int ret = -1;
  int valeur2 = 0;
  
  fd = open("mon_fichier", O_RDWR | O_CREAT , S_IRWXU);
  assert(fd > 0);
  
  ret = write(fd, &valeur, sizeof(valeur));
  assert(ret != -1);

  fd2 = open("mon_fichier", O_RDONLY);
  assert(fd > 0);
  
  ret = read(fd2, &valeur2, sizeof(valeur2));
  assert(ret != -1);

  fprintf(stdout,"Entier lu = %i\n",valeur2);
  
  close(fd);
  close(fd2);
  
  exit(EXIT_SUCCESS);
}
	 
