/* game of life fatto seguendo tutorial c 
lezione 8 di salvatore sanfilippo */

#include <stdio.h>
#include <unistd.h>

#define COLS 20
#define ROWS 20
#define GRID_CELLS (ROWS*COLS)
#define ALIVE '*'
#define DEAD '.'

// grid wrapping. translate the index x,y to index of the grid.  
int cell_to_index(int x, int y) {
    if (x < 0) {
        x = (-x) % COLS; //prima torno dentro la grid se necessario
        x = COLS - x;   // poi lo rendo interno la griglia
    }
    if (y < 0) {
        y = (-y) % ROWS;
        y = ROWS - y;
    }
    
    // l'overflow è 20 perche l'array è 0-19
    if (x >= COLS) x = x%COLS;   //se va oltre 19 deve tornare dentro la grid
    if (y >= ROWS) y = y%ROWS;   //es. se è 20, quindi il primo overflow diventa 0

    return y*COLS + x;
}

// setcell set state at specified cell x,y in grid
void setcell(char *grid, int x, int y, char state) {
    grid[cell_to_index(x,y)] = state;
}
// getcell returns the state of x,y cell
char getcell(char *grid, int x, int y) {
    return grid[cell_to_index(x,y)];
}

void print_grid(char *grid) {
    for (int y=0; y<ROWS; y++) {
        for (int x=0; x<COLS; x++){
            printf("%c", getcell(grid, x, y));
        }
        printf("\n");
    }
}

void set_grid(char *grid, char state) {
    for (int y=0; y<ROWS; y++) {
        for (int x=0; x<COLS; x++){
            setcell(grid, x, y, state);
        }
    }
}


// counts how many neighbors are alive from cell x,y
int count_living_neighbors(char *grid, int x, int y) {
    int alive = 0;
    for (int yn = -1; yn<=1; yn++){
        for (int xn = -1; xn<=1; xn++){
            if (xn == 0 && yn == 0) continue;
            if (getcell(grid, x+xn, y+yn) == ALIVE) alive++;
        }
        
    }
    return alive;
}

// compute new state of grid
void new_state(char *old, char *new) {
    for (int y=0; y<ROWS; y++) {
        for (int x=0; x<COLS; x++){
            int n_alive = count_living_neighbors(old, x, y);
            int new_state = DEAD;   // inizializza a dead cosi non fai entrambi i casi sotto
            if (getcell(old, x, y) == ALIVE) {
                if (n_alive == 2 || n_alive == 3) new_state = ALIVE;
            } else {
                if (n_alive == 3) new_state = ALIVE;
            }

            setcell(new, x, y, new_state);

        }
    }
}

int main(void) {
    char old_grid[GRID_CELLS];
    char new_grid[GRID_CELLS];

    set_grid(old_grid, DEAD);

    setcell(old_grid, 10,10, ALIVE);
    setcell(old_grid, 9,10, ALIVE);
    setcell(old_grid, 11,10, ALIVE);
    setcell(old_grid, 11,9, ALIVE);
    setcell(old_grid, 10,8, ALIVE);

    while(1){
        new_state(old_grid,new_grid);
        print_grid(new_grid);
        usleep(100000);
        new_state(new_grid, old_grid);
        print_grid(old_grid);
        usleep(100000);
    }
    
    return 0;
}