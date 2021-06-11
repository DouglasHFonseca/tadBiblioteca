#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "livro.h"

typedef struct endereco
{
  char logradouro[100];
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
  TData data_nascimento;
  int tipo_usuario;
} TUsuario;

typedef struct usuarios
{
  TUsuario usuario[100];
  int indice;
} TModuloUsuario;

// Operações Básicas
void lerUsuario(TUsuario *usuario);
void imprimirUsuario(TUsuario usuario);
void iniciarListaUsuarios(TModuloUsuario *usuarios);

#endif // USUARIO_H_INCLUDED