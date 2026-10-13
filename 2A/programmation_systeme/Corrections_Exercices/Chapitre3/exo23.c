#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = fork();
  
  if(0 == child){
    fprintf(stdout,"E: parent %i\n",getppid());    
  } else if ( child > 0 ){ 
    fprintf(stdout,"P: creation enfant %i\n",child);
  }
  
  exit(EXIT_SUCCESS);
}
	 
