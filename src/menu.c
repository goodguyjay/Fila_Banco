//
// Created by jay on 09/06/2024.
//

#include "menu.h"

// std
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void)
{
	while (getchar() != '\n');
}

void clearScreen(void)
{
    // arriscado...
	system("cls");
}

void setMenuChoice(Menu *menu)
{
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();
    menu->menuChoice = choice;
}

int getMenuChoice(const Menu *menu)
{
    return menu->menuChoice;
}

int optionChooser(const Menu *menu, Queue *queue)
{
    switch (menu->menuChoice)
    {
        case ADD_PERSON:
            char name[NAME_LENGTH];
            int id;
            puts("Informe o nome da pessoa: ");
            scanf("%s", name);
            clearInputBuffer();
            puts("\n");
            puts("Informe o ID da pessoa: ");
            scanf("%d", &id);
            clearInputBuffer();

            enqueue(queue, name, id);
            return EXIT_SUCCESS;

        case DEQUEUE:
            dequeue(queue);
            return EXIT_SUCCESS;

        case DISPLAY_QUEUE:
            displayQueue(queue);
            return EXIT_SUCCESS;

        case DISPLAY_FRONT:
            displayFront(queue);
            return EXIT_SUCCESS;

        case DISPLAY_REAR:
            displayRear(queue);
            return EXIT_SUCCESS;

        case DISPLAY_AT:
            int position;
            puts("Qual posição na fila você deseja que seja exibida?");
			scanf("%d", &position);
            clearInputBuffer();
            displayAt(queue, position);
            return EXIT_SUCCESS;

        case DISPLAY_SIZE:
            size(queue);
            return EXIT_SUCCESS;

        default:
            perror("Escolha inválida. Tente novamente.");
            return EXIT_FAILURE;
    }
}

void displayMainMenu(Menu *menu, Queue *queue)
{
    do {
        puts("<------------------------------------>\n");
        puts("1. Adicionar pessoa na fila\n");
        puts("2. Atender pessoa\n");
        puts("3. Exibir fila\n");
        puts("4. Exibir primeiro da fila\n");
        puts("5. Exibir último da fila\n");
        puts("6. Exibir fila a partir de uma posição\n");
        puts("7. Exibir tamanho da fila\n");
        puts("0. Sair\n");
        puts("<------------------------------------>\n");
        puts("Escolha uma opção: ");

        setMenuChoice(menu);
        if (getMenuChoice(menu) == 0) return;

        if (getMenuChoice(menu) < 0 || getMenuChoice(menu) > 7)
        {
            puts("Opção inválida. Tente novamente.\n");
            // função recursiva pra chamar o menu novamente
            displayMainMenu(menu, queue);
        }

        optionChooser(menu, queue);

        //clearScreen();
    } while (getMenuChoice(menu) != 0);
}