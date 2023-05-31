#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct vetor{
  int tamanhoTotal;
  int tamanhoAtual;
  int *vetorAux;
}vetor;

vetor vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1 || posicao > 10){
      printf("Posicao invalida\n");
      return POSICAO_INVALIDA;
    }
    // o tamanho nao pode ser menor que 1
    if(tamanho < 1){
      printf("Tamanho invalido\n");
      return TAMANHO_INVALIDO;
    }
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao - 1].vetorAux){
      printf("JA TEM ESTRUTURA\n");
      return JA_TEM_ESTRUTURA_AUXILIAR;
    }
  
    // Até então tudo certo, crie
    vetorPrincipal[posicao - 1].vetorAux = (int*)malloc(tamanho * sizeof(int));
    
    vetorPrincipal[posicao - 1].tamanhoTotal = tamanho;
    vetorPrincipal[posicao - 1].tamanhoAtual = 0; 
      
    // o tamanho ser muito grande
    if(!vetorPrincipal[posicao - 1].vetorAux){
      printf("SEM ESPAÇO DE MEMORIA\n");
      return SEM_ESPACO_DE_MEMORIA;
    }
  
    printf("Sucesso!\n");
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int atual = vetorPrincipal[posicao - 1].tamanhoAtual;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else
    {
      if(vetorPrincipal[posicao - 1].vetorAux){
        existeEstruturaAuxiliar = 1;
      }
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if(atual < vetorPrincipal[posicao - 1].tamanhoTotal){
              temEspaco = 1; 
            }
            if (temEspaco)
            {
                //insere
                vetorPrincipal[posicao - 1].vetorAux[atual] = valor; 
                vetorPrincipal[posicao - 1].tamanhoAtual++;
                
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int atual = vetorPrincipal[posicao - 1].tamanhoAtual;
  int retorno = SUCESSO;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
      retorno = POSICAO_INVALIDA;
    
    else if(!vetorPrincipal[posicao - 1].vetorAux)
      retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(atual == 0)
     retorno = ESTRUTURA_AUXILIAR_VAZIA;
     
    else{
      vetorPrincipal[posicao - 1].vetorAux[atual - 1] = 0; 
      vetorPrincipal[posicao - 1].tamanhoAtual--;
    }
      
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int atual = vetorPrincipal[posicao - 1].tamanhoAtual;
    
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
      return POSICAO_INVALIDA;
  
    if(!vetorPrincipal[posicao - 1].vetorAux)
      return SEM_ESTRUTURA_AUXILIAR;
  
    for(int i = 0; i <= atual && vetorPrincipal[posicao - 1].vetorAux; i++){
      if(vetorPrincipal[posicao - 1].vetorAux[i] == valor){
        vetorPrincipal[posicao - 1].vetorAux[i] = 0;

        for(int j = i + 1; j <= atual; j++, i++)
          vetorPrincipal[posicao - 1].vetorAux[i] = vetorPrincipal[posicao - 1].vetorAux[j];

        vetorPrincipal[posicao - 1].tamanhoAtual--;

        return SUCESSO; //porque só cabe ao primeiro caso do número
      }
      else
        return NUMERO_INEXISTENTE;
    }
  return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0, i = 0;
  int atual = vetorPrincipal[posicao - 1].tamanhoAtual;

      if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;
    
      if(!vetorPrincipal[posicao - 1].vetorAux)
        return SEM_ESTRUTURA_AUXILIAR;

      while(i < atual){
        vetorAux[i] = vetorPrincipal[posicao - 1].vetorAux[i];

        i++;
      }
      retorno = SUCESSO;

  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{  
    int retorno = 0;
    int atual = vetorPrincipal[posicao - 1].tamanhoAtual;
    int aux;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
      return POSICAO_INVALIDA;
    
    if(!vetorPrincipal[posicao - 1].vetorAux)
      return SEM_ESTRUTURA_AUXILIAR;

    for(int i = 0; i < atual; i++){
      vetorAux[i] = vetorPrincipal[posicao - 1].vetorAux[i];
    }

    for(int j = atual - 1; j >= 1; j--){
  	 for(int i = 0; i < j; i++){
  		  if(vetorAux[i] > vetorAux[i + 1]){//troca
          aux = vetorAux[i];
          vetorAux[i] = vetorAux[i + 1];
          vetorAux[i + 1] = aux;
        }
      }
    }

    retorno = SUCESSO;
  
   /* for(int i = 0; i < atual; i++){
      printf("VetorAuxiliar[%i] = %i\n", i, vetorAux[i]);
    }  */
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0, cont = 0, nao_vazia = 0;
    int atual = vetorPrincipal[cont].tamanhoAtual;
    int aux;

    for(int i = 0; i < TAM; i++){
      if(vetorPrincipal[i].vetorAux){
        //printf("Vetores existentes: %i\n", i);
        if(vetorPrincipal[i].tamanhoAtual){
          nao_vazia++;        
        }
      }
    }
  
    if(!nao_vazia){
      //printf("nao_vazia: %i\n", nao_vazia);
      return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
  
    int i = 0, j = 0;
    
    for(cont = 0; cont < TAM; cont++){
      atual = vetorPrincipal[cont].tamanhoAtual;
      
      if(vetorPrincipal[cont].vetorAux){
        for(i = 0; i < atual; i++, j++){
          vetorAux[j] = vetorPrincipal[cont].vetorAux[i];
          //printf("vetor auxiliar[%i] = %i\n", j, vetorAux[j]);
        }
      }
    }
  
    retorno = SUCESSO;
  
   /* for(int i = 0; i < atual; i++){
      printf("VetorAuxiliar[%i] = %i\n", i, vetorAux[i]);
    }  */
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0, i = 0, aux, recebe_tamanho;

    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    recebe_tamanho = tamanhos_somados();

    for(int j = recebe_tamanho - 1; j >= 1; j--){
    	 for(int i = 0; i < j; i++){
    		  if(vetorAux[i] > vetorAux[i + 1]){//troca
            aux = vetorAux[i];
            vetorAux[i] = vetorAux[i + 1];
            vetorAux[i + 1] = aux;
          }
        }
      }
  
  
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  int novoTamanhoTotal = novoTamanho + vetorPrincipal[posicao - 1].tamanhoTotal;
  //printf("NovoTamanho : %i + TamanhoTotal: %i = novoTamanhoTotal : %i\n", novoTamanho, vetorPrincipal[posicao - 1].tamanhoTotal, novoTamanhoTotal);
  
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
      return POSICAO_INVALIDA;
  }
    
  else if(!vetorPrincipal[posicao - 1].vetorAux){
      return SEM_ESTRUTURA_AUXILIAR;
  }
  
  else if(novoTamanhoTotal < 1){
      return NOVO_TAMANHO_INVALIDO;
  }
  

  vetorPrincipal[posicao - 1].vetorAux = realloc(vetorPrincipal[posicao - 1].vetorAux, novoTamanhoTotal);
  
  vetorPrincipal[posicao - 1].tamanhoTotal = novoTamanhoTotal;
  //printf("vetorPrincipal[posicao - 1].tamanhoTotal: %i\n", vetorPrincipal[posicao - 1].tamanhoTotal);

  if(vetorPrincipal[posicao - 1].tamanhoAtual > novoTamanhoTotal)
    vetorPrincipal[posicao - 1].tamanhoAtual = novoTamanhoTotal;

    //printf("tam atual : %i\n", vetorPrincipal[posicao - 1].tamanhoAtual);

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
      return POSICAO_INVALIDA;
    
  else if(!vetorPrincipal[posicao - 1].vetorAux)
      return SEM_ESTRUTURA_AUXILIAR;
  
  
  //printf("tamanho atual: %i\n", vetorPrincipal[posicao - 1].tamanhoAtual);
  
  return vetorPrincipal[posicao - 1].tamanhoAtual;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{  
  No* novo;
  No* inicio;
  int i = 0;

  //inicio->prox = novo; 

  while(i < TAM){
    if(vetorPrincipal[i].vetorAux){
      if(vetorPrincipal[i].tamanhoAtual > 0){
        for(int j = 0; j < vetorPrincipal[i].tamanhoAtual; j++){
          
          novo = (No*)malloc(sizeof(No));
  
          if(novo){
            novo->conteudo = vetorPrincipal[i].vetorAux[j];
            novo = novo->prox; 
          }
          else{
            printf("Não foi possível alocar novo nó\n");
          }
        }
      }
    }
    else{
      return NULL;
    }
    i++;
  }
  
    
    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  free(vetorPrincipal->vetorAux);
}

int tamanhos_somados(){
  
  int tamanho_somado = 0;

  for(int i = 0; i < TAM; i++){
      if(vetorPrincipal[i].vetorAux){
        if(vetorPrincipal[i].tamanhoAtual){
          tamanho_somado += vetorPrincipal[i].tamanhoAtual;   
        }
      }
    }
  
  return tamanho_somado;
}