#include <stdio.h>

#include "menu.h"
#include "node.h"
#include "locale.h"

int main(void) {
    (void)setlocale(LC_ALL, "Portuguese");
    Menu menu;
    Queue queue;

    printf("Bem vindo ao banco TucoBufo INC!\n");
    initializeQueue(&queue);

    displayMainMenu(&menu, &queue);

    return 0;
}
