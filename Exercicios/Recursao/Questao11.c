#include <stdio.h>
#include <stdlib.h>

int Multip_Rec(int n1, int n2);

int main() {

  int n1, n2;
  printf("Insira os números n1 e n2:\n");
  scanf("%d %d", &n1, &n2);

  printf("Resultado: %d\n", Multip_Rec(n1, n2));
}

int Multip_Rec(int n1, int n2) {
  if (n2 == 0)
    return 0;

  else
    return n1 + Multip_Rec(n1, n2 - 1);
}