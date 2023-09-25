#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_SEATS 10

void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void ler_texto(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

int main()
{

    // Quadro de boas vindas feita de uma estrutura para (for)

    char board[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 4)
            {
                printf("==============");
            }
            else if (j == 0 || j == 4)
            {
                printf("+   ");
            }
            else if (i == 2 && j == 2)
            {
                printf("Welcome to Voe Facil  ");
            }
            else
            {
                printf("                      ");
            }
        }
        printf("\n");
    }

    // Local inicial, destino e data

    char inicio[50], destino[50];
    int data, voo, N, soma, i, choice;
    char resp, conf, conf2;
    int seats [MAX_SEATS];
    

    printf("\n");

    printf("Escreva o local de partida: \n");
    ler_texto(inicio, 50);

    printf("\n");

    printf("Escreva o local de destino: \n");
    ler_texto(inicio, 50);

    printf("\n");

    // Empresas aéreas usado a estrurtura de estrutura repita até (do while) :

    do
    {
        printf("Escreva a data de partida: \n");
        scanf("%d", &data);

        if (data == 14102023)
        {

            printf("\n");

            printf("Voos encontrados: \n");

            sleep(1.8);

            printf("\n(1) LATAM:\n");
            printf("ida: sab. 14 oct. 2023 // volta: qua. 20 oct. 2023\n");
            printf("R$ 354,50");

            sleep(1.8);

            printf("\n");

            printf("\n(2) GOL:\n");
            printf("ida: sab. 14 oct. 2023 // volta: seg. 16 oct. 2023\n");
            printf("R$ 256,70");

            sleep(1.8);

            printf("\n");

            printf("\n(3) Azul:\n");
            printf("ida: sab. 14 oct. 2023 // volta: sex. 27 oct. 2023\n");
            printf("R$ 553,35");

            sleep(1.8);

            printf("\n");

            printf("\n(4) WEBJET:\n");
            printf("ida: sab. 14 oct. 2023 // volta: dom. 22 oct. 2023\n");
            printf("R$ 152,99");

            sleep(1.8);

            printf("\n");

            printf("\n(5) TRANSBRASIL:\n");
            printf("ida: sab. 14 oct. 2023 // volta: sab. 30 oct. 2023\n");
            printf("R$ 184,00");

            printf("\n");

            break;
        }

        else
        {
            printf("Nenhum Voo encontrado!\n");
            printf("Deseja saber outra data? (s/n) \n");
            limpar_entrada();
            scanf("%c", &resp);
        }

    } while (resp == 's');

    // Escolher voo

    printf("\n");

    printf("Escolha um voo: ");
    scanf("%d", &voo);

    sleep(1.8);

    if (voo == 1)
    {
        printf("LATAM (SLZ-SP)");
    }
    else if (voo == 2)
    {
        printf("GOL (SLZ-SP)");
    }
    else if (voo == 3)
    {
        printf("AZUL (SLZ-SP)");
    }
    else if (voo == 4)
    {
        printf("WEBJET (SLZ-SP)");
    }
    else if (voo == 5)
    {
        printf("TRANSBRASIL (SLZ-SP)");
    }

    printf("\n");

    sleep(1.8);

    printf("Gostaria de confirmar? (s/n) \n");
    limpar_entrada();
    scanf("%c", &conf);

    printf("\n");

    // Emição de passagens aereas

    printf("Quantas passagens voce vai emitir? ");
    scanf("%d", &N);

    printf("\n");

    char vet[N][50];
    soma = 152;

    for (int i = 0; i < N; i++)
    {
        printf("Digite somente o primeiro nome: ");
        scanf("%s", vet[i]);
        soma = soma * 2;
    }

    printf("\nNOMES CADASTRADOS:\n");

    sleep(1.8);

    for (int i = 0; i < N; i++)
    {
        printf("%s\n", vet[i]);
        printf("Passagem + taxas (SLZ-SP) R$: %d\n", soma);

        printf("\n");
    }
    
    printf("Escolha seu assento:\n");

    sleep(1.8);

    printf("\n");

    // Inicializa todos os assentos como disponíveis (0)

    for (i = 0; i < MAX_SEATS; i++)
    {
        seats[i] = 0;
    }

    // Loop para escolher assentos

    while (1)
    {
        printf("Escolha um assento (1-%d) ou 0 para sair: ", MAX_SEATS);
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice < 1 || choice > MAX_SEATS)
        {
            printf("Escolha inválida. Por favor, tente novamente.\n");
        }
        else
        {
            choice--; // Converte a escolha do usuário para índice baseado em 0

            if (seats[choice] == 0)
            {
                seats[choice] = 1; // Marca o assento como escolhido (1)
                printf("Assento %d escolhido.\n", choice + 1);
            }
            else
            {
                printf("Assento %d ja escolhido. Por favor, escolha outro.\n", choice + 1);
            }
        }
    }

    // Exibe os assentos escolhidos
    printf("Assentos escolhidos: \n");
    for (i = 0; i < MAX_SEATS; i++) {

        if (seats[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }

    printf("\n");

    printf("Aperte (c) para confirmar:\n");
    limpar_entrada();
    scanf("%c", &conf2);

    if (conf2 == 'c')
    {        
        printf("Confirmado!\n");
    }

    //Este código cria um array de inteiros chamados "assentos" para armazenar o estado de cada assento (0 para disponível e 1 para escolhido). 
    // O loop principal solicita ao usuário que escolha um assento quando o usuário digita 0, o loop termina e o programa exibe os assentos escolhidos.

    printf("\n");

    sleep(1.8);

    // Resumo da compra

    printf("Resumo da compra:\n");

    printf("\n");

    sleep(1.8);

    for (int i = 0; i < N; i++)
    {
        printf("Nome do passageiro(a): %s\n", vet[i]);
        printf("Valor da passagem R$: %d\n", soma);
        printf("Local de Destino: Sao Paulo\n");
        
        printf("\n");
    }
    
    printf("\nOBRIGADO PELA ESCOLHA DA VOE FACIL!\n");

    return 0;
}