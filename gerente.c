/*
 * gerente.c
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "sequencia.h"
#include "estudante.h"
#include "gerente.h"
#include "quarto.h"
#include "syst.h"

#define MAX_CHAR 50 //estudantes, gerentes, localidades, residencias e universidades
#define MAX_TEXTO 200 //textos (descricoes)
#define MAX_LETRAS 20 //restantes cadeias de caracteres ex: login
#define QUARTO 10



struct _gerente{
    char login[MAX_LETRAS]; 
    char nomeGerente[MAX_CHAR];
    char universidade[MAX_CHAR];
};


gerente criaGerente(char *login, char *nome, char *universidade){

    gerente g;
    g = (gerente)malloc(sizeof(struct _gerente));
    if(g == NULL){
        return NULL;
    }
    strcpy(g->login, login); 
    strcpy(g->nomeGerente, nome);
    strcpy(g->universidade, universidade);
    return g;
   
  
}  


void destroiGerente(gerente g)
{
    free(g);
}


char * darLoginGerente(gerente g) //comando DG- é dado o login e depois da o output com o login e o resto da info
{                                // no momento que temos um gerente ja é so ir busca-lo para ter o resto da info
    return g->login;            // ACHO QUE ISTO SE FAZ DEPOIS NA TAD PRINCIPAL
}




char * daNomeGerente(gerente g){
    return g->nomeGerente;
}

char * daUniversidadeGerente(gerente g){
    return g->universidade;
}
