#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "data.h"

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

typedef struct modulo2
{
  TUsuario usuarios[100];
  int indice;
} TModuloUsuario;

// Operações Básicas
void lerUsuario(TUsuario *usuario);
void imprimirUsuario(TUsuario usuario);
void iniciarListaUsuarios(TModuloUsuario *usuarios);
int cadastrarUsuario(TUsuario usuario, TModuloUsuario *modulo2);
void imprimirTodosUsuarios(TModuloUsuario *modulo2);
int pesquisarIdUsuario(TUsuario usuario, TModuloUsuario *modulo2);
void alterarUsuario(int indice, TUsuario usuario, TModuloUsuario *modulo2);
int excluirUsuario(int index, TModuloUsuario *modulo2);

#endif // USUARIO_H_INCLUDED