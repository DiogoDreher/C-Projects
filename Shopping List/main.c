#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
#define PRODUTO "ficheiroProduto.xpto"

struct defProduto
{        //Informações do produto
    char nome[100];
    int quantidade;
    float preco;
};

int main()
{        //Exibe mensagem de boas vindas e chama função opção

    printf("Seja bem vindo(a) a vossa lista de compras!\n\n");
    system("pause");
    system("cls");

    //Chama a função "opção" e a executa
    opcao();
}

void opcao()
{       //Cria ficheiro caso o mesmo não exista e executa operador switch usando o valor recebido da função menu

    //Ciclo para criar ficheiro caso o mesmo não exista
    FILE *fProduto;
    fProduto = fopen(PRODUTO, "rb+"); //Tenta abrir ficheiro
    if (fProduto == NULL) {   //Acontece quando o ficheiro nao existe
        fProduto = fopen(PRODUTO, "wb");   //Criar o ficheiro
        fclose(fProduto);
    } fclose(fProduto);

    switch (menu())
    {
    case 1:

        inserir();
        break;

    case 2:

        listar();
        break;

    case 3:

        limpar();
        break;

    case 4:

        system("cls");
        break;
        return 0;
    }
}

void inserir()
{       //Função para inserir produtos e armazena-los no ficheiro

    //Cria um produto genérico P que possui a estrutura de defProduto (nome, quantidade e preço)
    struct defProduto P;

    //Variável inteira "submenu" para ser utilizada no operador switch
    int submenu = 0;
    char nomeProduto[50];


    do {

        system("cls");

        //Abre o ficheiro
        FILE *fProduto;
        fProduto = fopen(PRODUTO, "rb+");


        //Leitura dos produtos

        //Limpa o buffer de leitura de strings para que nao ocorra erro na leitura de uma string com espaço
        setbuf(stdin, NULL);

        printf("\nProduto: ");

        //[^\n] é utilizado para que a leitura só pare ao encontrar um comando para nova linha
        scanf("%[^\n]s", nomeProduto);

        //Verifica se o produto já existe na lista
        fseek(fProduto, 0, SEEK_SET);
         do {
            if (!feof(fProduto)) {
                fread(&P, 1, sizeof(struct defProduto), fProduto);

                if(strcasecmp(P.nome, nomeProduto) == 0) {
                    system("cls");
                    printf("\n\nO produto %s ja existe na lista.\n\n", nomeProduto);
                    system("pause");
                    system("cls");
                    opcao();
                    return 0;
                }
            }
        } while (!feof(fProduto));
        strcpy(P.nome, nomeProduto);

        printf("\nQuantidade: ");
        scanf("%d", &P.quantidade);
        printf("\nPreco unitario: ");
        scanf("%f", &P.preco);

        //Leitura feita

        //Coloco o apontador no inicio do ficheiro (posição 0) e guardo os dados lidos em P
        fseek(fProduto, 0, SEEK_END);
        fwrite(&P, 1, sizeof(struct defProduto), fProduto);
        fclose(fProduto);


        system("cls");



        printf("Produto adicionado com sucesso! \n\n\nO que deseja fazer?\n\n1- Adicionar novo produto.\n2- Retornar ao menu principal.\n3- Fechar programa.\n\n");
        scanf("%d", &submenu);

        //Verifica se o valor introduzido se compreende entre o menor e o maior valor apresentado no menu
        while (submenu < 1 || submenu > 3) {
            system("cls");
            printf("Opcao invalida, tente novamente!\n\n1- Adicionar novo produto.\n2- Retornar ao menu principal.\n3- Fechar programa.\n\n ");
            scanf("%d", &submenu);
        }

        switch(submenu)
        {

        case 2:

            system("cls");
            opcao();

        case 3:

            return 0;

        }

    } while(submenu == 1);


}

