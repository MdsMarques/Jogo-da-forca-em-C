#include "visual.h"
#include "logica.h"




void boneco_perdeu(){
		printf("\n");
		printf("  ##########***##  \n");
		printf("  ####       *    \n");
		printf("  ####      ***   \n");
		printf("  ##       *X X*  \n");
		printf("  ##       * ^ *  \n");
		printf("  ##         *    \n");
		printf("  ##         |    \n");
		printf("  ##        /|\\   \n");
		printf("  ##       / | \\  \n");
		printf("  ##         |    \n");
		printf("  ##         |    \n");
		printf("  ##        / \\   \n");
		printf("  ##       /   \\  \n\n");
}

void boneco_ganhou(){
		printf("\n");
		printf("  ##########***##  \n");
		printf("  ####       *    \n");
		printf("  ####      ***   \n");
		printf("  ##       *@ @*  \n");
		printf("  ##       * D *  \n");
		printf("  ##         *    \n");
		printf("  ##         |    \n");
		printf("  ##        /|\\   \n");
		printf("  ##       / | \\  \n");
		printf("  ##         |    \n");
		printf("  ##         |    \n");
		printf("  ##        / \\   \n");
		printf("  ##       /   \\  \n\n");
}

void creditos(){

    printf("########################### CREDITOS ###########################\n");
   	printf("+--------------------------------------------------------------+\n");
	printf("|Programa Desenvolvido Por:                                    |\n");
	printf("|                           Matheus, Yuri, Jackson, Ruan       |\n");
	printf("|Este projeto foi feito com muito amor e carinho, antes de tudo|\n");
	printf("|, sabemos que não esta comcluido, porem dei o meu maximo, e   |\n");
	printf("|aprendemos muito com esse projeto e suas aulas.               |\n");
	printf("\n");
	printf("  OBRIGADO##***##                                               \n");
	printf("  ####       *    												\n");
	printf("  ####      ***   												\n");
	printf("  ##       *u u*  												\n");
	printf("  ##       * @ *  												\n");
	printf("  ##         *    												\n");
	printf("  ##         |    												\n");
	printf("  ##        /|\\   												\n");
	printf("  ##       / | \\  												\n");
	printf("  ##         |    												\n");
	printf("  ##         |    												\n");
	printf("  ##        / \\   												\n");
	printf("  ##       /   \\  												\n");
	printf("+------------------------------------------------------------+\n\n");
}

void boneco_chance(int chances){

	        		switch (chances) {
				case 6:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####            \n");
					printf("  ####            \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n\n");
					break;
				case 5:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n\n");
					break;
				case 4:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n\n");
					break;
				case 3:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|    \n");
					printf("  ##       / |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n\n");
					break;
				case 2:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n\n");
					break;
				case 1:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        /     \n");
					printf("  ##       /      \n\n");
					break;
				}

}

ENUM_OPC menu(int continuar)
{
	switch(continuar){
		case 1 :
			return JOGAR;
			break;
		case 2 :
			return CREDITOS;
			break;
		case 3 :
			return RANKING;
			break;
		case 4 :
			return SAIR;
			break;
	}




}


void mostrar_menu(){

		printf("\nJOGO DA FORCA\n\n");
        printf("1. JOGAR\n");
        printf("2. CREDITOS\n");
        printf("3. RANKING\n");
        printf("4. SAIR\n");
} 