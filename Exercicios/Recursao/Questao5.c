#include <stdio.h>
#include <stdlib.h>

int somatorio(int N);

int main() {
  int N;

  printf("Entre com N:\n");

  scanf("%d", &N);
  int soma = somatorio(N);

  printf("%d", soma);
}

int somatorio(int N) {
  if (N == 0)
    return 0;

  else
    return N + somatorio(N - 1);
}