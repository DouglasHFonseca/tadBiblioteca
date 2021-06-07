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

void iniciarListaLivro(TBiblioteca *biblioteca)
{
  biblioteca->indice = 0;
}

void cadastrarLivro(TLivro livro, TBiblioteca *biblioteca)
{
  biblioteca->livros[biblioteca->indice] = livro;
  biblioteca->indice++;
}

void imprimirTodos(TBiblioteca *biblioteca)
{
  for (int i = 0; i < biblioteca->indice; i++)
  {
    imprimirLivro(biblioteca->livros[i]);
  }
}

int pesquisarIdLivro(char ISBN[20], TBiblioteca *biblioteca)
{
  int response = 0;
  for (int i = 0; i < biblioteca->indice; i++)
  {
    if (strcmp(biblioteca->livros[i].ISBN, ISBN) == 0)
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

void excluirLivro(int posicao, TBiblioteca *biblioteca)
{
  if (posicao == biblioteca->indice - 1)
  {
    return biblioteca->indice - 1;
  }
  else
  {
    biblioteca->livros[posicao] = biblioteca->livros[posicao + 1];
    return excluirLivro(posicao + 1, biblioteca);
  }
}
