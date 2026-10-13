#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t pid = atoi(argv[1]);

  kill(pid,SIGSEGV);
  sleep(2);
  kill(pid,SIGUSR1);
  sleep(2);
  kill(pid,SIGUSR2);
  
  fprintf(stdout,"All signals sent\n");
  
  exit(EXIT_SUCCESS);
}
