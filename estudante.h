/*
 * estudante.h
 */

#ifndef _H_ESTUDANTE
#define _H_ESTUDANTE

#include "sequencia.h"

/* Tipo do TAD estudante */
typedef struct _estudante * estudante;

/* Protótipos das funções associadas a um estudante - TAD estudante */

/***********************************************
criaEstudante - Criação da instância da estrutura associada a um estudante.
Parâmetros:
	login - nome de utilizador do estudante
Retorno: apontador para a instância criada
Pré-condições: 
***********************************************/
estudante criaEstudante(char *login, char *nome, char *universidade, int idade, char *localidade);

/***********************************************
destroiEstudante - Liberta a memória ocupada pela instância da estrutura associada ao estudante.
Parâmetros:
	e - estudante a apagar
Retorno:
Pré-condições: a != NULL
***********************************************/
void destroiEstudante(estudante e);

/***********************************************
loginEstudante - Retorna o login do estudante.
Parâmetros:
	e - estudante
Retorno: login do estudante
Pré-condições: e != NULL
***********************************************/
char* LoginEstudante(estudante e);

/***********************************************
NomeEstudante - Retorna o nome do estudante.
Parâmetros:
	e - estudante
Retorno: nome do estudante
Pré-condições: e != NULL
***********************************************/
char* NomeEstudante(estudante e);

/***********************************************
UniversidadeEstudante - Retorna a universidade do estudante.
Parâmetros:
	e - estudante
Retorno: universidade do estudante
Pré-condições: e != NULL
***********************************************/
char* UniversidadeEstudante(estudante e);

/***********************************************
IdadeEstudante - Retorna a idade do estudante.
Parâmetros:
	e - estudante
Retorno: idade do estudante
Pré-condições: e != NULL
***********************************************/
int IdadeEstudante(estudante e);

/***********************************************
LocalidadeEstudante - Retorna a localidade do estudante.
Parâmetros:
	e - estudante
Retorno: localidade do estudante
Pré-condições: e != NULL
***********************************************/
char* LocalidadeEstudante(estudante e);

/***********************************************
adicionaQuartoEstudante - Adiciona um quarto à lista de quartos do estudante.
Parâmetros:
	e - estudante
	codigoQuarto - código do quarto a ser adicionado
Retorno: 1 se o quarto foi adicionado;
		 0 caso contrário
Pré-condições: e != NULL
***********************************************/
int adicionaQuartoEstudante(estudante e, char *codigoQuarto);

/***********************************************
removeQuarto - Remove um quarto da lista de quartos do estudante.
Parâmetros:
	e - estudante
	codigoQuarto - código do quarto a ser removido
Retorno:
Pré-condições: e != NULL
***********************************************/
void removeQuarto(estudante e, char *codigoQuarto);

/***********************************************
QuartosEstudante - Retorna a sequência de quartos do estudante.
Parâmetros:
	e - estudante
Retorno: sequência de quartos do estudante
Pré-condições: e != NULL
***********************************************/
sequencia QuartosEstudante(estudante e);


int estudanteCandidatura(estudante e, char *codigoQuarto);

void atualizaNomeEstudante(estudante e, char *novoNome);

#endif /* _H_ESTUDANTE */
