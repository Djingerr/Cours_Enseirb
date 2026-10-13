#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>

#if VERSION_GROUPE == 1
int main(int argc, char *argv[])
{
  int index = 0;
  int tube1[2];
  int tube2[2];

  pipe(tube1);
  pipe(tube2);

  for(index  = 0 ; index < 3 ; index++){
    pid_t child = fork();
    if(0 == child)
      break;
  }

  if(0 == index){ /* enfant #0 */
    close(tube1[0]);
    close(tube2[0]);

    close(tube2[1]);

    /* redirection de stdout */
    close(STDOUT_FILENO);
    dup(tube1[1]);
    close(tube1[1]);

    execlp("cat","cat","toto.txt",NULL);
    
  } else if (1 == index){ /* enfant #1 */
    close(tube1[1]);
    close(tube2[0]);

    close(STDIN_FILENO);
    dup(tube1[0]);
    close(tube1[0]);

    close(STDOUT_FILENO);
    dup(tube2[1]);
    close(tube2[1]);

    execlp("grep","grep","truc", NULL);
    
  } else if (2 == index){ /* enfant #2 */
    close(tube1[0]);

    close(tube1[1]);
    close(tube2[1]);

    close(STDIN_FILENO);
    dup(tube2[0]);
    close(tube2[0]);

    execlp("wc","wc","-l",NULL);
    
  } else if (3 == index){ /* parent */
    close(tube1[0]);
    close(tube1[1]);
    close(tube2[0]);
    close(tube2[1]);
    
    for(index  = 0 ; index < 3 ; index++)
      wait(NULL);
  }
  
  exit(EXIT_SUCCESS);
}
#else //VERSION_GROUPE == 2
int main(int argc, char *argv[])
{
  pid_t child = -1;
  int tube1[2];

  pipe(tube1);
  
  child = fork();

  if(child > 0){ /* code parent */
    close(tube1[1]); /* lecteur uniquement */

    /* redirection stdin */
    close(STDIN_FILENO);
    dup(tube1[0]);
    close(tube1[0]);

    /* execution de la commande finale */
    execlp("wc", "wc", "-l", NULL);
    
  } else if(0 == child){ /* code de l'enfant */
    int   tube2[2];
    pid_t child2 = -1;
    
    close(tube1[0]); /* ecrivain sur tube1 */

    pipe(tube2);

    child2 = fork();

    if(child2 > 0){ /* parent */
      close(tube2[1]);

      /* redirection stdout */
      close(STDOUT_FILENO);
      dup(tube1[1]);
      close(tube1[1]);

      /* redirection stdin */
      close(STDIN_FILENO);
      dup(tube2[0]);
      close(tube2[0]);
      
      execlp("grep", "grep", "truc", NULL);
      
    } else if ( 0 == child2) { /* enfant 2 */
      close(tube1[1]);
      close(tube2[0]);

      /* redirection stdout */
      close(STDOUT_FILENO);
      dup(tube2[1]);
      close(tube2[1]);

      execlp("cat","cat", "toto.txt", NULL );
    }
  }
  exit(EXIT_SUCCESS);
}
#endif
