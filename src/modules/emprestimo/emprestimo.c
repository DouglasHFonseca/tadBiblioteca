#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "emprestimo.h"

void lerEmprestimo(TEmprestimo *emprestimo)
{
  printf("\nDigite o CPF: ");
  __fpurge(stdin);
  fgets(emprestimo->cpf, 14, stdin);

  printf("\nISBN: ");
  __fpurge(stdin);
  fgets(emprestimo->ISBN, 20, stdin);

  //Data Emprestimo
  {
    printf("\n---Data de Emprestimo---\n");
    printf("\nDigite o dia: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.dia);

    printf("\nDigite o mês: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.mes);

    printf("\nDigite o ano: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.ano);
  }

  // Data Entrega
  {
    printf("\n---Data de Entrega---\n");
    printf("\nDigite o dia: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.dia);

    printf("\nDigite o mês: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.mes);

    printf("\nDigite o ano: ");
    __fpurge(stdin);
    scanf("%d", &emprestimo->data_emprestimo.ano);
  }
}

void imprimirEmprestimo(TEmprestimo emprestimo)
{
  printf("\nCPF: ");
  printf("%s", emprestimo.cpf);

  printf("\nISBN: ");
  printf("%s", emprestimo.ISBN);

  printf("\nData de Emprestimo: ");
  printf("%d/%d/%d\n", emprestimo.data_emprestimo.dia, emprestimo.data_emprestimo.mes, emprestimo.data_emprestimo.ano);

  printf("\nData de Entrega: ");
  printf("%d/%d/%d\n", emprestimo.data_entrega.dia, emprestimo.data_entrega.mes, emprestimo.data_entrega.ano);

  printf("\nData de Devolução: ");
  if (emprestimo.data_devolucao.dia == NULL)
  {
    printf("Livro ainda não devolvido");
  }
  else
  {
    printf("%d/%d/%d\n", emprestimo.data_devolucao.dia, emprestimo.data_devolucao.mes, emprestimo.data_devolucao.ano);
  }
}

void iniciarlistaEmprestimo(TModuloEmprestimo *modulo3)
{
  modulo3->indice = 0;
}

int cadastrarEmprestimo(TEmprestimo emprestimo, TModuloEmprestimo *modulo3)
{
  if (modulo3->indice == 100)
  {
    return 0;
  }
  else
  {
    modulo3->emprestimos[modulo3->indice] = emprestimo;
    modulo3->indice++;
    return 1;
  }
}

int pesquisarIdEmprestimo(TEmprestimo emprestimo, TModuloEmprestimo *modulo3)
{
  int response = 0;
  for (int i = 0; i < modulo3->indice; i++)
  {
    if (strcmp(modulo3->emprestimos[i].cpf, emprestimo.cpf) == 0 &&
        (strcmp(modulo3->emprestimos[i].ISBN, emprestimo.ISBN) == 0))
    {
      response = i;
      break;
    }
    else
    {
      response = -1;
    }
  }

  return response;
}

void alterarEmprestimo(int indice, TEmprestimo emprestimo, TModuloEmprestimo *modulo3)
{
  modulo3->emprestimos[indice] = emprestimo;
}

int excluirEmprestimo(int posicao, TModuloEmprestimo *modulo3)
{
  if (posicao == modulo3->indice - 1)
  {
    return modulo3->indice - 1;
  }
  else
  {
    modulo3->emprestimos[posicao] = modulo3->emprestimos[posicao + 1];
    return excluirEmprestimo(posicao + 1, modulo3);
  }
}