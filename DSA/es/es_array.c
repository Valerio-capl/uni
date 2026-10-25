#include <stdio.h>

// bool lista ordinata O(n)
// si puo fare con altri alg, aspetta lezione sort.
int isOrdered(int v[], int n) {
    for (int i = 0; i<n-1; i++){
        if (v[i]>v[i+1]) return 0;
    }
    return 1;
}


// ruota arr verso destra di 1. O(n)
// da fare rotazione di k posizioni
void ruotaDestra(int v[], int n){
    int temp = v[0];
    int temp2;
    for (int i = 0; i<n-1; i++){
        temp2 = v[i+1];
        v[i+1] = temp;
        temp = temp2;
    }
    v[0] = temp; 
}

// estrai pari da arr inizio e copia in destinazione
int estraiPari(int sorgente[], int n_sorgente, int destinazione[]){
    int count = 0;
    for (int i = 0; i<n_sorgente; i++){
        if(sorgente[i]%2 == 0){
            destinazione[count] = sorgente[i];
            count++;
        }
    }
    return count;
}

// somma righe di matrix e aggiungi somma a arr res
void sommaRighe(int r, int c, int mat[r][c], int res[]){
    int somma;
    for (int i = 0; i<r; i++){
        somma = 0;
        for (int j = 0; j<c; j++) somma+=mat[i][j];
        res[i] = somma;
    }
}

// ricerca target in arr v con complessita O(logn)
int ricercaBinaria(int v[], int n, int target) {
    int mid, i=0, j=n-1;
    while(i<j){
        mid = (i+j) / 2;
        printf("%d\n", mid);
        if (v[mid] == target) return mid;
        else if (v[mid] < target) i = mid+1;
        else if (v[mid] > target) j = mid-1;
        
    }
    return -1;
}

// da fare, non capita consegna aspetta tutoraggio
int rimuoviDuplicati(int v[], int n){

}

// aspetta lezione alg.
int maxSubarraySum(int v[], int n){
    int window[n];    
    int maxsum = 0;
    for (int i = 0; i<n; i++){
        
    }
}

int main(void){
    int v[] = {1,2,7,5,6,10,2,34};
    // printf("%d\n",isOrdered(v,5));
    ruotaDestra(v,5);
    // for (int i=0; i<5; i++) {
    //     printf("numero %d: %d\n", i, v[i]);
    // }  
    int des[] = {0};
    int len_Des = estraiPari(v,8,des);
    // printf("%d\n",len_Des);

    int matrix[4][2] = {{1,2},{3,4},{5,6},{7,8}};
    int res[4];
    sommaRighe(4,2,matrix,res);
    // for (int i=0; i<4; i++) {
    //     printf("somma %d\n", res[i]);
    // }  

    int ricerca[] = {1,4,5,7,8,12};
    int ind = ricercaBinaria(ricerca, 6, 8);
    printf("%d\n", ind);

    //es 7,8 da fare

    return 0;
}