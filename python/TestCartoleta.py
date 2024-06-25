import sys
import numpy as np
from glob import glob
from ModeloCartoleta import Atleta, GetFatorInflacao, GetValorizacao

datafilename = "../DadosExemplo.csv";

if len(glob(datafilename))==0:
  print("Arquivo " + datafilename + " não existe.")
  sys.exit()

valorizacoes = []
atletas = []

data = np.loadtxt(datafilename, delimiter=',', dtype=str)

for row in data[1:]:
  atleta = Atleta()
  atleta_id = int(row[0])
  clube = row[1]
  posicao = row[2]
  nome = row[3]
  atleta.jogos = int(row[4])
  atleta.preco = float(row[5])
  atleta.preco_medio = float(row[6])
  atleta.media = float(row[7])
  atleta.pontos = float(row[8])
  valorizacao = float(row[9])
  
  atletas.append(atleta);
  valorizacoes.append(valorizacao);


rodada = 5

fator_inflacao = GetFatorInflacao(atletas, rodada)

erros = []
n_atletas = len(atletas)
for i in range(n_atletas):
  previsao = GetValorizacao(atletas[i], rodada, fator_inflacao)
  erros.append(previsao - valorizacoes[i])

erroMedio = np.mean(erros)

erroRMS = np.sqrt(np.mean(np.square(erros)))

print("O erro da previsão foi approximadamente: {:.5f} +/- {:.5f}".format(erroMedio, erroRMS))
