# ModeloCartoletas

Esse é um modelo simples de regressão linear utilizado no CartolaAnalitico para prever valorização de jogadores no CartolaFC.

## ModeloCartoleta.h

Contém o modelo em si. São necessários os seguintes dados do jogador para prever a valorização:

* Pontuação na rodada em questão
* Pontuação na última rodada em que o atleta jogou
* Preço do jogador
* Média do jogador
* Número de jogos que participou
* Número de jogos que foi desfalque desde o último jogo
* Número da rodada em questão
* Número da rodada em que o jogador foi adicionado no CartolaFC

## DadosExemplo.csv

Contém cerca de mil exemplos de jogadores do CartolaFC 2018 com todas as variáveis necessárias e também a valorização real que o jogador obteve na rodada.

## TestCartoleta.C

Um exemplo de como aplicar o modelo aos dados acima. Como resultado, são informadas o erro médio (accuracy) da previsão e o desvio padrão da distribuição de erros (precision). A precisão do modelo é de aproximadamente C$0.08.
