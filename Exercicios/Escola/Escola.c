#include <stdio.h>
#include <string.h>

#define MAX_ALUNO 3
#define MAX_PROFESSOR 5
#define MAX_DISCIPLINA 10
#define MAX_NOME 60

typedef struct {
  int matricula;
  char nome[MAX_NOME];
  char sexo[2];
  int dia;
  int mes;
  int ano;
  char cpf[12];
  int existe;
} lista_geral;

typedef struct {
  char nome[MAX_NOME];
  int codigo;
  int semestre;
  int existe;
  int aluno[MAX_ALUNO];
  int professor;
} disciplina;

int menugeral();

int menualuno();

int menuprofessor();

void data_nascimento(int *dia, int *mes, int *ano);

void cadastro_sexo(char *sexo);

void cadastro_cpf(char *cpf);

void listar(int qtd_aluno, lista_geral aluno[]);

void listar_data(lista_geral aluno_auxiliar[], int qtd_aluno, lista_geral aluno[]);

void listar_sexo(int qtd_aluno, lista_geral aluno[]);

void listar_nome(lista_geral aluno_auxiliar[], int qtd_aluno, lista_geral aluno[]);

int cadastrar_geral(int qtd_aluno, lista_geral aluno[]);

int cadastro_disciplina(disciplina disciplina[], int qtd_disciplina);

void limpa_buffer(void) {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}

