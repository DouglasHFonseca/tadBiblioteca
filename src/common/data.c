#include <stdio.h>
#include <stdio_ext.h>
#include <time.h>
#include "data.h"

void dataAtual()
{
  //variável do tipo time_t (da biblioteca time.h) para armazenar o tempo em segundos
  time_t segundos;

  //obtendo o tempo em segundos
  time(&segundos);

  //para converter de segundos para o tempo local utilizamos a função localtime
  data_hora_atual = localtime(&segundos);
}

/* Função auxiliar para definir os valores da estrutura DataHora */
void defineDataHora(TData *pd, int hora, int minuto, int segundo, int dia, int mes, int ano)
{
  pd->hora = hora;
  pd->minuto = minuto;
  pd->segundo = segundo;
  pd->dia = dia;
  pd->mes = mes;
  pd->ano = ano;
}

/* Função auxiliar para imprimir os valores da estrutura DataHora formatados */
void imprimeDataHora(TData d)
{
  printf("%02d:%02d:%02d %02d/%02d/%04d", d.hora, d.minuto, d.segundo, d.dia, d.mes, d.ano);
}

/* Função para verificação se um ano é bissexto */
int ehBissexto(int ano)
{
  int test;
  /*
      Um ano só é bissexto se ele for divisível por 4 e NÃO FOR divisível por 100
      (a não ser que ele seja divisível por 100 E TAMBÉM divisível por 400).
    */
  if ((ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0))
  {
    return 1;
  }
  else
  {
    return 0;
  }
  return test;
}

/* Função para contar quantos anos bissextos tem entre o ano 1/1/1 e o ano dado */
int contaBissextos(int ano)
{
  return (ano / 4) - (ano / 100) + (ano / 400);
}

/* Função para converter a DataHora dada para segundos */
unsigned long long dataParaSegundos(TData d)
{
  unsigned long long total = 0LL;

  /*
     Primeiro, calcula o tempo decorrido em segundos até a data
     sem contar os anos bissextos, considerando:

     31536000 = número de segundos em um ano não bissexto (365 dias)
     86400 = número de segundos em um dia (24 horas)
     3600 = número de segundos em 1 hora (60 minutos)
     60 = número de segundos em 1 minuto (60 segundos)
    */

  total += (d.ano - 1) * 31536000LL;

  int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int mes = 1; mes < d.mes; mes++)
    total += meses[mes - 1] * 86400LL;

  total += (d.dia - 1) * 86400LL;

  total += d.hora * 3600LL;

  total += d.minuto * 60LL;

  total += d.segundo;

  /*
     Então, adiciona segundos para cada dia adicional dos anos bissextos
    */

  /* Número de dias adicionais, para os anos bissextos anteriores ao ano atual */
  int diasExtras = contaBissextos(d.ano - 1);
  total += diasExtras * 86400LL;

  /* Se o mês da data já passou de fereveiro e o ano atual é bissexto, adiciona mais um dia */
  if (ehBissexto(d.ano) == 1 && (d.mes - 1) >= 2)
    total += 86400LL;

  return total;
}

/* Função para o cálculo da diferença em segundos entre duas datas */
unsigned long long calculaDiferencaEmSegundos(TData d1, TData d2)
{
  unsigned long long segundosd1 = dataParaSegundos(d1);
  unsigned long long segundosd2 = dataParaSegundos(d2);

  if (segundosd1 > segundosd2)
    return segundosd1 - segundosd2;
  else
    return segundosd2 - segundosd1;
}

/* Função para o cálculo da diferença em dias entre duas datas */
unsigned long long calculaDiferencaEmDias(TData d1, TData d2)
{
  unsigned long long segundos = calculaDiferencaEmSegundos(d1, d2);
  return segundos / 86400LL;
}

/* Função principal do programa */
int comparaData(TData data)
{
  dataAtual();
  TData d1, d2;
  defineDataHora(&d1, 0, 0, 0, data.dia, data.mes, data.ano);
  defineDataHora(&d2, 0, 0, 0, data_hora_atual->tm_mday, data_hora_atual->tm_mon, data_hora_atual->tm_year);

  return calculaDiferencaEmDias(d1, d2);
}
