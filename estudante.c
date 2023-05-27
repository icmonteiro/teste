/*
 * estudante.c
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "sequencia.h"
#include "estudante.h"

#define MAX_CHAR 50 //estudantes, gerentes, localidades, residencias e universidades
#define MAX_TEXTO 200 //textos (descricoes)
#define MAX_LETRAS 20 //restantes cadeias de caracteres ex: login
#define QUARTO 10

struct _estudante{
    char login[MAX_LETRAS]; 
    char nomeEstudante[MAX_CHAR];
    int idade;
    char localidade[MAX_CHAR];
    char universidade[MAX_CHAR];
    sequencia quartos; // A sequencia "quartos" é uma sequencia de strings com os codigos dos quartos aos quais o estudante fez candidatura
};


estudante criaEstudante(char *login, char *nome, char *universidade, int idade, char *localidade)
{
    estudante e;
    e = (estudante)malloc(sizeof(struct _estudante));
    if(e==NULL){
        return NULL;
    }
    strcpy(e->login, login);
    strcpy(e->nomeEstudante, nome);
    e->idade = idade;
    strcpy(e->localidade, localidade); 
    strcpy(e->universidade, universidade);
    e->quartos = criaSequencia(QUARTO);
    if (e->quartos == NULL){
        free(e);
        return NULL;
    }
    return e;
}

void destroiEstudante(estudante e)
{
    free(e->quartos);
    free(e);
}


char *LoginEstudante(estudante e)
{
    return e->login;
}

char *NomeEstudante(estudante e)
{
    return e->nomeEstudante;
}

char *UniversidadeEstudante(estudante e)
{
    return e->universidade;
}

int IdadeEstudante(estudante e)
{
    return e->idade;
}

char *LocalidadeEstudante(estudante e)
{
    return e->localidade;
}

int adicionaQuartoEstudante(estudante e, char *codigoQuarto)
{
    sequencia quartos = e->quartos;
    char * quarto;

    // Verifica se o quarto já está na sequência
    iterador it = iteradorSequencia(quartos);
    while (temSeguinteIterador(it)){
        quarto = (char *)seguinteIterador(it);
        if (strcmp(quarto, codigoQuarto) == 0){
            destroiIterador(it);
            return 0; // O quarto já está na sequência, retorna 0
        }
    }
    destroiIterador(it);

    // Adiciona o quarto à sequência
    int capacidade = tamanhoSequencia(quartos) + 1;
    if (capacidade > QUARTO){
        return 0; // A sequência está cheia, retorna 0
    }
    adicionaPosSequencia(quartos, codigoQuarto, capacidade);
    return 1; // Quarto adicionado com sucesso à sequência, retorna 1
}

void removeQuarto(estudante e, char *codigoQuarto){
    sequencia quartos = e->quartos;

    for (int i = 0; i < tamanhoSequencia(quartos); i++){
        char* quarto = (char *)elementoPosSequencia(quartos, i);

        if (strcmp(quarto, codigoQuarto) == 0){
            removePosSequencia(quartos, i); // Remove o quarto da sequência
            break;
        }
    }
}

sequencia QuartosEstudante(estudante e){
    return e->quartos;
}

int estudanteCandidatura(estudante e, char *codigoQuarto){

    sequencia quartos = e->quartos;

    for (int i = 0; i < tamanhoSequencia(quartos); i++){
        char* quarto = (char *)elementoPosSequencia(quartos, i);
        
        if (strcmp(quarto, codigoQuarto) == 0){
            return 1; // O estudante fez candidatura para o quarto
        }
    }
    return 0; // O estudante não fez candidatura para o quarto
}

void atualizaNomeEstudante(estudante e, char *novoNome){
    strcpy(e->nomeEstudante, novoNome);
}

