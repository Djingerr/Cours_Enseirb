```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    int value = 33;
    char *str = "33";
    ssize_t ret = 0;

    fd = open("toto.truc", O_RDWR | O_CREAT, S_IRWXU);
    assert(fd > 0);

    ret = write(fd, &value, sizeof(value));
    assert(ret>0);
    
    ret=write(fd, str, sizeof(char)*strlen(str));
    assert (ret>0);
	
    exit(EXIT_SUCCESS);
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    int value = 33;
    ssize_t ret = 0;
    int value2;

    fd = open("toto.truc", O_RDWR | O_CREAT, S_IRWXU);
    assert(fd > 0);

    ret = write(fd, &value, sizeof(value));
    assert(ret>0);
    
    close(fd);
    
    ret=read(fd, &value2, sizeof(int));
    assert(ret>0);
    
    fprintf(stdout, "valeur lue = %i\n", value2)
	
	close(fd);
	
    exit(EXIT_SUCCESS);
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    ssize_t ret = 0;
    off_t pos = 2;

    assert(argc >= 3);

    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd >= 0);

    for (int i = 1; i <= atoi(argv[2]); i++)
    {
        char c = 'a';

        lseek(fd, pos, SEEK_SET);

        ret = write(fd, &c, sizeof(c));
        assert(ret > 0);

        printf("Écriture de '%c' à la position %ld\n", c, (long)pos);

        pos *= 2;
    }

    close(fd);

    exit(EXIT_SUCCESS);
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
  
int main(int argc, char *argv[]){
	
	int fd = open(output.txt, O_RDWR | O_CREAT, S_IRWXU);
	assert(fd != -1);

	close(STDOUT_FILENO);

	dup(fd);
	close(fd);

	printf("Hello World !\n");

	exit(EXIT_SUCCESS);
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    FILE *ret;

    // Redirige stdout vers output.txt/ Redirige stdout vers output.txt
    ret = freopen("output.txt", "w", stdout);
    assert(ret != NULL);

    // Ces lignes ne sont PAS modifiées
    fprintf(stdout, "Bonjour\n");
    fprintf(stdout, "La valeur est %d\n", 33);

    exit(EXIT_SUCCESS);
}
```
