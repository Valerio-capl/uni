#param A matrix m x n
#param i,j index target

def croce(A, i, j):
  target=A[i][j]
  rows = len(A)
  cols = len(A[0])
  if i > 0:
    if target <= A[i-1][j]:
      return False
  if i < rows - 1:
    if target <= A[i+1][j]:
      return False
  if j > 0:
    if target <= A[i][j-1]:
      return False
  if j < cols - 1:
    if target <= A[i][j+1]:
      return False
  return True

matrice=[[1,2,3,10],[3,5,7,2],[4,9,2,5]]
print croce(matrice,0,0)