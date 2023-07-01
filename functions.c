#include "def.h"

void es(estacionamento *definir){
    printf("escreva o preco/h dos tipos p m e g respectivamente:");
    scanf("%f %f %f", &(*definir).pp, &(*definir).pm, &(*definir).pg);
    printf("escreva o numero de vagas dos tipos p m e g respectivamente:");
    scanf("%d %d %d", &(*definir).vagasp, &(*definir).vagasm, &(*definir).vagasg);
}

void menu(){
    printf(" 1-adicionar carro \n 2-reservar vaga \n 3-ver vagas disponiveis \n 4-calcular preco\n");
    int selecao; // int para scanear oq o usuario quer fazer
    scanf("%d", &selecao);
    switch (selecao)
    {
    case 1:
        addcarro();
        break;
    case 2:
        //reservar();
        break;
    case 3:
        //vagas();
        break;
    case 4:
        //preco();
        break;
    default:
        printf("digite um numero valido\n");
        menu();
        break;
    }
}

void addcarro(){
    printf("qual o tipo do carro?");
    //char tipo;
   //scanf("%c", &)
}