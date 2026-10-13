#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

#if VERSION == 1
int main(int argc, char *argv[])
{
  int fd = -1;
  char tmp;

  fd = open("input.txt",O_RDONLY);

  while(read(fd, &tmp, sizeof(char))){
    fprintf(stderr,"%c",tmp);
  }

  close(fd);
  exit(EXIT_SUCCESS);
}

#elif VERSION == 2
int main(int argc, char *argv[])
{
  FILE *file = NULL;
  char tmp;

  file = fopen("input.txt","r");

  // tmp = getc(file) est equivalent a
  // fread(&tmp,sizeof(char),1,file);
  // getc permet de tester un caractere
  // particulier, le caractere EOF (End-Of-File)
  
  while( (tmp = getc(file)) != EOF){
    fprintf(stderr,"%c",tmp);
  }
  
  fclose(file);
  exit(EXIT_SUCCESS);
}

#else // VERSION == 3
int main(int argc, char *argv[])
{
  FILE *file = NULL;
  char tmp;

  file = fopen("input.txt","r");

  tmp = getc(file);
  while( !feof(file)){
    fprintf(stderr,"%c",tmp);
    tmp = getc(file);
  }

  fclose(file);
  exit(EXIT_SUCCESS);
}

#
#endif
