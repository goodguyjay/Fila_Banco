//
// Created by jay on 09/06/2024.
//

#include "node.h"

// std
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeQueue(Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, const char* name, const unsigned int id)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    // verifica se a alocação foi bem sucedida
    if (newNode == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // copia o nome para o novo nó
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->next = NULL;

    // verifica se a fila está vazia
    // se estiver, o novo nó será o primeiro e o último
    // senão, o novo nó será o último
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Nova pessoa para ser atendida: %s (ID: %d)\n", name, id);
}

void dequeue(Queue* queue)
{
    // verifica se a fila está vazia
    if (queue->front == NULL)
    {
        printf("A fila está vazia.\n");
        return;
    }

    // remove o primeiro nó da fila
    Node* temp = queue->front;
    queue->front = queue->front->next;

    // verifica se a fila ficou vazia
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    printf("Pessoa atendida: %s (ID: %d)\n", temp->name, temp->id);
    free(temp);
}

void displayQueue(const Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("A fila está vazia!\n");
        return;
    }

    Node* temp = queue->front;

    // percorre a fila e exibe os clientes
    while (temp != NULL)
    {
        printf("Nome: %s (ID: %d)\n", temp->name, temp->id);
        temp = temp->next;
    }
}

void freeQueue(Queue* queue)
{
    Node* temp = NULL;

    // libera a memória alocada para cada nó da fila
    while (queue->front != NULL)
    {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    queue->rear = NULL;
}

void displayFront(const Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Primeira pessoa da fila: %s (ID: %d)\n", queue->front->name, queue->front->id);
}

void displayRear(const Queue* queue)
{
    if (queue->rear == NULL)
    {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Última pessoa da fila: %s (ID: %d)\n", queue->rear->name, queue->rear->id);
}

void isEmpty(const Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("A fila está vazia!\n");
    }
    else
    {
        printf("A fila não está vazia!\n");
    }
}

void size(const Queue* queue)
{
    int count = 0;
    Node* temp = queue->front;

    // percorre a fila e conta o número de clientes
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Tamanho da fila: %d\n", count);
}

void displayAt(const Queue* queue, const unsigned int position)
{
    if (queue->front == NULL)
    {
        printf("A fila está vazia!\n");
        return;
    }

    int count = 0;
    Node* temp = queue->front;

    // percorre a fila até a posição desejada
    while (temp != NULL && count < position)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Posição inválida!\n");
    }
    else
    {
        printf("Pessoa na posição %d: %s (ID: %d)\n", position, temp->name, temp->id);
    }
}
