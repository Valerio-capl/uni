// puntatori

#include <stdio.h>
// guarda slides per info segmenti memoria e memoria dinamica
// github.com/federicamontes/federicamontes.github.io/

/*
    i puntatori sono una variabile che memorizza come valore l'indirizzo di memoria di un altra variabile
    operatori: & address-of restituisce l'indirizzo fisico logico di memoria di una var, * accede al valore del puntatorecle
*/


int main(void){
    int x = 10;
    int *ptr = &x;      // indirizzo di memoria di x
    int val = *ptr;     // valore del puntatore quindi valore di x
    printf("la variabile %d si trova all indirizzo %p", *ptr, ptr);

    // puntatore generico
    void *gptr = (void *) &x;
    val = (int *) gptr;  // valore con casting del puntatore generico

    ptr++;              // 
    val = *(ptr+1);     // equivalente di arr[1]

    int arr[3] = {10, 20, 30};
    int *p_int = arr;
    char *p_char = (char *) arr;
    int p_2 = &arr[2];

    return 0;
}

// memoria dinamica 
void *malloc(size_t size);  // alloca memoria
void free(void *ptr);       // rilasciare memoria

// guarda uso di malloc e free su esercizi (liste, stack ...)
