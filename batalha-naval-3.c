#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
  for (int i = 0; i < TAMANHO; i++)
  {
    for (int j = 0; j < TAMANHO; j++)
    {
      tabuleiro[i][j] = 0; // Inicializa com água
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

// Função para criar a matriz de habilidade em forma de Cone
void criarHabilidadeCone(int habilidade[5][5])
{
  int tamanho = 5;
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      if (j >= tamanho - 1 - i)
      {
        habilidade[i][j] = 1; // Preenche a área do cone com 1
      }
      else
      {
        habilidade[i][j] = 0; // Áreas não afetadas
      }
    }
  }
}

// Função para criar a matriz de habilidade em forma de Cruz
void criarHabilidadeCruz(int habilidade[5][5])
{
  int tamanho = 5;
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      if (i == 2 || j == 2)
      {
        habilidade[i][j] = 1; // Preenche a área da cruz com 1
      }
      else
      {
        habilidade[i][j] = 0; // Áreas não afetadas
      }
    }
  }
}

// Função para criar a matriz de habilidade em forma de Octaedro
void criarHabilidadeOctaedro(int habilidade[5][5])
{
  int tamanho = 5;
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      if (i + j >= 2 && i + j <= 6 && i - j <= 2 && j - i <= 2)
      {
        habilidade[i][j] = 1; // Preenche a área do octaedro com 1
      }
      else
      {
        habilidade[i][j] = 0; // Áreas não afetadas
      }
    }
  }
}

// Função para aplicar a área de efeito de uma habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int linha, int coluna)
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int l = linha + i - 2; // Ajusta para centralizar a habilidade no ponto de origem
      int c = coluna + j - 2;
      if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && habilidade[i][j] == 1)
      {
        if (tabuleiro[l][c] == 0)
        {
          tabuleiro[l][c] = HABILIDADE; // Marca a área afetada pela habilidade
        }
      }
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
      if (tabuleiro[i][j] == 0)
      {
        printf(" 0 "); // Água
      }
      else if (tabuleiro[i][j] == NAVIO)
      {
        printf(" 3 "); // Navio
      }
      else if (tabuleiro[i][j] == HABILIDADE)
      {
        printf(" 5 "); // Área afetada pela habilidade
      }
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

  // Posicionar os navios
  posicionarNavioHorizontalVertical(tabuleiro, linha1, coluna1, 1); // Horizontal
  posicionarNavioHorizontalVertical(tabuleiro, linha2, coluna2, 0); // Vertical
  posicionarNavioDiagonal(tabuleiro, linha3, coluna3, 1);           // Diagonal principal
  posicionarNavioDiagonal(tabuleiro, linha4, coluna4, -1);          // Diagonal secundária

  // Criar as matrizes de habilidade
  int cone[5][5];
  int cruz[5][5];
  int octaedro[5][5];

  criarHabilidadeCone(cone);
  criarHabilidadeCruz(cruz);
  criarHabilidadeOctaedro(octaedro);

  // Aplicar as habilidades no tabuleiro (definindo pontos de origem para as habilidades)
  aplicarHabilidade(tabuleiro, cone, 3, 3);     // Cone na posição (3, 3)
  aplicarHabilidade(tabuleiro, cruz, 5, 5);     // Cruz na posição (5, 5)
  aplicarHabilidade(tabuleiro, octaedro, 7, 7); // Octaedro na posição (7, 7)

  // Exibir o tabuleiro
  exibirTabuleiro(tabuleiro);

  return 0;
}
