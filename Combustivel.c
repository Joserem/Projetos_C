// Calculo de Combustível

#include <stdio.h>
#include <stdlib.h>

int Calculo(float vGas, float vEta)
{
    
        if ((vGas * 0.70) < vEta)
        {

            return 0;
        }   
        else if ((vGas * 0.70) > vEta)
        {

            return 1;
        }
        else
        {

            return 2;
        }

}

int main()
{

    float precoGasolina, precoEtanol;
    int resultado = Calculo(precoGasolina, precoEtanol);

    printf("###### GasoCar ###### \n");

    printf("\n");

    printf("Digite o preco da gasolina: \n");
    scanf("%f", &precoGasolina);

    printf("Digite o preco do Etanol: \n");
    scanf("%f", &precoEtanol);

    if (resultado == 0)
    {
        printf("Compensa abastecer com Gasolina! \n");
    }
    else if (resultado == 1)
    {
        printf("Compensa abastecer com Etanol! \n");
    }
    else
    {
        printf("Os preços sao equivalentes, abastecer com qualquer um! \n");
    }

    return 0;
}

