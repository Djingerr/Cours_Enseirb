#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>
#include <pthread.h>

#define NTHREADS (3)

void traitant(int sig){
  if(SIGUSR1 == sig){
    write(STDOUT_FILENO,"signal SIGUSR1\n",15);
  } else if (SIGUSR2 == sig){
    write(STDOUT_FILENO,"signal SIGUSR2\n",15);
  }
}

void *f1(void *arg){
  fprintf(stdout,"=== Thread 1\n");
  pause();
  fprintf(stdout,"=== Thread 1 sorti de pause\n");
  pthread_exit(NULL);
}

void *f2(void *arg){
  fprintf(stdout,"=== Thread 2\n");
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask,SIGUSR1);

  //On debloque SIGUSR1 pour le thread 2
  pthread_sigmask(SIG_UNBLOCK, &mask, NULL);
  pause();
  fprintf(stdout,"=== Thread 2 sorti de pause\n");
  
  pthread_exit(NULL);
}

void *f3(void *arg){
  fprintf(stdout,"=== Thread 3\n");
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask,SIGUSR2);

  //On debloque SIGUSR2^ pour le thread 3
  pthread_sigmask(SIG_UNBLOCK, &mask, NULL);
  pause();
  fprintf(stdout,"=== Thread 3 sorti de pause\n");
  
  pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
  pthread_t tids[NTHREADS];
  void *(*f_ptr[])(void *) = {f1, f2, f3};

  fprintf(stdout," === pid = %i\n",getpid());

  //Mise en place des masques pour *tous* les threads
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask,SIGUSR1);
  sigaddset(&mask,SIGUSR2);  
  pthread_sigmask(SIG_BLOCK, &mask, NULL);

  // Mise en place des traitants pour tous les threads
  struct sigaction action = {0};
  action.sa_handler = traitant;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
    
  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_create(tids+i, NULL, f_ptr[i%NTHREADS], NULL);
  }

  for(int i = 0 ; i < NTHREADS ; i++){
    pthread_join(tids[i],NULL);
  }
  
  exit(EXIT_SUCCESS);
}
	 
