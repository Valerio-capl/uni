def chromaKey(imgSfondo, imgSoggetto, coloreTarget):
  w=getWidth(imgSfondo)
  h=getHeight(imgSfondo)
  img=makeEmptyPicture(w,h)
  for y in range(h):
    for x in range(w):
      px_sogg=getPixel(imgSoggetto,x,y)
      px_img=getPixel(img,x,y)
      px_sfondo=getPixel(imgSfondo,x,y)
      if distance(getColor(px_sogg),coloreTarget)<15:
        setColor(px_img,getColor(px_sfondo))
      else:
        setColor(px_img,getColor(px_sogg))
  return img

def censura(img, x_centro, y_centro, k):
  nero=makeColor(0,0,0)
  w=getWidth(img)
  h=getHeight(img)
  if x_centro-k<0 or x_centro+k>w or y_centro-k<0 or y_centro+k>h:
    return False
  for y in range(y_centro-k,y_centro+k):
    for x in range(x_centro-k, x_centro+k):
      px=getPixel(img,x,y)
      setColor(px,nero)
  return True

def comprimi(s):
  count=1
  res=""
  for i in range(1,len(s)):
    if s[i] == s[i - 1]:
      count += 1
    else:
      res += s[i - 1] + str(count)
      count = 1
  res += s[-1] + str(count)
  return res

def censuraTesto(frase, parole_vietate):
  res=""
  for w in frase.split():
    if w in parole_vietate:
      res+=" "+"*"*len(w)
    else:
      res+=" "+w
  return res
  
