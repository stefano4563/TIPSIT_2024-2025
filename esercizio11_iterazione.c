#include <stdio.h>

int main()
{
    int numero;
    int somma = 0, contatore = 0;
    
    do{
        printf("inserisci numero \n");
        scanf("%d", &numero);
    }while(numero <= 0);
    
    contatore = numero;
    
    for(int i = 0; i < contatore; i++){
        if(numero%2 != 0){
            somma = somma + numero;
        }
        numero--;
    }
    
    printf("la somma vale dei primi numeri dispari vale: %d", somma);
    
    
    return 0;
}