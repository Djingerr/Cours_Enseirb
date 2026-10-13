#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>

void super_traitant(int signum)
{
  char *str = "Coucou!\n";
  write(STDOUT_FILENO, str, strlen(str));
}

int main(int argc, char *argv[])
{
  fprintf(stdout,"mon pid est %i\n",getpid());

  struct sigaction action;
  memset(&action,0,sizeof(struct sigaction));
  action.sa_handler = super_traitant;
  
  sigaction(SIGUSR1, &action, NULL);
  
  
  while(1);
  
  exit(EXIT_SUCCESS);
}
	 
