#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "interface.h"

void MSG_MENU()
{
  printf("\n\n\t>>>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<<<<");
  printf("\n\n\t1. MODULO 1 - GERENCIAMENTO DE LIVROS");
  printf("  \n\t2. MODULO 2 - GERENCIAMENTO DE USUARIOS");
  printf("  \n\t3. MODULO 3 - GERENCIAMENTO DE EMPRESTIMOS");
  printf("  \n\t4. SAIR");
}

void MSG_SUBMENU(int numero_modulo)
{
  system("clear");
  printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<<<<<<<<<<", numero_modulo);
  printf("\n\n\t1. CADASTRAR");
  printf("  \n\t2. PESQUISAR");
  printf("  \n\t3. ALTERAR");
  printf("  \n\t4. EXCLUIR");
  printf("  \n\t5. IMPRIMIR TODOS");
  printf("  \n\t6. SAIR");
}

void SubMenuModulo1(TModuloLivro *modulo1, TLivro book)
{
  int opcao = 0;
  int i;
  do
  {
    MSG_SUBMENU(1);
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      /**
                    Código para opção de menu Cadastrar
                */
      break;
    case 2:
      /**
                    Código para opção de menu PesquisarLivro
                */
      break;
    case 3:
      /**
                    Código para opção de menu Alterar
                */
      break;
    case 4:
      /**
                    Código para opção de menu Excluir
                */
      break;
    case 5:
      /**
                    Código para opção de menu Imprimir 2
                */
      break;
    case 6:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;
    default:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    } // fim do bloco switch
  } while (opcao != 6);
}

void SubMenuModulo2(TModuloUsuario *modulo2, TLivro usuario)
{
  int opcao = 0;
  int i;
  do
  {
    MSG_SUBMENU(2);
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      /**
                    Código para opção de menu Cadastrar
                */
      break;
    case 2:
      /**
                    Código para opção de menu PesquisarLivro
                */
      break;
    case 3:
      /**
                    Código para opção de menu Alterar
                */
      break;
    case 4:
      /**
                    Código para opção de menu Excluir
                */
      break;
    case 5:
      /**
                    Código para opção de menu Imprimir 2
                */
      break;
    case 6:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;
    default:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    } // fim do bloco switch
  } while (opcao != 6);
}

void SubMenuModulo1(TModuloEmprestimo *modulo3, TLivro emprestimo)
{
  int opcao = 0;
  int i;
  do
  {
    MSG_SUBMENU(3);
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      /**
                    Código para opção de menu Cadastrar
                */
      break;
    case 2:
      /**
                    Código para opção de menu PesquisarLivro
                */
      break;
    case 3:
      /**
                    Código para opção de menu Alterar
                */
      break;
    case 4:
      /**
                    Código para opção de menu Excluir
                */
      break;
    case 5:
      /**
                    Código para opção de menu Imprimir 2
                */
      break;
    case 6:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;
    default:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    } // fim do bloco switch
  } while (opcao != 6);
}