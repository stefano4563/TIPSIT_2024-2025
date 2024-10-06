#include <stdio.h>

int main()
{
    int numero1, numero2;
    int moltiplicazione = 0;
    int somma = 0;
    int cont = 0;
    
    do{
        cont++;
        printf("inserisci numero1: \n");
        scanf("%d", &numero1);
        
        printf("inserisci numero2: \n");
        scanf("%d", &numero2);
        
        moltiplicazione = numero1 * numero2;
        somma = moltiplicazione + cont;
        
        int *p;
        p = &moltiplicazione;
        
        printf("moltiplicazione = %d \n", *p);
        printf("somma= %d \n", somma);
        
        
    }while(numero1 > 0 && numero2 > 0);

    return 0;
}