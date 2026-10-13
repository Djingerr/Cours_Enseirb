#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = -1;

  child = fork();
  
  if( 0 == child){
  
    char *my_argv[] = {"exo5", NULL};
    int fd = -1;

    fd = open("toto.txt", O_RDONLY | O_CLOEXEC);
    fprintf(stdout,"Valeur de l'index de descripteur = %i\n",fd);
    fflush(stdout);
    
    execv("./exo5", my_argv);
    
  } else if ( child > 0) {

    wait(NULL);
    
  }
  
  exit(EXIT_SUCCESS);
}
	 
