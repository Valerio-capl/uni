#include <stdio.h>

#include <math.h> //per fabs
#include <float.h> //per epsilon

int main(void){
    int i=0, j;
    j = 25;

    if (i) printf("valore i: %d \n", i); // 0 valutato come false 
    else { 
        printf("valore j: %d \n",j);
    }

    int a = 0;
    int b = 10;

    if (a!=0 && (b/a) > 2){
        printf("condizione False \n");
    }
    else {                          // arriva all else nonostante la divisione per 0 dovrebbe essere errore perche 
        printf("condizione Vera \n"); // valuta prima la condizione !=0. 
    }

    
    double x = 0.1+0.2;
    double y = 0.3;
    if (x==y) printf("sono uguali \n");
    else printf("non sono uguali \n");      // non si puo fare cosi perche il compilatore su num reali non riconosce l uguaglianza

    if (fabs(x-y) < FLT_EPSILON) printf("sono uguali \n"); // importa math e float per calcolare il limite tra la differenza e capire se sono abbastanza vicini

    


    return 0;
}