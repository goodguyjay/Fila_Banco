//
// Created by jay on 09/06/2024.
//

#ifndef MENU_H
#define MENU_H

#include "node.h"

enum MenuChoice
{
    ADD_PERSON = 1,
    DEQUEUE= 2,
    DISPLAY_QUEUE = 3,
    DISPLAY_FRONT = 4,
    DISPLAY_REAR = 5,
    DISPLAY_AT = 6,
    DISPLAY_SIZE = 7,
    CLEAR_QUEUE = 8,
    ENQUEUE_FIRST = 9
};

typedef struct Menu
{
    int menuChoice;
} Menu;

void setMenuChoice(Menu *menu);

int getMenuChoice(const Menu *menu);

void displayMainMenu(Menu *menu, Queue *queue);

int optionChooser(const Menu *menu, Queue *queue);

void clearInputBuffer(void);

void clearScreen(void);

#endif //MENU_H
