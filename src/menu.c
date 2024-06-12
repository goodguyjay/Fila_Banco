//
// Created by jay on 09/06/2024.
//

#include "menu.h"

// std
#include <stdio.h>
#include <stdlib.h>

// public:
char name[NAME_LENGTH];
int id = 0;

void clearInputBuffer(void)
{
	// limpa o buffer de entrada
	while (getchar() != '\n');
}

void clearName()
{
	for (unsigned int i = 0; i < sizeof(name); i++)
	{
		name[i] = '\0';
	}
}

void clearScreen(void)
{
	// arriscado...
	system("cls");
}

void setMenuChoice(Menu* menu)
{
	int choice;
	scanf("%d", &choice);
	clearInputBuffer();
	menu->menuChoice = choice;
}

int getMenuChoice(const Menu* menu)
{
	return menu->menuChoice;
}

int optionChooser(const Menu* menu, Queue* queue)
{
	switch (menu->menuChoice)
	{
	case ADD_PERSON:
		puts("Informe o nome da pessoa: ");
		scanf("%s", name);
		clearInputBuffer();
		clearScreen();
		id++;
		enqueue(queue, name, id);

		// limpa a variável name
		clearName();

		return EXIT_SUCCESS;

	case DEQUEUE:
		clearScreen();
		dequeue(queue);
		return EXIT_SUCCESS;

	case DISPLAY_QUEUE:
		clearScreen();
		displayQueue(queue);
		return EXIT_SUCCESS;

	case DISPLAY_FRONT:
		clearScreen();
		displayFront(queue);
		return EXIT_SUCCESS;

	case DISPLAY_REAR:
		clearScreen();
		displayRear(queue);
		return EXIT_SUCCESS;

	case DISPLAY_AT:
		clearScreen();
		int position = 0;
		puts("Qual posição na fila você deseja que seja exibida?");
		scanf("%d", &position);
		clearInputBuffer();
		displayAt(queue, position);
		return EXIT_SUCCESS;

	case DISPLAY_SIZE:
		clearScreen();
		size(queue);
		return EXIT_SUCCESS;

	case CLEAR_QUEUE:
		clearScreen();
		freeQueue(queue);
		return EXIT_SUCCESS;

	case ENQUEUE_FIRST:
		clearScreen();
		puts("Informe o nome da pessoa: ");
		scanf("%s", name);
		clearInputBuffer();
		clearScreen();
		id++;
		enqueueFirst(queue, name, id);

		// limpa a variável name
		clearName();

		return EXIT_SUCCESS;

	default:
		perror("Escolha inválida. Tente novamente.");
		return EXIT_FAILURE;
	}
}

void displayMainMenu(Menu* menu, Queue* queue)
{
	clearScreen();
	do {
		puts("<------------------------------------>");
		puts("1. Adicionar pessoa na fila\n");
		puts("2. Atender pessoa\n");
		puts("3. Exibir fila\n");
		puts("4. Exibir primeiro da fila\n");
		puts("5. Exibir último da fila\n");
		puts("6. Exibir fila a partir de uma posição\n");
		puts("7. Exibir tamanho da fila\n");
		puts("8. Limpar toda a fila [ADMINISTRADOR]\n");
		puts("9. Adicionar no início da fila [ADMINISTRADOR]\n");
		puts("0. Sair");
		puts("<------------------------------------>");
		puts("Escolha uma opção: ");

		// seta a escolha do menu
		setMenuChoice(menu);
		if (getMenuChoice(menu) == 0) return;

		if (getMenuChoice(menu) < 0 || getMenuChoice(menu) > 9)
		{
			puts("Opção inválida. Tente novamente.\n");
			// função recursiva pra chamar o menu novamente
			displayMainMenu(menu, queue);
		}

		// chama a função que executa a opção escolhida
		optionChooser(menu, queue);

	} while (getMenuChoice(menu) != 0);
}