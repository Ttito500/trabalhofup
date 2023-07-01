typedef struct
{
    char tipo; //tipos do carro pequeno(p), medio(m), grande(g)
    int hora_entrada;
    int hora_saida;
}carro;

typedef struct
{
    int pp, pm, pg;  //preço da hora dos tipos a b e c
    int vagasp, vagasm, vagasg;  //numero de vagas de cada tipo
}estacionamento;

void addcarro();