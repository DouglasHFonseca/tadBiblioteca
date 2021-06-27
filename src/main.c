#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "interface.h"

int main()
{

  TLivro livro;
  TModuloLivro modulo1;
  TUsuario usuario;
  TModuloUsuario modulo2;
  TEmprestimo emprestimo;
  TModuloEmprestimo modulo3;
  Iniciar(&modulo1);

  int opcao = 0;
  do
  {
    system("clear");
    MSG_MENU();
    printf("\n\nDigite uma opcao: ");
    __fpurge(stdin);
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      SubMenuModulo1(&modulo1, livro);
      break;
    case 2:
      SubMenuModulo2(&modulo2, usuario);
      break;
    case 3:
      SubMenuModulo3(&modulo3, emprestimo);
      break;
    case 5:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Saindo do programa...!!! <<<<<<");
      system("PAUSE");
      break;
    default:
      system("clear");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    }
  } while (opcao != 3);

  system("PAUSE");

  return 0;