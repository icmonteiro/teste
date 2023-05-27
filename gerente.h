/*
 * gerente.h
 */
#ifndef _H_GERENTE
#define _H_GERENTE

/* Tipo do TAD estudante */
typedef struct _gerente * gerente;

/* Protótipos das funções associadas a um estudante - TAD estudante */

/***********************************************
criaGerente - Criação da instância da estrutura associada a um gerente.
Parâmetros:
	
Retorno: apontador para a instância criada
Pré-condições: 
***********************************************/
gerente criaGerente(char *login, char *nomeGerente, char *universidade);

/***********************************************
destroiGerente - Liberta a memória ocupada pela instância da estrutura associada ao gerente.
Parâmetros:
	g - gerente a apagar
Retorno:
Pré-condições: a != NULL
***********************************************/
void destroiGerente(gerente g);



char * darLoginGerente(gerente g);

char * daNomeGerente(gerente g);

char * daUniversidadeGerente(gerente g);



#endif /* _H_GERENTE */
