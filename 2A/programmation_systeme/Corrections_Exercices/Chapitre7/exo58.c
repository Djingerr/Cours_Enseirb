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

void *thread_func(void *arg){
  int indice = *(int *)arg;
  fprintf(stdout,"Thread === %i\n",indice);
  
  int *resultat = malloc(sizeof(int));
  *resultat = 1;
  
  for(int i = 0; i < indice ; i++){
    (*resultat) *= 10;
  }

  pthread_exit((void *)resultat);
}

int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
  int       indices[NTHREADS] = {0};
  int      *results[NTHREADS] = {NULL};
  int       result = 0;
  
  for(int i = 0 ; i < NTHREADS ; i++){
    indices[i] = i;
    pthread_create(tids+i,NULL,
		   thread_func,
		   (void *)(indices+i));
  }
  
  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_join(tids[i],(void **)&(results[i]));
    result += *(results[i]);
  }

  fprintf(stdout,"Resultat = %i\n",result);
  
  exit(EXIT_SUCCESS);
}
	 
