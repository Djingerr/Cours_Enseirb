#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int somme = 0;

  while(*++argv)
    somme += atoi(*argv);

  fprintf(stdout,"Somme = %i\n", somme);

  exit(EXIT_SUCCESS);
}
