# ES 1
# sistema per gestire l'acquisto di materiale didattico, un'eccezione personalizzata CreditiInsufficientiError, la classe Utente con un attributo privato _crediti,
# classe astratta MaterialeDidattico con un attributo titolo e un metodo astratto accedi(), CorsoVideo e Ebook. Fai l'overriding del metodo accedi() affinché stampi messaggi diversi
from abc import ABC, abstractmethod
class CreditiInsufficientiError(Exception):
  pass
class Utente_es1:
  def __init__(self,nome,crediti=0) -> None:
    self.crediti=crediti
    self.nome=nome
  @property
  def crediti(self):
    return self._crediti
  @crediti.setter
  def crediti(self,crediti):
    if crediti>=0:
      self._crediti=crediti
    else:
      raise CreditiInsufficientiError("crediti insufficienti")
    
class MaterialeDidattico(ABC):
  def __init__(self,titolo) -> None:
    self.titolo=titolo
  @abstractmethod
  def accedi(self):
    pass

class CorsoVideo(MaterialeDidattico):
  def __init__(self, titolo) -> None:
    super().__init__(titolo)
  def accedi(self):
    return f"Avvio riproduzione video di {self.titolo}"
class Ebook (MaterialeDidattico):
  def __init__(self, titolo) -> None:
    super().__init__(titolo)
  def accedi(self):
    return f"Apertura PDF di {self.titolo}"
  
# ES 2
class LineaBus:
  totale_linee_attive=0
  def __init__(self,numero_linea) -> None:
    self.numero_linea=numero_linea
    LineaBus.totale_linee_attive+=1
  def __del__(self):
    LineaBus.totale_linee_attive-=1
  def __repr__(self) -> str:
    return f"Linea Bus numero {self.numero_linea}"

class Fermata:
  def __init__(self, nome) -> None:
    self.nome_fermata=nome
  def __repr__(self) -> str:
    return f"fermata: {self.nome_fermata}"

class Transito:
  def __init__(self, lineabus: LineaBus,fermata: Fermata, orario_passaggio, ordine_fermata) -> None:
    self.linea=lineabus
    self.fermata=fermata
    self.orario_passaggio=orario_passaggio
    self.ordine_fermata=ordine_fermata
  def __repr__(self) -> str:
    return f"Linea {self.linea.numero_linea} passa a {self.fermata.nome_fermata} alle {self.orario_passaggio}"
  
# ES 3
class Dipendente:
  def __init__(self, nome, ruolo) -> None:
    self.nome=nome
    self.ruolo=ruolo
class Dipartimento:
  def __init__(self,nome) -> None:
    self.nome=nome
    self.lista_dipendenti = []
  def assumi_dipendente(self,dipendente):
    self.lista_dipendenti.append(dipendente)
class Azienda:
  def __init__(self) -> None:
    self.lista_dipartimenti = []
  def apri_dipartimento(self,nome_dipartimento):
    self.lista_dipartimenti.append(Dipartimento(nome_dipartimento))
  def __del__(self):
    self.lista_dipartimenti.clear()
#  ------------------------------
# ES 4
import unittest
class NumeroNottiError(Exception):
  pass
class Prenotazione:
  def __init__(self, cliente, prezzo_notte, notti) -> None:
    self.cliente=cliente
    self.prezzo=prezzo_notte
    self.set_notti(notti)
  def set_notti(self,notti):
    if notti>0:
      self.notti=notti
    else: raise NumeroNottiError("errore notti")
  def calcola_totale(self):
    return self.prezzo*self.notti

class PrenotazioneVIP(Prenotazione):
  def __init__(self, cliente, prezzo_notte, notti, costo_spa) -> None:
    super().__init__(cliente, prezzo_notte, notti)
    self.costo_spa=costo_spa
  def calcola_totale(self):
    costobase=super().calcola_totale()
    return costobase+self.costo_spa
  
class test_prenotazione(unittest.TestCase):
  def test_prenotazione_VIP(self):
    self.prenota_vip=PrenotazioneVIP("nome", 120, 2,20)
    self.assertEqual(self.prenota_vip.calcola_totale(),260)

  def test_prenotazione_base(self):
    with self.assertRaisesRegex(NumeroNottiError,"errore notti"):
      self.prenota_base=Prenotazione("nome", 120, -2)

# ES 5
class RitardoNegativoError(Exception):
  pass
class Articolo(ABC):
  def __init__(self,penale) -> None:
    self.penale=penale
  @abstractmethod
  def applica_penale(self,giorni):
    pass
  
class LibroFisico(Articolo):
  def __init__(self):
    super().__init__(1)
  def applica_penale(self, giorni):
    return giorni*self.penale
class Rivista(Articolo):
  def __init__(self):
    super().__init__(2)
  def applica_penale(self, giorni):
    return giorni*self.penale

class Utente:
  def __init__(self,articoli:list[Articolo]) -> None:
    self.__articoli=articoli
  @property
  def articoli(self):
    return self.__articoli

class Prestito:
  def __init__(self, utente, articolo, giorni_di_ritardo) -> None:
    self.utente=utente
    self.articolo=articolo
    if giorni_di_ritardo<0:
      raise RitardoNegativoError
    else: 
      self.giorniRitardo=giorni_di_ritardo
    
class test_es5(unittest.TestCase):
  def test(self):
    articolo1=LibroFisico()
    articolo2=Rivista()
    utente=Utente([articolo1, articolo2])
    self.assertEqual(utente.articoli[1],articolo2)
    self.assertNotEqual(articolo1.applica_penale(2),articolo2.applica_penale(2))
    with self.assertRaises(RitardoNegativoError):
      Prestito(utente,articolo2,-2)