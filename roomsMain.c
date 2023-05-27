/*
roomsMain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// meter os includes por ordem decrescente
/* TADs usados */

#include "messages.h"
#include "estudante.h"
#include "quarto.h"
#include "gerente.h"
#include "syst.h"

#include "sequencia.h"
#include "dicionario.h"
#include "iterador.h"
#include "chaves.h"

#define MAXL 40 
#define MAXVAR 50
#define CMD 3
#define MAX_CHAR 50	  // estudantes, gerentes, localidades, residencias e universidades
#define MAX_TEXTO 200 // textos (descricoes)
#define MAX_LETRAS 20 // restantes cadeias de caracteres ex: login
#define LOGIN 10

/* protótipos das funções usadas no main */
void interpretador(sistema s);
/*
IE -> insercao de novo estudante
DE -> informacao sobre um estudante
IG -> insercao de novo gerente
DG -> informacao sobre um gerente
IQ -> insercao de novo quarto
DQ -> informacao sobre um quarto
MQ -> modificacao do estado de um quarto
RQ -> remocao de um quarto
IC -> insercao de candidatura de um estudante a um quarto
AC -> aceitacao de candidatura (ou seja, atribuicao de quarto a um estudante)
LC -> listagem de candidaturas a um quarto
XS -> termina a execucao do programa
*/
void cmdInsercaoEstudante(sistema s, char * linha1);
void cmdInfoEstudante(sistema s, char * linha1);
void cmdInsercaoGerente(sistema s, char * linha1);
void cmdInfoGerente(sistema s, char * linha1);
void cmdInsercaoNovoQuarto(sistema s, char *linha1);
void cmdInfoQuarto(sistema s, char *linha1);
void cmdModificacaoEstadoQuarto(sistema s, char *linha1);


int main(void){

	sistema s = criaSistema(); // o que pomos nestes parametros?
	
	interpretador(s);
	destroiSistema(s);
	return 0;
}

void interpretador(sistema s){ 
	
	/*char login[MAXVAR];
	char nome[MAXVAR];*/

	//estudante e = criaEstudante(login, nome);
	char linha1[MAXL];
	
	char cmd[CMD];

	
	
	while (strcmp("XS", cmd) != 0){
		printf("> ");
		fgets(linha1, MAXL, stdin);
		sscanf(linha1, "%s ", cmd);
		
		/* Tratar comando - nao podemos usar switch pq tem 2 caracteres*/
		if(strcmp ("IE", cmd) == 0){
			cmdInsercaoEstudante(s, linha1);
		}else if(strcmp("DE", cmd) == 0){
			cmdInfoEstudante(s, linha1);
		}else if(strcmp("IG", cmd) == 0){
			cmdInsercaoGerente(s, linha1);
		}else if(strcmp("DG", cmd) == 0){
			cmdInfoGerente(s, linha1);
		}else if(strcmp("IQ", cmd) == 0){
			cmdInsercaoNovoQuarto(s, linha1);
		}else if(strcmp("DQ", cmd) == 0){
			cmdInfoQuarto(s, linha1);
		}else if(strcmp("MQ", cmd) == 0){
			cmdModificacaoEstadoQuarto(s, linha1);
		/*}else if(strcmp("RQ", cmd) == 0){
			cmdRemocaoQuarto();
		}else if(strcmp("IC", cmd) == 0){
			cmdCandidaturaAQuarto();
        }else if(strcmp("AC", cmd) == 0){
			cmdAceitacaoCandidatura();
        }else if(strcmp("LC", cmd) == 0){
			cmdListagemCandidaturas();*/
		
		}else if(strcmp("#", cmd) == 0){
			printf("\n\n");
			}else if(strcmp("XS", cmd) == 0){
				printf("Obrigado. Ate a proxima.\n\n");
				exit(0);	
		}else{
			printf("Comando invalido.\n\n");
		}	
	}
	printf("> ");
}

