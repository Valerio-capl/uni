def exsum(px, pxlsL):
#@param px: pixel
#@param pxlsL: list[px]
#@return bool
  for i in range(len(pxlsL)-1):
    for j in range(i+1,len(pxlsL)):
      if sum(px,pxlsL[i],pxlsL[j]):
        return True
  return False
def sum(p1,p2,p3):
#@param p1,p2,p3 : pixel
#return bool
  return getRed(p1)==getRed(p2)+getRed(p3) and getGreen(p1)==getGreen(p2)+getGreen(p3) and getBlue(p1)==getBlue(p2)+getBlue(p3)
  
  
def check(A, B):
# @param A: picture
# @param B: picture
# @return bool
  pxls_1 = getPixels(A)
  pxls_2 = getPixels(B)
  for px in pxls_1 :
    if not exSum(px, pxls_2):
    return False
  return True
