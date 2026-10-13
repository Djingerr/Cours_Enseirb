#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

volatile sig_atomic_t signaled = 0;

void handler(int sig)
{
  if(SIGUSR1 == sig){
    write(STDOUT_FILENO,"SIGUSR1 recu\n",14);
    signaled++;
  } else if (SIGUSR2 == sig){
    write(STDOUT_FILENO,"SIGUSR2 recu\n",14);
    signaled++;
  } else if (SIGSEGV == sig){
    write(STDOUT_FILENO,"SIGSEGV recu\n",14);
  }
}

int main(int argc, char *argv[])
{
  fprintf(stdout,"Mon pid est : %i\n",getpid());

  // Mise en place du masque pour bloquer SIGSEGV
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask,SIGSEGV);
  sigprocmask(SIG_BLOCK,&mask,NULL);

  // Mise en place du traitant pour SIGSEGV
  struct sigaction action;
  memset(&action,0,sizeof(struct sigaction));
  action.sa_handler = handler;
  sigaction(SIGSEGV,&action,NULL);

  // Mise en place du traitant pour SIGUSR1
  // On bloque automatiquement SIGUSR2 dans son traitant
  // pour eviter les problemes lors de l'incrementation
  // de la variable signaled
  sigaddset(&action.sa_mask,SIGUSR2);
  sigaction(SIGUSR1,&action,NULL);

  // Mise en place du traitant pour SIGUSR2
  // On bloque automatiquement SIGUSR1 dans son traitant
  // (meme raison que ci-dessus)
  sigaddset(&action.sa_mask,SIGUSR1);
  sigaction(SIGUSR2,&action,NULL);

  // Attente de SIGUSR1 et SIGUSR2
  while(signaled != 2){
    pause();
  }

  // Deblocage de SIGSEGV
  sigprocmask(SIG_UNBLOCK,&mask,NULL);
  
  exit(EXIT_SUCCESS);
}
