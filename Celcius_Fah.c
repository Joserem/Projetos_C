// estrutura repita até em C 
// (transformar Celsius para Fahrenheit)

#include <stdio.h>
#include <string.h>

void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{

    double C, F;
    char resp;

    printf("Vamos ver a temperatura de Celsius para Fahrenheit!\n");

    do
    {

        printf("Digite a temperatura em Celsius: ");
        scanf("%lf", &C);

        F = 9.0 * C / 5.0 + 32.0;

        printf("Equivalente a Fahrenheit: %.1lf\n ", F);
        printf("Deseja saber novamente a temperatura? (s/n) ");
        limpar_entrada();
        scanf("%c", &resp);

    

    } while (resp == 's');

    return 0;
}