#include <stdio.h>
#include <stdlib.h>

int Soma(int V[], int i);

int main(){
    int TAM;
    
    printf("Entre Tamanho do vetor: \n");
    scanf("%d", &TAM);
    
    int N[TAM];
    
    for(int i = 0; i < TAM; i++){
        scanf("%d", &N[i]);
    }
    
    
    int i = TAM - 1;
    printf("%d\n", Soma(N, i));
      
}

int Soma(int V[], int i){
    if(i == -1)
        return 0; 
  
    else
       return V[i] + Soma(V, i - 1); 
}