void cmdInsercaoEstudante(sistema s, char * linha1){

	char linha2[MAXL];
	char linha3[MAXL];
	char c[CMD];
	char login[MAXVAR];
	char nome[MAXVAR];
	int idade;
	char localidade[MAXVAR];
	char uni[MAXVAR];

	sscanf(linha1,"%s %s %[^\n]", c, login, nome);
    fgets(linha2, MAXL, stdin);
    sscanf(linha2,"%d %[^\n]",&idade, localidade); 
	 
	fgets(linha3, MAXL, stdin);
	sscanf(linha3,"%[^\n]", uni);
	
	if((procuraEstudante(s,login)==0)){
		insereEstudanteSistema(s,login,nome,idade,localidade,uni);
		printf("%s\n\n", MSG_REGISTO_ESTUDANTE_OK);
	}else{ //nao temos que fazer strcmp aqui?
		printf("%s\n\n", MSG_UTILIZADOR_EXISTENTE);
	}
	
}

void cmdInfoEstudante(sistema s, char *linha1){ //info gerente e info quarto vai ser igual
	char login[MAXVAR];
	char c[CMD];

	sscanf(linha1,"%s %[^\n]", c, login);
	estudante e = retornoE(s, login);

	if (procuraEstudante(s, login) == 0)
		printf("%s\n\n", MSG_ESTUDANTE_INEXISTENTE);
	else{
		printf("%s, %s, idade %d, %s\n", login, NomeEstudante(e), IdadeEstudante(e), LocalidadeEstudante(e));
		printf("%s\n\n", UniversidadeEstudante(e));
	}
}

void cmdInsercaoGerente(sistema s, char * linha1){
    
	char linha2[MAXL];
	char c[CMD];
	char login[MAXVAR];
	char nome[MAXVAR];
	char uni[MAXVAR];

	sscanf(linha1,"%s %s %[^\n]", c, login, nome);
    fgets(linha2, MAXL, stdin);
    sscanf(linha2,"%[^\n]", uni); 
	 
	if(insereGerenteSistema(s, login, nome, uni) == 1){ //eu quero percorrer a lista de estudantes e ver se o login já existe e isto nao ta bem...
		printf("%s\n\n",MSG_REGISTO_GERENTE_OK);
	}else{ //nao temos que fazer strcmp aqui?
		printf("%s\n\n", MSG_UTILIZADOR_EXISTENTE);
	}
}


void cmdInfoGerente(sistema s, char * linha1){
    
	char login[MAXVAR];
	char c[CMD];
	sscanf(linha1, "%s %[^\n]", c, login);

	/*TEMOS QUE IR BUSCAR O QUE CORRESPONDE A ESTE LOGIN: no cria estudante retornamos e 
	vamos ter que ter uma funcao do tipo estudante que vai dar os dados correspondentes aquele login */
	gerente g = elementoDicionario(daGerentes(s), login);

	if(procuraGerente(s, login) == 0){
		printf("%s, %s\n", login, daNomeGerente(g));
		printf("%s\n\n", daUniversidadeGerente(g));
	}else{
		printf("%s\n\n", MSG_GERENTE_INEXISTENTE);
	}
}

