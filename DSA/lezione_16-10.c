#include <stdio.h>
#include <stdlib.h>
/*
    errori comuni con memoria dinamica, sono gravi all esame 
    - mancato controllo null su malloc causa segmentation fault
    - double free chamare free 2 volte causa crash o vulnerabilita
    - memory leak, memoria allocata non liberata prima di perdere il puntatore che la riferisce
*/

void errori_comuni(int k) {
    int *p = malloc(k * sizeof(int));
    if (p == NULL){
        fprintf(stderr, "errore null");
    }

    int *a = malloc(sizeof(int));
    int *b = a;
    free(a);
    free(b); // errore double free.

    for (int i = 0; i<10; i++){
        // il vecchio indirizzo viene sovrascritto:
        // la memoria precedente è persa per sempre ma non liberata.
        p = malloc(k*sizeof(int));
    }
}

// per allocare memoria o modificare un puntatore all interno di una funzione 
// è necessario passarne l indirizzo di memoria tramite un doppio puntatore.
// se veniva passato con solo *v e si faceva v = malloc... viene creata una copia
// locale non cambia il valore globale.
void doppio_puntatore(int **v){
    *v = (int *) malloc(10 * sizeof(int)); 
}


// puntatore a valore constante (non si puo modificare il valore puntato)
// puntatore a indirizzo constante (non si puo modificare l indirizzo)
// puntatore constante sia valore che indirizzo
void puntatore_const(void){
    int x = 10, y = 20;
    // puntatore a valore const
    const int *p1 = &x;
    // *p1 = 15;  errore perche cambi valore
    p1 = &y; // non errore perche cambi il puntatore non il valore a cui punta

    // puntatore a indirizzo constante
    int *const p2 = &x;
    *p2 = 15;
    // p2 = &x; errore cambia l indirizzo
    
    // puntatore sia valore che indirizzo constante
    const int *const p3 = &x;
}


/*
    struct e typedef
    struct per dato derivato collezione di dati di tipi anche non omogenei
    il typedef è un agevolazione viene usato per non scrivere sempre struct quando creo una struttura associata
*/

struct Libro {
    char titolo[20];
    int anno;
    float prezzo;
};
typedef struct Persona{
    char *nome;
    int eta;
    float altezza;
} Persona;

Persona *crea(char *name, int age, float height){
    Persona *who = (Persona *) malloc(sizeof(Persona)); // assegna la dim dei vari campi sommandoli
    if (who == NULL) return NULL;
    who->nome = name;
    who->eta = age;
    who->altezza = height;
    return who;
}

// riempi i campi con puntatore
void riempi_persona(Persona **who, char *name, int age, int height){
    (*who)->nome = name;
    (*who)->eta  = age;
    (*who)->altezza  = height;
}

// union e enum
// union viene usato al posto di struct per usare meno memoria. tutti i membri condividono la STESSA cella di memoria
// hanno tutti lo stesso indirizzo di memoria,
// rendendo accessibile e utilizzabile un solo campo alla volta della union.
// enum sono costanti simili al #define 

// Enum 1: Assegnazione automatica (OK=0, WARNING=1, ERROR_NOT_FOUND=2, ERROR_CRITICAL=3)
typedef enum {
    OK,
    WARNING,
    ERROR_NOT_FOUND,
    ERROR_CRITICAL
} StatoOperazione;

// Enum 2: Assegnazione esplicita dei valori
typedef enum {
    HTTP_OK = 200,
    HTTP_NOT_FOUND = 404,
    HTTP_SERVER_ERROR = 500
} CodiceHTTP;

/*
I campi a differenza delle struct hanno tutti lo stesso indirizzo di memoria,
rendendo accessibile e utilizzabile un solo campo alla volta della union.
Si utilizzando per motivi di ottimizzazioni dello spazio poiché una union
ha dimensione uguale alla dimensione del campo maggiore.
*/
union Dato {
    int i;
    double d;
    char c;
};

int main (void){
    struct Libro libro1; // con struct va sempre incluso struct
    Persona *persona1;    // con typedef si usa l identifier che sta alla fine senza inizializzarlo con struct
    Persona  *johndoe;

    johndoe = create("John Doe",30,180);
    if (johndoe == NULL) {
        fprintf(stderr,"Malloc failure\n");
        return 1;
    }
    free(johndoe);  // free kibera la memoria.

    union Dato u;
    printf("sizeof(union Dato): %lu byte\n", sizeof(u));
    printf("sizeof(int): %lu | sizeof(double): %lu | sizeof(char): %lu\n\n", sizeof(int), sizeof(double), sizeof(char));

    u.i = 10;
    printf("Scritto u.i -> u.i vale: %d\n", u.i);
    u.d = 220.5; // Questa scrittura SOVRASCRIVE il valore di u.i!
    printf("Scritto u.d	-> u.d vale: %.5f\n", u.d);
    printf("Valore corrotto di u.i dopo la scrittura in u.d: %d\n", u.i); 
    //stiamo leggendo i byte di un double interpretandoli come un int

    return 0;
}