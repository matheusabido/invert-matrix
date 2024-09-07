#include <stdio.h>
#include <stdlib.h>

void mostrarMatriz(float **matriz, int tamanho);

int main()
{
  int tamanho;
  printf("Defina o tamanho da matriz (deve ser quadrada): ");
  scanf("%d", &tamanho);

  float **matriz = (float **)malloc(tamanho * sizeof(float *));
  for (int i = 0; i < tamanho; i++)
    matriz[i] = (float *)malloc(tamanho * 2 * sizeof(float));

  printf("Ótimo. Uma matriz %dx%d foi criada. Agora, vamos definir os valores dela.\n", tamanho, tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      printf("Linha %d, coluna %d: ", i + 1, j + 1);
      scanf("%f", &matriz[i][j]);
    }
  }

  // cria matriz identidade
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = tamanho; j < tamanho * 2; j++)
    {
      matriz[i][j] = i == j - tamanho ? 1 : 0;
    }
  }

  // subtrai as equações para tirar os números à esquerda
  for (int i = 0; i < tamanho - 1; i++)
  {
    float n = matriz[i][i];
    for (int j = i + 1; j < tamanho; j++)
    {
      float n2 = matriz[j][i];
      float m = -n2 / n;
      for (int k = 0; k < tamanho * 2; k++)
      {
        matriz[j][k] += matriz[i][k] * m;
      }
    }
    printf("\n");
    mostrarMatriz(matriz, tamanho);
  }

  // subtrai as equações para tirar os números à direita
  for (int i = tamanho - 1; i > 0; i--)
  {
    float n = matriz[i][i];
    for (int j = i - 1; j >= 0; j--)
    {
      float n2 = matriz[j][i];
      float m = -n2 / n;
      for (int k = 0; k < tamanho * 2; k++)
      {
        matriz[j][k] += matriz[i][k] * m;
      }
    }
    printf("\n");
    mostrarMatriz(matriz, tamanho);
  }

  // normaliza a matriz
  // em outras palavras, transforma a matriz da esquerda em identidade
  for (int i = 0; i < tamanho; i++)
  {
    float div = matriz[i][i];
    for (int j = 0; j < tamanho * 2; j++)
    {
      matriz[i][j] /= div;
      if (matriz[i][j] == -0)
        matriz[i][j] = 0;
    }
  }

  printf("\n");
  mostrarMatriz(matriz, tamanho);

  for (int i = 0; i < tamanho; i++)
    free(matriz[i]);
  free(matriz);
  return 0;
}

void mostrarMatriz(float **matriz, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho * 2; j++)
    {
      printf("%7.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}