#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct data
{
  int dia;
  int mes;
  int ano;
} TDate;

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

#endif // USUARIO_H_INCLUDED