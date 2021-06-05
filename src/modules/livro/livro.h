#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

typedef struct data
{
  int dia;
  int mes;
  int ano;
} TDate;

typedef struct livro
{
  char ISBN[20];
  char titulo[100];
  char editora[100];
  char local[100];
  TDate data_pub;
  char prim_autor[100];
  char seg_autor[100];
  int quantidade;
  int quant_emprestados;
} TLivro;

typedef struct biblioteca
{
  TLivro livros[100];
  int indice;
} TBiblioteca;

#endif // LIVRO_H_INCLUDED