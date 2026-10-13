#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  // creation du tube
  mkfifo("/tmp/montube",S_IRUSR|S_IWUSR);

  //creation de l'enfant
  pid_t child = fork(); 
  
  if( 0 == child ){ //code de l'enfant
    char  *buffer = NULL;
    size_t taille = 0;
    
    int fd = open("/tmp/montube",O_RDONLY);

    //lecture depuis le tube : taille puis donnees
    read(fd, &taille, sizeof(size_t)); 
    buffer = malloc(taille*sizeof(char));
    read(fd, buffer, taille); 

    fprintf(stdout,"Message recu = %s\n", buffer);

    free(buffer);
    close(fd);
    
  } else if ( child > 0 ){ //code du parent
    char  *buffer = "Bonjour";
    size_t taille = strlen(buffer) + 1;
    
    int fd = open("/tmp/montube",O_WRONLY);

    // ecriture dans le tube : taille + donnees
    write(fd, &taille, sizeof(size_t));
    write(fd, buffer, taille);

    close(fd);
    
    waitpid(child, NULL, 0); // synchronisation avec l'enfant

    unlink("/tmp/montube"); // effacement du fichier
  }
  
  exit(EXIT_SUCCESS);
}
