
#data una stringa s e un intero n, 0 ≤ n ≤ len(s), la funzione restituisce una nuova stringa ottenuta da s eliminando gli ultimi n caratteri, e inserendo nelle prime 
#n posizioni il carattere '$'; se n > len(s) la stringa s viene restituita immutata
def rimuovi_n(s, n):
  if n>len(s):
    return s
  str1=s[:n+1]
  str2="$"*n
  return str2+str1 #dimmi un altro modo di farlo se con stessa o migliore efficenza

#data una matrice A mxn , contenente valori numerici, e un intero k, la funzione restituisce la somma degli elementi di una riga della matrice
def sommaRiga(A, k):
  for i in range(len(A)):
    if A[i][0]==k:
      somma=sum(A[i][j] for j in range(len(A[0])))
      return somma
  return 0

#data una lista A di stringhe e una stringa s, la funzione restituisce una nuova lista ottenuta da A rimuovendo tutte le stringhe il cui primo carattere è uguale all'ultimo carattere di s
def rimuovi(A, s):
  res=[]
  for e in A:
    if e[0]!=s[-1]:
      res.append(e)
  return res

#data una matrice M mxn (m righe, n colonne), contenente valori numerici e 
#una coppia di indici h, k, la funzione modifica la matrice M moltiplicando per il valore dell'elemento in posizione h, k tutti gli elementi che si trovano sopra/sotto e a destra/sinistra dell'elemento in posizione h, k. L'elemento in posizione h, k deve rimanere invariato
def modifica(M, h, k):
  if h>=len(M) or h<0 or k>=len(M[0]) or k<0:
    return M
  val=M[h][k]
  if h+1<len(M):
    M[h+1][k]*=val
  if h-1>=0:
    M[h-1][k]*=val
  if k+1<len(M[0]):
    M[h][k+1]*=val
  if k-1>=0:
    M[h][k-1]*=val
  return M

#data una matrice M mxn, contenente valori numerici, e un intero k, la funzione restituisce una lista formata da tutti i valori contenuti nelle prime k righe di M;
def estraiRighe(M, k):
  if k>=len(M):
    return [M[i][j] for i in range(len(M)) for j in range(len(M[0]))]
  return [M[i][j] for i in range(k+1) for j in range(len(M[0]))]

#data una matrice M mxn (m righe, n colonne), contenente valori numerici, e due interi h e k, la funzione restituisce il prodotto dei valori (se esistono) 
#immediatamente adiacenti a sinistra e a destra dell'elemento di coordinate h e k.
def moltAdiacenti(M, h, k):
  if h>=len(M) or h<0 or k>=len(M[0]) or k<0:
    return 0
  if k+1<len(M[0]):
    val1=M[h][k+1]
  if k-1>=0:
    val2=M[h][k-1]
  if val1 and val2:return val1*val2
  else:return 0

#date due stringhe s1 e s2 la funzione restituisce una nuova stringa formata esclusivamente dai caratteri condivisi tra le due stringhe stessa posizione in s1 e s2 e che hanno uguale valore
def carCondivisi(s1, s2):
  res=''
  for i in range(min(len(s1),len(s2))):
    if s1[i]==s2[i]:
      res+=s1[i]
  return res

#data una matrice M mxn (m righe, n colonne), contenente valori numerici, e due interi h e k, la funzione restituisce il prodotto dei valori (se esistono) immediatamente adiacenti 
#sopra (nord), a sinistra (ovest), sotto (sud), a destra (est) dell'elemento di coordinate h e k.
def prodNOSE(M, h, k):
  if h>=len(M) or h<0 or k>=len(M[0]) or k<0:
    return 0
  val=1
  if h+1<len(M):
    val*=M[h+1][k]
  if h-1>=0:
    val*=M[h-1][k]
  if k+1<len(M[0]):
    val*=M[h][k+1]
  if k-1>=0:
    val*=M[h][k-1]
  return val

#data una stringa s e un intero k, la funzione restituisce una nuova stringa ottenuta da s sostituendo 
#ogni carattere che si trova in posizione multipla di k (inclusa la posizione 0) con il carattere '*'
def censuraJ(s, k):
  res=""
  for i in range(len(s)):
    if i%k==0:
      res+="*"
      continue
    res+=s[i]
  return res

#data una matrice M mxn (m righe, n colonne), contenente valori numerici, la funzione modifica M sostituendo con un carattere '*' tutti i valori sui "bordi" di M 
def cancellaBordi(M):
  for i in range(len(M)):
    M[i][0],M[i][-1]="*","*"
  for j in range(len(M[0])):
    M[0][j],M[-1][j]="*","*"
  return M

#data una lista di stringhe L, e un intero n, la funzione restituisce una nuova lista ottenuta da L trasformando in maiuscole tutte le stringhe che hanno lunghezza n;
def maiusc(L, n):
  res=[]
  for e in L:
    if len(e)==n:
      res.append(e.upper())
      continue
    res.append(e)
  return res

#data una matrice A mxn (m righe, n colonne), contenente valori numerici, e un intero k, la funzione pone a 0 ogni elemento che è un multiplo di k;
def azzeraMulK(A, k):
  for i in range(len(A)):
    for j in range(len(A[0])):
      if A[i][j]%k==0:A[i][j]=0
  return A

#data una lista di interi L, formata da un qualunque numero di elementi, e un intero n, la funzione restituisce una nuova lista formata dai soli elementi di L che sono immediatamente seguiti dal valore n
def seleziona(L, n):
  res=[]
  for i in range(len(L)-1):
    if L[i+1]!=n:
      res.append(L[i])
  return res

#data una matrice M mxn (m righe, n colonne), contenente valori numerici, e un intero k, la funzione modifica M sottraendo il valore k a tutti gli elementi delle righe il cui primo elemento è un valore > k
def sottraiK(M, k):
  for i in range(len(M)):
    for j in range(len(M[0])):
      if M[i][j]>k: M[i][j]*=k
  return M