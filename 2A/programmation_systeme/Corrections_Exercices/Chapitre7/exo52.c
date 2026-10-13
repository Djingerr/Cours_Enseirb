#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>

#define NTHREADS (2)

void *f(void *arg){
  int val = *(int *)arg;
  fprintf(stdout,"Coucou === %i\n",val);
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
  int args[] = {111,222};
  
  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_create(tids+i,NULL,f, (void *)&args[i]);
  }

  sleep(5);
  exit(EXIT_SUCCESS);
}
	 
