#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se o navio pode ser posicionado sem ultrapassar os limites
bool validar_posicao(int linha, int coluna, int orientacao, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
  if (orientacao == 0)
  { // Horizontal
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
      return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
      if (tabuleiro[linha][coluna + i] != 0)
        return false;
    }
  }
  else
  { // Vertical
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
      return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
      if (tabuleiro[linha + i][coluna] != 0)
        return false;
    }
  }
  return true;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int linha, int coluna, int orientacao, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
  if (orientacao == 0)
  { // Horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
      tabuleiro[linha][coluna + i] = 3;
    }
  }
  else
  { // Vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
      tabuleiro[linha + i][coluna] = 3;
    }
  }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
  printf("Tabuleiro:\n");
  for (int i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++)
    {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

  // Coordenadas e orientações dos navios
  int linha1 = 2, coluna1 = 3, orientacao1 = 0; // Horizontal
  int linha2 = 5, coluna2 = 7, orientacao2 = 1; // Vertical

  // Validação e posicionamento dos navios
  if (validar_posicao(linha1, coluna1, orientacao1, tabuleiro))
  {
    posicionar_navio(linha1, coluna1, orientacao1, tabuleiro);
  }
  else
  {
    printf("Falha ao posicionar o primeiro navio.\n");
  }

  if (validar_posicao(linha2, coluna2, orientacao2, tabuleiro))
  {
    posicionar_navio(linha2, coluna2, orientacao2, tabuleiro);
  }
  else
  {
    printf("Falha ao posicionar o segundo navio.\n");
  }

  // Exibe o tabuleiro
  exibir_tabuleiro(tabuleiro);

  return 0;
}