int main(void) {
  
  int menu, matricula, i, opcao_aluno, opcao_professor, opcao_disciplina,
  qtd_aluno = 0, qtd_professor = 0, qtd_disciplina = 0, excluir, sair, cont, j;
  char aux_nome[MAX_NOME], aux[MAX_NOME];
  lista_geral aluno[MAX_ALUNO], aluno_auxiliar[MAX_ALUNO], professor[MAX_PROFESSOR], professor_auxiliar[MAX_PROFESSOR];
  disciplina disciplina[MAX_DISCIPLINA];

  do {

    menu = menugeral();

    switch (menu) {
    case 0: {
      menu = -1;
      printf("\nEncerrado!\n");
      break;
    }

    case 1: {
      printf("Entrou na opção aluno!\n\n");

      do {

        opcao_aluno = menualuno();

        switch (opcao_aluno) {
        case 1: {
            printf("Listar alunos:\n\n");
          
            listar(qtd_aluno, aluno);
          
            break;
        }

        case 2: {
            printf("Entrou na opção listar aluno por sexo!\n\n");
          
            listar_sexo(qtd_aluno, aluno);
          
            break;
        }

        case 3: {
            printf("Listar alunos por nome:\n\n");
    
            listar_nome(aluno_auxiliar, qtd_aluno, aluno);
              
            break;
        }

        case 4: {
            listar_data(aluno_auxiliar, qtd_aluno, aluno);  
          
            break;
        }

        case 5: {
            
            if(qtd_aluno >= MAX_ALUNO){
                printf("\n(!aviso)Número máximo de alunos atingido, exclua algum aluno!\n\n");
                break;
            }
            
            printf("Cadastrar aluno:\n\n");
            
            if(cadastrar_geral(qtd_aluno, aluno) == -2){
                aluno[qtd_aluno].existe = 1;
                qtd_aluno++;
            }
            
            printf("\nAluno Cadastrado com sucesso!\n\n");

            break;
        }

        case 6: {
            printf("Excluir aluno\n\n");
    
            printf("Insira a matrícula do aluno que deseja excluir:\n");
            scanf("%i", &excluir);

          
            char excluido[MAX_NOME] = "Excluido";

          
            for (i = 0; i < MAX_ALUNO; i++) {
                if (aluno[i].matricula == excluir) {
                    printf("Aluno excluído!\n");
                    cont = i;

                    while (cont < MAX_ALUNO) { 
                        if(aluno[cont+1].existe == 1) {  
                
                            aluno[cont].matricula = aluno[cont + 1].matricula;
                            strcpy(aluno[cont].nome, aluno[cont + 1].nome);
                            aluno[cont].sexo[0] = aluno[cont + 1].sexo[0];
                            cont++;
                        }
                    }

                    aluno[cont].matricula = -5;

                    strcpy(aluno[cont].nome, excluido);

            
                    aluno[cont].sexo[0] = -5; 

                    qtd_aluno--;
                
                    break;
                    
                } else if (i == MAX_ALUNO - 1) {
                    printf("Aluno não encontrado!\n");
                }
            }
          break;
        }

        case 7: {
            printf("Atualizar aluno\n\n");
            printf("Digite a matrícula\n");
            scanf("%i", &matricula);

            int guarda;
            int sim_nao;

            for (i = 0; i <= MAX_ALUNO; i++) {
                if (matricula == aluno[i].matricula && aluno[i].matricula != 0) {
                    guarda = i;
                    printf("Aluno(%i) encontrado!\n", guarda);
                    printf("Atualizar a matrícula do aluno?(1 - Sim / 2 - Não)\n");

                    do {
                        scanf("%i", &sim_nao);
                        if (sim_nao != (1 && 2)) {
                            printf("Digito incorreto, digite 1(Sim) ou 2(Não)!\n");
                        }
                        
                    } while (sim_nao != (1 && 2));

                    switch (sim_nao) {
                        case 1: {
                            aluno[guarda].matricula = matricula;
                            printf("Matrícula atualizada com sucesso!\n\n");
                        }
                        case 2: {
                            break;
                        }
                    }
                } else if (i == MAX_ALUNO) {
              printf("Aluno não encontrado!\n");
                }
            }
        }

        default: {
            printf("\nOpção inválida - retorne ao menu!\n\n");
            break;
        }
        }
        } while (opcao_aluno > 0 && opcao_aluno < 8);
        break;
    }

    case 2: {
        printf("Entrou na opção professor!\n\n");

        do {

            opcao_professor = menuprofessor();
    
            switch (opcao_professor) {
                case 1: {
                    printf("Lista de professores:\n\n");
                  
                    listar(qtd_professor, professor);
                    
                    break;
                }
                case 2: {
                    printf("Lista de professores por sexo:\n\n");
                      
                    listar_sexo(qtd_professor, professor);
                      
                    break;
                }
                case 3: {
                    printf("Lista de professores por nome:\n\n");
                    
                    listar_nome(professor_auxiliar, qtd_professor, professor);
                    
                    break;
                }
                case 4: {
                    printf("Lista de professores por data de nascimento:\n\n");
                  
                    listar_data(professor_auxiliar, qtd_professor, professor);
                    
                    break;
                }
                case 5: {
                    printf("Cadastrar professor:\n\n");
            
                    if(qtd_professor >= MAX_PROFESSOR){
                        printf("\n(!aviso)Número máximo de alunos atingido, exclua algum aluno!\n\n");
                        break;
                    }
            
                    if(cadastrar_geral(qtd_professor, professor) == -2){
                        professor[qtd_professor].existe = 1;
                        qtd_professor++;
                    }
                
                    printf("\nProfessor Cadastrado com sucesso!\n\n");
            
                    break;
                }
                default: {
                    printf("\nOpção inválida - retorne ao menu!\n\n");
                    break;
                }
            }
        } while (opcao_professor < 8 && opcao_professor > 0);
      break;
    }

    case 3: {
        printf("Entrou na opção disciplina!\n\n");

        do {
            printf("1 - Listar disciplinas(dados sem os alunos:\n");
            printf("2 - Listar UMA disciplina(todos os dados, incluindo os alunos):\n");
            printf("3 - Cadastrar uma disciplina\n");
            printf("(!)Qualquer outro valor irá retornar ao menu principal!\n");
    
            scanf("%i", &opcao_disciplina);
            switch (opcao_disciplina) {
                case 1: {
                    printf("Lista de disciplinas(apenas as disciplinas):\n\n");
                    break;
                }
                case 2: {
                    printf("Lista de UMA disciplina(incluindo os alunos):\n\n");
                    break;
                }
                case 3: {
                    printf("Cadastrar disciplina(incluindo respectivos professores e alunos):\n\n"); //separar as funções depois
                    
                    if(cadastro_disciplina(disciplina, qtd_disciplina) == -2){
                        qtd_disciplina++;
                    }
                    
                    break;
                }
                default: {
                    printf("\nOpção inexistente - retorne ao menu!\n\n");
                    break;
                }
            }
        } while (opcao_disciplina < 4 && opcao_disciplina > 0);
        break;
    }

    default: {
      printf("Valor errado!\n\n");
    }
    
    }
 } while (menu != -1);
}


//funções

int menugeral() {

    int menu;
    
    printf("Bem vindo ao menu do Projeto Escola!\n\n");
    printf("Digite 0 para sair\n");
    printf("Digite 1 para a opção aluno\n");
    printf("Digite 2 para a opção professor\n");
    printf("Digite 3 para a opção disciplina\n");
    
    scanf("%i", &menu);
    
    return menu;
}

