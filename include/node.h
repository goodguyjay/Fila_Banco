//
// Created by jay on 09/06/2024.
//

#ifndef NODE_H
#define NODE_H

// tamanho máximo para o nome
#define NAME_LENGTH 50

typedef struct Node
{
    char name[NAME_LENGTH];
    unsigned int id;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

// incializar a fila:
void initializeQueue(Queue* queue);

// adicionar a fila:
void enqueue(Queue* queue, const char* name, unsigned int id);

// remover da fila:
void dequeue(Queue* queue);

// exibir a fila:
void displayQueue(const Queue* queue);

// limpar a fila:
void freeQueue(Queue* queue);

// exibir o primeiro cliente da fila:
void displayFront(const Queue* queue);

// exibir o último cliente da fila:
void displayRear(const Queue* queue);

// verificar se a fila está vazia:
void isEmpty(const Queue* queue);

// verificar o tamanho da fila:
void size(const Queue* queue);

// exibir a fila a partir de uma posição:
void displayAt(const Queue* queue, unsigned int position);

#endif //NODE_H
