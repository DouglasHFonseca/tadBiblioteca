#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct data
{
  int dia;
  int mes;
  int ano;
} TData;

typedef struct livro
{
  char ISBN[20];
  char titulo[100];
  char editora[100];
  char local[100];
  TData data_pub;
  char prim_autor[100];
  char seg_autor[100];
  int quantidade;
  int quant_emprestados;
} TLivro;

typedef struct biblioteca
{
  TLivro livros[100];
  int indice;
} TModuloLivro;

// Operações Básicas
void lerLivro(TLivro *livro);
void imprimirLivro(TLivro livro);
void iniciarListaLivro(TModuloLivro *biblioteca);
int cadastrarLivro(TLivro livro, TModuloLivro *biblioteca);
void imprimirTodos(TModuloLivro biblioteca);
int pesquisarIdLivro(char ISBN[20], TModuloLivro *biblioteca);
int excluirLivro(int posicao, TModuloLivro *biblioteca);

#endif // LIVRO_H_INCLUDED