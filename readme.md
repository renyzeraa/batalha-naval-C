# Batalha Naval com Habilidades Especiais

Este é um jogo de Batalha Naval desenvolvido em C, onde você pode posicionar navios no tabuleiro e aplicar habilidades especiais com diferentes áreas de efeito. O jogo exibe o tabuleiro com navios e áreas afetadas pelas habilidades, incluindo um formato de cone, cruz e octaedro. O objetivo principal deste projeto é demonstrar como implementar essas habilidades e suas áreas de efeito em um ambiente de Batalha Naval.

## Funcionalidades

- **Tabuleiro 10x10**: Representação do jogo com posições de navios e áreas de efeito das habilidades.
- **Posicionamento de Navios**: Quatro navios são posicionados no tabuleiro, sendo dois horizontais, um vertical e dois diagonais.
- **Habilidades Especiais**: Implementação de três tipos de habilidades com áreas de efeito:
  - **Cone**: Área em forma de cone, com origem no topo e se expandindo para baixo.
  - **Cruz**: Área em forma de cruz com origem no centro.
  - **Octaedro**: Área em forma de octaedro (como um losango) com origem no centro.
- **Visualização**: O tabuleiro é exibido no console com diferentes símbolos para representar:
  - `0`: Água
  - `3`: Navio
  - `5`: Área afetada por uma habilidade

## Estrutura do Projeto

- **tabuleiro.c**: Contém as funções para inicializar o tabuleiro, posicionar os navios e aplicar as habilidades especiais.
- **main.c**: Contém a função principal onde o tabuleiro é configurado e as habilidades são aplicadas.

## Como Executar

1. **Pré-requisitos**:

   - Compilador C (por exemplo, GCC).
   - Sistema operacional com suporte a compiladores C.

2. **Passos para execução**:

   1. Clone este repositório para sua máquina local:

      ```bash
      git clone https://github.com/seu-usuario/batalha-naval.git
      ```

   2. Acesse o diretório do projeto:

      ```bash
      cd batalha-naval
      ```

   3. Compile o código com o compilador GCC:

      ```bash
      gcc -o batalha_naval main.c tabuleiro.c
      ```

   4. Execute o programa:
      ```bash
      ./batalha_naval
      ```

3. **Saída Esperada**:
   O programa exibirá o tabuleiro no console, mostrando os navios e as áreas afetadas pelas habilidades.

## Exemplo de Saída

Após a execução, a saída do programa exibirá o tabuleiro com navios e áreas de efeito das habilidades. Aqui está um exemplo de saída:

**Tabuleiro Final:**

```
0 0 3 0 0 0 0 0 0 0 0 3 3 3 0 0 0 0 0 0 3 3 3 3 3 0 0 0 0 0 0 3 3 3 0 0 5 5 5 0 0 0 5 3 5 3 3 0 0 0 0 0 5 5 5 3 0 0 0 0 0 0 0 5 3 3 0 0 0 0 0 0 0 3 3 3 3 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```

- `3` representa os navios.
- `5` representa as áreas afetadas pelas habilidades.
- `0` representa a água.
