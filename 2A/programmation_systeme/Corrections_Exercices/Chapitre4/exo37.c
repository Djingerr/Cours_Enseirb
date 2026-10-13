#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  pid_t child = -1;
  int tube[2];

  pipe(tube); //creation du tube anonyme
  
  child = fork(); //creation de l'enfant
  
  if( 0 == child){ //code de l'enfant
    char *buffer  = NULL;
    size_t taille = 0;
    
    close(tube[1]); //enfant lecteur = fermeture 
                    //de l'extremite en ecriture 

    // Protocole : lecture taille/allocation/lecture donnees
    read(tube[0],&taille,sizeof(size_t));
    buffer = malloc(taille*sizeof(char));
    read(tube[0],buffer,taille); //lecture depuis le tube

    fprintf(stdout,"Message recu = %s\n", buffer);

    free(buffer);
    
    close(tube[0]); //fermeture de l'extremite en lecture
    
  } else if ( child > 0) { //code du parent
    char *buffer  = "Coucou";
    size_t taille = strlen(buffer)+1;
    
    close(tube[0]); //parent ecrivain = fermeture
                    //de l'extremite en lecture

    // Protocole : ecriture taille puis ecriture donnees
    write(tube[1], &taille, sizeof(size_t));
    write(tube[1], buffer, strlen(buffer)+1); // ecriture dans 
                                              // le tube 
    close(tube[1]); //fermeture de l'extremite en ecriture
    
    waitpid(child,NULL,0); // synchronisation avec l'enfant
  }
  
  exit(EXIT_SUCCESS);
}
