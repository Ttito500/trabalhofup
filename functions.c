#include <time.h>
#include "def.h"
#include <string.h>

void es(estacionamento *definir){
    float pp, pm, pg;
    printf("escreva o preco/h dos tipos p m e g respectivamente: \n");
    scanf("%f %f %f", &pp, &pm, &pg); //scaneando o preço de cada tipo
   
    definir->pp = pp / 60;//transformando preco/h em preço/min
    definir->pm = pm / 60;
    definir->pg = pg / 60;

    printf("escreva o numero de vagas dos tipos p m e g respectivamente: \n");
    scanf("%d %d %d", &definir->vagasp, &definir->vagasm, &definir->vagasg); // numero de vagas de cada tipo
}

void menu(estacionamento *definir, carro *carros){
    printf("|||%d %d %d|||\n", definir->vagasp, definir->vagasm, definir->vagasg); // isso ta aqui so pra testa

    printf(" 1-adicionar carro \n 2-reservar vaga \n 3-ver vagas disponiveis \n 4-calcular preco\n");
    int selecao; // int para scanear oq o usuario quer fazer
    scanf("%d", &selecao);
    int index = 0; // index do vetor carros
    if (selecao == 1) {                     //inputs do usuario
        addcarro(&definir, carros, &index); //chamada da função de acordo com o input
    } else if (selecao == 2) {
        reservar(&definir, carros, &index);
    } else if (selecao == 3) {
        vagas(&definir, carros);
    } else if (selecao == 4) {
       preco(&definir, carros, &index);
    } else {
        printf("Digite um numero valido.\n");
        menu(&definir, carros);
    }

}

void addcarro(estacionamento **definir, carro *carros, int *index){
    printf("qual o tipo do carro? \n");
    scanf(" %c", &carros[*index].tipo);

    carros[*index].hora_entrada = tempo();

    printf("digite a placa do carro \n");
    scanf(" %[^\n]", carros[*index].placa);

    if (carros[*index].tipo == 'p')
    {
        (*definir)->vagasp -= 1;
    }
    if (carros[*index].tipo == 'm')
    {
        (*definir)->vagasm -= 1;
    }
    if (carros[*index].tipo == 'g')
    {
        (*definir)->vagasg -= 1;
    }
    *index++;
    menu(*definir, carros);
    
}

void reservar(estacionamento **definir, carro *carros, int *index){
    printf("qual o tipo do carro? \n");
    scanf(" %c", &carros[*index].tipo);

    printf("digite a placa do carro \n");
    scanf(" %[^\n]", carros[*index].placa);

    int h, m; //horas e minutos para calcular no formato minutos
    printf("digite as horas ex: 23:59 \n");
    scanf("%d:%d", &h, &m);

    carros[*index].hora_entrada = h * 60 + m;

    if (carros[*index].tipo == 'p')
    {
        (*definir)->vagasp -= 1;
    }
    if (carros[*index].tipo == 'm')
    {
        (*definir)->vagasm -= 1;
    }
    if (carros[*index].tipo == 'g')
    {
        (*definir)->vagasg -= 1;
    }
    *index++;
    menu(*definir, carros);
}

void vagas(estacionamento **definir, carro *carros){ //mostra as vagas que restam
    printf("vagas p:%d vagas m:%d vagas g:%d \n", (*definir)->vagasp, (*definir)->vagasm, (*definir)->vagasg);
    menu(*definir, carros);
}

void preco(estacionamento **definir, carro *carros, int *index){
    char placa[11];
    printf("qual a placa? \n");
    scanf(" %[^\n]", placa);
    float preco = 0;
    int numv = (*definir)->vagasp + (*definir)->vagasm + (*definir)->vagasg;
    for(int i = 0; i < numv; i++){
        if(strcmp(placa, carros[i].placa) == 0){
            *index++;
            if (carros[i].tipo == 'p')
            {
                preco = (*definir)->pp * (tempo() - carros[i].hora_entrada);
                (*definir)->vagasp += 1;
            }else if (carros[i].tipo == 'm')
            {
                preco = (*definir)->pm * (tempo() - carros[i].hora_entrada);
                (*definir)->vagasm += 1;
            }else if (carros[i].tipo == 'g')
            {
                preco = (*definir)->pg * (tempo() - carros[i].hora_entrada);
                (*definir)->vagasg += 1;
            }
            printf("%.2f\n", preco);
            break;
        }
    }
    printf("nao encontrado");
    menu(*definir, carros);
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