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

void *f1(void *arg){
  fprintf(stdout,"Coucou\n");
  return NULL;
}

void *f2(void *arg){
  fprintf(stdout,"Hello\n");
  return NULL;
} 

int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
  void *(*f_ptr_array[])(void *) = {f1,f2};

  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_create(tids+i,NULL,f_ptr_array[i%2], NULL);
  }

  sleep(5);
  exit(EXIT_SUCCESS);
}
	 
