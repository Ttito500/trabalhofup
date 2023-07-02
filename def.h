typedef struct
{
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

void addcarro(estacionamento **definir, carro *carros);

int tempo();