def specchiaVert():
  img=pickAFile()
  img=makePicture(img)
  larghezza=getWidth(img)
  altezza=getHeight(img)
  for y in range(altezza):
    for x in range(larghezza/2):
      left=getPixel(img,x,y)
      right=getPixel(img,larghezza-1-x,y)
      setColor(right,getColor(left))
  show(img)
  
def specchiaOri():
  img=pickAFile()
  img=makePicture(img)
  larghezza=getWidth(img)
  altezza=getHeight(img)
  for x in range(larghezza):
    for y in range(altezza/2):
      top=getPixel(img,x,y)
      bottom=getPixel(img,x,altezza-1-y)
      setColor(bottom,getColor(top))
  show(img)
  

def lineeVert():
  img=pickAFile()
  img=makePicture(img)
  larghezza=getWidth(img)
  altezza=getHeight(img)
  for y in range(altezza):
    for x in range(0,larghezza,3):
      px=getPixel(img,x,y)
      setColor(px,black)
  show(img)
  
def distanzaCol(col1,col2):
  calcoloRed = (col1.getRed() - col2.getRed())**2
  calcoloBlue = (col1.getBlue() - col2.getBlue())**2
  calcoloGreen = (col1.getGreen() - col2.getGreen())**2
  return (calcoloRed+calcoloBlue+calcoloGreen)**0.5
def occhiRossi():
  img=pickAFile()
  img=makePicture(img)
  larghezza=getWidth(img)
  altezza=getHeight(img)
  for y in range(altezza):
    for x in range(larghezza):
      px=getPixel(img,x,y)
      if distanzaCol(getColor(px),black)<130:
        setColor(px,red)
  show(img)
  
occhiRossi()