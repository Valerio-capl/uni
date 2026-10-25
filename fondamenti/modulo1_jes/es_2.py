def azzera_colonna_se_somma(M, x):
  for j in range(len(M[0])):
    somma=0
    for i in range(len(M)):
      somma+=M[i][j]
    if somma>x:
      for i in range(len(M)):
        M[i][j]=0
  return M

def filtra_tuple(L, n):
  for e in L[:]:
    if len(e)!=n:
      L.remove(e)
  return L

def verifica_cornice(M, k):
  res=True
  for i in range(len(M)):
    if M[i][0]%k!=0 or M[i][-1]%k!=0:
      res=False
  for j in range(len(M[0])):
    if M[0][j]%k!=0 or M[-1][j]%k!=0:
      res=False
  return res
  
def coord_massimi(M):
  res=[]
  for i in range(len(M)):
    el=M[i][0]
    coor=(i,0)
    for j in range(len(M[0])):
      if M[i][j]>el:
        el=M[i][j]
        coor=(i,j)
    res.append(coor)
  return res

def intersezione_senza_duplicati(L1, L2):
  res=set()
  if len(L1)>=len(L2):
    for e in L1:
      if e in L2:
        res.add(e)
  else:
    for e in L2:
      if e in L1:
        res.add(e)
  return list(res)
