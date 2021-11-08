// Sintese
//   data "11/11/2019"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declaracao de tipo
struct tHeroi {
	char nome[20];
	int atk;
    int def;
    int classe;
	char deletado; // ' '=OK/*=deletado
};

struct tPlayer{
	char nick[20];
};

struct tPremio{
	char desejo[90];
};
struct tClasse{
	char classe[20];
	int posicao;
	char deletado; 
};

// Prototipos de funcao
int menuPrincipal(void);
void menuHeroi(void);
int ataque(void);
void name(struct tHeroi *heroi);
void mostrarHeroi(struct tHeroi heroi);
void incluirHeroi(void);
void listarHeroi(void);
void consultarHeroi(void);
void alterarHeroi(void);
void excluirHeroi(void);
void nickname(struct player *name);
void desejo(struct Realize *desejo);
void nomeClasse(struct classe *nome);
void incluirClasse(void);
//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	int opcao;
	struct tPlayer nick;
	struct tPremio premio;
	do {
		opcao = menuPrincipal();
		switch (opcao) {
			case 1:
				menuHeroi();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

//- Menus ---------------------------------------------------------------------------
void menuHeroi(){
	struct tHeroi heroi;
	int opcao;
	
	system("cls");
	printf("\n=== Menu Héroi ===\n");
	printf("\n");
	printf("1. Incluir Héroi\n");
	printf("2. Excluir Héroi\n");
	printf("3. Alterar Héroi\n");
	printf("4. Consultar Héroi\n");
	printf("5. Listar Hérois\n");
	printf("0. Voltar\n");
	printf("\nDigite sua opcao: ");
	scanf("%d",&opcao);
	 
	switch (opcao) {
		case 1:
			printf("\n*** Inclusão ***\n");
			incluirHeroi();
			break;
		case 2:
			printf("\n*** Exclusão ***\n");
			excluirHeroi();
			break;
		case 3:
			printf("\n*** Alteração ***\n");
			alterarHeroi();
			break;
		case 4:
			printf("\n*** Consulta ***\n");
			consultarHeroi();
			break;
		case 5:
			printf("\n*** Listagem ***\n");
			listarHeroi();
			break;	
	}
}
void menuPremios(){
	struct tPremio premios ;
	int opcao;
	
	system("cls");
	printf("\n=== Menu Prêmio ===\n");
	printf("\n");
	printf("1. Incluir Prêmio\n");
	printf("2. Excluir Prêmio\n");
	printf("3. Alterar Prêmio\n");
	printf("4. Consultar Prêmio\n");
	printf("5. Listar Prêmios\n");
	printf("0. Voltar\n");
	printf("\nDigite sua opcao: ");
	scanf("%d",&opcao);
	 
	switch (opcao) {
		case 1:
			printf("\n*** Inclusão ***\n");
			incluirHeroi();
			break;
		case 2:
			printf("\n*** Exclusão ***\n");
			excluirHeroi();
			break;
		case 3:
			printf("\n*** Alteração ***\n");
			alterarHeroi();
			break;
		case 4:
			printf("\n*** Consulta ***\n");
			consultarHeroi();
			break;
		case 5:
			printf("\n*** Listagem ***\n");
			listarHeroi();
			break;	
	}
}

int menuPrincipal(void) {
	int op;
	system("cls");
	printf("\n\n*** MENU ***\n\n");
	printf("1. Menu do Héroi\n");
	printf("2. Menu do Prêmio\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}
int setaMenu () {
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                      ------------ Bem Vindo -----------");

	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(33,4);
		printf("  Menu Do Héroi");
		gotoxy(33,5);
		printf("  Menu Do Prêmio "); 
		gotoxy(33,6);
		printf("  Menu Do Usuário");
		gotoxy(33,7);
		printf("  Sair");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(33,4);
				textcolor(10);
				printf("=>Menu Do Héroi");
				break;
			case 2:
				gotoxy(33,5);
				textcolor(10);
				printf("=>Menu Do Prêmio");
				break;
			case 3:
				gotoxy(33,6);
				textcolor(10);
				printf("=>Menu Do Usuário");
				break;
			case 4:
				gotoxy(33,7);
				textcolor(10);
				printf("=>Sair");
				break;
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 6;
			if (opcao == 7)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC

	textcolor(15);
	textbackground(0);

	return opcao;
}

//--- Receber o codigo do produto ----------------------------------------
int ataque(void) {
	int atk;
	("digite um numero");
	scanf("%d", &atk);
	return atk;
}

//--- Receber os demais dados do produto ---------------------------------
void name(struct tHeroi *heroi) {
	printf("Digite o nome do heroi: ");
	fflush(stdin);
	gets((*heroi).nome);
	printf("Digite a defesa do heroi invocado....: ");
	scanf("%d", &((*heroi).def));
}
//-----------receber nome do usuario---------------------------------------
void nickname(struct tPlayer *name) {
	printf("Digite o seu nome: ");
	fflush(stdin);
	gets((*name).nick);
}

//--- Mostrar dos dados do heroi-----------------------
void mostrarHeroi(struct tHeroi heroi) {
	printf("nome....................: %s\n", heroi.nome);
	printf("atk........................: %d\n", heroi.atk);
	printf("def........................: %d\n", heroi.def);
}

//--- Incluir ------------------------------------------------------------
void incluirHeroi(void) {
	struct tHeroi heroi;
	FILE *arq = fopen("Realize.dat","ab");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	name(&heroi);
	heroi.atk = ataque();
	heroi.deletado = ' ';
	fwrite(&heroi, sizeof(heroi), 1, arq);
	fclose(arq);
}
//-----adicionar classe-------------------------------------------------
void nomeClasse(struct tClasse *nome) {
	printf("Digite o seu nome: ");
	fflush(stdin);
	gets((*nome).classe);
}
void incluirClasse(void) {
	struct tClasse heroi;
	FILE *arq = fopen("Realize.dat","ab");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	nomeClasse(&heroi);
	heroi.posicao = ataque();
	heroi.deletado = ' ';
	fwrite(&heroi, sizeof(heroi), 1, arq);
	fclose(arq);
}


//--- Listar -------------------------------------------------------------
void listarHeroi(void) {
	struct tHeroi heroi;
	FILE *arq = fopen("Realize.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("nome     Defesa             ataque\n");
	printf("--- - -------------------- - ----------\n");
	while (fread(&heroi, sizeof(heroi), 1, arq)) {
		if (heroi.deletado != '*')
			printf("%s - %d - %d\n", heroi.nome, heroi.def, heroi.atk);
	}
	fclose(arq);
}

//--- Consultar ----------------------------------------------------------
void consultarHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("Realize.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("informe o nome do heroi");
	gets(nome);
	while (fread(&heroi, sizeof(heroi), 1, arq)) {
		if ((heroi.nome == nome) && (heroi.deletado != '*')) {
			mostrarHeroi(heroi);
			achei=1;
		}
	}
	if (!achei)
		printf("Codigo nao encontrado!");
	fclose(arq);
}

//--- Alterar ------------------------------------------------------------
void alterarHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("Realize.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
    printf("informe o nome do heroi");
	gets(nome);
	while (fread(&heroi, sizeof(heroi), 1, arq)) {
		if ((heroi.nome == nome) && (heroi.deletado != '*')) {
			mostrarHeroi(heroi);
			achei=1;
			name(&heroi);
			fseek(arq, -sizeof(heroi), SEEK_CUR);
			fwrite(&heroi, sizeof(heroi), 1, arq);
			fseek(arq, 0, SEEK_CUR); // Eu nao sou idiota! Codigo necessario para reposicionar o ponteiro para evitar erro de perda de endereco.
		}
	}
	if (!achei)
		printf("Codigo nao encontrado!");
	fclose(arq);
}

//--- Excluir ------------------------------------------------------------
void excluirHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("Realize.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
printf("informe o nome do heroi");
	gets(nome);
	while (fread(&heroi, sizeof(heroi), 1, arq)) {
		if ((heroi.nome == nome) && (heroi.deletado != '*')) {
			mostrarHeroi(heroi);
			achei=1;
			heroi.deletado = '*';
			fseek(arq, -sizeof(heroi), SEEK_CUR);
			fwrite(&heroi, sizeof(heroi), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("Codigo nao encontrado!");
	fclose(arq);
}


//------------------------------------------------------------------------