int menualuno() {

    int opcao_aluno;

    printf("1 - Listar alunos\n");
    printf("2 - Listar alunos por sexo\n");
    printf("3 - Listar alunos por nome\n");
    printf("4 - Listar alunos por data de nascimento\n");
    printf("5 - Cadastrar aluno\n");
    printf("6 - Excluir aluno\n");
    printf("7 - Atualizar aluno\n");
    printf("(!)Qualquer outro valor irá retornar ao menu principal!\n");
    
    scanf("%i", &opcao_aluno);

    return opcao_aluno;
}

int menuprofessor() {

    int opcao_professor;

    printf("1 - Listar professores\n");
    printf("2 - Listar professores por sexo\n");
    printf("3 - Listar professores por nome\n");
    printf("4 - Listar professores por data de nascimento\n");
    printf("5 - Cadastrar professor\n");
    printf("6 - Excluir professor\n");
    printf("7 - Atualizar professor\n");
    printf("(!)Qualquer outro valor irá retornar ao menu principal!\n");
    
    scanf("%i", &opcao_professor);
    
    return opcao_professor;
}


void data_nascimento(int *dia, int *mes, int *ano){
    
    printf("Cadastrar data de nascimento:\n");

    printf("Cadastrar dia:\n");
    scanf("%i", dia);
    printf("Cadastrar mês:\n");
    scanf("%i", mes);
    printf("Cadastrar ano:\n");
    scanf("%i", ano);


    printf("dia: %i mes: %i ano: %i\n", *dia, *mes, *ano);

    if(*mes > 12 || *mes < 1){
        printf("1º if\n");
        do {
            printf("mês inválido, redigite!\n");
            scanf("%i", mes);
        } while(*mes > 12 || *mes < 1);
    }

    if(*mes == 2){
        do {
            if(*dia < 1 || *dia > 28){
                printf("dia inválido, redigite!\n");
                scanf("%i", dia);
            }
        } while(*dia < 1 || *dia > 28);
    }

    else if(*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12){
        do{
            if(*dia < 1 || *dia > 31){
                printf("dia inválido, redigite!\n");
                scanf("%i", dia);
            }
        }while(*dia < 1 || *dia > 31);
    }

    else if(*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11){
        do {
            if(*dia < 1 || *dia > 30){
                printf("dia inválido, redigite!\n");
                scanf("%i", dia);
            }
        } while(*dia < 1 || *dia > 30);
    }


    if(*ano > 2023 || *ano < 1920){
        do {
            printf("ano inválido, redigite\n");
            scanf("%i", ano);
        } while(*ano > 2023 || *ano < 1920);
    }
}

void cadastro_sexo(char *sexo){
  
    printf("Cadastrar sexo(M - Masculino / F - Feminino)\n");
    do {
        fgets(sexo, 2, stdin);

        if (sexo[0] != 'F' && sexo[0] != 'M') {
            printf("Erro de digitação. Redigitar o sexo(M - Masculino / F - ""Feminino)\n"); // as vezes repetindo linhas na execução
        }
    } while (sexo[0] != 'F' && sexo[0] != 'M');
    
    limpa_buffer();
}

void cadastro_cpf(char *cpf){
    
    int i, cpf_invalido;
    
    printf("Cadastrar CPF(11 digitos):\n");
    do {
        fgets(cpf, 12, stdin);

        for (i = 0; i <= 11; i++) {

            if (i == 11) { // invalidar CPF para quando for digitado CPF repetido
                if (cpf[i] != '\0') {
                    printf("CPF inválido(sem o final de string), redigite!\n"); // Falha                 // em                                                                           // diagnosticar                                                                          // excedentes                                                                           // do                                                                           // usuário(ex:12                                                                           // digitos)
                    cpf_invalido = 1;
                } 
                
                else {
                  printf("CPF cadastrado com sucesso!\n");
                  cpf_invalido = 0;
                }
            }

            else if (cpf[i] < '0' || cpf[i] > '9') {
                printf("CPF inválido, redigite!\n");
                cpf_invalido = 1;
                break;
            }
        }
    } while (cpf_invalido);
}


