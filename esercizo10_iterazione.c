#include <stdio.h>

int main()
{
    int numero, contatore = 0;
    int somma = 0;
    do{
        printf("inserire un numero intero positivo \n");
        scanf("%d", &numero);
    }while(numero <= 0);
    
    contatore = numero;
    
    for(int i = 0; i < contatore; i++){
        somma = somma + numero;
        numero--;
    }

    printf("la somma è uguale a: %d", somma);
    return 0;
}