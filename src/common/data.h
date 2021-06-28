#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <time.h>

/* Estrutura para representar uma DataHora */
typedef struct data
{
  int hora;
  int minuto;
  int segundo;
  int dia;
  int mes;
  int ano;
} TData;
/*
*Ponteiro para struct que armazena data e hora
*essa struct tm vem da biblioteca time.h
*/
struct tm *data_hora_atual;

// inicializa a estrutura tm com as informações da data atual;
void dataAtual();
int comparaData(TData data);
#endif // DATA_H_INCLUDED