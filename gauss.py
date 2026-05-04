import numpy as np

# prima mossa scambio Ri con Rj
# seconda mossa Ri[r][c]+xRj[r][c]=0 => Ri=Ri+xRj

def primaMossa(griglia: np.array, i: int, j: int):
    griglia[i], griglia[j] = griglia[j], griglia[i]
    return griglia

def secondaMossa(griglia: np.array, i: int, riga_pivot: int, col_pivot: int):
    if griglia[i][col_pivot] == 0:
        return griglia
    
    x = -griglia[i][col_pivot] / griglia[riga_pivot][col_pivot]
    
    griglia[i] = griglia[i] + (x * griglia[riga_pivot])
    return griglia

class grid():
    def __init__(self, r, c):
        self.rows = r
        self.cols = c
        self.griglia = np.zeros((r, c), dtype="f")
    
    def stampa(self):
        return print(self.griglia)
    
    def riempi(self):
        for r in range(self.rows):
            for c in range(self.cols):
                num = int(input(f"inserisci M[{r}][{c}]: "))
                self.griglia[r][c] = num
    
    def Gauss(self):
        riga_pivot = 0 
        for col_pivot in range(self.cols):
            if riga_pivot >= self.rows:
                break
            r_con_pivot = -1
            for r in range(riga_pivot, self.rows):
                if self.griglia[r][col_pivot] != 0:
                    r_con_pivot = r
                    break
            
            if r_con_pivot == -1:
                continue
            if r_con_pivot != riga_pivot:
                self.griglia = primaMossa(self.griglia, riga_pivot, r_con_pivot)
            for r_sotto in range(riga_pivot + 1, self.rows):
                if self.griglia[r_sotto][col_pivot] != 0:
                    self.griglia = secondaMossa(self.griglia, r_sotto, riga_pivot, col_pivot)
            
            riga_pivot += 1

griglia = grid(4,4)
griglia.riempi()
print("Matrice originale:")
griglia.stampa()
griglia.Gauss()
print("Matrice dopo Gauss:")
griglia.stampa()