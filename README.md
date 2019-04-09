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

## Performance

Testamos o nosso modelo com dados do CartolaFC 2018 e obtivemos um resultado muito melhor que um modelo antigo mais simples de 2018. O novo modelo tem uma precisão de aproximadamente C$0.08.

![Alt text](img/NovaValorizacao.png?raw=true "Comparação da precisão dos modelos 2018 e 2019")

Também testamos o impacto de remover cada uma das variáveis. Mostramos aqui as principais delas para diferentes rodadas.

![Alt text](img/Importancia.png?raw=true "Impacto da remoção de algumas variáveis do modelo")
