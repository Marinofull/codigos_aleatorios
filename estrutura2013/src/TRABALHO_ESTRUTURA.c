/*
 ============================================================================
 Name        : TRABALHO_ESTRUTURA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "header.h"

int main() {
	pnota lista_nota;
	pnome lista_aluno, lista_disc, lista_curso;
	psexo lista_sexo; 
	char opcao, opcao2;
	float var_consulta;


	inicializanome(&lista_aluno);
	inicializanome(&lista_curso);
	inicializanome(&lista_disc);
	inicializanota(&lista_nota);
	inicializasexo(&lista_sexo);


	while (true){ 
		scanf(" %c", &opcao);
			switch(opcao){
			case 'i':
				scanf(" %c", &opcao2);// a or d or c and n
				switch(opcao2){
					case 'a':
						insere(&lista_aluno);
						break;
					case 'd':
						insere(&lista_disc);
						break;
					case 'c':
						insere(&lista_curso);
						break;
					case 'n':
						inserenota(&lista_aluno, &lista_disc, &lista_curso, &lista_sexo, &lista_nota);
						break;
				}
				break;

			case 'm':
				scanf(" %c", &opcao2);// a or d or c and s and t
				switch(opcao2){
					case 'a':
						printf("%.1f\n", media(&lista_aluno, opcao2));
						break;

					case 'd':
						printf("%.1f\n", media(&lista_disc, opcao2));
						break;

					case 'c':
						printf("%.1f\n", media(&lista_curso, opcao2));
						break;
					case 's':
						printf("%.1f\n", media_sexo(&lista_sexo));
						break;
					case 't':
						printf("%.1f\n", mediageral(&lista_nota));
						break;
				}
				break;

			case 'n':
				var_consulta=consulta(&lista_aluno, &lista_disc);
				if(var_consulta!=0)
					printf("%.1f\n",var_consulta);
				else
					printf("-\n");
				break;
			case 'l':
				scanf(" %c", &opcao2);
				switch(opcao2){
				case 'a':
					listar(&lista_aluno);
					break;
				case 'd':
					listar(&lista_disc);
					break;
				case 'c':
					listar(&lista_curso);
					break;
				}
				break; 

			case 'r':
				retira(&lista_aluno, &lista_sexo, &lista_disc, &lista_curso, &lista_nota);
				break;
			case 'p':
				scanf(" %c", &opcao2);
				switch(opcao2){
				case 'a':
					notasnome(&lista_aluno, opcao2);
					break;
				case 'd':
					notasnome(&lista_disc, opcao2);
					break;
				case 'c':
					notasnome(&lista_curso, opcao2);
					break;
				case 's':
					notasexo(&lista_sexo);
					break;
				case 't':
					printageral(&lista_nota);
					break;
				}
				break;






			case 'e':
				return 0;
		}

	}




	return 0;
}
