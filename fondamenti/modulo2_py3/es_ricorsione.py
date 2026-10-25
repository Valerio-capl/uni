# es 1 somma lista
def sommalista(l:list):
  if len(l)==0:
    return 0
  return l[0]+sommalista(l[1:])

def contavoc(s:str,n=0):
  if s=="":
    return n
  if s[0].lower() in "aeiou":
    n+=1
  return contavoc(s[1:],n)

def esponente(n,e):
  if e>1:
    return n*esponente(n,e-1)
  elif e==0: return 1
  else: return n
  
def ricerca_binaria(lista, target, start, end):
  if start > end: return False
  mid=(end+start)//2
  if lista[mid]==target:
    return True
  if lista[mid]<target:
    return ricerca_binaria(lista,target,mid+1,end)
  elif lista[mid]>target:
    return ricerca_binaria(lista,target,start,mid-1)

def percorsi(x,y):
  if x==0 or y==0:
    return 1
  return percorsi(x - 1, y) + percorsi(x, y - 1)
print(percorsi(2,2))