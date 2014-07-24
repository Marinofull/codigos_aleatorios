/*
 * header.h
 *
 *  Created on: 04/02/2013
 *      Author: ap401a
 */

#ifndef HEADER_H_
#define HEADER_H_
#define true 1
#define false 0

typedef struct nota{
	float chave; 
	struct nota *prox, *prxa, *prxd, *prxc, *prxs;// *ant, *anta, *antd, *antc, *ants;
}nota, *pnota;

typedef struct nome{
	char chave[30];
	struct nome *prox;
	pnota prxn;
}nome, *pnome;

typedef struct sexo{
	char chave;
	struct sexo *prox;
	pnota prxn;
}sexo, *psexo;



void inicializanome(pnome *l);
void inicializasexo(psexo *l);
void inicializanota(pnota *l);


void insere(pnome *l);
void listar(pnome *l);

void inserenota(pnome *lista_aluno, pnome *lista_disc,pnome *lista_curso,psexo *lista_sexo, pnota *lista_nota);

float consulta(pnome *lista_aluno,pnome *lista_disc);

float media(pnome *l, char opcao2);
float media_sexo(psexo *l);
float mediageral(pnota *l);

void retira(pnome *lista_aluno, psexo *lista_sexo, pnome *lista_disc,pnome *lista_curso, pnota *lista_nota);

void notasnome(pnome *l, char op);
void notasexo(psexo *l);
void printageral(pnota *l);

#endif /* HEADER_H_ */
