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
  rodada = int(row[0])
  atleta_id = int(row[1])
  clube = row[2]
  posicao = row[3]
  nome = row[4]
  atleta.jogos = int(row[5])
  atleta.preco = float(row[6])
  atleta.preco_medio = float(row[7])
  atleta.media = float(row[8])
  atleta.pontos = float(row[9])
  valorizacao = float(row[10])
  
  atletas.append(atleta);
  valorizacoes.append(valorizacao);


fator_inflacao = GetFatorInflacao(atletas, rodada)

erros = []
n_atletas = len(atletas)
for i in range(n_atletas):
  previsao = GetValorizacao(atletas[i], rodada, fator_inflacao)
  erros.append(previsao - valorizacoes[i])

erroMedio = np.mean(erros)

erroRMS = np.sqrt(np.mean(np.square(erros)))

print("O erro da previsão foi approximadamente: {:.5f} +/- {:.5f}".format(erroMedio, erroRMS))
