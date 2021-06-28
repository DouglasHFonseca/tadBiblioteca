#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "livro.h"
#include <string.h>

void lerLivro(TLivro *livro)
{
  // Dados Básicos do Livro
  {
    printf("\nDados Livro\n");
    printf("\nISBN: ");
    __fpurge(stdin);
    fgets(livro->ISBN, 20, stdin);

    printf("\nTitulo: ");
    __fpurge(stdin);
    fgets(livro->titulo, 100, stdin);

    printf("\nEditora: ");
    __fpurge(stdin);
    fgets(livro->editora, 100, stdin);

    printf("\nLocal de Publicação: ");
    __fpurge(stdin);
    fgets(livro->local, 100, stdin);
  }

  // Data de Publicação do Livro
  {
    printf("\n---Data de Publicação---\n");
    printf("\nDigite o dia: ");
    __fpurge(stdin);
    scanf("%d", &livro->data_pub.dia);

    printf("\nDigite o mês: ");
    __fpurge(stdin);
    scanf("%d", &livro->data_pub.mes);

    printf("\nDigite o ano: ");
    __fpurge(stdin);
    scanf("%d", &livro->data_pub.ano);
  }

  // Dados dos Autores
  {
    printf("\nPrimeiro Autor: ");
    __fpurge(stdin);
    fgets(livro->prim_autor, 100, stdin);

    printf("\nSegundo Autor: ");
    __fpurge(stdin);
    fgets(livro->seg_autor, 100, stdin);
  }

  //Controle de Estoque dos Livros
  {
    printf("\nQuantidade de livros para o acervo: ");
    __fpurge(stdin);
    scanf("%d", &livro->quantidade);
    livro->quant_emprestados = 0;
  }
}

void imprimirLivro(TLivro livro)
{
  printf("\nISBN: ");
  printf("%s", livro.ISBN);

  printf("\nTitulo: ");
  printf("%s", livro.titulo);

  printf("\nEditora: ");
  printf("%s", livro.editora);

  printf("\nLocal de Publicação: ");
  printf("%s", livro.local);

  printf("\nData de Publicação: ");
  printf("%d/%d/%d\n", livro.data_pub.dia, livro.data_pub.mes, livro.data_pub.ano);

  printf("\nPrimeiro Autor: ");
  printf("%s", livro.prim_autor);

  printf("\nSegundo Autor: ");
  printf("%s", livro.seg_autor);

  printf("\nQuantidade disponível: ");
  printf("%d", livro.quantidade);
}

void iniciarListaLivro(TModuloLivro *modulo1)
{
  modulo1->indice = 0;
}

int verificaDisponibilidade(TLivro *livro)
{
  int percent = ((livro->quant_emprestados - livro->quantidade) / livro->quantidade) * 100;

  return percent;
}

int cadastrarLivro(TLivro livro, TModuloLivro *modulo1)
{
  if (modulo1->indice == 100)
  {
    return 0;
  }
  else
  {
    modulo1->livros[modulo1->indice] = livro;
    modulo1->livros[modulo1->indice].quant_emprestados++;
    modulo1->indice++;

    return 1;
  }
}

void imprimirTodosLivros(TModuloLivro *modulo1)
{
  for (int i = 0; i < modulo1->indice; i++)
  {
    imprimirLivro(modulo1->livros[i]);
    printf("\n");
  }
}

int pesquisarIdLivro(TLivro livro, TModuloLivro *modulo1)
{
  int response = 0;
  for (int i = 0; i < modulo1->indice; i++)
  {
    if (strcmp(modulo1->livros[i].ISBN, livro.ISBN) == 0)
    {
      response = i;
      break;
    }
    else
    {
      response = -1;
    }
  }

  return response;
}

void alterarLivro(int indice, TLivro livro, TModuloLivro *modulo1)
{
  modulo1->livros[indice] = livro;
}

int excluirLivro(int posicao, TModuloLivro *modulo1)
{
  if (posicao == modulo1->indice - 1)
  {
    return modulo1->indice - 1;
  }
  else
  {
    modulo1->livros[posicao] = modulo1->livros[posicao + 1];
    return excluirLivro(posicao + 1, modulo1);
  }
}