#include <stdio.h>

int soma(int a, int b){

    return a + b;
}

int main(){

    int a, b;

    scanf("%i %i", &a, &b);
    
    printf("a soma é %i", soma(a,b));

}

