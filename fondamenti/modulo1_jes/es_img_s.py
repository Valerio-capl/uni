def filtroMezzaluna(img, cTarget, cNuovo):
  w=getWidth(img)
  h=getHeight(img)
  res=makeEmptyPicture(w, h)
  for y in range(0,h):
    for x in range(w):
      px=getPixel(img,x,y)
      pixel_copia = getPixel(res, x, y)
      c=getColor(px)
      if distance(c, cTarget)==0 and y<=h//2: #si puo fare c==cTarget? rispondi in chat
        setColor(pixel_copia,cNuovo)
      else:
        setColor(pixel_copia,c)
  return res

def evidenziaRighe(img, k):
  w=getWidth(img)
  h=getHeight(img)
  nero=makeColor(0,0,0)
  giallo=makeColor(255, 255, 0)
  
  for y in range(0,h):
    contak=0
    riga=False
    for x in range(w):
      px=getPixel(img,x,y)
      if getColor(px)==nero:
        contak+=1
      if contak>k:
        riga=True
        break
    if riga==True:
      for x in range(w):
        px=getPixel(img,x,y)
        setColor(px,giallo)
    
def separaTipi(s):
  lettere=""
  num=""
  for e in s:
    if e.isalpha():
      lettere+=e
    elif e.isdigit():
      num+=e
    else:
      continue
  return [lettere,num]

def saltaStringa(s, k):
  res=""
  for i in range(0,len(s),k+1):
    res+=s[i]
  return res
      
      
      
      
      