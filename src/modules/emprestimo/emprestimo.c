#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "emprestimo.h"
#include "data.h"

/* Realiza a leitura do Emprestimo , campo a campo*/
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

/* Recebe um emprestimo com valor e imprime campo a */
void imprimirEmprestimo(TEmprestimo emprestimo)
{
  printf("\nCPF: %s", emprestimo.cpf);

  printf("\nISBN: %s", emprestimo.ISBN);

  printf("\nData de Emprestimo: %d/%d/%d", emprestimo.data_emprestimo.dia, emprestimo.data_emprestimo.mes, emprestimo.data_emprestimo.ano);

  printf("\nData de Entrega: %d/%d/%d", emprestimo.data_entrega.dia, emprestimo.data_entrega.mes, emprestimo.data_entrega.ano);

  printf("\nData de Devolução: ");
  if (emprestimo.data_devolucao.dia == 0)
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

int verificaMultaDias(TEmprestimo emprestimo)
{
  int valid = 1;

  if (emprestimo.data_entrega.ano < (data_hora_atual->tm_year + 1900))
  {
    valid = -1;
  }
  else if (emprestimo.data_entrega.mes < (data_hora_atual->tm_mon + 1))
  {
    valid = -1;
  }
  else if (emprestimo.data_entrega.dia < data_hora_atual->tm_mday)
  {
    valid = -1;
  }

  if (valid == -1)
  {
    return comparaData(emprestimo.data_entrega);
  }
  else
  {
    return 0;
  }
}

int verificaMultas(TModuloEmprestimo *emprestimosBiblioteca, char cpf[14])
{
  int multas = 0;

  for (int i = 0; i < emprestimosBiblioteca->indice; i++)
  {
    if (strcmp(emprestimosBiblioteca->emprestimos[i].cpf, cpf) == 0)
    {
      multas = verificaMultaDias(emprestimosBiblioteca->emprestimos[i]);
    }
  }

  return multas;
}

int verificaEmprestimos(TModuloEmprestimo *emprestimosBiblioteca, char cpf[14])
{
  int count = 0;
  for (int i = 0; i < emprestimosBiblioteca->indice; i++)
  {
    if (strcmp(emprestimosBiblioteca->emprestimos[i].cpf, cpf) == 0)
    {
      if (emprestimosBiblioteca->emprestimos[i].data_devolucao.dia == 0)
      {
        count++;
      }
    }
  }

  return count;
}