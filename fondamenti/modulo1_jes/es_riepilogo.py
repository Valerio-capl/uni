def specchio(img):
  w=getWidth(img)#num colonne
  h=getHeight(img)#num righe
  show(img)
  for y in range(h):
    for x in range(w//2):
      px1=getPixel(img,x,y)
      px2=getPixel(img,w-x-1,y)
      c2=getColor(px2)
      c1=getColor(px1)
      setColor(px1,c2)
      setColor(px2,c1)
  repaint(img)

def cornice(img, k, c):
  w=getWidth(img)
  h=getHeight(img)
  for x in range(w):
    for y in range(0,k):
      setColor(getPixel(img,x,y),c)
      setColor(getPixel(img,x,h-y-1),c)
  for y in range(h):
    for x in range(0,k):
      setColor(getPixel(img,x,y),c)
      setColor(getPixel(img,h-x-1,y),c)
      
def esisteQuadrato(img, c, L):
  somma_px=0
  w=getWidth(img)
  h=getHeight(img)
  for y in range(h):
    for x in range(1,w):
      if getColor(getPixel(img,x,y))==c:
        somma+=1
        
def veneziana(img, k):
  w=getWidth(img)
  h=getHeight(img)
  for y in range(k):
    if (y // k) % 2 == 0:
      for x in range(w):
        px=getPixel(img,x,y)
        c=makeColor(getRed(px)//2, getGreen(px)//2, getBlue(px)//2)
        setColor(px,c)

def cifraVocali(s):
  vocali=(a, e, i, o, u)
  for i in len(s):
    if s[i] in vocali:
      s[i]=i
      
def piuFrequenti(lista, k):
  sommael=0
  el=lista[0]
  nuovaL=[]
  for e in lista:
    if e==el:
      sommael+=1
    else:
      if sommael>k:
        nuovaL.append(e)
        continue
      sommael=0
      el=e
      
  