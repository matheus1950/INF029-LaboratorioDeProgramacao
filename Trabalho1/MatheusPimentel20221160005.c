// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Matheus Oliveira Hirth Pimentel
//  email: pmatheus29@yahoo.com
//  Matrícula: 20221160005
//  Semestre: 3º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// ################################################

#include <stdio.h>
#include "MatheusPimentel20221160005.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para teste
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int inverte(){
  
}


DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  DataQuebrada dq;
  
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
    return 0;
  } 
  
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
    return 0;
  }
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
    return 0;
  }
  

  if(atoi(sMes) > 12 || atoi(sMes) < 1){ 
    
    return 0;
  } 

  if(atoi(sAno) % 4 == 0 && atoi(sAno) % 100 != 0 && (atoi(sAno) % 400 != 0)){
    if(atoi(sMes) == 2){
      if(atoi(sDia) < 1 || atoi(sDia) > 29){
        
        return 0;            
      }
      else{
        
        return 1;
      }
    }
  }

  if(atoi(sMes) == 2){
    if(atoi(sDia) < 1 || atoi(sDia) > 28){
      
      return 0;            
    }
  }
  

  if(atoi(sMes) == 1 || atoi(sMes) == 3 || atoi(sMes) == 5 || atoi(sMes) == 7 || atoi(sMes) == 8 || atoi(sMes) == 10 || atoi(sMes) == 12){
    if(atoi(sDia) < 1 || atoi(sDia) > 31){
      
      return 0;              
    }   
  }

  if(atoi(sMes) == 4 || atoi(sMes) == 6 || atoi(sMes) == 9 || atoi(sMes) == 11){
    if(atoi(sDia) < 1 || atoi(sDia) > 30){ 
      
      return 0;
    }    
  }
  
  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);
  

  return 1;
  
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    int i = 0, j = 0;
    int diasMes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    char Mes_f[3] = {0}, Dia_f[3] = {0}, Ano_f[5] = {0};
    char Mes_i[3] = {0}, Dia_i[3] = {0}, Ano_i[5] = {0};

    if(q1(datainicial) == 0){
      dma.retorno = 2;
    }
    else if(q1(datafinal) == 0){
      dma.retorno = 3;
    }
    else{
      //data inicial
      for (i = 0; datainicial[j] != '/'; j++){
    		Dia_i[i] = datainicial[j];
    		i++;
	    }
      Dia_i[i] = '\0';
      j += 1;
      for (i = 0; datainicial[j] != '/'; j++){
    		Mes_i[i] = datainicial[j];
    		i++;
  	  }
      Mes_i[i] = '\0';
      j += 1;
      for(i = 0; datainicial[j] != '\0'; j++){
    	 	Ano_i[i] = datainicial[j];
    	 	i++;
	    }
      Ano_i[i] = '\0';
      
      //data final
      j = 0;
      for (i = 0; datafinal[j] != '/'; j++){
    		Dia_f[i] = datafinal[j];
    		i++;
	    }
      Dia_f[i] = '\0';
      j += 1;
      for (i = 0; datafinal[j] != '/'; j++){
    		Mes_f[i] = datafinal[j];
    		i++;
  	  }
      Mes_i[i] = '\0';
      j += 1;
      for(i = 0; datafinal[j] != '\0'; j++){
    	 	Ano_f[i] = datafinal[j];
    	 	i++;
	    }
      Ano_i[i] = '\0';
        
      //###################### Maior ou menor #########################################
      if(atoi(Ano_f) < atoi(Ano_i)){
        dma.retorno = 4;
      }
      else if(atoi(Ano_f) == atoi(Ano_i) && atoi(Mes_f) < atoi(Mes_i)){
        dma.retorno = 4;
      }
      else if(atoi(Ano_f) == atoi(Ano_i) && atoi(Mes_f) == atoi(Mes_i) && atoi(Mes_f) < atoi(Mes_i)){
        dma.retorno = 4;
      }
      else{
        dma.qtdAnos = atoi(Ano_f) - atoi(Ano_i);

        dma.qtdMeses = atoi(Mes_f) - atoi(Mes_i);
        if(dma.qtdMeses < 0){
          dma.qtdMeses = 0; 
          dma.qtdAnos -= 1;
        }
        //quantidade de dias com checagem de bissexto
        dma.qtdDias = atoi(Dia_f) - atoi(Dia_i);
        if(dma.qtdDias < 0){
          dma.qtdDias = (diasMes[atoi(Mes_i) - 1] - atoi(Dia_i)) + atoi(Dia_f);
          
          if((((atoi(Ano_i) % 4 == 0) && (atoi(Ano_i) % 100 != 0)) || (atoi(Ano_i) % 400 == 0)) && atoi(Mes_i) == 2)
            dma.qtdDias--;
          
          dma.qtdMeses -= 1;
        }
        
        dma.retorno = 1;
      }
    }
  
  return dma;  
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  
  int len = 0, i = 0, qtdOcorrencias = 0;
  
    while(texto[i] != '\0'){  
      len++;
      i++;
    }
  

    for(i = 0; i < len; i++){
      if(isCaseSensitive != 1){
        if(c < 'Z' && c >= 'A'){
          if(texto[i] == c + 32 || texto[i] == c){
            qtdOcorrencias++;
          }
        }
        else{
          if(texto[i] == c || texto[i] == c - 32){
            qtdOcorrencias++;
          }
        }
      }
          
      else{
        if(texto[i] == c){
          qtdOcorrencias++;   
        }
      }   
    }
  
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int i = 0, j = 0, i_copy, pos_inicial = 0, n = 0, cont = 1;
  int qtdOcorrencias = 0;

  for(i = 0; strTexto[i] != '\0'; i++){ //retirar a casa extra dos acentos
    if(strTexto[i] == -61){
      for(j = i; strTexto[j] != '\0'; j++){
        strTexto[j] = strTexto[j + 1];
      }
    }
  }  
  

  for(i = 0; strTexto[i] != '\0'; i++){ 
    
    if(strTexto[i] == strBusca[0]){
      pos_inicial = i;
      i_copy = i;
      for(j = 1; strBusca[j] != '\0'; j++){
        i_copy++; 
        if(strTexto[i_copy] == strBusca[j]){
          if(strBusca[j + 1] == '\0'){
            posicoes[n] = pos_inicial + 1;
            posicoes[n + 1] = i_copy + 1;
            qtdOcorrencias = cont++;
            n += 2;
            i = i_copy;
          }
        }
        else
          break;
      }
    }
  }
  
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int i, TAM, num_invertido = 0, multiplicador = 1, num_aux = num;
  
  for(TAM = 0; num_aux > 0; TAM++){ //contando o tamanho
      
    num_aux /= 10;  
  }
  
  
  int casas[TAM];
  
  
  for(i = 0; i < TAM; i++){  //atribuindo(já ao contrário)
    
    casas[i] = num % 10;
    
    num /= 10; 
  }
  
  
  for(i = TAM - 1; i >= 0; i--){ //tirando do vetor
    
    num_invertido += casas[i] * multiplicador;
      
    multiplicador *= 10;
  }

  return num_invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int i, j, TAM, TAM1, num_invertido = 0, multiplicador = 1, num_aux = numerobase, num_aux1 = numerobusca;
  int qtdOcorrencias = 0;


  for(TAM = 0; num_aux > 0; TAM++){ //contando o tamanho
    num_aux /= 10;
  }
  
  int casas[TAM];
  
  for(i = TAM - 1; i >= 0; i--){  //atribuindo(ordem correta)
    casas[i] = numerobase % 10;
    numerobase /= 10;
  }

  //repetindo para o número de busca num vetor

  for(TAM1 = 0; num_aux1 > 0; TAM1++){ //contando o tamanho
    num_aux1 /= 10;
  }
  
  int casas_busca[TAM1];
  
  for(i = TAM1 - 1; i >= 0; i--){  //atribuindo(ordem correta)
    casas_busca[i] = numerobusca % 10;
    numerobusca /= 10;
  }
  
  for(i = 0; i < TAM; i++){          //buscando!
    j = 0;
    while(casas_busca[j] == casas[i] && j < TAM1){
      if(j == (TAM1 - 1) && casas_busca[j] == casas[i]){
          qtdOcorrencias++;
      }
      j++;
      i += TAM1 - 1;
    }  
  }
  
  return qtdOcorrencias; 
}