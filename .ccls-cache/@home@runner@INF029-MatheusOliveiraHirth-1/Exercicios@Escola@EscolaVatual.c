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
} aluno;

typedef struct {
  int matricula;
  char nome[MAX_NOME];
  char sexo[2];
  int dia;
  int mes;
  int ano;
  char cpf[12];
  int existe;
} professor;

typedef struct {
  char nome[30];
  int codigo[20];
  int semestre;
  int existe;
} disciplina;

int menugeral();

int menualuno();

int menuprofessor();

int cadastrar_aluno(int qtd_aluno, aluno aluno[]);

void limpa_buffer(void) {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}

int main(void) {
  // TODO primeira dica, inicialize todas as variaveis com um valor, imagine um
  // valor default ou um que caso tenha ele vai ser considerado invalido para
  // poder debuggar melhor
  int menu, matricula, i, opcao_aluno, opcao_professor, opcao_disciplina,
  qtd_aluno = 0, excluir, sair, cont, j;
  char aux_nome[MAX_NOME];
  aluno aluno[MAX_ALUNO], aluno_auxiliar[MAX_ALUNO];
  professor professor[MAX_PROFESSOR];
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
          if (qtd_aluno == 0) {
            printf("A lista de alunos está vazia\n\n");
          }

          else {
            for (i = 0; i <= MAX_ALUNO; i++) {
              if(aluno[i].existe == 1){
                printf("Matrícula: %i - (%i) %s\n", aluno[i].matricula, i,
                     aluno[i].nome);
                aluno[i].existe == 1;
            }
          }
          break;
        }
        }

        case 2: {
          printf("Entrou na opção listar aluno por sexo!\n\n");
          if (qtd_aluno == 0) {
            printf("A lista de alunos está vazia");
          }

          else {
            printf(
                "Listar alunos por sexo:\n\n"); // melhorar? *caso não encontre
                                                // alunos em algum dos sexos
            printf("Masculino:\n");
            // TODO
            // ao utilizar dessa forma você vai pular todos os alunos que estão
            // depois de um aluno inativo, assim excluindo eles da listagem ou
            // os colocando mas de forma bugada para esse caso eu sugiro que
            // troque a condição de parada por     i < qtd_aluno      e caso
            // queira continuar com o 'existe' ver se ele é igual a 1 na
            // condição do if
            for (i = 0; i <= MAX_ALUNO; i++) {
              if (aluno[i].sexo[0] == 'M' && aluno[i].existe == 1) {
                printf("(%c) - %s", aluno[i].sexo[0], aluno[i].nome);
              }
            }
            printf("\nFeminino:\n\n");
            // TODO ver dica acima
            for (i = 0; i <= MAX_ALUNO; i++) {
              if (aluno[i].sexo[0] == 'F' && aluno[i].existe == 1) {
                printf("(%c) - %s", aluno[i].sexo[0], aluno[i].nome);
              }
            }
          }
          break;
        }

        case 3: {
          printf("Listar alunos por nome:\n\n");

          if (qtd_aluno == 0) {
            printf("A lista de alunos está vazia\n\n");
          }

          else {

            char aux[MAX_ALUNO];

            // TODO mesma dica acima da condição do for
            for (i = 0; i <= MAX_ALUNO; i++) {
                if(aluno[i].existe == 1){
                    strcpy(aluno_auxiliar[i].nome, aluno[i].nome);
                }
            }

            for (i = 0; i <= MAX_ALUNO && aluno[i].existe == 1; i++) {
              if ((strcmp(aluno_auxiliar[i].nome, aluno_auxiliar[i + 1].nome) >
                   0) &&
                  aluno[i + 1].existe ==
                      1) { // posso utilizar a struct antiga como referência, já
                           // que se tratam de cópias
                strcpy(aux, aluno_auxiliar[i + 1].nome);
                strcpy(aluno_auxiliar[i + 1].nome, aluno_auxiliar[i].nome);
                strcpy(aluno_auxiliar[i].nome, aux);
              }
              printf("Ordenado por nome - Aluno(%i): %s\n", i,
                     aluno_auxiliar[i].nome);
            }
          }
          break;
        }

        case 4: {
          printf("Listar alunos por data de nascimento:\n\n");

          if (qtd_aluno == 0) {
            printf("A lista de alunos está vazia\n\n");
          }

          else {

            // TODO sugiro que faça uma função de comparação das datas ao invês
            // de colocar tudo dentro do for, facilita a vida e leitura
            // posterior também vai deixar o for mais "limpo" você pode
            // praticamente reutilizar a mesma lógica do for acima só que se
            // preocupando com as datas, também vale notar que a condição de
            // parada deve ser corrigida para usar o qtd_aluno como em outros
            // for's
            //
            // dica de implementação de código no geral, uma função só deve
            // fazer uma coisa (e bem), uma função inicialmente gigante deve ser
            // diminuida ao criar funções e abstrações para simplificá-la e
            // (como falei antes) facilitar a leitura e localização da parte
            // buscada
            for (i = 0; i < MAX_ALUNO; i++) {
              for (j = 1; j < MAX_ALUNO; j++) {
                if (aluno[i].ano > aluno[j].ano) {
                  aluno_auxiliar[i].ano = aluno[j].ano;
                  aluno_auxiliar[i].mes = aluno[j].mes;
                  aluno_auxiliar[i].dia = aluno[j].dia;
                } else if (aluno[i].ano == aluno[j].ano) {
                  if (aluno[i].mes > aluno[j].mes) {
                    aluno_auxiliar[i].ano = aluno[j].ano;
                    aluno_auxiliar[i].mes = aluno[j].mes;
                    aluno_auxiliar[i].dia = aluno[j].dia;
                  }
                } else if (aluno[i].mes == aluno[j].mes) {
                  if (aluno[i].dia > aluno[j].dia) {
                    aluno_auxiliar[i].ano = aluno[j].ano;
                    aluno_auxiliar[i].mes = aluno[j].mes;
                    aluno_auxiliar[i].dia = aluno[j].dia;
                  }
                }
              }
            }
          }
          break;
        }

        case 5: {
          cadastrar_aluno(qtd_aluno, aluno);

          break;
        }

        case 6: {
          printf("Excluir aluno\n\n");

          printf("Insira a matrícula do aluno que deseja excluir:\n");
          scanf("%i", &excluir);

          // é estranho você mudar o nome para excluido, vai perder praticamente
          // toda a vantagem de nao o apagar do array simplesmente, talvez seja
          // uma boa repensar isso
          char excluido[MAX_NOME] = "Excluido";

          // TODO corrigir condicional de parada
          for (i = 0; i < MAX_ALUNO; i++) {
            if (aluno[i].matricula == excluir) {
              printf("Aluno excluído!\n");
              cont = i;
              
              while (cont < MAX_ALUNO) {
                aluno[cont].matricula = aluno[cont + 1].matricula;
                strcpy(aluno[cont].nome, aluno[cont + 1].nome);
                aluno[cont].sexo[0] = aluno[cont + 1].sexo[0];
                cont++;
              }

              aluno[cont].matricula = -5;

              strcpy(aluno[cont].nome, excluido);

              aluno[cont].sexo[0] = -5; //-5 é valor arbitrário

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

          for (i = 0; i <= MAX_ALUNO; i++) {
            if (matricula == aluno[i].matricula && aluno[i].matricula != -5) {
              guarda = i;
              printf("Aluno(%i) encontrado!\n", guarda);
              printf("Atualizar a matrícula do aluno?(1 - Sim / 2 - Não)\n");

              int sim_nao;

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
          break;
        }
        case 2: {
          printf("Lista de professores por sexo:\n\n");
          break;
        }
        case 3: {
          printf("Lista de professores por nome:\n\n");
          break;
        }
        case 4: {
          printf("Lista de professores por data de nascimento:\n\n");
          break;
        }
        case 5: {
          printf("Cadastrar professor:\n\n");
          break;
        }
        default: {
          printf("\nOpção inválida - retorne ao menu!\n\n");
          break;
        }
        }
      } while (opcao_professor < 6 && opcao_professor > 0);
      break;
    }

    case 3: {
      printf("Entrou na opção disciplina!\n\n");

      do {
        printf("1 - Listar disciplinas(dados sem os alunos:\n");
        printf(
            "2 - Listar UMA disciplina(todos os dados, incluindo os alunos:\n");
        printf("(!)Qualquer outro valor irá retornar ao menu principal!\n");

        scanf("%i", &opcao_disciplina);
        switch (opcao_disciplina) {
        case 1: {
          printf("Lista de disciplinas(dados sem os alunos:\n\n");
          break;
        }
        case 2: {
          printf("Lista de UMA disciplina(todos os dados, incluindo os "
                 "alunos:\n\n");
          break;
        }
        default: {
          printf("\nOpção inexistente - retorne ao menu!\n\n");
          break;
        }
        }
      } while (menu < 3 && menu > 0);
      break;
    }

    default: {
      printf("Valor errado!\n\n");
    }
    }
  } while (menu != -1);
}

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
  printf("(!)Qualquer outro valor irá retornar ao menu principal!\n");

  scanf("%i", &opcao_professor);

  return opcao_professor;
}

