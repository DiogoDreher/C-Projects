#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define NULL 0
#define JOGADOR "jogador.xpto"

static char nome[50];
int tema;

struct defJogador
{
	char nome[50];
	int certo, errado, total, tema;
};

int main(void)
{
    char *locale;
    locale = setlocale(LC_ALL, "");

	definirJogador();

	return 0;
}


//Escolha de tema e realização do Quiz

void escolherTema()
{
	int opcao;

	printf("\t*==========================================================================================================*\n");
	printf("\t|              Escolha a o tema que queres fazer quiz.                                                     |\n");
	printf("\t|  1: Anime: Tudo sobre o mundo dos animes.                                                                |\n");
	printf("\t|  2: Tema 2: Outro tema                                                                                   |\n");
	printf("\t|  3: Tema 3:                                                                                              |\n");
	printf("\t|  4: Fechar programa.                                                                                     |\n");
	printf("\t*==========================================================================================================*\n\n");
	scanf("%d", &opcao);
	system("cls");

	switch (opcao) {

	case 1:
	    tema = opcao;
		animeQuiz();
		break;

	case 2:
        tema = opcao;
        outroQuiz();
		break;
	case 3:

		break;
	case 4:

        sair();
		break;
	}
}

void animeQuiz()
{
	struct defJogador jogador;

	FILE *fJogador;
	fJogador = fopen(JOGADOR, "rb+");

	setbuf(stdin, NULL);


	char resp;
	int certo = 0, errado = 0, contp = 0, pontostotal = 0, menuFinal = 0;
	system("color 9A");


	system("cls");
	printf("\t*===================================================================*\n");
	printf("\t|       _________ ___   ___ ___ ____     ____ __________            |\n");
	printf("\t|       XXXXXXXXX XXX_  XXX XXX XXXX_   _XXXX XXXXXXXXXX            |\n");
	printf("\t|       XXXXXXXXX XXXX_ XXX XXX XXXXX_ _XXXXX XXXXXXXXXX            |\n");
	printf("\t|       XXX___XXX XXXXX_XXX XXX XXXXXX_XXXXXX XXX_____              |\n");
	printf("\t|       XXXXXXXXX XXXXXXXXX XXX XXXXXXXXXXXXX XXXXXXXX              |\n");
	printf("\t|       XXXXXXXXX XXX XXXXX XXX XXXXX X XXXXX XXX_______            |\n");
	printf("\t|       XXX   XXX XXX  XXXX XXX XXXXX   XXXXX XXXXXXXXXX            |\n");
	printf("\t|       XXX   XXX XXX   XXX XXX XXXX    XXXXX XXXXXXXXXX            |\n");
	printf("\t|                                                                   |\n");
	printf("\t*===================================================================*\n\n");
	printf("\t AS PERGUNTAS SOBRE \"ANIME\" VALEM 1 PONTO CADA\n\n");

	printf("\tPressiona a tecla Enter para continuar...");
	getchar(); system("cls");
	system("color B");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.1 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Li Shenlong nasceu de que esfera?\n\n");
	printf("A) Esfera cooler\n");
	printf("B) Esfera totil\n");
	printf("C) Esfera 7\n");
	printf("D) Esfera 1\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'D') || (resp == 'd'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"D\"\n");
		errado++;
		pontostotal--;
	}
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 6");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.2 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Em Dragon Ball Z as esferas do dragão do planeta\n");
	printf("\t namejuseikin concedem quantos desejos ?\n\n");
	printf("A) 1 DESEJO\n");
	printf("B) 2 DESEJOS\n");
	printf("C) 3 DESEJOS\n");
	printf("D) 4 DESEJOS\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"C\"\n\n");
		errado++;
		pontostotal--;

	}

	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 5");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.3 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Qual é o nome do irmão distante de Vegeta?\n\n");
	printf("A) Tapion\n");
	printf("B) Tarble\n");
	printf("C) Taurus\n");
	printf("D) Trunks\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'B') || (resp == 'b'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"B\"\n\n");
		errado++;
		pontostotal--;

	}
	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 7");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.4 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Goku Jr. é neto de quem?\n\n");
	printf("A) PAN\n");
	printf("B) BULMA\n");
	printf("C) CHI CHI\n");
	printf("D) Android 18\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"A\"\n\n");
		errado++;
		pontostotal--;

	}
	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color C");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.5 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Gogeta é a fusão de quem com quem?\n\n");
	printf("A) Goku e Malaga\n");
	printf("B) Goku e chourico\n");
	printf("C) Goku e Vegeta\n");
	printf("D) Goku e Gorgeta\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"D\"\n\n");
		errado++;
		pontostotal--;

	}

	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color E6");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.6 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Qual é o poder de um Saibamen?\n\n");
	printf("A) 2000\n");
	printf("B) 1500\n");
	printf("C) 1200\n");
	printf("D) 5000\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"C\"\n\n");
		errado++;
		pontostotal--;

	}

	system("pause");
	system("cls");

	system("color 9E");
	printf("**");
	printf("\t\t\t\tRESULTADOS DO JOGO                 \n\n\n");

	if (pontostotal <= 0);
	{
		pontostotal = certo;
	}

	strcpy(jogador.nome, nome);
	jogador.certo = certo;
	jogador.errado = errado;
	jogador.tema = tema;
	jogador.total = pontostotal;


	fseek(fJogador, 0, SEEK_END);
	fwrite(&jogador, 1, sizeof(struct defJogador), fJogador);

	printf("\t\t\tParticipante      : %s              \n", jogador.nome);
	printf("\t\t\tTotal de Certas   : %d              \n", jogador.certo);
	printf("\t\t\tTotal de erradas  : %d              \n", jogador.errado);
	printf("\t\t\tPontuacao total   : %d              \n\n", jogador.total);

	fclose(fJogador);


	system("pause");
	system("cls");

	printf("O que desejas fazer?\n\n1- Retornar ao menu principal.\n2- Fechar o jogo.\n\n");
	scanf("%d", &menuFinal);

	switch (menuFinal)
	{
	case 1:
		system("cls");
		menu();
		break;

	case 2:
        sair();
        break;
	}
}

