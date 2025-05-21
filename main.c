#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    system("chcp 65001");
    printf("\n\n----- Acesso a biblioteca universitaria -----\n ");

    int matricula, idade, categoriaUsuario, possuiDebito, diaSemana, horario;
    char curso[50];

    do
    {
        printf("\nMatricula (apenas numeros): ");
        scanf("%d", &matricula);
        if (matricula < 1)
        {
            printf("Você inseriu um numero de matricula invalido, tente novamente\n");
        }

    } while (matricula < 1);

    printf("\nIdade: ");
    scanf("%d", &idade);

    printf("\nCurso: ");
    scanf(" %[^\n]", &curso);

    do
    {
        printf("\nCategoria do usuario: \n");
        printf("  1 - Aluno de graudação.\n");
        printf("  2 - Aluno de pós-graduação.\n");
        printf("  3 - Professor\n");
        printf("  4 - Visitante\n");
        printf("Selecione sua categoria: ");
        scanf("%d", &categoriaUsuario);

        if (categoriaUsuario < 1 || categoriaUsuario > 4)
        {
            printf("Categoria de usuario invalida, tente novamente\n");
        }

    } while (categoriaUsuario < 1 || categoriaUsuario > 4);


    do
    {
        
        printf("\nEstá em débito com a biblioteca? (1 - sim / 0 - não): ");
        scanf("%d", &possuiDebito);
        if (possuiDebito != 1 && possuiDebito != 0)
        {
            printf("Você selecionou uma opção invalida, tente novamente\n");
        }
        
    } while (possuiDebito != 1 && possuiDebito != 0);


    do
    {
        
        printf("\nQual é o dia da semana no acesso? \n");
        printf("  1 - Domingo \n");
        printf("  2 - Segunda \n");
        printf("  3 - Terça \n");
        printf("  4 - Quarta \n");
        printf("  5 - Quinta \n");
        printf("  6 - Sexta \n");
        printf("  7 - Sabado \n");
        printf("Selecione o dia da semana: ");
        scanf("%d", &diaSemana);
        if (diaSemana < 1 || diaSemana > 7)
        {
            printf("Dia da semana invalido, tente novamente\n");
        }
        
    } while (diaSemana < 1 || diaSemana > 7);


    do
    {
        printf("\nQual o horario do acesso? (apenas o numero, ex: 20 = 20:00) ");
        scanf("%d", &horario);
        if (horario < 0 || horario > 24)
        {
            printf("Horario invalido, tente novamente\n");
        }
        
    } while (horario < 0 || horario > 24);

    switch (categoriaUsuario)
    {
    case 3: // Professor
    printf("\nAcesso liberado\n");
      break;
    case 1: // Aluno de graduação
    if (possuiDebito == 1){
      printf("\nAcesso negado por problemas de débito, regularize sua situação e tente novamente. \n");
    }
   if (diaSemana == 1 || diaSemana == 7){
        printf("\n Acesso negado, tente novamente de segunda a sexta.\n");
    }
   if (horario < 8 || horario > 22){
        printf("\n Acesso negado, tente novamente entre 08:00 e 22:00.\n");
    }
   if (possuiDebito == 0 && diaSemana != 1 && diaSemana != 7 && horario >= 8 && horario <= 22){
        printf("\nAcesso liberado\n");
        break;
      }
      case 2: // Aluno de pós-graduação~
      if (possuiDebito == 1){
        printf("\nAcesso negado por problemas de débito, regularize sua situação e tente novamente. \n");
      }
     if (diaSemana == 1){
        printf("\n Acesso negado, tente novamente de segunda a sabado.");
      }
     if (horario < 8 || horario > 22){
          printf("\n Acesso negado, tente novamente entre 08:00 e 22:00.\n");
      }
     if (possuiDebito == 0 && diaSemana != 1 && horario >= 8 && horario <= 22){
        printf("\nAcesso liberado\n");
      }
      break;
      case 4: // Visitante
    if (possuiDebito == 1){
        printf("\nAcesso negado por problemas de débito, regularize sua situação e tente novamente. \n");
    }
   if (diaSemana == 1 || diaSemana == 7){
        printf("\n Acesso negado, tente novamente de segunda a sexta.\n");
    }
   if (horario < 8 || horario > 17){
        printf("\n Acesso negado, tente novamente entre 08:00 e 17:00.\n");
      }
   if (possuiDebito == 0 && diaSemana != 1 && diaSemana != 7 && horario >= 8 && horario <= 17){
        printf("\nAcesso liberado\n");
        break;
      }
    }
    printf("\nmatricula: %d \n", matricula);
    printf("idade: %d \n", idade);
    printf("curso: %s \n", curso);
    printf("categoriaUsuario: %d \n", categoriaUsuario);
    printf("possuiDebito: %d \n", possuiDebito);
    printf("diaSemana: %d \n", diaSemana);
    printf("horario: %d \n\n", horario);
    return 0;
  }