#include <vector>

struct Atleta {

  float pontos;
  float preco;
  float preco_medio;
  float media;
  int jogos;
  int rodada_inicial;

};

float GetValorizacao(Atleta atleta, int rodada, float fator_inflacao) {

  // Abreviacoes
  int   r  = rodada;
  float s  = fator_inflacao;

  int   r0 = atleta.rodada_inicial;
  float p  = atleta.pontos;
  float a  = atleta.media;
  float g  = atleta.jogos;
  float cm = atleta.preco_medio;

  // Média de pontos por rodada
  float am = (g*a+p) / (r-r0+1);

  float novo_preco = s * (p + 4*am + 5*cm);

  // Assegura um preço mínimo de C$0.75
  if(novo_preco < 0.75) novo_preco = 0.75;

  return novo_preco - atleta.preco;

}

float GetFatorInflacao(std::vector<Atleta> atletas, int rodada) {

  int n_atletas = atletas.size();
  
  if(n_atletas==0) return 0.15;

  float c_mean = 0; // Média de preço
  float denom = 0;  // Média do novo preço

  for(int i=0; i<n_atletas; i++){
    c_mean += atletas[i].preco;
    denom += GetValorizacao(atletas[i], rodada, 1);
  }
  
  c_mean /= n_atletas;
  denom /= n_atletas;
  denom += c_mean;

  // Primeira estimativa do fator de inflação
  float fator_inflacao = c_mean / denom;

  // Cacula a valorização média para corrigir
  // efeitos residuais devido ao preço mínimo
  float val_media = 0;
  for(int i=0; i<n_atletas; i++){
    val_media += GetValorizacao(atletas[i], rodada, fator_inflacao);
  }
  val_media /= n_atletas;

  // Reduz o preço médio para compensar
  // os atletas com preço mínimo
  c_mean -= val_media;

  // fator de correção da inflação final
  fator_inflacao = c_mean / denom;
  
  return fator_inflacao;

}