void outroQuiz()
{
	struct defJogador jogador;

	FILE *fJogador;
	fJogador = fopen(JOGADOR, "rb+");

	setbuf(stdin, NULL);


	char resp;
	int certo = 0, errado = 0, contp = 0, pontostotal = 0, menuFinal = 0;
	system("color 9A");


	system("cls");
	printf("\t*===================================================================*\n");
	printf("\t|       _________ ___   ___ ___ ____     ____ __________            |\n");
	printf("\t|       XXXXXXXXX XXX_  XXX XXX XXXX_   _XXXX XXXXXXXXXX            |\n");
	printf("\t|       XXXXXXXXX XXXX_ XXX XXX XXXXX_ _XXXXX XXXXXXXXXX            |\n");
	printf("\t|       XXX___XXX XXXXX_XXX XXX XXXXXX_XXXXXX XXX_____              |\n");
	printf("\t|       XXXXXXXXX XXXXXXXXX XXX XXXXXXXXXXXXX XXXXXXXX              |\n");
	printf("\t|       XXXXXXXXX XXX XXXXX XXX XXXXX X XXXXX XXX_______            |\n");
	printf("\t|       XXX   XXX XXX  XXXX XXX XXXXX   XXXXX XXXXXXXXXX            |\n");
	printf("\t|       XXX   XXX XXX   XXX XXX XXXX    XXXXX XXXXXXXXXX            |\n");
	printf("\t|                                                                   |\n");
	printf("\t*===================================================================*\n\n");
	printf("\t AS PERGUNTAS SOBRE \"ANIME\" VALEM 1 PONTO CADA\n\n");

	printf("\tPressiona a tecla Enter para continuar...");
	getchar(); system("cls");
	system("color B");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.1 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Li Shenlong nasceu de que esfera?\n\n");
	printf("A) Esfera cooler\n");
	printf("B) Esfera totil\n");
	printf("C) Esfera 7\n");
	printf("D) Esfera 1\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'D') || (resp == 'd'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"D\"\n");
		errado++;
		pontostotal--;
	}
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 6");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.2 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Em Dragon Ball Z as esferas do dragão do planeta\n");
	printf("\t namejuseikin concedem quantos desejos ?\n\n");
	printf("A) 1 DESEJO\n");
	printf("B) 2 DESEJOS\n");
	printf("C) 3 DESEJOS\n");
	printf("D) 4 DESEJOS\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"C\"\n\n");
		errado++;
		pontostotal--;

	}

	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 5");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.3 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Qual é o nome do irmão distante de Vegeta?\n\n");
	printf("A) Tapion\n");
	printf("B) Tarble\n");
	printf("C) Taurus\n");
	printf("D) Trunks\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'B') || (resp == 'b'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"B\"\n\n");
		errado++;
		pontostotal--;

	}
	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color 7");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.4 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Goku Jr. é neto de quem?\n\n");
	printf("A) PAN\n");
	printf("B) BULMA\n");
	printf("C) CHI CHI\n");
	printf("D) Android 18\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"A\"\n\n");
		errado++;
		pontostotal--;

	}
	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color C");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.5 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Gogeta é a fusão de quem com quem?\n\n");
	printf("A) Goku e Malaga\n");
	printf("B) Goku e chourico\n");
	printf("C) Goku e Vegeta\n");
	printf("D) Goku e Gorgeta\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"D\"\n\n");
		errado++;
		pontostotal--;

	}

	printf("**");
	getchar(); printf("Pressiona a tecla Enter para continuar-...");
	getchar(); system("cls");
	system("color E6");
	printf("\t*==================================================*\n");
	printf("\t|            Pergunta de N.6 %.2d --- Anime         |\n", contp++);
	printf("\t*==================================================*\n\n");
	printf("\t Qual é o poder de um Saibamen?\n\n");
	printf("A) 2000\n");
	printf("B) 1500\n");
	printf("C) 1200\n");
	printf("D) 5000\n\n");
	printf("\t QUAL É A RESPOSTA CORRETA?\n\n");
	scanf("%s", &resp);

	if ((resp == 'C') || (resp == 'c'))
	{
		printf("\tA TUA RESPOSTA ESTÁ CORRETA...\n\n");
		certo++;
		pontostotal++;
	}
	else
	{
		printf("\t RESPOSTA ESTÁ ERRADA\n...");
		printf("\tA ALTERNATIVA CORRETA ERA A LETRA \"C\"\n\n");
		errado++;
		pontostotal--;

	}

	system("pause");
	system("cls");

	system("color 9E");
	printf("**");
	printf("\t\t\t\tRESULTADOS DO JOGO                 \n\n\n");

	if (pontostotal <= 0);
	{
		pontostotal = certo;
	}

	strcpy(jogador.nome, nome);
	jogador.certo = certo;
	jogador.errado = errado;
	jogador.tema = tema;
	jogador.total = pontostotal;


	fseek(fJogador, 0, SEEK_END);
	fwrite(&jogador, 1, sizeof(struct defJogador), fJogador);

	printf("\t\t\tParticipante      : %s              \n", jogador.nome);
	printf("\t\t\tTotal de Certas   : %d              \n", jogador.certo);
	printf("\t\t\tTotal de erradas  : %d              \n", jogador.errado);
	printf("\t\t\tPontuacao total   : %d              \n\n", jogador.total);

	fclose(fJogador);


	system("pause");
	system("cls");

	printf("O que desejas fazer?\n\n1- Retornar ao menu principal.\n2- Fechar o jogo.\n\n");
	scanf("%d", &menuFinal);

	switch (menuFinal)
	{
	case 1:
		system("cls");
		menu();
		break;

	case 2:
        sair();
        break;
	}
}


