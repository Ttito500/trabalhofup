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
    int index = 0; // index do vetor carros
    if (selecao == 1) {
        addcarro(&definir, carros, index);
        index++;
    } else if (selecao == 2) {
        reservar(&definir, carros, index);
        index++;
    } else if (selecao == 3) {
        vagas(&definir);
    } else if (selecao == 4) {
       // preco();
    } else {
        printf("Digite um número válido.\n");
        menu(&definir, carros);
    }

}

void addcarro(estacionamento **definir, carro *carros, int index){
    printf("qual o tipo do carro?");
    scanf(" %c", &carros->tipo);

    carros[index].hora_entrada = tempo();

    printf("digite a placa do carro");
    scanf(" %[^\n]", carros[index].placa);

    if (carros[index].tipo == 'p')
    {
        (*definir)->vagasp -= 1;
    }
    if (carros[index].tipo == 'm')
    {
        (*definir)->vagasm -= 1;
    }
    if (carros[index].tipo == 'g')
    {
        (*definir)->vagasg -= 1;
    }
    menu(*definir, carros);
}

void reservar(estacionamento **definir, carro *carros, int index){
    printf("qual o tipo do carro?");
    scanf(" %c", &carros[index].tipo);

    printf("digite a placa do carro");
    scanf(" %[^\n]", carros[index].placa);

    int h, m; //horas e minutos para calcular no formato minutos
    printf("digite as horas ex: 23:59");
    scanf("%d:%d", &h, &m);

    carros->hora_entrada = h * 60 + m;

    if (carros[index].tipo == 'p')
    {
        (*definir)->vagasp -= 1;
    }
    if (carros[index].tipo == 'm')
    {
        (*definir)->vagasm -= 1;
    }
    if (carros[index].tipo == 'g')
    {
        (*definir)->vagasg -= 1;
    }
    menu(*definir, carros);
}

void vagas(estacionamento **definir){ //mostra as vagas que restam
    printf("vagas p:%d\n vagas m:%d\n vagas g:%d", (*definir)->vagasp, (*definir)->vagasm, (*definir)->vagasg);
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