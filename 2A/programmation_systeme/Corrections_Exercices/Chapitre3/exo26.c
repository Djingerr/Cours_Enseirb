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
    fprintf(stdout,"E: parent %i\n",getppid());
  } else if (child > 0){ 
    short int toto = 0; 
    pid_t fini = -1;

    fprintf(stdout,"P: creation enfant %i\n",child);
    while(++toto);

    fini = wait(NULL);
    
    fprintf(stdout,"P: le processus %i est fini\n",fini);    
  }
  
  fprintf(stdout,"Je suis  %i\n",getpid());
  
  exit(EXIT_SUCCESS);
}
	 
