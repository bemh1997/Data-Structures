/*
 \file stack.h
 \Author Bernal Mondragon Humberto
 \Version 1.0
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3.
 
 Definición del tipo de dato struct stack,
 así como las funciones.
 El tamaño crece al doble cada que se llena 
 y se reduce a la mitad cuando está desocupado
 la mitad del espacio.
*/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
//Structs
struct node{
    int data;
    struct node * down;
    
};

struct stack{
    struct node* peak;
    unsigned int length;
};

struct queue
{
    struct stack * stack1;
    struct stack * stack2;
};

//node
struct node * Createnode(int data);
void deletenode(struct node* nodo);

//stack functions
void push(struct stack* stack, int data);
int pop(struct stack* stack);
int peak(struct stack* stack);
int slength(struct stack * stack);
void showstack(struct queue* queue);

//clear stack
void Clearstack(struct stack* stack);

#endif