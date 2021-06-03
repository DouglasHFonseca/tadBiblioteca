#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void cadastrarUsuario();

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

typedef struct endereco
{
  char loagadrouro[100];
  int numero;
  char bairro[100];
  char cidade[100];
  char cep[10];
} TEndereco;

typedef struct usuario
{
  char cpf[14];
  char nome[30];
  char sobrenome[30];
  char identidade[11];
  TEndereco endereco;
  TDate data_nascimento;
  char tipo_usuario[10];
} TUsuario;

typedef struct usuarios
{
  TUsuario usuario[100];
  int indice;
} TUsuarios;

#endif // FUNCTIONS_H_INCLUDED