/*
 * syst.c
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "tuplo.h"
#include "iterador.h"
#include "sequencia.h"
#include "dicionario.h"
#include "estudante.h"
#include "gerente.h"
#include "quarto.h"
#include "syst.h"

#define MAX_CHAR 50 //estudantes, gerentes, localidades, residencias e universidades
#define MAX_TEXTO 200 //textos (descricoes)
#define MAX_LETRAS 20 //restantes cadeias de caracteres ex: login
#define QUARTO 10
#define CAP_ESTUDANTES 20000
#define CAP_GERENTES 1000
#define CAP_QUARTOS 10000



struct _sistema{
    dicionario estudantes; //dicionario de estudantes
    dicionario gerentes;  //dicionario de gerentes
    dicionario quartos;  //dicionario de quartos
    //gerente gere;
};

//criar o sistema
sistema criaSistema(){

    sistema s = (sistema)malloc(sizeof(struct _sistema));
    if(s==NULL){
        return NULL;
    }

    s->estudantes = criaDicionario(CAP_ESTUDANTES, 1); // 1 -> É STRING (perceber melhor)
    s->gerentes = criaDicionario(CAP_GERENTES, 1);
    s->quartos = criaDicionario(CAP_QUARTOS, 1);
    //s->gere = criaGerente(login,nome,uni);
    
    return s;
}

//retornar um dicionario de estudantes
dicionario daEstudantes(sistema s){
    return s->estudantes;
}

// retornar um dicionario de gerentes
dicionario daGerentes(sistema s){
    return s->gerentes;
}

// retornar um dicionario de quartos
dicionario daQuartos(sistema s){
    return s->quartos;
}

//apagar o sistema
void destroiSistema(sistema s){
    //destroiDicionario(s->estudantes);
    //destroiDicionario(s->gerentes);
    //destroiDicionario(s->quartos);
    free(s->estudantes);
    free(s->gerentes);
    free(s->quartos);
    //free(s->gere);

    free(s);
    
}

//inserir um estudante na base de dados
/*void insereEstudanteSistema(sistema s, char *login, char *nome, int idade,  char *localidade, char *uni){
    int numElems = tamanhoDicionario(s->estudantes)+1;
    estudante e = criaEstudante(login, nome, uni, idade, localidade);
    adicionaElemDicionario(s->estudantes, e, &numElems);

}*/

int insereEstudanteSistema(sistema s, char *loginEstudante, char *nomeEstudante, int idadeEstudante, char *localidadeEstudante, char *universidadeEstudante){
    estudante e = criaEstudante(loginEstudante, nomeEstudante, universidadeEstudante, idadeEstudante, localidadeEstudante);
    if(adicionaElemDicionario(s->estudantes, loginEstudante, e)==1){
        printf("Estudante %s inserido com sucesso!\n", loginEstudante);
        return 1;
    }else{
        printf("Erro ao inserir estudante %s\n", loginEstudante);
        return 0;
    }
}

    /*
    estudante retornaE(sistema s){
        insereEstudanteSistema(s,LoginEstudante(s->student),NomeEstudante(s->student),IdadeEstudante(s->student),LocalidadeEstudante(s->student),UniversidadeEstudante(s->student));
        return (s->student);
    }
    */

    // inserir um gerente na base de dados
    int insereGerenteSistema(sistema s, char *login, char *nome, char *uni)
{
    int numElems = tamanhoDicionario(s->gerentes) + 1;
    gerente g = criaGerente(login, nome, uni);
    if(adicionaElemDicionario(s->gerentes, login, &numElems) != 0 )
        return 1;
    else{
        destroiGerente(g);
        return 0;
    }
}

//inserir um quarto na base de dados
int insereQuartoSistema(sistema s, char *codigo, char *loginGerente, char *nomeResi, char* uni, char* loc, int andar, char* descricao){
    int numElems = tamanhoDicionario(s->quartos) + 1;
    quarto q = criaQuarto(codigo, loginGerente, nomeResi, uni, loc, andar, descricao);
    if (adicionaElemDicionario(s->quartos, loginGerente, &numElems) != 0)
        return 1;
    else{
        destroiQuarto(q);
        return 0;
    }
}

//ver se um dado quarto esta na base de dados
int procuraQuarto(sistema s, char* codigo){

    if(existeElemDicionario(s->quartos,codigo)==1)
        return 1; //existe
    else
        return 0;
    
}

// ver se um dado estudante esta na base de dados
/*int procuraEstudante(sistema s, char *login){

    if (existeElemDicionario(s->estudantes, login) == 1){
        return 1; // existe
    }else
        return 0; //nao existe
    
}*/

int procuraEstudante(sistema s, char *login)
{
    printf("Procurando estudante com login: %s\n", login);

    if (existeElemDicionario(s->estudantes, login) == 1)
    {
        printf("Estudante encontrado!\n");
        return 1; // existe
    }
    else
    {
        printf("Estudante não encontrado!\n");
        return 0; // nao existe
    }
}

// ver se um dado gerente esta na base de dados
int procuraGerente(sistema s, char *darLoginGerente){

    if (existeElemDicionario(s->gerentes, darLoginGerente) == 1)
        return 1; // existe
    else
        return 0; // nao existe
}

// ver se um dado quarto existe na base de dados e pertence a uni que o gerente pertence
int quartoUniGerente(sistema s, char* universidade, char *login, char *nome, char *uni, char *codigo){
    gerente g = elementoDicionario(s->gerentes, login);
    if(strcmp(daUniversidadeGerente(g), universidade) == 0){ // se for == universidade
        if (procuraQuarto(s, codigo) == 1)
            return 1; // o quarto existe e esta na uni do gerente
        else
            return 0; // o quarto nao existe
    }else
        return 0; //o quarto não está na uni do do gerente
}

//retorna a quantidade de quartos na base de dados
int quantidadeDeQuartos(sistema s){
    return(tamanhoDicionario(s->quartos));
}

// retorna a quantidade de estudantes na base de dados
int quantidadeDeEstudantes(sistema s){
    return (tamanhoDicionario(s->estudantes));
}

// retorna um estudante da base de dados
estudante retornoE(sistema s, char *loginEstudante){
    estudante e = elementoDicionario(s->estudantes, loginEstudante);
    if (e == NULL){
        return NULL;
    }
    return e;
}

