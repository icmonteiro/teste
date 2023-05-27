/*
    quarto.h
 */

#ifndef _H_QUARTO
#define _H_QUARTO

#include "sequencia.h"
#include "estudante.h"

/* Tipo do TAD quarto */
typedef struct _quarto *quarto;

/* Tipo do TAD candidato */
typedef struct _candidato *candidato;

/* Protótipos das funções associadas a um quarto - TAD quarto */

/***********************************************
criaQuarto - Criação da instância da estrutura associada a um quarto.
Parâmetros:
codigo - código do quarto
loginGerente - login do gerente responsável pelo quarto
nomeResidencia - nome da residência do quarto
universidade - universidade do quarto
localidade - localidade do quarto
andar - andar onde o quarto está localizado
descricao - descrição do quarto
Retorno: apontador para a instância criada
Pré-condições:
***********************************************/
quarto criaQuarto(char *codigo, char *loginGerente, char *nomeResidencia, char *universidade, char *localidade, int andar, char *descricao);

/***********************************************
destroiQuarto - Liberta a memória ocupada pela instância da estrutura associada ao quarto.
Parâmetros:
q - quarto a apagar
Retorno:
Pré-condições: q != NULL
***********************************************/
void destroiQuarto(quarto q);

/***********************************************
daEstadoQuarto - Obtém o estado do quarto (livre ou ocupado).
Parâmetros:
q - quarto
Retorno: string representando o estado do quarto
Pré-condições: q != NULL
**********************************************/
char *daEstadoQuarto(quarto q);

/***********************************************
mudaEstadoQuarto - Muda o estado do quarto para o estado fornecido.
Parâmetros:
q - quarto
estado - novo estado do quarto
Retorno:
Pré-condições: q != NULL, estado != NULL
***********************************************/
void mudaEstadoQuarto(quarto q);



/***********************************************
EstudantesQuarto - Obtém a sequência de estudantes candidatos ao quarto.
Parâmetros:
q - quarto
Retorno: sequência de estudantes candidatos ao quarto
Pré-condições: q != NULL
***********************************************/
sequencia EstudantesQuarto(quarto q);

/***********************************************
fezCandidatura - Verifica se o estudante especificado fez candidatura para o quarto.
Parâmetros:
q - quarto
loginEstudante - login do estudante
Retorno: 1 se o estudante fez candidatura para o quarto, 0 caso contrário
Pré-condições: q != NULL, loginEstudante != NULL
***********************************************/
int fezCandidatura(quarto q, char *loginEstudante);

/***********************************************
criaCandidato - Criação da instância da estrutura associada a um candidato.
Parâmetros:
e - estudante candidato
Retorno: apontador para a instância criada
Pré-condições: e != NULL
***********************************************/
candidato criaCandidato(estudante e);

/***********************************************
destroiCandidato - Liberta a memória ocupada pela instância da estrutura associada ao candidato.
Parâmetros:
c - candidato a apagar
Retorno:
Pré-condições: c != NULL
***********************************************/
void destroiCandidato(candidato c);

/***********************************************
getEstudanteCandidato - Obtém o estudante associado ao candidato.
Parâmetros:
c - candidato
Retorno: estudante associado ao candidato
Pré-condições: c != NULL
***********************************************/
estudante getEstudanteCandidato(candidato c);

/***********************************************
adicionaCandidatoQuarto - Adiciona um candidato ao quarto.
Parâmetros:
q - quarto
c - candidato
Retorno: 1 se o candidato foi adicionado ao quarto
         0 caso contrário
Pré-condições: q != NULL, c != NULL
***********************************************/
int adicionaCandidatoQuarto(quarto q, candidato c);

/***********************************************
removeCandidatoQuarto - Remove o candidato especificado do quarto.
Parâmetros:
q - quarto
loginEstudante - login do estudante candidato
Retorno: 1 se o candidato foi removido do quarto
         0 caso contrário
Pré-condições: q != NULL, loginEstudante != NULL
***********************************************/
int removeCandidatoQuarto(quarto q, char *loginEstudante);

char *daCodigoQuarto(quarto q);
char *daLoginGerenteQuarto(quarto q);
char *daNomeResidencia(quarto q);
char *daLocalidadeQuarto(quarto q);
int daAndarQuarto(quarto q);
char *daDescricaoQuarto(quarto q);
char *daUniversidadeQuarto(quarto q);
int verCandidaturasQuarto(quarto q);

#endif
