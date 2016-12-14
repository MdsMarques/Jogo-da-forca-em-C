#include "logica.h"
#include "visual.h"

typedef struct rank{
    char nome [20];
    int pontos;
    
}ranking_pos;

int contRanking = 0;
int qtd_struct_arq = 0;

char jogador [20];
int chances = 6;
int pontuacao;
char palavra[20];
char forca[20];
char erros[27];


void limparBuffer(char *buf, int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        buf[i] = 0;
    }
}

void so_palavra(char *str) { //Tira o \n que lê junto com a variavel pra ir para a ultima linha
    int p;
    for (p = strlen(str); isspace(str[p]); p--) {
        str[p] = 0;
    }
}



int ehLetra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char maiuscula(char c) {
    return (c >= 'a' && c <= 'z') ? (c - 32) : c;
}

void start(void) {

    printf("Digite seu nome: ");
    scanf("%s", jogador);




    limparBuffer(palavra, 20);
    limparBuffer(forca, 20);
    limparBuffer(erros, 27);

    limpar_tela();

    printf("\nDigite uma palavra com até 15 letras sem usar espaçamento: ");
    scanf("%s", &palavra);
    limpar_input();
    
    



    so_palavra(palavra);

    int i;
    for (i = 0; palavra[i] != 0; i++) {
        char c = palavra[i];
        forca[i] = ehLetra(c) ? '_' : c;
    }
}

int jogo(void) {
    char tentativa;
    

    int letras = 0;
    int i;
    for (i = 0; palavra[i] != 0; i++) {
        if (ehLetra(palavra[i])) letras++;
    }

    while (chances > 0) {
        limpar_tela();
	    // printf("%s\n", palavra);  
        printf("\nVocê tem %d chances - palavras tem %d letras\n\n", chances, letras);
		boneco_chance(chances);

        printf("%s", forca);
        if (strlen(erros) > 0) {
            printf("\nErros: %s", erros);
        }
 		
        printf("\n\nDigite uma letra: ");
        scanf("%c", &tentativa);
        limpar_input();

        // Se o usuário digitou algo que não é letra, apenas insiste sem queimar uma chance.
        if (!ehLetra(tentativa)) continue;

        // Se o usuário digitou algo que ele já tentou antes (seja errando ou acertando), apenas insiste sem queimar uma chance.
        int jaTentou = 0;
        for (i = 0; erros[i] != 0; i++) {
            if (erros[i] == maiuscula(tentativa)) {
                jaTentou = 1;
                break;
            }
        }
        if (jaTentou) continue;
        for (i = 0; forca[i] != 0; i++) {
            if (maiuscula(forca[i]) == maiuscula(tentativa)) {
                jaTentou = 1;
                break;
            }
        }
        if (jaTentou) continue;

        int ganhou = 1;
        int achou = 0;
        for (i = 0; palavra[i] != 0; i++) {
            if (!ehLetra(palavra[i])) continue;
            if (forca[i] == '_') {
                if (maiuscula(palavra[i]) == maiuscula(tentativa)) {
                    forca[i] = palavra[i];
                    achou = 1;
                } else {
                    ganhou = 0;
                }
            }
        }

        if (ganhou) {
            return 1; // Ou seja, ganhou.
        }

        if (!achou) {
            chances--;
            erros[strlen(erros)] = maiuscula(tentativa);
        }
        if (chances==6){pontuacao=10;}
        else if (chances==5){pontuacao=8;}
        else if (chances==4){pontuacao=6;}
        else if (chances==3){pontuacao=4;}
        else if (chances==2){pontuacao=2;}
        else if (chances==1){pontuacao=1;}
    }
    return 0; // Ou seja, perdeu.
}

void mostrarResultado(int resultado) {
    limpar_input();
    if (resultado == 0) {
        printf("\nVoce perdeu maninho, mas não deixe de tentar. \nA palavra era: %s", palavra);
		boneco_perdeu();
    } 
    else {
        printf("\nParabéns meu brother, você acertou \nEsta é a palavra: %s ", palavra);
		boneco_ganhou();
        salvarRanking();
		
    }
}

void ranking_menu(){
    FILE *arq;
    ranking_pos *ranking = NULL, *a = NULL; 
    int i=0;

    //declarando a variavel para struct
    ranking_pos add;

    limpar_tela();
    //abrindo o arquivo
    arq = fopen("ranking.bat", "r+b");

    //verifica se o arquivo foi criado
    if(!arq){
        printf("Impossivel criar o arquivo\n");
    }

    fseek(arq,0,SEEK_END);
    qtd_struct_arq = ftell(arq)/sizeof(ranking_pos);

    //Alocando dinamicamente o arquivo no ponteiro
    ranking = (ranking_pos *)malloc(ftell(arq));
    a = (ranking_pos *)malloc(ftell(arq)); 

    fseek(arq,0,SEEK_SET);
    rewind(arq);
    printf("\t\tRanking\n");
    for(contRanking = 0; contRanking < qtd_struct_arq; contRanking++){
        //for(i=0;i<qtd_struct_arq;i++){
            fread(ranking+contRanking,sizeof(ranking_pos),1,arq);
            printf("============================================\n");
            printf("%s", ranking[contRanking].nome);
            printf(":%d\n", ranking[contRanking].pontos);
            printf("============================================\n\n");
        //} 
    }   

    fclose(arq);
}

void salvarRanking(){
    FILE *arq;
    ranking_pos *ranking = NULL, *a = NULL;
    int i = 0;
    int auxi = 0;
    int auxP = 0;
    char auxN[10+1];
    int qtd_registros = 0;

    //abrindo arquivo
    arq = fopen("ranking.bat", "r+b");

    if(!arq){
        printf("Impossivel criar o arquivo\n");
    }

    fseek(arq, 0, SEEK_END);

    qtd_struct_arq = ftell(arq)/sizeof(ranking_pos);

    ranking = (ranking_pos *)malloc(sizeof(ranking_pos)*(qtd_struct_arq+2));

    a = (ranking_pos *)malloc(ftell(arq));
    rewind(arq);

    for(contRanking = 0; contRanking < qtd_struct_arq; contRanking++){
        fread(ranking+contRanking, sizeof(ranking_pos), 1, arq);
        strcpy(a[contRanking].nome, ranking[contRanking].nome);
        a[contRanking].pontos = ranking[contRanking].pontos;
    } 

    for(contRanking = 0; contRanking < qtd_struct_arq; contRanking++){

        strcpy(ranking[contRanking].nome, a[contRanking].nome);
        ranking[contRanking].pontos = a[contRanking].pontos;
    }

    fclose(arq);


    //Abre um arquivo binario para escrever1
    arq = fopen("ranking.bat", "w+b");

    if(!arq){
        printf("Impossivel criar o arquivo\n");
    }

    fseek(arq, 0, SEEK_SET);
    ranking = (ranking_pos *)realloc(ranking, sizeof(ranking_pos)*(qtd_struct_arq+1));
   
        fflush(stdin);
        strcpy(ranking[qtd_struct_arq].nome, jogador);
        ranking[qtd_struct_arq].pontos = pontuacao;
        fwrite(ranking,sizeof(ranking_pos)*(qtd_struct_arq+1), 1, arq);
    

   
    fclose(arq);

    free(a);
    free(ranking);
}



