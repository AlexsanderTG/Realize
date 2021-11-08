// Sintese
//   data "25/11/2019"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "conio2.c"

// Declaracao de tipo
struct tHeroi {
	char nome[20];
	int atk;
    int def;
    int classe;
	char deletado; // ' '=OK/*=deletado
};

struct tPlayer{
	int cod;
	char nick[20];
	char deletado; // ' '=OK/*=deletado
};

struct tPremio{
	int cod;
	char desejo[90];
	char deletado; // ' '=OK/*=deletado
};
struct tClasse{
	int cod;
	char nome[20];
	int posicao;
	char deletado; // ' '=OK/*=deletado
};

// Prototipos de funcao
int menuPrincipal(void);
int menuHeroi(void);
int menuClasses(void);
int menuPremios(void);
int menuUsuario(void);
int chamarMenuHeroi(void);
int chamarMenuClasses(void);
int chamarMenuPremios(void);
int chamarMenuUsuarios(void);
void dadosHeroi(struct tHeroi *heroi);
void mostrarHeroi(struct tHeroi heroi);
void incluirHeroi(void);
void listarHeroi(void);
void consultarHeroi(void);
void alterarHeroi(void);
void excluirHeroi(void);
int  codClasse(void);
void dadosClasse(struct tClasse *classe);
void mostrarClasse(struct tClasse classe);
void incluirClasse(void);
void listarClasse(void);
void consultarClasse(void);
void alterarClasse(void);
void excluirClasse(void);
int  codPremio(void);
void dadosPremio(struct tPremio *premio);
void mostrarPremio(struct tPremio premio);
void incluirPremio(void);
void listarPremio(void);
void consultarPremio(void);
void alterarPremio(void);
void excluirPremio(void);	
int  codPlayer(void);
void listarPlayer(void);
void consultarPlayer(void);	
void excluirPlayer(void);


