<<<<<<< HEAD
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

void menu();

void addcarro();
=======
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
>>>>>>> 714fe53aaca705c9386767c24a3b143fbd10e22a
