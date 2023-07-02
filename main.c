//<<<<<<< HEAD
#include <stdio.h>
#include "functions.c"

int main()
{
    estacionamento definir; // struct do estacionamento
    es(&definir); // função para definir o estacionamento
    //printf("%d %d %d", definir.vagasp, definir.vagasm, definir.vagasg);
    menu();
    return 0;
}
=======
#include <stdio.h>
#include "def.h"
#include "functions.c"

int main()
{
    printf("%f", areaq(10, 11));
    return 0;
}
//>>>>>>> 714fe53aaca705c9386767c24a3b143fbd10e22a