//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	int opcao,opHeroi,opClasses,opPremios,opUsuarios;
	struct tPlayer player;
	struct tPremio premio;
	struct tClasse classe;
	
	do {
		opcao = menuPrincipal();
		switch (opcao) {
			case 1:
				opHeroi = chamarMenuHeroi(); 
				break;
			case 2:
				opClasses = chamarMenuClasses();
				break;
			case 3:
				opPremios = chamarMenuPremios();
				break;
			case 4:
				opUsuarios = chamarMenuUsuarios();
				break;	
			case 5:
				return;	
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

//- Menus ---------------------------------------------------------------------------
int menuHeroi(){
	struct tHeroi heroi;
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                                   ------------        H�ROI         -----------");
	
	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(50,4);
		printf("  Incluir H�roi");
		gotoxy(50,5);
		printf("  Excluir H�roi "); 
		gotoxy(50,6);
		printf("  Alterar H�roi");
		gotoxy(50,7);
		printf("  Consultar H�roi");
		gotoxy(50,8);
		printf("  Listar H�rois");
		gotoxy(50,9);
		printf("  Voltar");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(50,4);
				textcolor(10);
				printf("=>Incluir H�roi");
				break;
			case 2:
				gotoxy(50,5);
				textcolor(10);
				printf("=>Excluir H�roi");
				break;
			case 3:
				gotoxy(50,6);
				textcolor(10);
				printf("=>Alterar H�roi");
				break;
			case 4:
				gotoxy(50,7);
				textcolor(10);
				printf("=>Consultar H�roi");
				break;
			case 5:
				gotoxy(50,8);
				textcolor(10);
				printf("=>Listar H�rois");
				break;
			case 6:
				gotoxy(50,9);
				textcolor(12);
				printf("=>Voltar");
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

int menuUsuario(){
	struct tPlayer player;
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                                   ------------        USU�RIO         -----------");
	
	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(50,4);
		printf("  Consultar Usu�rio");
		gotoxy(50,5);
		printf("  Listar Usu�rios"); 
		gotoxy(50,6);
		printf("  Banir Usu�rio");
		gotoxy(50,7);
		printf("  Voltar");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(50,4);
				textcolor(10);
				printf("=>Consultar Usu�rio");
				break;
			case 2:
				gotoxy(50,5);
				textcolor(10);
				printf("=>Listar Usu�rios");
				break;
			case 3:
				gotoxy(50,6);
				textcolor(10);
				printf("=>Banir Usu�rio");
				break;
			case 4:
				gotoxy(50,7);
				textcolor(12);
				printf("=>Voltar");
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

int menuPremios(){
	struct tPremio premio;
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                                   ------------        PR�MIOS         -----------");
	
	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(50,4);
		printf("  Incluir Pr�mio");
		gotoxy(50,5);
		printf("  Excluir Pr�mio"); 
		gotoxy(50,6);
		printf("  Alterar Pr�mio");
		gotoxy(50,7);
		printf("  Consultar Pr�mio");
		gotoxy(50,8);
		printf("  Listar Pr�mios");
		gotoxy(50,9);
		printf("  Voltar");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(50,4);
				textcolor(10);
				printf("=>Incluir Pr�mio");
				break;
			case 2:
				gotoxy(50,5);
				textcolor(10);
				printf("=>Excluir Pr�mio");
				break;
			case 3:
				gotoxy(50,6);
				textcolor(10);
				printf("=>Alterar Pr�mio");
				break;
			case 4:
				gotoxy(50,7);
				textcolor(10);
				printf("=>Consultar Pr�mio");
				break;
			case 5:
				gotoxy(50,8);
				textcolor(10);
				printf("=>Listar Pr�mios");
				break;
			case 6:
				gotoxy(50,9);
				textcolor(12);
				printf("=>Voltar");
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

int menuClasses(){
	struct tClasse classe;
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                                   ------------        CLASSES         -----------");
	
	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(50,4);
		printf("  Incluir Classe");
		gotoxy(50,5);
		printf("  Excluir Classe"); 
		gotoxy(50,6);
		printf("  Alterar Classe");
		gotoxy(50,7);
		printf("  Consultar Classe");
		gotoxy(50,8);
		printf("  Listar Classes");
		gotoxy(50,9);
		printf("  Voltar");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(50,4);
				textcolor(10);
				printf("=>Incluir Classe");
				break;
			case 2:
				gotoxy(50,5);
				textcolor(10);
				printf("=>Excluir Classe");
				break;
			case 3:
				gotoxy(50,6);
				textcolor(10);
				printf("=>Alterar Classe");
				break;
			case 4:
				gotoxy(50,7);
				textcolor(10);
				printf("=>Consultar Classe");
				break;
			case 5:
				gotoxy(50,8);
				textcolor(10);
				printf("=>Listar Classe");
				break;
			case 6:
				gotoxy(50,9);
				textcolor(12);
				printf("=>Voltar");
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

int menuPrincipal() {
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	system("cls");
	printf("                                   ------------ Realize Administrador -----------");

	do {
	//	setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(50,4);
		printf("  Menu Do H�roi");
		gotoxy(50,5);
		printf("  Menu Das Classes "); 
		gotoxy(50,6);
		printf("  Menu Do Pr�mio");
		gotoxy(50,7);
		printf("  Menu Do Usu�rio");
		gotoxy(50,8);
		printf("  Sair");
		// Escreve o item selecionado em destaque
		textcolor(15);
		switch (opcao) {
			case 1:
				gotoxy(50,4);
				textcolor(10);
				printf("=>Menu Do H�roi");
				break;
			case 2:
				gotoxy(50,5);
				textcolor(10);
				printf("=>Menu Das Classes");
				break;
			case 3:
				gotoxy(50,6);
				textcolor(10);
				printf("=>Menu Do Pr�mio");
				break;
			case 4:	
				gotoxy(50,7);
				textcolor(10);
				printf("=>Menu Do Usu�rio");
				break;	
			case 5:
				gotoxy(50,8);
				textcolor(12);
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

int chamarMenuHeroi(){
	int opcao;
	
	opcao = menuHeroi();
	switch(opcao){
		case 1:
			system("cls");
			incluirHeroi();
			break;
		case 2:
			system("cls");
			excluirHeroi();
			break;
		case 3:
			system("cls");
			alterarHeroi();
			break;
		case 4:
			system("cls");
			consultarHeroi();
			break;
		case 5:
			system("cls");
			listarHeroi();
			break;
		break;	
	}
	return opcao;
}

int chamarMenuPremios(){
	int opcao;
	
	opcao = menuPremios();
	switch(opcao){
		case 1:
			system("cls");
			incluirPremio();
			break;
		case 2:
			system("cls");
			excluirPremio();
			break;
		case 3:
			system("cls");
			alterarPremio();
			break;
		case 4:
			system("cls");
			consultarPremio();
			break;
		case 5:
			system("cls");
			listarPremio();
			break;
		break;	
	}
	return opcao;
}

int chamarMenuClasses(){
	int opcao;
	
	opcao = menuClasses();
	switch(opcao){
		case 1:
			system("cls");
			incluirClasse();
			break;
		case 2:
			system("cls");
			excluirClasse();
			break;
		case 3:
			system("cls");
			alterarClasse();
			break;
		case 4:
			system("cls");
			consultarClasse();
			break;
		case 5:
			system("cls");
			listarClasse();
			break;
		break;	
	}
	return opcao;
}

int chamarMenuUsuarios(){
	int opcao;
	
	opcao = menuUsuario();
	switch(opcao){
		case 1:
			system("cls");
			consultarPlayer();
			break;
		case 2:
			system("cls");
			listarPlayer();
			break;
		case 3:
			system("cls");
			excluirPlayer();
			break;
	}
	return opcao;
}
//--------------------------------------------------------------------------------------------- FUN��ES DO USU�RIO ---------------------------------------------------------------------------------------------------------------------------------------------------

int codPlayer(void) {
	int cod;
	printf("digite o c�digo do usu�rio: ");
	scanf("%d",&cod);
	return cod;
}

//--- Listar -------------------------------------------------------------
void listarPlayer(void) {
	struct tPlayer player;
	FILE *arq = fopen("players.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("player         c�digo");
	printf("--- - -------------------- - ----------\n");
	while (fread(&player, sizeof(player), 1, arq)) {
		if (player.deletado != '*')
			printf(" %s   -     %d -\n", player.nick, player.cod);
	}
	fclose(arq);
}

//--- Consultar ----------------------------------------------------------
void consultarPlayer(void) {
	struct tPlayer player;
	int achei=0;
	int codigo;
	FILE *arq = fopen("players.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("informe o c�digo do player: ");
	scanf("%d", &codigo);
	while (fread(&player, sizeof(player), 1, arq)) {
		if ((player.cod == codigo) && (player.deletado != '*')) {
			printf("Player.......................: %s\n", player.nick);
			achei=1;
		}
	}
	if (!achei)
		printf("player n�o encontrado!");
	fclose(arq);
}

//--- Excluir ------------------------------------------------------------
void excluirPlayer(void) {
	struct tPlayer player;
	int achei=0;
	int codigo;
	FILE *arq = fopen("players.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
printf("informe o c�digo do player: ");
scanf("%d", &codigo);
	while (fread(&player, sizeof(player), 1, arq)) {
		if ((player.cod == codigo) && (player.deletado != '*')) {
			printf("Player.......................: %s\n", player.nick);
			achei=1;
			player.deletado = '*';
			fseek(arq, -sizeof(player), SEEK_CUR);
			fwrite(&player, sizeof(player), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("player nao encontrado!");
	fclose(arq);
}

//--------------------------------------------------------------------------------------------- FUN��ES DO PR�MIO ---------------------------------------------------------------------------------------------------------------------------------------------------

//--- Receber o codigo do pr�mio ----------------------------------------
int codPremio(void) {
	int cod;
	printf("digite o c�digo do pr�mio: ");
	scanf("%d",&cod);
	return cod;
}

//--- Receber os demais dados do pr�mio ---------------------------------
void dadosPremio(struct tPremio *premio) {

	printf("Digite o pr�mio: ");
	fflush(stdin);
	gets((*premio).desejo);
	printf("Digite o c�digo do pr�mio....: ");
	scanf("%d",&((*premio).cod));

}

//--- Mostrar dos dados do premio-----------------------
void mostrarPremio(struct tPremio premio) {
	printf("Pr�mio.......................: %s\n", premio.desejo);
	printf("c�digo.....................: %d\n", premio.cod);
}

//--- Incluir ------------------------------------------------------------
void incluirPremio(void) {
	struct tPremio premio;
	FILE *arq = fopen("premios.dat","ab");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
    dadosPremio(&premio);
	premio.deletado = ' ';
	fwrite(&premio, sizeof(premio), 1, arq);
	fclose(arq);
}

//--- Listar -------------------------------------------------------------
void listarPremio(void) {
	struct tPremio premio;
	FILE *arq = fopen("premios.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("pr�mio         c�digo");
	printf("--- - -------------------- - ----------\n");
	while (fread(&premio, sizeof(premio), 1, arq)) {
		if (premio.deletado != '*')
			printf(" %s   -     %d -\n", premio.desejo, premio.cod);
	}
	fclose(arq);
}

//--- Consultar ----------------------------------------------------------
void consultarPremio(void) {
	struct tPremio premio;
	int achei=0;
	int codigo;
	FILE *arq = fopen("premios.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("informe o codigo: ");
	scanf("%d", &codigo);
	while (fread(&premio, sizeof(premio), 1, arq)) {
		if ((premio.cod == codigo) && (premio.deletado != '*')) {
			mostrarPremio(premio);
			achei=1;
		}
	}
	if (!achei)
		printf("pr�mio n�o encontrado!");
	fclose(arq);
}

//--- Alterar ------------------------------------------------------------
void alterarPremio(void) {
	struct tPremio premio;
	int achei=0;
	int codigo;
	FILE *arq = fopen("premios.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
    printf("informe o c�digo do pr�mio: \n");
	scanf("%d", &codigo);
	while (fread(&premio, sizeof(premio), 1, arq)) {
		if ((premio.cod == codigo) && (premio.deletado != '*')) {
			mostrarPremio(premio);
			achei=1;
			dadosPremio(&premio);
			fseek(arq, -sizeof(premio), SEEK_CUR);
			fwrite(&premio, sizeof(premio), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("C�digo nao encontrado!");
	fclose(arq);
}

//--- Excluir ------------------------------------------------------------
void excluirPremio(void) {
	struct tPremio premio;
	int achei=0;
	int codigo;
	FILE *arq = fopen("premios.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
printf("informe o c�digo do pr�mio: ");
scanf("%d", &codigo);
	while (fread(&premio, sizeof(premio), 1, arq)) {
		if ((premio.cod == codigo) && (premio.deletado != '*')) {
			mostrarPremio(premio);
			achei=1;
			premio.deletado = '*';
			fseek(arq, -sizeof(premio), SEEK_CUR);
			fwrite(&premio, sizeof(premio), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("C�digo nao encontrado!");
	fclose(arq);
}

//--------------------------------------------------------------------------------------------- FUN��ES DA CLASSE ---------------------------------------------------------------------------------------------------------------------------------------------------

//--- Receber o codigo da classe ----------------------------------------
int codClasse(void) {
	int cod;
	printf("digite o c�digo da classe");
	scanf("%d",&cod);
	return cod;
}

//--- Receber os demais dados da classe ---------------------------------
void dadosClasse(struct tClasse *classe) {

	printf("Digite a classe: ");
	fflush(stdin);
	gets((*classe).nome);
	printf("Digite o c�digo da classe....: ");
	scanf("%d",&((*classe).cod));

}

//--- Mostrar dos dados da classe-----------------------
void mostrarClasse(struct tClasse classe) {
	printf("nome.......................: %s\n", classe.nome);
	printf("c�digo.....................: %d\n", classe.cod);
}

//--- Incluir ------------------------------------------------------------
void incluirClasse(void) {
	struct tClasse classe;
	FILE *arq = fopen("classes.dat","ab");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
    dadosClasse(&classe);
	classe.deletado = ' ';
	fwrite(&classe, sizeof(classe), 1, arq);
	fclose(arq);
}

//--- Listar -------------------------------------------------------------
void listarClasse(void) {
	struct tClasse classe;
	FILE *arq = fopen("classes.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("classe         c�digo");
	printf("--- - -------------------- - ----------\n");
	while (fread(&classe, sizeof(classe), 1, arq)) {
		if (classe.deletado != '*')
			printf(" %s   -     %d -\n", classe.nome, classe.cod);
	}
	fclose(arq);
}

//--- Consultar ----------------------------------------------------------
void consultarClasse(void) {
	struct tClasse classe;
	int achei=0;
	int codigo;
	FILE *arq = fopen("classes.dat","rb");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	printf("informe o codigo: ");
	scanf("%d", &codigo);
	while (fread(&classe, sizeof(classe), 1, arq)) {
		if ((classe.cod == codigo) && (classe.deletado != '*')) {
			mostrarClasse(classe);
			achei=1;
		}
	}
	if (!achei)
		printf("classe n�o encontrada!");
	fclose(arq);
}

//--- Alterar ------------------------------------------------------------
void alterarClasse(void) {
	struct tClasse classe;
	int achei=0;
	int codigo;
	FILE *arq = fopen("classes.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
    printf("informe o c�digo do heroi \n");
	scanf("%d", &codigo);
	while (fread(&classe, sizeof(classe), 1, arq)) {
		if ((classe.cod == codigo) && (classe.deletado != '*')) {
			mostrarClasse(classe);
			achei=1;
			dadosClasse(&classe);
			fseek(arq, -sizeof(classe), SEEK_CUR);
			fwrite(&classe, sizeof(classe), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("C�digo nao encontrado!");
	fclose(arq);
}

//--- Excluir ------------------------------------------------------------
void excluirClasse(void) {
	struct tClasse classe;
	int achei=0;
	int codigo;
	FILE *arq = fopen("classes.dat","r+b");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
printf("informe o c�digo do pr�mio: ");
scanf("%d", &codigo);
	while (fread(&classe, sizeof(classe), 1, arq)) {
		if ((classe.cod == codigo) && (classe.deletado != '*')) {
			mostrarClasse(classe);
			achei=1;
			classe.deletado = '*';
			fseek(arq, -sizeof(classe), SEEK_CUR);
			fwrite(&classe, sizeof(classe), 1, arq);
			fseek(arq, 0, SEEK_CUR);
		}
	}
	if (!achei)
		printf("C�digo nao encontrado!");
	fclose(arq);
}

//--------------------------------------------------------------------------------------------- FUN��ES DO H�ROI ---------------------------------------------------------------------------------------------------------------------------------------------------

//--- Mostrar dos dados do heroi -----------------------
void mostrarHeroi(struct tHeroi heroi) {
	printf("nome....................: %s\n", heroi.nome);
	printf("atk........................: %d\n", heroi.atk);
	printf("def........................: %d\n", heroi.def);
}

//--- Receber os demais dados do h�roi ---------------------------------
void dadosHeroi(struct tHeroi *heroi) {
	printf("Digite o nome do heroi: ");
	fflush(stdin);
	gets((*heroi).nome);
	printf("Digite o ataque do heroi invocado....: ");
	scanf("%d",&((*heroi).atk));
	printf("Digite a defesa do heroi invocado....: ");
	scanf("%d",&((*heroi).def));
}

void incluirHeroi(void) {
	struct tHeroi heroi;
	FILE *arq = fopen("herois.dat","ab");
	if (arq == NULL) {
		printf("Erro de abertura!");
		return;
	}
	dadosHeroi(&heroi);
	heroi.deletado = ' ';
	fwrite(&heroi, sizeof(heroi), 1, arq);
	fclose(arq);
}

void listarHeroi(void) {
	struct tHeroi heroi;
	FILE *arq = fopen("herois.dat","rb");
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

void consultarHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("herois.dat","rb");
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
		printf("H�roi nao encontrado!");
	fclose(arq);
}

void alterarHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("herois.dat","r+b");
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
			dadosHeroi(&heroi);
			fseek(arq, -sizeof(heroi), SEEK_CUR);
			fwrite(&heroi, sizeof(heroi), 1, arq);
			fseek(arq, 0, SEEK_CUR); 
		}
	}
	if (!achei)
		printf("C�digo nao encontrado!");
	fclose(arq);
}

void excluirHeroi(void) {
	struct tHeroi heroi;
	int achei=0;
	char nome[20];
	FILE *arq = fopen("herois.dat","r+b");
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
		printf("C�digo nao encontrado!");
	fclose(arq);
}

//------------------------------------------------------------------------
