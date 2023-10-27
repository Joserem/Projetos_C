// Bibliotecas incluidas

#include <stdio.h>
#include <string.h>


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

    // Quadro de boas vindas

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
                printf("============");
            }
            else if (j == 0 || j == 4)
            {
                printf("+   ");
            }
            else if (i == 2 && j == 2)
            {
                printf("    FinatI        ");
            }
            else
            {
                printf("                  ");
            }
        }
        printf("\n");
    }

    char usuario[50];
    int senha;
    char novamente;
    int opcao, i = 0;
    float saldo;
    float valor;
    int sair;

    // Definindo uma estrutura chamada "DESPESA" para o registro  despesas.

    typedef struct
    {
        char categoria[50];
        float valor;
        char data[10];
    } Despesa;

    Despesa despesa[25]; // adicionar um vetor 

    // Login de Usuarío

    do
    {

        printf("Digite seu usuario: \n");
        scanf("%s", usuario);
        printf("\n");

        printf("Digite sua senha: \n");
        scanf("%d", &senha);
        printf("\n");

        printf("Adicione seu saldo: R$:");
        scanf("%f", &saldo);
        printf("\n");

        if ((strcmp(usuario, "joderem") == 0) && (senha == 12345))
        {
            printf("Bem-vindo de volta, %s!  \n", usuario);
            break;
        }
        else
        {
            printf("Usuario ou senha incorretos! \n");
            printf("Digite (s) para colocar o usuario e senha novamente!\n");
            limpar_entrada();
            scanf(" %c", &novamente);
        }

    } while (novamente == 's');

    sleep(2);

    system("cls"); // Limpar Tela (system("clear") caso nao funcionar

    printf("\n");

    printf("============= Gerenciamento Financeito T.I =============\n");

    do
    {

        sleep(2);

        // Exibe o saldo atual

        printf("Seu saldo atual: R$: %.2f\n", saldo);

        printf("\n");

        printf("1 - Registrar Despesas\n");
        printf("2 - Consultar transacoes\n");
        printf("3 - Relatorio de Gastos\n");
        printf("4 - Estatistica das suas financas\n");
        printf("5 - Sair");

        printf("\n");

        printf("Escolha uma opcao:\n");
        limpar_entrada();
        scanf(" %d", &opcao);

        sleep(2);

        system("cls");

        // Usando uma estrutura de controle que permite executar diferentes blocos do código (switch).

        switch (opcao)
        {

        // Registrar despesas
        case 1:
        {
            printf("Categoria: ");
            scanf("%s", despesa[i].categoria);
            printf("Valor: ");
            scanf("%f", &despesa[i].valor);
            printf("Data (dd/mm/aaaa): ");
            scanf("%s", despesa[i].data);
            saldo -= despesa[i].valor; 
            i++;
            break;
        }

        // Consultar transação
        case 2:

            sleep(2);

            for (int j = 0; j < i; j++)
            {

                printf("Descricao: %s, Valor: %.2f, Data: %s\n", despesa[j].categoria, despesa[j].valor, despesa[j].data);
                printf("----------------------------------------------------------------\n");
            }

            break;

        // Relatorio de Gastos
        case 3:

        {
            // Criando um array para armazenar as categorias únicas e seus totais

            char categorias[25][50];
            float total[25] = {0};
            int num_categorias = 0;

            // Percorra todas as despesas

            for (int j = 0; j < i; j++)
            {
                // Verificar se a categoria da despesa atual já está no array de categorias

                int k;
                for (k = 0; k < num_categorias; k++)
                {
                    if (strcmp(despesa[j].categoria, categorias[k]) == 0)
                    {
                        // Se a categoria já estiver no array, vai adicionar o valor da despesa ao total dessa categoria

                        total[k] += despesa[j].valor;
                        break;
                    }
                }

                // Se a categoria não estiver no array, vai adicionar e atualize o total

                if (k == num_categorias)
                {
                    strcpy(categorias[num_categorias], despesa[j].categoria);
                    total[num_categorias] = despesa[j].valor;
                    num_categorias++;
                }
            }

            // Exibir o relatório de gastos por categoria

            printf("Relatorio de Gastos por Categoria:\n");
            printf("\n");

            for (int j = 0; j < num_categorias; j++)
            {
                printf("Categoria: %s, Total gasto: %.2f\n", categorias[j], total[j]);
                printf("----------------------------------------------------------------\n");
            }

            break;
        }

        // Estastisticas da Finanças 
        case 4:
        {
            float total_despesas = 0;
            int total_transacoes = 0;

            // Calcular o total de despesas e o número total de transações
            for (int j = 0; j < i; j++)
            {
                total_despesas += despesa[j].valor;
                total_transacoes++;
            }

            // Calcular a média de despesas por mês e a média de transações por mês
            float media_despesas = total_despesas / 12;
            float media_transacoes = (float)total_transacoes / 12;

            // Exibindo as estatísticas financeiras
            printf("Media de despesas por mes R$: %.2f\n", media_despesas);
            printf("----------------------------------------------------------------\n");
            printf("Media de transacoes por mes: %.2f\n", media_transacoes);

            break;
        }

        // Sair do aplicativo
        case 5:

            do
            {
                printf("Aperte 0 para confirmar:\n");
                scanf("%d", &sair);

                if (sair == 0)
                {
                    printf("Saindo....\n");
                }

            } while (sair != 0);

            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
