#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char *argv[])
{

    int p2 = fork();

    if (p2 < 0)
    {
        printf("errore");
    }
    else if (p2 == 0)
    {
        execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);

        exit(0);
    }
}
