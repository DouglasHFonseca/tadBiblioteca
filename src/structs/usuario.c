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
  char cpf;
  char nome;
  char sobrenome;
  char identidade;
  TEndereco endereco;
  TDate data_nascimento;
  char tipo_usuario;
} TUsuario;

typedef struct usuarios
{
  TUsuario usuario[100];
  int indice;
} TUsuarios;
