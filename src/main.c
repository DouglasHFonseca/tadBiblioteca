#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
  int option;

  printf("TAD - Biblioteca\n");
  printf("---------------------\n");
  printf("1 - Cadastrar Usuário\n2 - Cadastrar Livro\n3 - Alugar Livro\n4 - Devolver Livro\n");
  scanf("%d", &option);

  switch (option)
  {
  case 1:
    cadastrarUsuario();
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    break;
  }

  return 0;
}
