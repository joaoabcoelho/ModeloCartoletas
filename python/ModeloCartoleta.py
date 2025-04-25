
class Atleta:

  def __init__(self):
    self.pontos = 0
    self.preco = 5
    self.preco_medio = 5
    self.media = 0
    self.jogos = 0


def GetValorizacao(atleta, fator_inflacao):

  # Abreviacoes
  s  = fator_inflacao

  p  = atleta.pontos
  a  = atleta.media
  g  = atleta.jogos
  cm = atleta.preco_medio

  a = (a*g + p)/(g+1)
  g = g+1

  ka = (3 + g)/2
  kc = (15 - g)/2

  if g>5:
    ka = 4
    kc = 5

  novo_preco = s * (p + ka * a + kc * cm)

  # Assegura um preço mínimo de C$0.7
  if novo_preco < 0.7: novo_preco = 0.7

  return novo_preco - atleta.preco


def GetFatorInflacao(atletas):

  n_atletas = len(atletas)
  
  if n_atletas==0: return 0.15

  c_mean = 0 # Média de preço
  denom = 0  # Média do novo preço

  for i in range(n_atletas):
    c_mean += atletas[i].preco
    denom  += GetValorizacao(atletas[i], 1)
  
  c_mean /= n_atletas
  denom  /= n_atletas
  denom  += c_mean

  # Primeira estimativa do fator de inflação
  fator_inflacao = c_mean / denom

  # Cacula a valorização média para corrigir
  # efeitos residuais devido ao preço mínimo
  val_media = 0
  for i in range(n_atletas):
    val_media += GetValorizacao(atletas[i], fator_inflacao)
  val_media /= n_atletas

  # Reduz o preço médio para compensar
  # os atletas com preço mínimo
  c_mean -= val_media

  # fator de correção da inflação final
  fator_inflacao = c_mean / denom
  
  return fator_inflacao
