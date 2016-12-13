#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer(char *buf, int tamanho);
void so_palavra(char *str);
int ehLetra(char c);
char maiuscula(char c);
void start(void);
int jogo(void);
void mostrarResultado(int resultado);
void ranking_menu();
void salvarRanking();
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")