int cadastrar_geral(int qtd_aluno, lista_geral aluno[]){
    
    int cpf_invalido, i;
    
    
    printf("Cadastrar matrícula\n");
    scanf("%i", &aluno[qtd_aluno].matricula);
    
    data_nascimento(&aluno[qtd_aluno].dia, &aluno[qtd_aluno].mes, &aluno[qtd_aluno].ano); 
    printf("Cadastrar nome\n");
    
    getchar();
    
    do{
        fgets(aluno[qtd_aluno].nome, MAX_NOME, stdin);
    
        if(strlen(aluno[qtd_aluno].nome) <= 2){
            printf("Digite ao menos 2 caracteres!\n");
        }
    }while(strlen(aluno[qtd_aluno].nome) <= 2);
    
    printf("%li\n", strlen(aluno[qtd_aluno].nome));
    
    cadastro_sexo(aluno[qtd_aluno].sexo); 
    
    cadastro_cpf(aluno[qtd_aluno].cpf);  

    limpa_buffer();
    
    return -2; 
}


void listar(int qtd_aluno, lista_geral aluno[]){
    int i;
    
    if (qtd_aluno == 0) {
        printf("A lista de alunos está vazia\n\n");
    }
   
    for (i = 0; i < qtd_aluno; i++) {
        if(aluno[i].existe == 1){
            printf("Matrícula: %i - (%i) %s\n", aluno[i].matricula, i, aluno[i].nome);
        }
    }
}


void listar_data(lista_geral aluno_auxiliar[], int qtd_aluno, lista_geral aluno[]){
    
    int aux_dia, aux_mes, aux_ano, i, j;
    char aux[MAX_NOME];
            
    printf("Listar por data de nascimento:\n\n");

    if (qtd_aluno == 0) {
        printf("A lista está vazia\n\n");
    }

    else {
            
        for (i = 0; i < qtd_aluno; i++) {
            aluno_auxiliar[i].dia = aluno[i].dia;
            aluno_auxiliar[i].mes = aluno[i].mes;
            aluno_auxiliar[i].ano = aluno[i].ano;
            strcpy(aluno_auxiliar[i].nome, aluno[i].nome);
        }
    
        for (i = 0; i < qtd_aluno; i++) {
            for (j = 1; j < qtd_aluno; j++) {
                if (aluno[i].ano > aluno[j].ano) {
                    
                    aux_dia = aluno_auxiliar[i].dia;  //troca de datas;
                    aux_mes = aluno_auxiliar[i].mes;
                    aux_ano = aluno_auxiliar[i].ano;
                    
                    aluno_auxiliar[i].ano = aluno_auxiliar[j].ano;
                    aluno_auxiliar[i].mes = aluno_auxiliar[j].mes;
                    aluno_auxiliar[i].dia = aluno_auxiliar[j].dia;
                    
                    aluno_auxiliar[j].ano = aux_ano;
                    aluno_auxiliar[j].mes = aux_mes;
                    aluno_auxiliar[j].dia = aux_dia;
                    
                    strcpy(aux, aluno_auxiliar[i].nome); //troca de nomes;
                    strcpy(aluno_auxiliar[i].nome, aluno_auxiliar[j].nome);
                    strcpy(aluno_auxiliar[j].nome, aux);
                    
                    } else if (aluno[i].ano == aluno[j].ano) {
                        if (aluno[i].mes > aluno[j].mes) {
                      
                            aux_dia = aluno_auxiliar[i].dia;  //troca de datas;
                            aux_mes = aluno_auxiliar[i].mes;
                            aux_ano = aluno_auxiliar[i].ano;
                    
                            aluno_auxiliar[i].ano = aluno_auxiliar[j].ano;
                            aluno_auxiliar[i].mes = aluno_auxiliar[j].mes;
                            aluno_auxiliar[i].dia = aluno_auxiliar[j].dia;
                    
                            aluno_auxiliar[j].ano = aux_ano;
                            aluno_auxiliar[j].mes = aux_mes;
                            aluno_auxiliar[j].dia = aux_dia;
                    
                            strcpy(aux, aluno_auxiliar[i].nome); //troca de nomes;
                            strcpy(aluno_auxiliar[i].nome, aluno_auxiliar[j].nome);
                            strcpy(aluno_auxiliar[j].nome, aux);
                        }
                    } else if (aluno[i].mes == aluno[j].mes) {
                        if (aluno[i].dia > aluno[j].dia) {
                      
                            aux_dia = aluno_auxiliar[i].dia;  //troca de datas;
                            aux_mes = aluno_auxiliar[i].mes;
                            aux_ano = aluno_auxiliar[i].ano;
                    
                            aluno_auxiliar[i].ano = aluno_auxiliar[j].ano;
                            aluno_auxiliar[i].mes = aluno_auxiliar[j].mes;
                            aluno_auxiliar[i].dia = aluno_auxiliar[j].dia;
                    
                            aluno_auxiliar[j].ano = aux_ano;
                            aluno_auxiliar[j].mes = aux_mes;
                            aluno_auxiliar[j].dia = aux_dia;
                    
                            strcpy(aux, aluno_auxiliar[i].nome); //troca de nomes;
                            strcpy(aluno_auxiliar[i].nome, aluno_auxiliar[j].nome);
                            strcpy(aluno_auxiliar[j].nome, aux);
                        }
                    }
            }
        }
                
            for(i = 0; i< qtd_aluno; i++){
                printf("(%i) = %i/%i/%i - %s",  i, aluno_auxiliar[i].dia, aluno_auxiliar[i].mes, aluno_auxiliar[i].ano, aluno_auxiliar[i].nome);
            } 
    }
}

