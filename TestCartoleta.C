#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <numeric>

#include "ModeloCartoleta.h"

using namespace std;

int main(){

  string line;

  string datafilename = "DadosExemplo_v2.csv";

  ifstream datafile(datafilename.c_str());

  if(!datafile){
    cerr << "Arquivo " << datafilename << " não existe." << endl;
    return 1;
  }

  vector<float> valorizacoes;
  vector<Atleta> atletas;

  getline(datafile, line);
  
  while( getline(datafile, line) ){

    istringstream ss(line);

    char delim = ',';
    string buffer;
    
    int    atleta_id;
    float  valorizacao;
    string clube, posicao, nome;

    Atleta atleta;
    
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &atleta_id);
    getline(ss, buffer, delim); clube = buffer;
    getline(ss, buffer, delim); posicao = buffer;
    getline(ss, buffer, delim); nome = buffer;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &atleta.rodada_inicial);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &atleta.jogos);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &atleta.preco);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &atleta.preco_medio);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &atleta.media);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &atleta.pontos);
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &valorizacao);
    
    atletas.push_back(atleta);
    valorizacoes.push_back(valorizacao);
    
  }
  
  int rodada = 5;
  
  float fator_inflacao = GetFatorInflacao(atletas, rodada);
  
  vector<float> erros;  
  int n_atletas = atletas.size();
  for(int i=0; i<n_atletas; i++){
    float previsao = GetValorizacao(atletas[i], rodada, fator_inflacao);
    erros.push_back(previsao - valorizacoes[i]);
  }
    
  float erroMedio = accumulate( erros.begin(), erros.end(), 0.0)/erros.size();

  float sq_sum  = std::inner_product(erros.begin(), erros.end(), erros.begin(), 0.0);
  float erroRMS = sqrt(sq_sum / erros.size() - erroMedio * erroMedio);
  
  cout << "O erro da previsão foi approximadamente: " << erroMedio << " +/- " << erroRMS << endl;
  
  return 0;

}
