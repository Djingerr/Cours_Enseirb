#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>


int main(int argc, char *argv[])
{
  
  int fd = open("toto.txt",
		O_RDONLY | O_CREAT,
		S_IRWXU );
  
  fprintf(stdout,"valeur de l'index = %i\n",fd);
  
  
  exit(EXIT_SUCCESS);
}
	 
