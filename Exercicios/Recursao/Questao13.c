#include <stdio.h>
#include <stdlib.h>

int decrescente(int N, int fim);

int main() {
  int N;

  printf("Entre com N:\n");

  scanf("%d", &N);

  decrescente(N, N);
}

int decrescente(int N, int fim) {
  printf("num: %d\n", fim);

  if (fim == 0)
    return 0;

  else
    decrescente(N, fim - 1);
}