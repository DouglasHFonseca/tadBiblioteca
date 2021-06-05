#include <stdio.h>
#include <stdlib.h>
#include "./modules/usuario/usuario.h"

int main(void)
{
  int option;
  TUsuario usuario;

  printf("TAD - Biblioteca\n");
  printf("---------------------\n");
  printf("1 - Cadastrar Usuário\n2 - Cadastrar Livro\n3 - Alugar Livro\n4 - Devolver Livro\n");
  scanf("%d", &option);

  switch (option)
  {
  case 1:
    lerUsuario(&usuario);
    imprimirUsuario(usuario);
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
