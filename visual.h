#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {JOGAR=1,CREDITOS=2,RANKING=3,SAIR=4} ENUM_OPC;

void boneco_perdeu();
void boneco_ganhou();
void creditos();
void boneco_chance(int chances);
void mostrar_menu();
ENUM_OPC menu(int continuar);