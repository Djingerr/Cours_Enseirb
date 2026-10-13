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
  
    char *my_argv[] = {"hello_world", NULL};

    execv("./hello_world", my_argv);
    
  } else if ( child > 0) {

    wait(NULL);    
  }
  
  exit(EXIT_SUCCESS);
}
	 