//Consulta dos resultados por tema de Quiz

void consultar()
{
	int opcao;

	printf("\t*==========================================================================================================*\n");
	printf("\t|              Escolha qual o tema que queres consultar.                                                   |\n");
	printf("\t|  1: Anime: Tudo sobre o mundo dos animes.                                                                |\n");
	printf("\t|  2: Tema 2: outro tema                                                                                   |\n");
	printf("\t|  3: Tema 3:                                                                                              |\n");
	printf("\t|  4: Fechar programa.                                                                                     |\n");
	printf("\t*==========================================================================================================*\n\n");
	scanf("%d", &opcao);
	system("cls");

	switch (opcao) {

	case 1:
		consultarAnime();
		break;

	case 2:
        consultarOutro();
		break;
	case 3:

		break;
	case 4:
        sair();
		break;
	}
}

void consultarAnime()
{
	int menuFinal;

	struct defJogador jogador;

	system("cls");
	FILE* fJogador;
	fJogador = fopen(JOGADOR, "rb+");

	fseek(fJogador, 0, SEEK_SET);
	do {
		fread(&jogador, 1, sizeof(struct defJogador), fJogador);

		if (!feof(fJogador)) {
                if (jogador.tema == 1){
                    printf("\t\t\tParticipante      : %s              \n", jogador.nome);
                    printf("\t\t\tTotal de Certas   : %d              \n", jogador.certo);
                    printf("\t\t\tTotal de erradas  : %d              \n", jogador.errado);
                    printf("\t\t\tPontuacao total   : %d              \n\n\n", jogador.total);
                }
		}
	} while (!feof(fJogador));

	fclose(fJogador);

	system("pause");
	system("cls");
	printf("O que desejas fazer?\n\n1- Retornar ao menu principal.\n2- Fechar o jogo.\n\n");
	scanf("%d", &menuFinal);

	switch (menuFinal)
	{
	case 1:
		system("cls");

		if (strcasecmp(nome, "ao Menu") == 0) {
			menuAlt();
		} else {
            menu();
		}

		break;

	case 2:

		sair();
		break;
	}
}

