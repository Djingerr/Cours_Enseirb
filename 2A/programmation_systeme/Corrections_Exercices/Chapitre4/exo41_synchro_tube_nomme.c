#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <assert.h>

int main(int argc, char **argv)
{
  assert( 2 == argc);
  
  char  *base_addr = NULL;
  pid_t  pid;    
  int    fd;
  size_t map_size = (size_t)sysconf(_SC_PAGE_SIZE);
  
  //tube pour la synchronisation
  mkfifo("/tmp/montube", S_IRUSR | S_IWUSR);

  //creation de la zone de memoire partagee
  base_addr = (char *)mmap(NULL, map_size ,
			   PROT_READ  | PROT_WRITE,
			   MAP_SHARED | MAP_ANONYMOUS,
			   -1, 0);
  pid = fork(); // creation du processus-enfant
  
  if(pid > 0){ //Code du parent
    size_t str_len = strlen(argv[1]) + 1;

    //Copie en memoire partagee
    memcpy(base_addr, argv[1], str_len );

    //synchronisation
    fd = open("/tmp/montube",O_WRONLY); 

    //attente terminaison de l'enfant
    waitpid(pid,NULL,0);
    
    close(fd);
    unlink("/tmp/montube");	  

  } else if (0 == pid){ // Code de l'enfant

    // synchronisation
    fd = open("/tmp/montube",O_RDONLY); 

    //Lecture en memoire partagee
    fprintf(stdout,"String is : %s\n", base_addr);

    close(fd);
  }
    
  munmap((void *)base_addr, map_size); 
  return 0;
}

