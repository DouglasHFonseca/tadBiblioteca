#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "usuario.h"

void lerUsuario(TUsuario *usuario)
{
  // Informações Pessoais
  printf("\nDados Pessoais\n");
  {
    printf("\nDigite o Nome: ");
    __fpurge(stdin);
    fgets(usuario->nome, 20, stdin);

    printf("\nDigite o Sobrenome: ");
    __fpurge(stdin);
    fgets(usuario->sobrenome, 20, stdin);

    printf("\nDigite o CPF: ");
    __fpurge(stdin);
    fgets(usuario->cpf, 20, stdin);

    printf("\nDigite a identidade: ");
    __fpurge(stdin);
    fgets(usuario->identidade, 20, stdin);
  }

  // Data de Nascimento
  printf("\n---Data de Nascimento---\n");
  {

    printf("\nDigite o dia: ");
    __fpurge(stdin);
    scanf("%d", &usuario->data_nascimento.dia);

    printf("\nDigite o mês: ");
    __fpurge(stdin);
    scanf("%d", &usuario->data_nascimento.mes);

    printf("\nDigite o ano: ");
    __fpurge(stdin);
    scanf("%d", &usuario->data_nascimento.ano);
  }

  // Endereço
  printf("\n---Endereço---");
  {
    printf("\nLogradouro: ");
    __fpurge(stdin);
    fgets(usuario->endereco.logradouro, 100, stdin);

    printf("\nNumero: ");
    __fpurge(stdin);
    scanf("%d", &usuario->endereco.numero);

    printf("\nBairro: ");
    __fpurge(stdin);
    fgets(usuario->endereco.bairro, 100, stdin);

    printf("\nCidade: ");
    __fpurge(stdin);
    fgets(usuario->endereco.cidade, 100, stdin);

    printf("\nCEP: ");
    __fpurge(stdin);
    fgets(usuario->endereco.cep, 10, stdin);
  }
  // Tipo Usuário
  printf("\nSelecione o Tipo de Usuário: ");
  {
    int option;
    printf("\n1 - Aluno\n2 - Professor");
    __fpurge(stdin);
    scanf("%d", &option);

    if (option != 1 || option != 2)
    {
      printf("Opção invalida");
    }
    else
    {
      usuario->tipo_usuario = option;
    }
  }
}

void imprimirUsuario(TUsuario usuario)
{
  printf("\nNome: ");
  printf("%s", usuario.nome);

  printf("\nSobrenome: ");
  printf("%s", usuario.sobrenome);

  printf("\nIdentidade: ");
  printf("%s", usuario.identidade);

  printf("\nCPF: ");
  printf("%s", usuario.cpf);

  printf("\nData de Nascimento: ");
  printf("%d/%d/%d\n", usuario.data_nascimento.dia, usuario.data_nascimento.mes, usuario.data_nascimento.ano);

  printf("\nEndereço:\n");
  printf("- Logradouro: %s\n- Numero: %d\n- Bairro: %s\n- Cidade: %s\n- CEP: %s\n\n");
}

void alterarUsuario()
{
}

void excluirUsuario()
{
}