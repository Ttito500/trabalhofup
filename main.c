#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main()
{
    estacionamento definir; // struct do estacionamento
    es(&definir); // função para definir o estacionamento

    int n = definir.vagasp + definir.vagasm + definir.vagasg;
    carro *carros = (carro*)malloc(n*sizeof(carro)); //alocação dinamica do vetor dos carros

    menu(&definir, carros);

    return 0;
}