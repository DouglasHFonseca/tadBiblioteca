#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "interface.h"
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"
#include "usuario.h"
#include "livro.h"

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

void SubMenuModulo1(TModuloLivro *modulo1, TLivro livro)
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
      lerLivro(&livro);
      if (cadastrarLivro(livro, modulo1) == 1)
      {
        printf("Livro cadastrado com sucesso");
      }
      else
      {
        printf("Não foi possível cadastrar o livro, limite atingido!");
      }
      break;
    case 2:
      lerLivro(&livro);
      if (pesquisarIdLivro(livro, modulo1) == -1)
      {
        printf("Livro não encontrado");
      }
      else
      {
        imprimirLivro(modulo1->livros[pesquisarIdLivro(livro, modulo1)]);
      }
      break;
    case 3:
      lerLivro(&livro);
      if (pesquisarIdLivro(livro, modulo1) == -1)
      {
        printf("Livro não encontrado para alteração");
      }
      else
      {
        alterarLivro(pesquisarIdLivro(livro, modulo1), livro, modulo1);
      }
      break;
    case 4:
      lerLivro(&livro);
      int i = pesquisarIdLivro(livro, modulo1);
      if (i == -1)
      {
        printf("Não há como excluir um livro que não está cadastrado!");
      }
      else
      {
        excluirLivro(i, modulo1);
      }
      break;
    case 5:
      imprimirTodosLivros(modulo1);
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

void SubMenuModulo2(TModuloUsuario *modulo2, TUsuario usuario)
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
      lerUsuario(&usuario);
      if (cadastrarUsuario(usuario, modulo2) == 1)
      {
        printf("Usuário cadastrado com sucesso!");
      }
      else
      {
        printf("Não foi possível cadastrar o usuário, limite atingido!");
      }
      break;
    case 2:
      lerUsuario(&usuario);
      if (pesquisarIdUsuario(usuario, modulo2) == -1)
      {
        printf("Usuário não encontrado");
      }
      else
      {
        imprimirUsuario(modulo2->usuarios[pesquisarIdUsuario(usuario, modulo2)]);
      }
      break;
    case 3:
      lerUsuario(&usuario);
      if (pesquisarIdUsuario(usuario, modulo2) == -1)
      {
        printf("Usuário não encontrado");
      }
      else
      {
        alterarUsuario(pesquisarIdUsuario(usuario, modulo2), usuario, modulo2);
      }
      break;
    case 4:
      lerUsuario(&usuario);
      int i = pesquisarIdUsuario(usuario, modulo2);
      if (i == -1)
      {
        printf("Não há como excluir um usuário que não está cadastrado!");
      }
      else
      {
        excluirUsuario(i, modulo2);
      }
      break;
    case 5:
      imprimirTodosUsuarios(modulo2);
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

void SubMenuModulo3(TModuloEmprestimo *modulo3, TEmprestimo emprestimo)
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
      lerEmprestimo(&emprestimo);
      int multas = verificaMultas(modulo3, emprestimo.cpf);
      int emprestados = verificaEmprestimos(modulo3, emprestimo.cpf);

      if (multas == 0 && emprestados <= 3)
      {
        if (cadastrarEmprestimos(emprestimo, modulo3) == 1)
        {
          printf("Emprestimo realizado com sucesso!");
        }
        else
        {
          printf("Não foi possível o emprestimo, limite atingido!");
        }
      }
      break;
    case 2:
      lerEmprestimo(&emprestimo);
      if (pesquisarIdEmprestimo(emprestimo, modulo3) == -1)
      {
        printf("Emprestimo não encontrado");
      }
      else
      {
        imprimirEmprestimo(modulo3->emprestimos[pesquisarIdEmprestimo(emprestimo, modulo3)]);
      }
      break;
    case 3:
      lerEmprestimo(&emprestimo);
      if (pesquisarIdEmprestimo(emprestimo, modulo3) == -1)
      {
        printf("Emprestimo não encontrado");
      }
      else
      {
        alterarEmprestimo(pesquisarIdEmprestimo(emprestimo, modulo3), emprestimo, modulo3);
      }
      break;
    case 4:
      lerEmprestimo(&emprestimo);
      int i = pesquisarIdEmprestimo(emprestimo, modulo3);
      if (i == -1)
      {
        printf("Não há como excluir um emprestimo que não foi realizado!");
      }
      else
      {
        excluirEmprestimo(i, modulo3);
      }
      break;
    case 5:
      imprimirTodosEmprestimos(modulo3);
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