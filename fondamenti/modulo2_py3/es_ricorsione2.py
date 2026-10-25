# es1 
# Scrivi una funzione ricorsiva is_ordinata(lista) che riceve una lista di numeri e restituisce True 
# se la lista è ordinata in modo strettamente crescente, False altrimenti.
def is_ordinata(lista):
  if len(lista)<=1:
    return True
  if lista[0] >= lista[1]:
    return False
  return is_ordinata(lista[1:])

# es 2
# Scrivi una funzione ricorsiva is_palindroma_avanzata(s) che ignora gli spazi vuoti e la differenza tra maiuscole e minuscole.
def is_palindroma_avanzata(s:str):
  if len(s) <= 1:
        return True
  if s[0] == " ":
    return is_palindroma_avanzata(s[1:])
  if s[-1] == " ":
    return is_palindroma_avanzata(s[:-1])
  if s[0].lower()!=s[-1].lower():
    return False
  return is_palindroma_avanzata(s[1:-1])
  
# es 3
# Scrivi la funzione decimale_a_binario(n) in modo puramente ricorsivo (niente cicli while, niente str(), solo ricorsione e operatori aritmetici).
# Deve restituire il numero binario sotto forma di stringa.
def decimale_a_binario(n):
  
  def helper_int(n:int):
    if n == 0: return ""
    carattere_resto = chr(48+int(n % 2))
    return helper_int(n//2)+carattere_resto
  def helper_dec(n:float, conta=0):
    if n == 0.0 or conta >= 4: return ""
    num=n*2
    intero=int(num//1)
    conta+=1
    return chr(48+intero)+helper_dec((num-intero),conta)
  
  parte_intera = int(n // 1)
  parte_decimale = n - parte_intera
  intero=helper_int(parte_intera)
  dec=helper_dec(parte_decimale)
  return intero+"."+dec

# es 4
def appiattisci(lista):
  if len(lista) == 0:
    return []
  primo_elemento = lista[0]
  resto_lista = lista[1:]
  if type(primo_elemento) == list:
    return appiattisci(primo_elemento) + appiattisci(resto_lista)
  else:
    return [primo_elemento] + appiattisci(resto_lista)