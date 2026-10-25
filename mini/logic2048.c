// translated the 2048 game logic from PY to C
// whitout altering the logic itself.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COLS 4
#define ROWS 4

// start grid with all 0;
void initialize_grid(int grid[ROWS][COLS]) {
    memset(grid, 0, ROWS*COLS*sizeof(int));
}

// print grid, using pointers to learn how to use em;
void print_grid(const int *grid) {
    int dimtot = ROWS*COLS;
    printf("\n");
    for (int i = 0; i<dimtot; i++){
        printf("%4d", *grid);
        grid++;
        if ((i+1)%COLS == 0) printf("\n");
    }
}

// start game with two 2 in random position in the grid;
void start_game(int grid[ROWS][COLS]){
    int posx1 = rand() %4, posx2 = rand() %4;
    int posy1 = rand() %4, posy2 = rand() %4;
    while (posx1 == posx2 && posy1 == posy2) {
        posx2 = rand() %4;
        posy2 = rand() %4;
    }

    grid[posx1][posy1] = 2;
    grid[posx2][posy2] = 2;
}

// insert a number, either 2 or 4, in a random position at every round;
void insert(int grid[ROWS][COLS]){
    int posy;
    int posx;
    int num = (rand() % 2 == 0) ? 2 : 4;

    while(1){
        posx = rand() %4;
        posy = rand() %4;
        if (grid[posx][posy] == 0) {
            grid[posx][posy] = num;
            break;
        }
    }
}

// for every row shift the not 0 numbers to one side; 
void shift_grid(int grid[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        int pos = 0;
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != 0) {
                grid[i][pos] = grid[i][j];
                pos++;
            }
        }
        while (pos < COLS) {
            grid[i][pos] = 0;
            pos++;
        }
    }
}

// sum the nearby elements of the grid that are equals;
void sum_grid(int grid[ROWS][COLS]){
    for (int i = 0; i<ROWS; i++){
        for (int j = 0; j<(COLS-1); j++){
            if (grid[i][j] != 0 && grid[i][j] == grid[i][j+1]){
                grid[i][j] *= 2;
                grid[i][j+1] = 0;
            }
        }
    }
}

// flip the grid by the rows;
void flip(int grid[ROWS][COLS]) {
    int temp;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<(COLS/2); j++) {
            temp = grid[i][j];
            grid[i][j] = grid[i][3 - j];
            grid[i][3 - j] = temp;
        }
    }
}

/* rotate the grid of 90*, clockwise or anticlockwise, 
 first transpose than flip rows or cols based on direction; */
void rotate(int grid[ROWS][COLS], int dir){
    int temp;
    for (int i = 0; i<ROWS; i++){
        for (int j = i+1; j<COLS; j++){
            temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
        }
    }

    switch (dir) {
    case 1:
        for (int j = 0; j<COLS; j++) {
            for (int i = 0; i<(ROWS/2); i++) {
                temp = grid[i][j];
                grid[i][j] = grid[3-i][j];
                grid[3-i][j] = temp;
            }
        }
        break;
        
    case -1:
        flip(grid);
        break;
    
    default:
        break; // error rotation
    }
}

// handle moves of the grid;
void move(int grid[ROWS][COLS], char dir){
    switch (dir) {
    case 'w':
        rotate(grid, -1);
        shift_grid(grid);
        sum_grid(grid);
        shift_grid(grid);
        rotate(grid, 1);

        insert(grid);
        print_grid(*grid);
        break;
    
    case 's':
        rotate(grid, 1);
        shift_grid(grid);
        sum_grid(grid);
        shift_grid(grid);
        rotate(grid, -1);

        insert(grid);
        print_grid(*grid);
        break;
    
    case 'a':
        shift_grid(grid);
        sum_grid(grid);
        shift_grid(grid);
        insert(grid);
        print_grid(*grid);
        break;
    
    case 'd':
        flip(grid);
        shift_grid(grid);
        sum_grid(grid);
        shift_grid(grid);
        flip(grid);
        
        insert(grid);
        print_grid(*grid);
        break;
    
    default:
        break; // invalid key dir
    }
}

void test_grid(){
    int grid[ROWS][COLS] = {
        {2, 0, 2, 0},
        {0, 4, 0, 16},
        {4, 0, 0, 4},
        {0, 0, 2, 0}
    };
    shift_grid(grid);
    sum_grid(grid);
    shift_grid(grid);
    print_grid(*grid);
}

int main(void) {
    srand(time(NULL));
    int griglia[ROWS][COLS];
    initialize_grid(griglia);
    start_game(griglia);

    return 0;
}