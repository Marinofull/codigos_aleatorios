/*
 * header.c
 *
 *  Created on: 04/02/2013
 *      Author: ap401a
 */



#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void inicializasexo(psexo *l){
	psexo masc,fem;
	masc = (psexo)malloc(sizeof(sexo));
	fem = (psexo)malloc(sizeof(sexo));
	if (masc && fem){ 
		fem->chave='f';
		fem->prxn=NULL; 
		fem->prox=masc;
		masc->prox=NULL;
		masc->prxn=NULL;
		masc->chave='m';
		*l = fem;
	}

}

void inicializanota(pnota *l){
	*l=NULL;
}

void inicializanome(pnome *l){
	*l=NULL;
}


void insere(pnome *l){
	char nome_insere[30];
	pnome aux,aux2;
	pnome novo;
	scanf(" %s", nome_insere);
	novo=(pnome)malloc(sizeof(nome));
	strcpy(novo->chave,nome_insere);
	novo->prxn=NULL;

	for(aux=*l,aux2=NULL; aux && (strcmp(aux->chave, nome_insere) < 0); aux2=aux, aux=aux->prox);
	if(aux2){
		novo->prox=aux2->prox;
		aux2->prox=novo;
	}
	else{
		novo->prox=*l;
		*l=novo;
	}

}

void listar(pnome *l){
	pnome aux=*l;
	for(; aux; aux=aux->prox)
		printf("%s\n",aux->chave);
}

void inserenota(pnome *lista_aluno, pnome *lista_disc,pnome *lista_curso,psexo *lista_sexo, pnota *lista_nota){
	char nome_aluno[30], nome_disc[30], nome_curso[30], csexo;
	float n;
	pnome aux_aluno=*lista_aluno, aux_disc=*lista_disc, aux_curso=*lista_curso;
	psexo aux_sexo=*lista_sexo;
	pnota novo = (pnota)malloc(sizeof(nota));
	scanf(" %s", nome_aluno);
	scanf(" %c", &csexo);
	scanf(" %s", nome_disc);
	scanf(" %s", nome_curso);
	scanf(" %f", &n);

	novo->chave=n;
	for(; strcmp(aux_aluno->chave,nome_aluno) ; aux_aluno=aux_aluno->prox);
	for(; strcmp(aux_disc->chave,nome_disc); aux_disc=aux_disc->prox);
	for(; strcmp(aux_curso->chave,nome_curso); aux_curso=aux_curso->prox);
	for(; aux_sexo->chave!=csexo; aux_sexo=aux_sexo->prox);

	novo->prxa=aux_aluno->prxn;
	novo->prxc=aux_curso->prxn;
	novo->prxd=aux_disc->prxn;
	novo->prxs=aux_sexo->prxn;
	novo->prox=*lista_nota;


	/*novo->anta=NULL;
	novo->antc=NULL;
	novo->antd=NULL;
	novo->ants=NULL;
	novo->ant=NULL;

	if (aux_aluno->prxn){
		aux_aluno->prxn->anta=novo;
	}
	if (aux_disc->prxn){
		aux_disc->prxn->antd=novo;
	}
	if (aux_curso->prxn){
		aux_curso->prxn->antc=novo;
	}
	if (aux_sexo->prxn){
		aux_sexo->prxn->ants=novo;
	}
	if (*lista_nota){
		(*lista_nota)->ant=novo;
	}*/

	*lista_nota=novo;
	aux_aluno->prxn=novo;
	aux_disc->prxn=novo;
	aux_curso->prxn=novo;
	aux_sexo->prxn=novo;
}


float consulta(pnome *lista_aluno,pnome *lista_disc){
	pnome aux_aluno=*lista_aluno, aux_disc=*lista_disc;
	pnota aux_aluno_nota, aux_disc_nota;
	char nome_aluno[30], nome_disc[30];
	pnota	intercessao=NULL;

	scanf(" %s", nome_aluno);
	scanf(" %s", nome_disc);

	for(; strcmp(aux_aluno->chave,nome_aluno) ; aux_aluno=aux_aluno->prox);
	for(; strcmp(aux_disc->chave,nome_disc); aux_disc=aux_disc->prox);

	for(aux_aluno_nota=aux_aluno->prxn; aux_aluno_nota ; aux_aluno_nota=aux_aluno_nota->prxa)
		for(aux_disc_nota=aux_disc->prxn; aux_disc_nota ; aux_disc_nota=aux_disc_nota->prxd)
			if(aux_aluno_nota == aux_disc_nota)
				intercessao=aux_aluno_nota;
	return intercessao->chave;
}


