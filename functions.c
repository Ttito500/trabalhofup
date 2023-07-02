#include <time.h>
#include "def.h"

void es(estacionamento *definir){
    printf("escreva o preco/h dos tipos p m e g respectivamente:");
    scanf("%f %f %f", &definir->pp, &definir->pm, &definir->pg); //scaneando o preço de cada tipo
    printf("escreva o numero de vagas dos tipos p m e g respectivamente:");
    scanf("%d %d %d", &definir->vagasp, &definir->vagasm, &definir->vagasg); // numero de vagas de cada tipo
}

void menu(estacionamento *definir, carro *carros){
    printf(" 1-adicionar carro \n 2-reservar vaga \n 3-ver vagas disponiveis \n 4-calcular preco\n");
    int selecao; // int para scanear oq o usuario quer fazer
    scanf("%d", &selecao);
    switch (selecao)
    {
    case 1:
        addcarro(&definir, carros);
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
        menu(&definir, carros);
        break;
    }
}

void addcarro(estacionamento **definir, carro *carros){
    printf("qual o tipo do carro?");
    scanf(" %c", &carros->tipo);
    carros->hora_entrada = tempo();

    if (carros->tipo == 'p')
    {
        (*definir)->vagasp -= 1;
    }
    if (carros->tipo == 'm')
    {
        (*definir)->vagasm -= 1;
    }
    if (carros->tipo == 'g')
    {
        (*definir)->vagasg -= 1;
    }
}

int tempo() {  //retornar o tempo em minutos para ser mais facil de calcular
    // Obter o tempo atual
   time_t tempoAtual = time(NULL);

    // Converter o tempo para uma estrutura de tempo local
    struct tm *infoTempo = localtime(&tempoAtual);

    // Extrair a hora e os minutos da estrutura de tempo
    int hora = infoTempo->tm_hour;
    int minutos = infoTempo->tm_min;

    // Calcular a quantidade de minutos passados desde a meia-noite
    int minutosPassados = hora * 60 + minutos;

    return minutosPassados;
}