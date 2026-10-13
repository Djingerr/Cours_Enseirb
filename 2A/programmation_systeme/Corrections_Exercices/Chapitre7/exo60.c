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

_Thread_local int variable = 0;

void *thread_func(void *arg){
  int indice = *(int *)arg;
  variable += indice; 
  fprintf(stdout,"Thread[%i] === %i\n",indice,variable);    
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
  int       indices[NTHREADS] = {0};
  
  for(int i = 0 ; i < NTHREADS ; i++){
    indices[i] = i;
    pthread_create(tids+i,NULL,
		   thread_func,
		   (void *)(indices+i));
  }
  
  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_join(tids[i],NULL);
  }
  
  exit(EXIT_SUCCESS);
}
	 
