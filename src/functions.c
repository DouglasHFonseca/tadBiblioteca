#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "functions.h"

void cadastrarUsuario()
{
  TUsuario teste2;

  printf("Criando novo usuário:\n");
  __fpurge(stdin);
  fgets(teste2.nome, 20, stdin);

  printf("%s", teste2.nome);
}