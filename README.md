# ModeloCartoletas

Essa é uma implementação do modelo exato de valorização do Cartola e utilizado pelo CartolaAnalitico. Uma descrição mais aprofundada do modelo pode ser encontrada [aqui](https://medium.com/cartolaanalitico/a-f%C3%B3rmula-de-valoriza%C3%A7%C3%A3o-2025-51f19d97fb4a).

Na versão v3, implementamos o novo modelo válido a partir de 2025. A principal mudança é que agora a fórmula não depende mais da rodada, mas apenas do número de jogos.

## ModeloCartoleta.h

Contém o modelo em si. São necessários os seguintes dados do jogador para prever a valorização:

* Pontuação na rodada em questão
* Preço do jogador
* Média do jogador
* Número de jogos que participou
* Preço médio do jogador ao longo do ano

A previsão leva em conta uma correção de inflação, e para isso é necessário contabilizar todos os atletas que atuaram. Esse fator sempre gira em torno de 0.13 e essa pode ser uma estimativa inicial caso não seja possível utilizar todos os atletas.

## DadosExemplo.csv

Contém um exemplo com todos os atletas que atuaram na rodada 4 CartolaFC 2025, incluindo todas as variáveis necessárias e também a valorização real que cada atleta obteve na rodada.

## TestCartoleta.C

Um exemplo de como aplicar o modelo aos dados acima. Como resultado, são informadas o erro médio (accuracy) da previsão e o desvio padrão da distribuição de erros (precision). A precisão do modelo é menor que C$0.01.

## Performance

O modelo 2025 tem sido testado e funciona quase perfeitamente, porém ainda falta entender como funciona a valorização quando o jogador toma cartão no banco. Também não sabemos ainda como o Cartola determina o preço mínimo que um jogador pode ter, que parece variar ao longo do ano.
