#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>

#define NTHREADS (10)

void *f(void *arg){
  int toto = 0;
  while(++toto);
    
  fprintf(stdout,"Coucou\n");

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
    
  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_create(tids+i,NULL, f, NULL);
  }

  
  pthread_exit(NULL);
  //exit(EXIT_SUCCESS);
}
	 
