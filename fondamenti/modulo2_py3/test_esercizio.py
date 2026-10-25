import unittest
import esercizio

class testEs(unittest.TestCase):
# ESERCIZIO 8
# Crea una classe di test usando il modulo unittest. Scrivi un test per la classe Termometro (dell'Esercizio 2). 
# Istanzi il termometro a 20 gradi, cambialo a 30, e usa assertEqual per verificare che la modifica sia avvenuta correttamente.
  def test_es8(self):
    self.termometro=esercizio.Termometro(20)
    self.termometro.temperatura=30
    self.assertEqual(self.termometro.temperatura,30)

# ESERCIZIO 9
# scrivi un test per la classe ContoBancario (dell'Esercizio 3). Istanzi un conto con saldo 50. 
# Usa assertRaisesRegex per assicurarti che chiamare preleva(100) sollevi esattamente 
# la classe FondiInsufficientiError e che il messaggio contenga il testo corretto.
  def test_es9(self):
    self.conto=esercizio.ContoBancario(50)
    with self.assertRaisesRegex(esercizio.FondiInsufficientiError,"importo troppo alto"):
      self.conto.preleva(100)

