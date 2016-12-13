#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logica.h"
#include "visual.h"


int main() {
	limpar_tela();
	int continuar = 0;

    do
    {
        
    	mostrar_menu();

        scanf("%d", &continuar);
        limpar_tela();
        limpar_input();
        switch(continuar){
            case JOGAR:
       			start();
 				int resultado = jogo();
 				mostrarResultado(resultado);;
                break;

            case CREDITOS:
            	limpar_tela();
            	creditos();
                break;

            case RANKING:
            	ranking_menu();
                break;
            case SAIR:
        		continuar = 0;
            	break;
            default:
                printf("Digite uma opcao valida\n");
                continuar = 1;
    	}
    } while(continuar);
    return 0;
}