void cmdInsercaoNovoQuarto(sistema s, char *linha1){
	char c[CMD];
	char linha2[MAXL];
	char linha3[MAXL];
	char linha4[MAXL];
	char linha5[MAXL];
	char linha6[MAXL];
	char codigo[MAX_CHAR];
	char loginGerente[MAX_LETRAS];
	char nomeResidencia[MAX_CHAR];
	char universidade[MAX_CHAR];
	char localidade[MAX_CHAR];
	int andar;
	char descricao[MAX_TEXTO];
	//char* estado = "livre";

	quarto q = elementoDicionario(daQuartos(s),loginGerente);

	sscanf(linha1, "%s %s %[^\n]", c, codigo, loginGerente);
	fgets(linha2, MAXL, stdin);
	sscanf(linha2, "%s %[^\n]", c, nomeResidencia);
	fgets(linha3, MAXL, stdin);
	sscanf(linha3, "%s %[^\n]", c, universidade);
	fgets(linha4, MAXL, stdin);
	sscanf(linha4, "%s %[^\n]", c,localidade);
	fgets(linha5, MAXL, stdin);
	sscanf(linha5, "%d %[^\n]",&andar, c);
	fgets(linha6, MAXL, stdin);
	sscanf(linha6, "%s %[^\n]",c, descricao);

	if (procuraQuarto(s, codigo) == 1){
		printf("%s\n\n", MSG_OP_NAO_AUTORIZADA);
	}else{
		if (procuraGerente(s, loginGerente) == 0){											   // verificamos se o gerente existe
			printf("%s\n\n", MSG_GERENTE_INEXISTENTE); // gerente nao existe
		}
		if (procuraGerente(s, loginGerente) == 0){											   // verificamos se o gerente existe
			printf("%s\n\n", MSG_GERENTE_INEXISTENTE); // gerente nao existe
		}
		if (quartoUniGerente(s, universidade, loginGerente, nomeResidencia, universidade, codigo) == 1){											// verificamos se o quarto pertence à uni do gerente
			printf("%s\n\n", MSG_QUARTO_EXISTENTE); // quarto ja existe, nao podemos inserir um novo
		}
		insereQuartoSistema(s, codigo, loginGerente, nomeResidencia, universidade, localidade, andar, descricao);
		daEstadoQuarto(q); // sempre livre
		printf("%s\n\n", MSG_REGISTO_QUARTO_OK);
	}

}


void cmdInfoQuarto(sistema s, char *linha1){
	char c[CMD];
	char codigo[MAX_CHAR];

	sscanf(linha1, "%s %[^\n]", c, codigo);

	if (procuraQuarto(s, codigo) == 1){
		quarto q = elementoDicionario(daQuartos(s), codigo);
			printf("%s, %s\n", codigo, daNomeResidencia(q));
			printf("%s\n", daUniversidadeQuarto(q));
			printf("%s\n", daLocalidadeQuarto(q));
			printf("%d\n", daAndarQuarto(q));
			printf("%s\n", daDescricaoQuarto(q));
			printf("%s \n\n", MSG_LIVRE);
			if (strcmp(daEstadoQuarto(q), "livre") == 0)
				printf("%s \n\n", MSG_LIVRE);
			else
				printf("%s \n\n", MSG_OCUPADO);
	}else{
		printf("%s \n\n", MSG_QUARTO_INEXISTENTE);
	}
}



void  cmdModificacaoEstadoQuarto(sistema s, char* linha1){
	char c[CMD];
	char loginGerente[MAX_LETRAS];
	char codigo[MAX_CHAR];
	char estado[MAX_CHAR];

	sscanf(linha1, "%s %s %s %[^\n]", c, codigo, loginGerente, estado);
	quarto q = elementoDicionario(daQuartos(s), codigo);

	if(procuraQuarto(s, codigo)==1){ //se o quarto existe
		if(strcmp(daLoginGerenteQuarto(q),loginGerente)!=0)
			printf("%s \n\n",MSG_OP_NAO_AUTORIZADA);
		else if((verCandidaturasQuarto(q)==1)&& (strcmp(daEstadoQuarto(q),"ocupado")==0))
			printf("%s \n\n", MSG_CANDIDATURAS_ACTIVAS);
		else{
			if (strcmp(estado, "livre") == 0 || strcmp(estado, "ocupado") == 0){
				mudaEstadoQuarto(q);
				printf("%s \n\n", MSG_QUARTO_ATUALIZADO);
			}
		}
	}else
		printf("%s\n\n", MSG_QUARTO_INEXISTENTE);
}

/*void cmdRemocaoQuarto(){
    
}


void cmdCandidaturaAQuarto(){
    
}


void cmdAceitacaoCandidatura(){
    
}


void cmdListagemCandidaturas(){
    
}*/