float media(pnome *l, char op){
	int i=0;
	float soma=0;
	pnota aux_nota;
	pnome aux_nome=*l;
	char nome_procurado[30];

	scanf(" %s", nome_procurado);

	for(; strcmp(aux_nome->chave,nome_procurado) ; aux_nome=aux_nome->prox);
	aux_nota=aux_nome->prxn;
	switch(op){
	case 'a':
		for(; aux_nota ; aux_nota=aux_nota->prxa){
			soma = soma + aux_nota->chave;
			i++;
		}
		break;
	case 'd':
		for(; aux_nota ; aux_nota=aux_nota->prxd){
			soma = soma + aux_nota->chave;
			i++;
		}
		break;
	case 'c':
		for(; aux_nota ; aux_nota=aux_nota->prxc){
			soma = soma + aux_nota->chave;
			i++;
		}
		break;
	}


	return soma/i;
}



float media_sexo(psexo *l){
	int i=0;
	float soma=0;
	pnota aux_nota;
	psexo aux_sexo=*l;
	char sx;

	scanf(" %c", &sx);

	for(; aux_sexo->chave!=sx ; aux_sexo=aux_sexo->prox);
	aux_nota=aux_sexo->prxn;

	for(; aux_nota; aux_nota=aux_nota->prxs){
		soma = soma + aux_nota->chave;
		i++;
	}

	return soma/i;
}

float mediageral(pnota *l){
	int i=0;
	float soma=0;
	pnota aux_nota;

	for(aux_nota=*l; aux_nota ; aux_nota=aux_nota->prox){
		soma = soma + aux_nota->chave;
		i++;
	}


	return soma/i;
}