void listar()
{       //Lista os produtos dentro do ficheiro e faz print da lista com o total

    //Abre o ficheiro
    FILE *fProduto;
    fProduto = fopen(PRODUTO, "rb+");

    struct defProduto P;

    //Variável para armazenar o valor total da compra
    float total = 0;
    int submenu = 0;

    system("cls");

    //Verifica se o ficheiro está vazio

    fseek(fProduto, 0, SEEK_END);
    int size = ftell(fProduto);

    fseek(fProduto, 0, SEEK_SET);

    //Se o ficheiro não está vazio então executa a impressão da lista para cada posição até que se encontre o final do ficheiro
    if (size != 0){

        printf("\t\tLista de Compras\n");
        printf("\nProduto\t\t\t| Quantidade\t| Preco\n");
        do {
            fread(&P, 1, sizeof(struct defProduto), fProduto);

            if(!feof(fProduto)) {
                printf("\n%-20.20s\t| %d\t\t| %.2f", P.nome, P.quantidade, P.preco);
                total = total + ((float)P.preco * P.quantidade);
            }

        } while (!feof(fProduto));
        printf("\n\nO valor total da compra sera %.2f.\n\n", total);

        fclose(fProduto);

        printf("\n\nO que deseja fazer?\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n");
        scanf("%d", &submenu);

        //Verifica se o valor introduzido se compreende entre o menor e o maior valor apresentado no menu
        while (submenu < 1 || submenu > 2) {
            system("cls");
            printf("Opcao invalida, tente novamente!\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n ");
            scanf("%d", &submenu);
        }

        switch(submenu)
        {
        case 1:

            system("cls");
            opcao();

        case 2:

            return 0;

        }


    //Ocorre caso o ficheiro esteja vazio
    } else {
        system("cls");
        printf("Nao ha items na vossa lista!\n\n");
        fclose(fProduto);

        printf("\n\nO que deseja fazer?\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n");
        scanf("%d", &submenu);

        //Verifica se o valor introduzido se compreende entre o menor e o maior valor apresentado no menu
        while (submenu < 1 || submenu > 2) {
            system("cls");
            printf("Opcao invalida, tente novamente!\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n ");
            scanf("%d", &submenu);
        }

        switch(submenu)
        {
        case 1:

            system("cls");
            opcao();

        case 2:

            return 0;
        }
    }
}

void limpar()
{       //Limpa o ficheiro para reiniciar a lista do zero

    int submenu = 0;

    //Abre o ficheiro
    FILE *fProduto;

    //Apaga tudo que há dentro do ficheiro
    fProduto = fopen(PRODUTO, "w");
    system("cls");
    printf("Vossa lista foi apagada com sucesso!\n\n");
    fclose(fProduto);

    printf("\n\nO que deseja fazer?\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n");
    scanf("%d", &submenu);

    //Verifica se o valor introduzido se compreende entre o menor e o maior valor apresentado no menu
    while (submenu < 1 || submenu > 2) {
        system("cls");
        printf("Opcao invalida, tente novamente!\n\n1- Retornar ao menu principal.\n2- Fechar programa.\n\n ");
        scanf("%d", &submenu);
    }

    switch(submenu)
    {
    case 1:

        system("cls");
        opcao();

    case 2:

        return 0;

    }
}

void menu()
{       //Apresenta o menu ao utilizador, lê o valor da resposta e faz uma verificação simples

    //Variável para armazenar o valor correspondente à opção escolhida
    int escolha = 0;

    printf("O que deseja fazer?\n\n1 - Adicionar produtos a lista.\n2 - Consultar lista.\n3 - Apagar lista.\n4 - Fechar programa.\n\n");
    scanf("%d", &escolha);

    //Verifica se o valor introduzido se compreende entre o menor e o maior valor apresentado no menu
    while (escolha < 1 || escolha > 4) {
        system("cls");
        printf("Opcao invalida, tente novamente!\n\n1 - Adicionar itens a lista.\n2 - Consultar lista.\n3 - Apagar lista.\n4 - Fechar programa.\n\n ");
        scanf("%d", &escolha);
    }

    //Retorna para a função "opção" o conteúdo da variável escolha
    return escolha;
}






