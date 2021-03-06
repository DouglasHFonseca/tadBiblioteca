#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "usuario.h"
#include <string.h>

void lerUsuario(TUsuario *usuario)
{
  // Informações Pessoais
  printf("\nDados Pessoais\n");
  {
    printf("\nDigite o Nome: ");
    __fpurge(stdin);
    fgets(usuario->nome, 30, stdin);

    printf("\nDigite o Sobrenome: ");
    __fpurge(stdin);
    fgets(usuario->sobrenome, 30, stdin);

    printf("\nDigite o CPF: ");
    __fpurge(stdin);
    fgets(usuario->cpf, 14, stdin);

    printf("\nDigite a identidade: ");
    __fpurge(stdin);
    fgets(usuario->identidade, 11, stdin);
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
    char setor[100], tipo[100];
    while (option != 1 && option != 2 && option != 3)
    {
      printf("\n1 - Aluno\n2 - Professor\n3 - Técnico");
      __fpurge(stdin);
      scanf("%d", &option);
      if (option != 1 && option != 2 && option != 3)
      {
        printf("Opção invalida!");
      }
    }
    switch (option)
    {
    case 1:
      strcpy(setor, "Discente - ");
      printf("Entre com o nome curso: ");
      __fpurge(stdin);
      fgets(tipo, 100, stdin);
      strncat(setor, tipo, 100);
      strcpy(usuario->tipo_usuario, setor);
      break;
    case 2:
      strcpy(setor, "Docente - ");
      printf("Entre com o nome do departamento: ");
      __fpurge(stdin);
      fgets(tipo, 100, stdin);
      strncat(setor, tipo, 100);
      strcpy(usuario->tipo_usuario, setor);
      break;
    case 3:
      strcpy(setor, "Tecnico - ");
      printf("Entre com o nome do departamento: ");
      __fpurge(stdin);
      fgets(tipo, 100, stdin);
      strncat(setor, tipo, 100);
      strcpy(usuario->tipo_usuario, setor);
      break;
    default:
      //Não existe a possibilidade de chegar no default já cercado no while anterior
      break;
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
  printf("- Logradouro: %s- Numero: %d- Bairro: %s- Cidade: %s- CEP: %s",
         usuario.endereco.logradouro, usuario.endereco.numero, usuario.endereco.bairro, usuario.endereco.cidade, usuario.endereco.cep);

  printf("\nTipo Usuário: ");
  printf("%s", usuario.tipo_usuario);
}

void iniciarListaUsuarios(TModuloUsuario *usuarios)
{
  usuarios->indice = 0;
}

int cadastrarUsuario(TUsuario usuario, TModuloUsuario *modulo2)
{
  if (modulo2->indice == 100)
  {
    return 0;
  }
  else
  {
    modulo2->usuarios[modulo2->indice] = usuario;
    modulo2->indice++;
    return 1;
  }
}

void imprimirTodosUsuarios(TModuloUsuario *modulo2)
{
  for (int i = 0; i < modulo2->indice; i++)
  {
    imprimirLivro(modulo2->usuarios[i]);
    printf("\n");
  }
}

void alterarLivro(int indice, TUsuario usuario, TModuloUsuario *modulo2)
{
  modulo2->usuarios[indice] = usuario;
}

int excluirLivro(int posicao, TModuloUsuario *modulo2)
{
  if (posicao == modulo2->indice - 1)
  {
    return modulo2->indice - 1;
  }
  else
  {
    modulo2->usuarios[posicao] = modulo2->usuarios[posicao + 1];
    return excluirLivro(posicao + 1, modulo2);
  }
}
