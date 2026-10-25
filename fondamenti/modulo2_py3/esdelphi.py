class Delphi():
  def __init__(self):
    self.lista_corsi=[]
  def aggiungiCorso(self,nomeCorso:str,codiceCorso:str):
    self.nuovoCorso=corso(codiceCorso,nomeCorso)
    self.lista_corsi.append(self.nuovoCorso)
  def __repr__(self) -> str:
    return f"Delphi: corsi disponibili {len(self.lista_corsi)}"
    

class corso():
  voto_min_approvato=18
  voto_max=30
  def __init__(self,codice:str,nome_corso:str):
    self._codice=codice
    self.nome_corso=nome_corso
    self.__studentiIscritti=[]

  def iscriviStudente(self,nome:str,matricola:int):
    self.nuovoStudente=studente(nome,matricola)
    self.__studentiIscritti.append(self.nuovoStudente)

  def aggiungiVoto(self, voto:int, matricola:int):
    if voto>=self.voto_min_approvato and voto<=self.voto_max:
      self.voto=voto
      studente=next((s for s in self.__studentiIscritti if s.matricola == matricola), None)
      if studente:
        studente.__voti.append(self.voto)
      # else raise exep
  
  def __repr__(self) -> str:
    return f"corso: {self.nome_corso} {self._codice}: {len(self.__studentiIscritti)} studenti iscritti"
  def __del__(self):
    print(f"rimosso corso {self.nome_corso} con {len(self.__studentiIscritti)} iscritti")
    

class studente():
  def __init__(self, nome:str, matricola:int):
    self.nome=nome
    self._matricola=matricola
    self.__voti=[]

  def __repr__(self) -> str:
    return f"studente: {self.nome}, {self._matricola}"
  def __del__(self):
    print(f"studente {self._matricola} rimosso")
    