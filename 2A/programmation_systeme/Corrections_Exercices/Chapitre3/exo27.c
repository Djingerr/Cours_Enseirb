#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = fork();
  
  if(0 == child){
    short int toto = 0; 

    fprintf(stdout,"E: Je suis  %i\n",getpid());
    fprintf(stdout,"E: parent %i\n",getppid());

    while(++toto);

    exit(33);
  } else if (child > 0){ 
    pid_t fini = -1; 
    int status = 0;

    fprintf(stdout,"P: creation enfant %i\n",child);
    
    fini = wait(&status);
    fprintf(stdout,
	    "P: le processus %i est fini, valeur de retour = %i\n",
	    fini,
	    WEXITSTATUS(status));
  }
  
  exit(EXIT_SUCCESS);
}
	 
