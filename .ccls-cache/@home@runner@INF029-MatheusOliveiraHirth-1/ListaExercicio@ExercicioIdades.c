#include <stdio.h>

int main(void) {
 
  int n;
  scanf("%i", &n);
  
  int idade[n];
  int i= n;
 
  n=0;
  
  while(i>n){
   scanf("%i", &idade[n]);
    n++; 
  }

  int media, soma=0;
  
  n=0;

  while(i>n){
   soma+= idade[n]; 
   n++;
  }

  media= soma/i;

  n=0;

  while(i>n){
  if(idade[n]>media){
  printf("Idade acima da média: %i\n", idade[n]);
  }
  n++;
  }
  
  return 0;
}