/*
 \File stack.c
 \Author Bernal Mondragon Humberto
 \Version 1.0
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una stack de memoria contigua: 
 + Insertar:
    -Push.
 + Eliminar:   
    -Pop.
 + Mostrar:
    -Peak (muestra la cima del stack).
    -showstack(muestra la pila completa)
        Comentario: Es de orden 2N debido a se posiciona
        en otra pila para mostrarse completa y luego vuelve a su origen.
 + Clear stack.
    -Limpia el stack.
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
//node
struct node * Createnode(int data){
    struct node * nodo = (struct node*)malloc(sizeof(struct node));
    nodo->data= data;
    nodo->down = NULL;
    return nodo;
}

void deletenode(struct node* nodo){
    free(nodo);
}
//stack functions
void push(struct stack * stack, int data){
    struct node* nodo = Createnode(data);
    if(!nodo){
        printf("Stack overflow\n");
        getchar();
        exit(0);
    }
    nodo->down= stack->peak;
    stack->peak = nodo;
    stack->length++;
}

int pop(struct stack * stack){
    if(stack->peak){
        int res;
        struct node * deleted = stack ->peak;
        res = deleted ->data;
        stack->peak = stack ->peak-> down; 
        deletenode(deleted);
        stack->length--;
        return res;
    }else{
        printf("Stack underflow\n");
        getchar();
        exit(0);
    }
}

int peak(struct stack * stack){
    if(!stack->peak){
        return 0;
    }else{
        return  stack->peak->data;
    }
}

int slength(struct stack * stack){
    return stack ->length;
}

void showstack(struct queue* q){
    int length = slength((struct stack *)&q-> stack1);
    int x,y;
    if(q->stack1 == NULL &&q->stack2== NULL){
        printf("Q is empty\n");
        getchar();
        exit(0);
    }

    do{
        x = pop((struct stack *)&q-> stack1);
        push((struct stack *)&q-> stack2, x);
        y = peak((struct stack *)&q-> stack2);
        if(length==1){
            printf("%d\n", y);
        } else{
            printf("%d\n",y);
            printf("↓\n");
        }
        length--;
    }while(length > 0);
    //Returning to the stack origin.
    length = slength((struct stack *)&q-> stack2);
    do{
        x = pop((struct stack *)&q-> stack2);
        push((struct stack *)&q-> stack1, x);
        length--;
    }while(length > 0);
}

//Clear Stack
void Clearstack(struct stack * stack){
    int pops;
    while (stack->peak)
    {
        pops = pop(stack);
    }
}