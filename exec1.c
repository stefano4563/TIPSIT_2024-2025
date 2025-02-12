#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{

    int p2 = fork();

    if (p2 < 0)
    {
        printf("errore");
    }
    else if (p2 == 0)
    {
        if (argc < 2)
        {
            printf("numero di argomenti non corretto");
        }

        execl("/usr/bin/cat", "cat", argv[2], NULL);

        exit(0);
    }
}
