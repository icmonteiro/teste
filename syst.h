/*
 * syst.h
 */
#ifndef _H_SYST
#define _H_SYST

#include "dicionario.h"
/* Tipo do TAD estudante */
typedef struct _sistema * sistema;

/* Protótipos das funções associadas ao sistema - TAD sistema */

/***********************************************
criaSistema - Criação da instância da estrutura associada ao sistema.
Parâmetros:
Retorno: apontador para a instância criada
Pré-condições: 
***********************************************/
sistema criaSistema();

dicionario daEstudantes(sistema s);

dicionario daGerentes(sistema s);

dicionario daQuartos(sistema s);
/***********************************************
destroiEstudante - Liberta a memória ocupada pela instância da estrutura associada ao sistema.
Parâmetros:
	s - sistema a apagar
Retorno:
Pré-condições: s != NULL
***********************************************/
void destroiSistema(sistema s);

int insereEstudanteSistema(sistema s, char *login, char *nome, int idade,  char *localidade, char *uni);

int insereGerenteSistema(sistema s, char *login, char *nome, char * uni);
int procuraQuarto(sistema s, char *codigo);
int procuraGerente(sistema s, char *darLoginGerente);
int procuraEstudante(sistema s, char *LoginEstudante);
int quartoUniGerente(sistema s, char *universidade, char *login, char *nome, char *uni, char *codigo);
int insereQuartoSistema(sistema s, char *codigo, char *loginGerente, char *nomeResi, char* uni, char* loc, int andar, char* descricao);
int quantidadeDeQuartos(sistema s);
estudante retornoE(sistema s,char *loginEstudante);
int quantidadeDeEstudantes(sistema s);


#endif