int cadastrar_aluno(int qtd_aluno, aluno aluno[]){
    int cpf_invalido, i;
    
    printf("Cadastrar aluno!\n\n");
    
    printf("Cadastrar matrícula\n");
    scanf("%i", &aluno[qtd_aluno].matricula);

    printf("Cadastrar data de nascimento:\n");

    printf("Cadastrar dia:\n");
    scanf("%i", &aluno[qtd_aluno].dia);
    printf("Cadastrar mês:\n");
    scanf("%i", &aluno[qtd_aluno].mes);
    printf("Cadastrar ano:\n");
    scanf("%i", &aluno[qtd_aluno].ano);


    printf("dia: %i mes: %i ano: %i\n", aluno[qtd_aluno].dia, aluno[qtd_aluno].mes, aluno[qtd_aluno].ano);

    if(aluno[qtd_aluno].mes > 12 || aluno[qtd_aluno].mes < 1){
        printf("1º if\n");
        do {
            printf("mês inválido, redigite!\n");
            scanf("%i", &aluno[qtd_aluno].mes);
        } while(aluno[qtd_aluno].mes > 12 || aluno[qtd_aluno].mes < 1);
    }

    if(aluno[qtd_aluno].mes == 2){
        do {
            if(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 28){
                printf("dia inválido, redigite!\n");
                scanf("%i", &aluno[qtd_aluno].dia);
            }
        } while(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 28);
    }

    else if(aluno[qtd_aluno].mes == 1 || aluno[qtd_aluno].mes == 3 || aluno[qtd_aluno].mes == 5 || aluno[qtd_aluno].mes == 7 || aluno[qtd_aluno].mes == 8 || aluno[qtd_aluno].mes == 10 || aluno[qtd_aluno].mes == 12){
        do{
            if(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 31){
                printf("dia inválido, redigite!\n");
                scanf("%i", &aluno[qtd_aluno].dia);
            }
        }while(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 31);
    }

    else if(aluno[qtd_aluno].mes == 4 || aluno[qtd_aluno].mes == 6 || aluno[qtd_aluno].mes == 9 || aluno[qtd_aluno].mes == 11){
        do {
            if(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 30){
                printf("dia inválido, redigite!\n");
                scanf("%i", &aluno[qtd_aluno].dia);
            }
        } while(aluno[qtd_aluno].dia < 1 || aluno[qtd_aluno].dia > 30);
    }


    if(aluno[qtd_aluno].ano > 2023 || aluno[qtd_aluno].ano < 1920){
        do {
            printf("ano inválido, redigite\n");
            scanf("%i", &aluno[qtd_aluno].ano);
        } while(aluno[qtd_aluno].ano > 2023 || aluno[qtd_aluno].ano < 1920);
    }


    printf("Cadastrar nome\n");

    getchar();
    fgets(aluno[qtd_aluno].nome, MAX_NOME, stdin);

    printf("Cadastrar sexo(M - Masculino / F - Feminino)\n");
    do {
        fgets(aluno[qtd_aluno].sexo, 2, stdin);

        if (aluno[qtd_aluno].sexo[0] != 'F' && aluno[qtd_aluno].sexo[0] != 'M') {
            printf("Erro de digitação. Redigitar o sexo(M - Masculino / F - ""Feminino)\n"); // as vezes repetindo linhas na execução
        }
    } while (aluno[qtd_aluno].sexo[0] != 'F' && aluno[qtd_aluno].sexo[0] != 'M');

    limpa_buffer();

    printf("Cadastrar CPF(11 digitos):\n");
    do {
        fgets(aluno[qtd_aluno].cpf, 12, stdin);

        for (i = 0; i <= 11; i++) {
            printf("i = %i\n", i); // verificadores - apagar dps
            printf("vetor = %c\n", aluno[qtd_aluno].cpf[i]);

            if (i == 11) { // invalidar CPF para quando for digitado CPF repetido
                if (aluno[qtd_aluno].cpf[i] != '\0') {
                    printf("CPF inválido(sem o final de string), redigite!\n"); // Falha                 // em                                                                           // diagnosticar                                                                          // excedentes                                                                           // do                                                                           // usuário(ex:12                                                                           // digitos)
                    cpf_invalido = 1;
                } 
                
                else {
                  printf("CPF cadastrado com sucesso!\n");
                  cpf_invalido = 0;
                }
            }

            else if (aluno[qtd_aluno].cpf[i] < '0' || aluno[qtd_aluno].cpf[i] > '9') {
                printf("CPF inválido, redigite!\n");
                cpf_invalido = 1;
                break;
            }
        }
    } while (cpf_invalido);

    limpa_buffer();

    printf("\nAluno cadastrado com sucesso!\n\n");
    
    return 1;
}
