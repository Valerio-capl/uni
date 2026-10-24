import numpy as np

# prima mossa scambio Ri con Rj
# seconda mossa Ri[r][c]+xRj[r][c]=0 => Ri=Ri+xRj
# rango num pivot
# det matrice (-1)^num scambi *diagonale

class grid():
    def __init__(self, r:int, c:int):
        self.rows = r
        self.cols = c
        self.rango = 0
        self.determinante = 1
        self.griglia = np.zeros((r, c), dtype="f")

    def stampa(self):
        return print(self.griglia)
    
    def riempi(self):
        for r in range(self.rows):
            for c in range(self.cols):
                num = int(input(f"inserisci M[{r}][{c}]: "))
                self.griglia[r][c] = num
    
    def primaMossa(self,i:int, j:int):
        self.griglia[[i,j]] = self.griglia[[j,i]]

    def secondaMossa(self, i: int, riga_pivot: int, col_pivot: int):
        if self.griglia[i][col_pivot] != 0:
            x = -self.griglia[i][col_pivot] / self.griglia[riga_pivot][col_pivot]
            self.griglia[i] = self.griglia[i] + (x * self.griglia[riga_pivot])
    
    def Gauss(self):
        riga_pivot = 0 
        for col_pivot in range(self.cols):
            if riga_pivot >= self.rows:
                break
            r_con_pivot = -1
            for r in range(riga_pivot, self.rows):
                if self.griglia[r][col_pivot] != 0:
                    r_con_pivot = r
                    self.rango += 1
                    self.determinante *= self.griglia[r][col_pivot]
                    break
            
            if r_con_pivot == -1:
                continue
            if r_con_pivot != riga_pivot:
                self.primaMossa(riga_pivot, r_con_pivot)
                self.determinante *= -1
                
            for r_sotto in range(riga_pivot + 1, self.rows):
                if self.griglia[r_sotto][col_pivot] != 0:
                    self.secondaMossa(r_sotto, riga_pivot, col_pivot)
            
            riga_pivot += 1

# --------------

griglia = grid(3,3) #matrix 3x3 scegli nxm
griglia.riempi()
print("Matrice originale:")
griglia.stampa()
griglia.Gauss()
print("Matrice dopo Gauss:")
griglia.stampa()
print(f"rango della matrice: {griglia.rango}\n determinante della matrice: {griglia.determinante}")