void consultarOutro()
{
	int menuFinal;

	struct defJogador jogador;

	system("cls");
	FILE* fJogador;
	fJogador = fopen(JOGADOR, "rb+");

	fseek(fJogador, 0, SEEK_SET);
	do {
		fread(&jogador, 1, sizeof(struct defJogador), fJogador);

		if (!feof(fJogador)) {
                if (jogador.tema == 2){
                    printf("\t\t\tParticipante      : %s              \n", jogador.nome);
                    printf("\t\t\tTotal de Certas   : %d              \n", jogador.certo);
                    printf("\t\t\tTotal de erradas  : %d              \n", jogador.errado);
                    printf("\t\t\tPontuacao total   : %d              \n\n\n", jogador.total);
                }
		}
	} while (!feof(fJogador));

	fclose(fJogador);

	system("pause");
	system("cls");
	printf("O que desejas fazer?\n\n1- Retornar ao menu principal.\n2- Fechar o jogo.\n\n");
	scanf("%d", &menuFinal);

	switch (menuFinal)
	{
	case 1:
		system("cls");

		if (strcasecmp(nome, "ao Menu") == 0) {
			menuAlt();
		} else {
            menu();
		}

		break;

	case 2:

		sair();
		break;
	}
}


//Inserir nome de jogador e duas opções de menu principal

void definirJogador()
{

    FILE *fJogador;
	fJogador = fopen(JOGADOR, "rb+");
	if (fJogador == NULL) {
		fJogador = fopen(JOGADOR, "wb");
		fclose(fJogador);
	} fclose(fJogador);

	setbuf(stdin, NULL);


	system("color 9A");

	if (strcmp(nome, "") == 0) {
		printf("\t\nOlá jogador. Por favor informa o teu nome ou digita *\Menu*\ para aceder ao menu principal.\n\n");
		//printf("Nome do Jogador: ");
		scanf("%[^\n]s", nome);
	}

	if (strcasecmp(nome, "menu") != 0) {

		menu();
	} else {

	strcpy(nome, "ao Menu");
	menuAlt();

	}
}

void menu()
{
	int nivel;

	system("cls");
	system("color F6");

	printf("\t*===========================================================================================================*\n");
	printf("\t|                                         Bem-vindo/a %-20.20s                                  |\n", nome);
	printf("\t|  Este é um jogo divertido de perguntas e respostas. Em que o jogador poderá escolher o que gosta de jogar.|\n");
	printf("\t*===========================================================================================================*\n");
	printf("\t|              Escolha a opção que desejas e em seguida carrega em enter.                                   |\n");
	printf("\t|  1: Escolher tema do Quiz.                                                                                |\n");
	printf("\t|  2: Colsultar: Todos os resultados.                                                                       |\n");
	printf("\t|  3: Trocar Jogador.                                                                                       |\n");
	printf("\t|  4: Fechar programa.                                                                                      |\n");
	printf("\t*===========================================================================================================*\n\n");
	scanf("%d", &nivel);
	system("cls");




	switch (nivel)
	{
	case 1:

		escolherTema();
		break;


	case 2:

		consultar();
		break;

	case 3:

		system("cls");
		strcpy(nome, "");
		definirJogador();
		break;

	case 4:

        sair();
        break;
	}
}

void menuAlt()
{
	int opcao;

	system("cls");
	system("color F6");

	printf("\t*===========================================================================================================*\n");
	printf("\t|                                         Bem-vindo/a %-20.20s                                  |\n", nome);
	printf("\t|  Este é um jogo divertido de perguntas e respostas. Em que o jogador poderá escolher o que gosta de jogar.|\n");
	printf("\t*===========================================================================================================*\n");
	printf("\t|              Escolha a opção que desejas e em seguida carrega em enter.                                   |\n");
	printf("\t|  1: Colsultar: Todos os resultados.                                                                       |\n");
	printf("\t|  2: Inserir nome de de jogador.                                                                           |\n");
	printf("\t|  3: Fechar programa.                                                                                      |\n");
	printf("\t*===========================================================================================================*\n\n");
	scanf("%d", &opcao);
	system("cls");


	switch (opcao)
	{
	case 1:

		consultar();

		return 0;
		break;


	case 2:

		system("cls");
		strcpy(nome, "");
		definirJogador();
		break;

	case 3:
		sair();
		break;
	}
}


//Função com mensagem para fechar programa

void sair()
{
	system("cls");
	printf("Bye bye :)\n\n");
	system("pause");
	return 0;
}

