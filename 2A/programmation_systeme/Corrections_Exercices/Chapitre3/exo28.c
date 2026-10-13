#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_FILS 5 


int main(int argc, char **argv)
{
  pid_t fils[NUM_FILS];
  int toto = 0;
  int idx;

  for(idx = 0 ; idx < NUM_FILS ; idx++)
    {
      fils[idx] = fork();
      if( 0 == fils[idx])
	{
	  pid_t pid = getpid();
	  usleep(pid+1000);	  
	  exit(33+idx);
	}
      else{
	fprintf(stdout,"===== Creation du fils : %i\n",fils[idx]);
      }
    }
  
  while(++toto);	
  
  for(idx = NUM_FILS - 1 ; idx >= 0 ; idx--)
    {      
      pid_t fils2 = waitpid(fils[idx],NULL,0);
      fprintf(stdout,"Fils %i termine \n",fils2);
    }  
    
  return EXIT_SUCCESS;
}
