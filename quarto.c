/*
 * quarto.c
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "sequencia.h"
#include "estudante.h"
#include "quarto.h"
#include "gerente.h"

#define MAX_CHAR 50 //estudantes, gerentes, localidades, residencias e universidades
#define MAX_TEXTO 200 //textos (descricoes)
#define MAX_LETRAS 20 //restantes cadeias de caracteres ex: login
#define QUARTO 10
#define CAP_ESTUDANTES 20000

struct _quarto
{
    char codigo[MAX_CHAR];
    char loginGerente[MAX_LETRAS];
    char nomeResidencia[MAX_CHAR];
    char universidade[MAX_CHAR];
    char localidade[MAX_CHAR];
    int andar;
    char descricao[MAX_TEXTO];
    char estado[MAX_CHAR]; // livre ou ocupado
    sequencia estudantes;  // sequencia de logins dos estudantes que fizeram candidatura a este quarto
};

struct _candidato
{
    estudante estudante;
};

quarto criaQuarto(char *codigo, char *loginGerente, char *nomeResidencia, char *universidade, char *localidade, int andar, char *descricao){
    
    quarto q = (quarto)malloc(sizeof(struct _quarto));
    if (q == NULL){
        return NULL;
    }

    strcpy(q->codigo, codigo);
    strcpy(q->loginGerente, loginGerente);
    strcpy(q->nomeResidencia, nomeResidencia);
    strcpy(q->universidade, universidade);
    strcpy(q->localidade, localidade);
    q->andar = andar;
    strcpy(q->descricao, descricao);
    strcpy(q->estado, "livre");
    q->estudantes = criaSequencia(CAP_ESTUDANTES); // Inicializa a sequência de estudantes
    if (q->estudantes == NULL){
        free(q);
        return NULL;
    }

    return q;
}

void destroiQuarto(quarto q){
    destroiSequencia(q->estudantes);
    free(q);
}


char *daCodigoQuarto(quarto q){
    return q->codigo;
}

char *daLoginGerenteQuarto(quarto q){
    return q->loginGerente;
}

char *daNomeResidencia(quarto q){
    return q->nomeResidencia;
}

char *daLocalidadeQuarto(quarto q){
    return q->localidade;
}

int daAndarQuarto(quarto q){
    return q->andar;
}

char *daDescricaoQuarto(quarto q){
    return q->descricao;
}

char *daUniversidadeQuarto(quarto q){
    return q->universidade;
}

char *daEstadoQuarto(quarto q){ //"livre" ou "ocupado"
    return q->estado;
}

void mudaEstadoQuarto(quarto q){
    if (strcmp(q->estado, "livre") == 0)
        strcpy(q->estado, "ocupado");
    else if (strcmp(q->estado, "ocupado") == 0)
        strcpy(q->estado, "livre");
}

sequencia EstudantesQuarto(quarto q){
    return q->estudantes;
}

int fezCandidatura(quarto q, char *loginEstudante){
// Verifica se o estudante fez candidatura para o quarto

    for (int i = 0; i < tamanhoSequencia(q->estudantes); i++){
    candidato c = (candidato)elementoPosSequencia(q->estudantes, i);

        if (strcmp(LoginEstudante(c->estudante), loginEstudante) == 0){
            return 1; // O estudante fez candidatura para o quarto
        }
    }
    return 0;
}

candidato criaCandidato(estudante e){

    candidato c = (candidato)malloc(sizeof(struct _candidato));
    if (c == NULL){
        return NULL;
    }
    c->estudante = e;
    return c;
}

void destroiCandidato(candidato c){
    free(c);
}

estudante getEstudanteCandidato(candidato c){
    return c->estudante;
}

int verCandidaturasQuarto(quarto q){
    if(tamanhoSequencia(q->estudantes)==0)
        return 0; //nao há candidaturas para este quarto
    else
        return 1; //ha candidaturas para o quarto
}

int adicionaCandidatoQuarto(quarto q, candidato c){
    // Verifica se o candidato já fez candidatura para o quarto
    int i;
    for (i = 0; i < tamanhoSequencia(q->estudantes); i++){
        candidato candidatoExistente = (candidato)elementoPosSequencia(q->estudantes, i);

        if (strcmp(LoginEstudante(candidatoExistente->estudante), LoginEstudante(c->estudante)) == 0){
            return 0; // O candidato já fez candidatura para o quarto
        }
    }
    // Adiciona o candidato à sequência de estudantes
    adicionaPosSequencia(q->estudantes, c, i);
    return 1; // Candidato adicionado ao quarto com sucesso
}

int removeCandidatoQuarto(quarto q, char *loginEstudante){
    // Verifica se o estudante é um candidato para o quarto

    for (int i = 0; i < tamanhoSequencia(q->estudantes); i++){
        candidato c = (candidato)elementoPosSequencia(q->estudantes, i);
        if (strcmp(LoginEstudante(c->estudante), loginEstudante) == 0){
            removePosSequencia(q->estudantes, i);
            return 1; // Candidato removido do quarto com sucesso
            }
        }

        return 0; // O estudante não é um candidato para o quarto
    }
