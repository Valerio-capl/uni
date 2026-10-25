def filtra_parallelo(s, t):
  res=""
  for i in range(len(s)):
    if t[i]%2==0:
      res+=s[i]
  return res

def rimuovi_negativi(L):
  for e in L[:]:
    if e<0:
      L.remove(e)
  return L
  
def azzera_primo_se_ultimo(M, x):
  for i in range(len(M)):
    if M[i][-1]==x:
      M[i][0]=0
      
def ruota_tupla(t, n):
  if not t:
    return t
  lista = list(t)
  if n > 0:
    passi = 0
    while passi < n:
      elemento = lista.pop()
      lista.insert(0, elemento)
      passi += 1
  elif n < 0:
    passi = 0
    while passi < abs(n):
      elemento = lista.pop(0)
      lista.append(elemento)
      passi += 1
            
  return tuple(lista)
  
def scambia_se_multiplo(M, c1, c2, k):
  if c1>=len(M[0]) or c2>=len(M[0]) or c1<0 or c2<0:
    return M
  somma1=sum(M[i][c1] for i in range(len(M)))
  if somma1%k==0:
    for i in range(len(M)):
      M[i][c1],M[i][c2]=M[i][c2],M[i][c1]
  return M

def estrai_caratteri(L, k):
  res=''
  for e in L:
    if len(e)<=k:
      res+='*'
      continue
    res+=e[k]
  return res

def azzera_diagonali_dispari(M):
  c=len(M[0])
  r=len(M)
  for i in range(r):
    if M[i][i]%2!=0:
      M[i][i]=0
    if M[i][c-1-i]%2!=0:
      M[i][c-1-i]=0
  return M
  
def sposta_vocali_fine(s):
  voc=("a","e","i","o","u")
  strV=""
  res=""
  for e in s:
    if e.lower() in voc:
      strV+=e
    else:
      res+=e
      
  return res+strV


