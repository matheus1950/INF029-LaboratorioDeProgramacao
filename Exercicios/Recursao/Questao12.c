#include <stdio.h>
#include <stdlib.h>

int crescente(int N, int inicio);

int main() {
  int N;

  printf("Entre com N:\n");

  scanf("%d", &N);

  crescente(N, 0);
}

int crescente(int N, int inicio) {
  printf("num: %d\n", inicio);

  if (inicio == N)
    return 0;

  else
    crescente(N, inicio + 1);
}