#include <stdio.h>
#include "functions.c"

int main()
{
    estacionamento definir; // struct do estacionamento
    es(&definir); // função para definir o estacionamento
    //printf("%d %d %d", definir.vagasp, definir.vagasm, definir.vagasg);
    menu();
    return 0;
}
