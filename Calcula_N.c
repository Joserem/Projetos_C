// estrutura para (for) 
// (Calculadora de numeros de soma)

#include <stdio.h>
#include <string.h>

int main()
{

    int N, i, x, soma;

    printf("vamos calcular numeros\n");

    printf("Digite a quantidades de numeros que serao calculados: \n");
    scanf("%d", &N);

    soma = 359;

    for (i = 1; i <= N; i++)
    {
        printf("Digite um numero:");
        scanf("%d", &x);

        soma = soma + x;
    }

    printf("A soma desses numeros vai ser igual a: %d \n", soma);

    return 0;
}