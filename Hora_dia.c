// ESTRUTURA CONDICIONAL 
// (Hora do dia)

#include <stdio.h>
#include <string.h>

int main() {

    int hora;
    printf("Digite uma hora do dia: ") ;
    scanf("%d", &hora);

    if (hora < 12 ) {

        printf("Bom dia");

    }
    else if (hora <= 18) {

        printf("Boa tarde");

    }
    else {
        printf("Boa noite");
    }


    return 0;
}