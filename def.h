typedef struct
{
    char placa[11];
    char tipo; //tipos do carro pequeno(p), medio(m), grande(g)
    int hora_entrada;
    int hora_saida;
}carro;

typedef struct
{
    float pp, pm, pg;  //preço da hora dos tipos a b e c
    int vagasp, vagasm, vagasg;  //numero de vagas de cada tipo
}estacionamento;

void es(estacionamento *definir);  //guarda as informaçôes sobre o estacionamento

void menu(estacionamento *definir, carro *carros); // menu

void addcarro(estacionamento **definir, carro *carros); // adciona um carro ao array dos carros usando  time.h para hora de entrada

void reservar(estacionamento **definir, carro *carros); // reserva uma vaga tendo que receber a hora de entrada

void vagas(estacionamento **definir, carro *carros); // lê o numero restante de vagas de cada tipo

void preco(estacionamento **definir, carro *carros); // checkout, procurando no array pela placa

int tempo(); // devolve o tempo atual em minutos, usada para os calculos