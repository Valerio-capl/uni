#include <stdio.h>
#define N 10

/*  accesso casuale è o(1)
    se si vuole aggiungere un elemento oltre la dimensione  o(n) perche serve crearne uno nuovo 
    array è mutable quindi quando si passa a una funzione è sempre il puntatore
    e quello che viene fatto all interno della funzione cambia l array 
*/

/* gli scorrimenti su matrici dim 2 si fa sulle righe, quello sulle colonne ci vuole quasi il doppio 
   si passano sempre le dimensioni dell array nelle funzioni senno si usano puntatori*/
void stampa_matrice(int r, int c, int arr[r][c]){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%d\n", arr[i][j]);
        }
    }
}
void riempi_matrice(int r, int c, int arr[r][c]){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            arr[i][j] = 1; // valore 1 da inserire
        }
    }
}



int main(void){
    // array
    int arr[] = {1,2,3};            // array con dim automatica
    int arr_dim[5] = {1,3,4,5,1};  // array con dimensione fissa

    for (int i=0; i<5; i++) {      //dim 5 dell array
        printf("numero %d: %d\n", i, arr_dim[i]);
    }   


    // stringhe sono array di char
    char str_1[] = {'h', 'e', 'l', 'l', 'o', 0};   // si puo scrivere cosi come array 
    // si usa lo 0 per terminale la stringa (si usa anche'\0')
    printf("%s\n", str_1);

    char str_2[] = "hello"; // oppure cosi in modo piu semplice (anche qui str_2 sara lunga 5, 4 lettere e 1 terminatore)
    printf("%s\n", str_2);

    for (int i=0; str_2[i] != 0; i++){      // finche non arriva alla fine (si usa lo 0) anche nelle stringhe
        printf("%c\n", str_2[i]);           // definite in modo semplice si ha lo 0 automatico per bloccare
    }
        
    /* sulle stringhe si usa f.. e fgets non gets per evitare buffer overflow
    non si puo assegnare ad una stringa un altra stringa come str_1=str_2 è necessaria
    una funzione di copia. inoltre non si possono fare operazioni aritmetiche su stringhe
    o su array come py s[i]+='i' NO  */


    // array multidim
    int matrix[N][N];   // array NxN  righe*col
    /*  per accedere con la memoria a un valore matrix[i][j] (al suo indirizzo)
    si calcola (i*n + j) + sizeof(type)  con n dimensione del matrix delle colonne. */

    
    return 0;
}