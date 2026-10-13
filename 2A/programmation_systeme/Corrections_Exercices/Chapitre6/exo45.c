#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  pid_t pid = atoi(argv[1]);
  fprintf(stdout,"envoi du signal au processus %i\n",pid);

  kill(pid, SIGUSR1);
  
  exit(EXIT_SUCCESS);
}
	 
