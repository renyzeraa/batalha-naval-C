#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
  for (int i = 0; i < TAMANHO; i++)
  {
    for (int j = 0; j < TAMANHO; j++)
    {
      tabuleiro[i][j] = 0;
    }
  }
}

// Função para posicionar um navio horizontal ou vertical
void posicionarNavioHorizontalVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal)
{
  if (horizontal)
  {
    for (int i = 0; i < NAVIO; i++)
    {
      tabuleiro[linha][coluna + i] = NAVIO;
    }
  }
  else
  {
    for (int i = 0; i < NAVIO; i++)
    {
      tabuleiro[linha + i][coluna] = NAVIO;
    }
  }
}

// Função para posicionar um navio diagonal (só para direções válidas)
void posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int diagonal)
{
  if (diagonal == 1)
  { // Diagonal principal (linha e coluna aumentam)
    for (int i = 0; i < NAVIO; i++)
    {
      tabuleiro[linha + i][coluna + i] = NAVIO;
    }
  }
  else
  { // Diagonal secundária (linha aumenta e coluna diminui)
    for (int i = 0; i < NAVIO; i++)
    {
      tabuleiro[linha + i][coluna - i] = NAVIO;
    }
  }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
  for (int i = 0; i < TAMANHO; i++)
  {
    for (int j = 0; j < TAMANHO; j++)
    {
      printf("%2d ", tabuleiro[i][j]); // Espaço de 2 para melhor visualização
    }
    printf("\n");
  }
}

int main()
{
  int tabuleiro[TAMANHO][TAMANHO];
  inicializarTabuleiro(tabuleiro);

  // Posicionamento dos navios
  int linha1 = 2, coluna1 = 3; // Horizontal
  int linha2 = 5, coluna2 = 6; // Vertical
  int linha3 = 1, coluna3 = 1; // Diagonal principal
  int linha4 = 7, coluna4 = 8; // Diagonal secundária

  // Garantir que os navios não ultrapassem os limites (exemplo simplificado)
  if (coluna1 + NAVIO <= TAMANHO)
  {
    posicionarNavioHorizontalVertical(tabuleiro, linha1, coluna1, 1); // Horizontal
  }

  if (linha2 + NAVIO <= TAMANHO)
  {
    posicionarNavioHorizontalVertical(tabuleiro, linha2, coluna2, 0); // Vertical
  }

  if (linha3 + NAVIO <= TAMANHO && coluna3 + NAVIO <= TAMANHO)
  {
    posicionarNavioDiagonal(tabuleiro, linha3, coluna3, 1); // Diagonal principal
  }

  if (linha4 + NAVIO <= TAMANHO && coluna4 - NAVIO >= 0)
  {
    posicionarNavioDiagonal(tabuleiro, linha4, coluna4, -1); // Diagonal secundária
  }

  // Exibir o tabuleiro
  exibirTabuleiro(tabuleiro);

  return 0;
}
