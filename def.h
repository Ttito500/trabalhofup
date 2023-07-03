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

void es(estacionamento *definir);

void menu(estacionamento *definir, carro *carros);

void addcarro(estacionamento **definir, carro *carros, int *index);

void reservar(estacionamento **definir, carro *carros, int *index);

void vagas(estacionamento **definir, carro *carros);

void preco(estacionamento **definir, carro *carros, int *index);

int tempo();