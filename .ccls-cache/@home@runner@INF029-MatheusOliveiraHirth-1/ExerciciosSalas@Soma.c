#include <stdio.h>

int soma(int a, int b){

    return a + b;
}

int main(){

    int a, b;

    printf("escreva os 2 valores que serão somados\n");
    scanf("%i %i", &a, &b);
    
    printf("a soma é %i\n", soma(a,b));

}

