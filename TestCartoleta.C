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

  string datafilename = "DadosExemplo.csv";

  ifstream datafile(datafilename.c_str());

  if(!datafile){
    cerr << "Arquivo " << datafilename << " não existe." << endl;
    return 1;
  }

  vector<float> erros;

  getline(datafile, line);
  
  while( getline(datafile, line) ){

    istringstream ss(line);

    char delim = ',';
    string buffer;
    
    int    jogadorId;
    float  valorizacao;
    string posicao;

    PlayerData player;
    
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &jogadorId);;
    getline(ss, buffer, delim); posicao = buffer;  
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &player.rodadaAtual);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &player.rodadaInicial);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &player.pontos);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &player.preco);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &player.ultima);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &player.media);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &player.jogos);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%d", &player.desfalques);;
    getline(ss, buffer, delim); sscanf(buffer.c_str(), "%f", &valorizacao);;
    
    float previsao = GetCartoletas(player);
    
    erros.push_back(previsao - valorizacao);
    
  }
  
  float erroMedio = accumulate( erros.begin(), erros.end(), 0.0)/erros.size();

  float sq_sum  = std::inner_product(erros.begin(), erros.end(), erros.begin(), 0.0);
  float erroRMS = sqrt(sq_sum / erros.size() - erroMedio * erroMedio);
  
  cout << "O erro da previsão foi approximadamente: " << erroMedio << " +/- " << erroRMS << endl;
  
  return 0;

}
