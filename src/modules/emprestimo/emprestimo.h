#ifndef EMPRESTIMO_H_INCLUDED
#define EMPRESTIMO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "data.h"

typedef struct emprestimo
{
  char cpf[14];
  char ISBN[20];
  TData data_emprestimo;
  TData data_entrega;
  TData data_devolucao;
} TEmprestimo;

typedef struct modulo3
{
  TEmprestimo emprestimos[100];
  int indice;
} TModuloEmprestimo;

void lerEmprestimo(TEmprestimo *emprestimo);
void imprimirEmprestimo(TEmprestimo emprestimo);
void iniciarListaEmprestimos(TModuloEmprestimo *emprestimos);
int cadastrarEmprestimos(TEmprestimo emprestimo, TModuloEmprestimo *modulo3);
void imprimirTodosEmprestimos(TModuloEmprestimo *modulo3);
int pesquisarIdEmprestimo(TEmprestimo emprestimo, TModuloEmprestimo *modulo3);
void alterarEmprestimo(int indece, TEmprestimo emprestimo, TModuloEmprestimo *modulo3);
int excluirEmprestimo(int index, TModuloEmprestimo *modulo3);

#endif // EMPRESTIMO_H_INCLUDED
