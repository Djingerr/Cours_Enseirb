#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  for(int i = 0 ; i < 10 ; i++){
    pid_t child = fork();
    if(0 == child)
      break;
    else
      fprintf(stdout,"creation enfant %i\n",child);
  }  
  exit(EXIT_SUCCESS);
}
	 
