#include <stdio.h>

int main()
{
    int numero1, numero2;
    float rapporto = 0;
    
    do{
        
        
        printf("inserisci numero1: \n");
        scanf("%d", &numero1);
        
        printf("inserisci numero2: \n");
        scanf("%d", &numero2);
        
        if(numero1 > numero2){
            rapporto = numero1 / numero2;
        }
        else{
            rapporto = numero2 / numero1;
        }
        
        printf("il rapporto vale: %f \n", rapporto);
    }while(numero1 >= 0 || numero2 >= 0);

    return 0;
}