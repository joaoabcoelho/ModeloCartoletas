
class Atleta:

  def __init__(self):
    self.pontos = 0
    self.preco = 5
    self.preco_medio = 5
    self.media = 0
    self.jogos = 0
    self.rodada_inicial = 1


def GetValorizacao(atleta, rodada, fator_inflacao):

  # Abreviacoes
  r  = rodada
  s  = fator_inflacao

  r0 = atleta.rodada_inicial
  p  = atleta.pontos
  a  = atleta.media
  g  = atleta.jogos
  cm = atleta.preco_medio

  # Média de pontos por rodada
  am = (g*a+p) / (r-r0+1)

  novo_preco = s * (p + 4*am + 5*cm)

  # Assegura um preço mínimo de C$0.75
  if novo_preco < 0.75: novo_preco = 0.75

  return novo_preco - atleta.preco


def GetFatorInflacao(atletas, rodada):

  n_atletas = len(atletas)
  
  if n_atletas==0: return 0.15

  c_mean = 0 # Média de preço
  denom = 0  # Média do novo preço

  for i in range(n_atletas):
    c_mean += atletas[i].preco
    denom  += GetValorizacao(atletas[i], rodada, 1)
  
  c_mean /= n_atletas
  denom  /= n_atletas
  denom  += c_mean

  # Primeira estimativa do fator de inflação
  fator_inflacao = c_mean / denom

  # Cacula a valorização média para corrigir
  # efeitos residuais devido ao preço mínimo
  val_media = 0
  for i in range(n_atletas):
    val_media += GetValorizacao(atletas[i], rodada, fator_inflacao)
  val_media /= n_atletas

  # Reduz o preço médio para compensar
  # os atletas com preço mínimo
  c_mean -= val_media

  # fator de correção da inflação final
  fator_inflacao = c_mean / denom
  
  return fator_inflacao
