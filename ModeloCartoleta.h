#include <vector>

struct Atleta {

  float pontos;
  float preco;
  float preco_medio;
  float media;
  int jogos;

};

float GetValorizacao(Atleta atleta, int rodada, float fator_inflacao) {

  // Abreviacoes
  float s  = fator_inflacao;

  float p  = atleta.pontos;
  float a  = atleta.media;
  float g  = atleta.jogos;
  float cm = atleta.preco_medio;

  float kp = 1.5 * (1 + 1/(g+1));
  float ka = 2 + g/2;
  float kc = 7 - g/2;

  if(g>4){
    ka = 4;
    kc = 5;
    kp = 1 + 4/(g+1);
  }

  if(rodada>4) ka *= g / (g+1);

  if(g==0) a = 0;

  float novo_preco = s * (kp * p + ka * a + kc * cm);

  // Assegura um preço mínimo de C$0.7
  if(novo_preco < 0.7) novo_preco = 0.7;

  return novo_preco - atleta.preco;

}

float GetFatorInflacao(std::vector<Atleta> atletas, int rodada) {

  int n_atletas = atletas.size();

  if(n_atletas==0) return 0.13;

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