void retira(pnome *lista_aluno, psexo *lista_sexo, pnome *lista_disc,pnome *lista_curso, pnota *lista_nota){
	char nome_aluno[30], nome_disc[30], nome_curso[30], sexo;
	pnome aux_aluno=*lista_aluno, aux_disc=*lista_disc, aux_curso=*lista_curso;
	psexo aux_sexo=*lista_sexo;
	pnota percorrenota=*lista_nota, percorrenota2, nota_aluno, nota_disc, nota_curso, nota_sexo, nota2_aluno, nota2_disc, nota2_curso, nota2_sexo;

	scanf(" %s", nome_aluno);
	scanf(" %c", &sexo);
	scanf(" %s", nome_disc);
	scanf(" %s", nome_curso);

	for(; strcmp(aux_aluno->chave, nome_aluno); aux_aluno=aux_aluno->prox);
	for(; strcmp(aux_disc->chave, nome_disc); aux_disc=aux_disc->prox);
	for(; strcmp(aux_curso->chave, nome_curso); aux_curso=aux_curso->prox);
	for(; aux_sexo->chave!=sexo; aux_sexo=aux_sexo->prox);

	for(nota_curso=aux_curso->prxn, nota2_curso=NULL; (nota_curso); nota2_curso=nota_curso, nota_curso=nota_curso->prxc)
		for(nota_sexo=aux_sexo->prxn, nota2_sexo=NULL; (nota_sexo); nota2_sexo=nota_sexo, nota_sexo=nota_sexo->prxs)
			for(nota_disc=aux_disc->prxn, nota2_disc=NULL; (nota_disc); nota2_sexo=nota_sexo, nota_disc=nota_disc->prxd)
				for(nota_aluno=aux_aluno->prxn, nota2_aluno=NULL; (nota_aluno); nota2_aluno=nota_aluno, nota_aluno=nota_aluno->prxa)
					for(percorrenota2=NULL;(percorrenota);percorrenota=percorrenota->prox)
						if ((nota_curso==nota_sexo) && (nota_sexo==nota_disc) && (nota_disc==nota_aluno) && (nota_aluno=percorrenota)){
							if (nota2_aluno)
								nota2_aluno->prxa=nota_aluno->prxa;
							else
								aux_aluno->prxn=nota_aluno->prxa;
							if (nota2_disc)
								nota2_disc->prxd=nota_disc->prxd;
							else
								aux_disc->prxn=nota_disc->prxd;

							if (nota2_curso)
								nota2_curso->prxc=nota_curso->prxc;
							else
								aux_curso->prxn=nota_curso->prxc;

							if (nota2_sexo)
								nota2_sexo->prxs=nota_sexo->prxs;
							else
								aux_sexo->prxn=nota_sexo->prxs;
							if (percorrenota2)
								percorrenota2->prox=percorrenota->prox;
							else
								*lista_nota=percorrenota->prox;

							free(percorrenota);
							return;
						}


	/*for(nota_curso=aux_curso->prxn; i && nota_curso; nota_curso=nota_curso->prxc)
		for(nota_sexo=aux_sexo->prxn; i && nota_sexo; nota_sexo=nota_sexo->prxs)
			for(nota_disc=aux_disc->prxn; i && nota_disc; nota_disc=nota_disc->prxd)
				for(nota_aluno=aux_aluno->prxn; i && nota_aluno ; nota_aluno=nota_aluno->prxa)
					if (nota_curso==nota_sexo && nota_sexo==nota_curso && nota_curso==nota_aluno){
						if (nota_aluno){
							if (nota_aluno->anta)
								nota_aluno->anta->prxa=nota_aluno->prxa;
							else
							{
								aux_aluno->prxn=nota_aluno->prxa;nota_aluno->prxa->anta=NULL;
							}
						}
						if (nota_disc){
							if (nota_disc->anta)
								nota_disc->antd->prxd=nota_disc->prxd;
							else
							{
								aux_disc->prxn=nota_disc->prxd;nota_disc->prxd->antd=NULL;
							}
						}
						if (nota_curso){
							if (nota_curso->anta)
								nota_curso->antc->prxc=nota_curso->prxc;
							else
							{
								aux_curso->prxn=nota_curso->prxc;nota_curso->prxc->antc=NULL;
							}
						}
						if (nota_sexo){
							if (nota_sexo->anta)
								nota_sexo->ants->prxs=nota_sexo->prxs;
							else
							{
								aux_sexo->prxn=nota_sexo->prxs;nota_sexo->prxs->ants=NULL;
							}
						}

						i=0;
					}*/



}

void notasnome(pnome *l, char op){
	pnota aux_nota;
	pnome aux_nome=*l;
	char nome_procurado[30];

	scanf(" %s", nome_procurado);

	for(; strcmp(aux_nome->chave,nome_procurado) ; aux_nome=aux_nome->prox);
	aux_nota=aux_nome->prxn;
	switch(op){
	case 'a':
		for(; aux_nota ; aux_nota=aux_nota->prxa){
			printf("%.1f ", aux_nota->chave);
		}
		break;
	case 'd':
		for(; aux_nota ; aux_nota=aux_nota->prxd){
			printf("%.1f ", aux_nota->chave);
		}
		break;
	case 'c':
		for(; aux_nota ; aux_nota=aux_nota->prxc){
			printf("%.1f ", aux_nota->chave);
		}
		break;
	}
}


void notasexo(psexo *l){
	pnota aux_nota;
	psexo aux_sexo=*l;
	char sx;

	scanf(" %c", &sx);

	for(; aux_sexo->chave!=sx ; aux_sexo=aux_sexo->prox);
	aux_nota=aux_sexo->prxn;

	for(; aux_nota; aux_nota=aux_nota->prxs){
		printf("%.1f ", aux_nota->chave);
	}
}

void printageral(pnota *l){
	pnota aux_nota;

	for(aux_nota=*l; aux_nota ; aux_nota=aux_nota->prox){
		printf("%.1f ", aux_nota->chave);
	}
}