void listar_sexo(int qtd_aluno, lista_geral aluno[]){

    int i;
    
    if (qtd_aluno == 0) {
        printf("A lista de alunos está vazia");
    }

    else {
        printf("Listar alunos por sexo:\n\n"); // melhorar? *caso não encontre
                                                // alunos em algum dos sexos
        printf("Masculino:\n");
    
        for (i = 0; i <= MAX_ALUNO; i++) {
            if (aluno[i].sexo[0] == 'M' && aluno[i].existe == 1) {
            printf("(%c) - %s", aluno[i].sexo[0], aluno[i].nome);
            }
        }
        printf("\nFeminino:\n\n");
        
        for (i = 0; i <= MAX_ALUNO; i++) {
            if (aluno[i].sexo[0] == 'F' && aluno[i].existe == 1) {
                printf("(%c) - %s\n", aluno[i].sexo[0], aluno[i].nome);
            }
        }
    }
}

void listar_nome(lista_geral aluno_auxiliar[], int qtd_aluno, lista_geral aluno[]){

    int i, j;
    char aux[MAX_NOME];
    
    if (qtd_aluno == 0) {
        printf("A lista de alunos está vazia\n\n");
    }

    else {
        char aux[MAX_NOME];

        for (i = 0; i < qtd_aluno; i++) {
            if(aluno[i].existe == 1) {
                strcpy(aluno_auxiliar[i].nome, aluno[i].nome);
            }
        }

        for (i = 0; i < qtd_aluno; i++) {
            for (j = 1; j < qtd_aluno; j++) {       
                if ((strcmp(aluno_auxiliar[i].nome, aluno_auxiliar[j].nome) > 0) && aluno[j].existe == 1) {    
                    strcpy(aux, aluno_auxiliar[i].nome);
                    strcpy(aluno_auxiliar[i].nome, aluno_auxiliar[j].nome);
                    strcpy(aluno_auxiliar[j].nome, aux);
                }
            }
              printf("Aluno(%i): %s\n", i, aluno_auxiliar[i].nome);
        }
    }
}

int cadastro_disciplina(disciplina disciplina[], int qtd_disciplina){
    
    int j = 0;
        
    printf("Cadastre o código da disciplina:\n");
    
    scanf("%i", &disciplina[qtd_disciplina].codigo);
    
    limpa_buffer();
    
    printf("Cadastre o nome da disciplina\n");
    
    do{
        fgets(disciplina[qtd_disciplina].nome, MAX_NOME, stdin);
        if(strlen(disciplina[qtd_disciplina].nome) <= 2){
            printf("Digite ao menos 2 caracteres!\n");
        }
    }while(strlen(disciplina[qtd_disciplina].nome) <= 2);    
    
    printf("Cadastre o professor da disciplina via matrícula:\n");
        
    scanf("%i", &disciplina[qtd_disciplina].professor); //validar professor comparando com a variável professores
    
    do{
        printf("Cadastre um aluno via matrícula na disciplina(digite 0 para sair): \n"); //validar aluno comparando com a variável professores
    
        scanf("%i", &disciplina[qtd_disciplina].aluno[j]);
        j++;
    }while(j < MAX_ALUNO && disciplina[qtd_disciplina].aluno[j-1] != 0);
    
    return -2;
}




