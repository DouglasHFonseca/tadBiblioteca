#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "data.h"

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

typedef struct modulo1
{
  TLivro livros[100];
  int indice;
} TModuloLivro;

// Operações Básicas
void lerLivro(TLivro *livro);
void imprimirLivro(TLivro livro);
void iniciarListaLivro(TModuloLivro *modulo1);
int cadastrarLivro(TLivro livro, TModuloLivro *modulo1);
void imprimirTodosLivros(TModuloLivro *modulo1);
int pesquisarIdLivro(TLivro livro, TModuloLivro *modulo1);
void alterarLivro(int indice, TLivro livro, TModuloLivro *modulo1);
int excluirLivro(int posicao, TModuloLivro *modulo1);

#endif // LIVRO_H_INCLUDED