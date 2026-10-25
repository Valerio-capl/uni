from abc import ABC, abstractmethod
import math


# ESERCIZIO 1
# Crea una classe base Dipendente con gli attributi nome e stipendio_base, 
# e un metodo calcola_stipendio() che restituisce lo stipendio base. Crea poi una sottoclasse Manager. 
# Il Manager ha un attributo aggiuntivo bonus. Usa super() nell'__init__ del Manager per inizializzare nome e stipendio base, 
# e fai l'overriding di calcola_stipendio() (sempre usando super()) per restituire lo stipendio base sommato al bonus.

class dipendente():
  def __init__(self,nome,stipendioBase) -> None:
    self.nome=nome
    self.stipendioBase=stipendioBase
  def calcola_Stipendio(self):
    return self.stipendioBase
  
class manager(dipendente):
  def __init__(self,nome,stipendioBase,bonus) -> None:
    super().__init__(nome,stipendioBase)
    self.bonus=bonus

  def calcola_Stipendio(self):
    self.stipendioTotale=super().calcola_Stipendio()+self.bonus
    return self.stipendioTotale
  
# ESERCIZIO 2
# Crea una classe Termometro. Deve avere un attributo "privato" _temperatura_celsius. 
# Implementa il getter con @property. Implementa il setter in modo che accetti solo valori superiori allo zero assoluto (-273.15 °C). 
# Se l'utente cerca di impostare una temperatura inferiore, solleva un ValueError con un messaggio descrittivo.

class Termometro():
  def __init__(self, temperatura) -> None:
    self.temperatura=temperatura

  @property
  def temperatura(self):
    return self._temperatura_celsius
  @temperatura.setter
  def temperatura(self, temp):
    if temp>-273.15:
      self._temperatura_celsius=temp
    else: raise ValueError("errore valore inferiore allo zero assoluto")

# ESERCIZIO 3
# Definisci un'eccezione personalizzata FondiInsufficientiError (che eredita da Exception). 
# Crea una classe ContoBancario con un saldo iniziale. Implementa il metodo preleva(importo). 
# Se l'importo richiesto è maggiore del saldo, solleva la tua eccezione personalizzata anziché un generico ValueError.

class FondiInsufficientiError(Exception):
  pass
class ContoBancario():
  def __init__(self,saldo_iniziale) -> None:
    self.set_saldo(saldo_iniziale)
  def preleva(self,importo):
    if importo>self._saldoIniziale:
      raise FondiInsufficientiError("importo troppo alto")
    self._saldoIniziale-=importo
  def set_saldo(self,saldo):
    self._saldoIniziale=saldo if saldo>0 else None

# ESERCIZIO 4
# Crea una classe ConnessioneDatabase. Usa un attributo di classe connessioni_attive inizializzato a 0. 
# Ogni volta che istanzi un nuovo oggetto, l'__init__ deve incrementare questo contatore. 
# Implementa il distruttore __del__ affinché decrementi il contatore e stampi "Connessione chiusa. Attive: X".

class ConnessioneDatabase():
  connessioni_attive=0
  def __init__(self) -> None:
    ConnessioneDatabase.connessioni_attive+=1
  def __del__(self):
    ConnessioneDatabase.connessioni_attive-=1
    print(f"connessione chiusa. attive: {self.connessioni_attive}")

# ESERCIZIO 5
# Crea due classi: Progetto e Programmatore. La molteplicità è: un progetto ha 0..* programmatori. 
# I programmatori devono essere istanziati fuori dal progetto (nel main) e passati al progetto tramite un metodo aggiungi_programmatore(programmatore). 
# Se il progetto viene distrutto, i programmatori devono poter continuare a esistere.

class Progetto:
  def __init__(self, nome_progetto) -> None:
    self.nome_progetto = nome_progetto
    self.listaProgrammatori=[] #molteplicita 0.*
  def aggiungi_programmatore(self,programmatore):
    self.listaProgrammatori.append(programmatore)
    
class Programmatore:
  def __init__(self, nome):
    self.nome = nome

# ESERCIZIO 6
# Crea due classi: Libro e Capitolo. Un libro è composto da 1..* capitoli. 
# La classe Libro deve avere un metodo aggiungi_capitolo(titolo, pagine). 
# L'istanza dell'oggetto Capitolo deve essere creata all'interno di questo metodo, non passata dall'esterno. 
# Nel __del__ del Libro, svuota esplicitamente la lista dei capitoli.

class Libro:
  def __init__(self) -> None:
    self.listaCapitoli=[]
  def aggiungi_capitolo(self,titolo, pagine):
    nuovo_capitolo=Capitolo(titolo,pagine)
    self.listaCapitoli.append(nuovo_capitolo)
  def __del__(self):
    self.listaCapitoli.clear()

class Capitolo:
  def __init__(self,titolo,pag):
    self.titolo=titolo
    self.pagine=pag

# ESERCIZIO 7
# Importa ABC e abstractmethod dal modulo abc. Crea una classe astratta FormaGeometrica con un metodo astratto calcola_area(). 
# Crea due classi concrete: Quadrato (che prende il lato) e Cerchio (che prende il raggio). 
# Implementa il metodo calcola_area() in entrambe seguendo le relative formule matematiche.
class FormaGeometrica(ABC):
  @abstractmethod
  def calcola_area(self):
    """Metodo astratto: non fa nulla, obbliga le figlie a scriverlo."""

class Quadrato(FormaGeometrica):
  def __init__(self, lato):
    self.lato = lato
  def calcola_area(self):
    return self.lato * self.lato        
class Cerchio(FormaGeometrica):
  def __init__(self, raggio):
    self.raggio = raggio       
  def calcola_area(self):
    return math.pi * (self.raggio ** 2)
  
# ESERCIZIO 10
# Crea le classi Utente e Conto. Un utente può avere più conti, e un conto può essere cointestato a più utenti. 
# Crea una terza classe Titolarita (la classe di associazione) che viene creata quando un utente si associa a un conto. 
# Questa classe deve contenere gli attributi data_iscrizione e tipo_firma (es. "singola" o "congiunta"). 
# Crea uno script di prova in cui due utenti diversi hanno firme diverse sullo stesso conto

class Utente:
  def __init__(self,nome) -> None:
    self.nome=nome

class Conto:
    def __init__(self):
        self.lista_titolari = [] # Qui salveremo le istanze della classe di associazione!
    def aggiungi_utente(self, utente, data_iscrizione, tipo_firma):
        nuovo_collegamento = Titolarita(utente, self, data_iscrizione, tipo_firma)
        self.lista_titolari.append(nuovo_collegamento)

class Titolarita:
    # La classe di associazione collega CHI e COSA, e aggiunge i dettagli del COME
    def __init__(self, utente, conto, data_iscrizione, tipo_firma):
        self.utente = utente
        self.conto = conto
        self.data_iscrizione = data_iscrizione
        self.tipo_firma = tipo_firma
if __name__=="__main__":
  utente1 = Utente("Mario")
  utente2 = Utente("Luigi")
  mio_conto = Conto()
  mio_conto.aggiungi_utente(utente1, "12/06/2026", "Dispositiva")
  mio_conto.aggiungi_utente(utente2, "13/06/2026", "Consultiva")
  print(f"Firma di {mio_conto.lista_titolari[0].utente.nome}: {mio_conto.lista_titolari[0].tipo_firma}")
  print(f"Firma di {mio_conto.lista_titolari[1].utente.nome}: {mio_conto.lista_titolari[1].tipo_firma}")

