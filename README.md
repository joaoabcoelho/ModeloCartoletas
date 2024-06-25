# ModeloCartoletas

Essa é uma implementação do provável modelo exato de valorização do CartolaFC e utilizado pelo CartolaAnalitico. Uma descrição mais aprofundada do modelo pode ser encontrada [aqui](https://medium.com/cartolaanalitico/a-f%C3%B3rmula-de-valoriza%C3%A7%C3%A3o-8064b82b0f0 "A fórmula de valorização").

Na versão v2, implementamos o novo modelo válido a partir de 2024. A principal mudança é que agora a média de preço é computada apenas após jogos em que o atleta atuou.

## ModeloCartoleta.h

Contém o modelo em si. São necessários os seguintes dados do jogador para prever a valorização:

* Pontuação na rodada em questão
* Preço do jogador
* Média do jogador
* Número de jogos que participou
* Preço médio do jogador ao longo do ano
* Número da rodada em questão

A previsão leva em conta uma correção de inflação, e para isso é necessário contabilizar todos os atletas que atuaram. Esse fator sempre gira em torno de 0.13 e essa pode ser uma estimativa inicial caso não seja possível utilizar todos os atletas.

## DadosExemplo.csv

Contém um exemplo com todos os atletas que atuaram na rodada 10 CartolaFC 2024, incluindo todas as variáveis necessárias e também a valorização real que cada atleta obteve na rodada.

## TestCartoleta.C

Um exemplo de como aplicar o modelo aos dados acima. Como resultado, são informadas o erro médio (accuracy) da previsão e o desvio padrão da distribuição de erros (precision). A precisão do modelo é menor que C$0.01.

## Performance (modelo 2023)

O modelo 2024 também tem sido testado e funciona tão bem quanto, porém ainda falta entender como funciona a valorização quando o jogador toma cartão no banco.

Testamos o nosso modelo com dados do CartolaFC entre 2018 e 2020 e obtivemos resultados quase perfeitos. Os erros remanescentes parecem ser relacionados a alguns fatores minoritários como a definição do preço mínimo do jogador, a estratégia de arredondamento, e alguns erros da base de dados quando atletas são retirados do mercado no meio de uma rodada.

Como exemplo temos aqui a distribuição de resíduos do modelo em função do preço do jogador ao fim da rodada para as 11 primeiras rodadas do CartolaFC 2020.

![Alt text](img/Erros_R11_2020.jpeg?raw=true "Erro do modelo para as 11 primeiras rodadas de 2020")
