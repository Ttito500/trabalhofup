#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main()
{
    estacionamento definir; // struct do estacionamento
    es(&definir); // função para definir o estacionamento

    int n = definir.vagasp + definir.vagasm + definir.vagasg;
    carro *carros = (int*)malloc(n*sizeof(int)); //alocação dinamica do vetor dos carros

    menu(&definir, carros);

    printf("%d", definir.vagasm);
    return 0;
}
