/*
 \File list.c
 \Author Bernal Mondragon Humberto
 \Version 1.1
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3.
 Implementación de las funciones básicas
 de una lista de memoria contigua: 
 + Insertar:
    -Principio.
    -Final.
    -Posición n.
 + Eliminar:   
    -Principio.
    -Final.
    -Posición n.
 + Mostrar
 + Free list(Comentario: este último no libera completa la lista, queda determinar la razón)
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

//node functions
struct node *Createnode(int data){
    struct node* nodo = (struct node*)malloc(sizeof(struct node));
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}

void deletenode(struct node* nodo){
    free(nodo);
}

//insert functions
void insertstart(struct list* list, int data){
    struct node* nodo = Createnode(data);
    nodo->next = list->head;
    list->head = nodo;
    list->length++;
}

void insertfinal(struct list* list, int data){
    struct node* nodo = Createnode(data);
    if(!list->head){
        list->head = nodo;
    } else{
        struct node* pointer = list->head;
        while(pointer->next){
            pointer = pointer->next; 
        }
        pointer->next = nodo;
    }
    list->length++;
}

void insert_nposition(struct list* list, int data, int n){
    struct node* nodo = Createnode(data);
    struct node* pointer = list->head;

    if(!list->head){
        list->head = nodo;
        printf("No existe la cabeza de lista. Se insertará en la posición inicial.\n");         
        
    }else if(n<=1){
        nodo->next = list->head;
        list->head = nodo;
    }else{
        int count=1;
        while (count < n-1 && pointer->next)
        {
            count++;
            pointer= pointer->next;
        }
        if(count==n-1){
            nodo->next = pointer->next;
            pointer -> next = nodo;
        }else if(!pointer->next){
            pointer->next = nodo;
            printf("No existe la posicion: %d. Se insertará en la posición más próxima.\n", n);
        }
    }
    list->length++;
}

//delete functions
void deletestart(struct list* list){
    if(list->head){
        struct node * deleted = list->head;
        list-> head = list ->head ->next;
        deletenode(deleted);
        list->length--;
    }        
}

void deletefinal(struct list* list){
    if(list->head){  
        if(list->head->next){  
            struct node * pointer = list->head;
            while(pointer->next->next){
                pointer = pointer->next;
            }
            struct node * deleted = pointer ->next;
            pointer ->next = NULL;
            deletenode(deleted);
        }else{
            struct node * deleted = list ->head;
            list ->head = NULL;
            deletenode(deleted);
        }
        list->length--;
    }
}

void delete_nposition(struct list* list, int n){
    if(list->head){
        if(n<=1){
            struct node* deleted = list->head;
            list->head =list->head->next;
            deletenode(deleted);
        }else if(n <= list->length){
            struct node * pointer= list->head;
            int count=1;
            for(count=1; count < n-1; count++)
            {
                pointer= pointer->next;
            }
            struct node * deleted = pointer->next;
            pointer -> next = deleted ->next;
            deletenode(deleted);
        }else{
                deletefinal(list);
                printf("No existe la posicion: %d. Se eliminó la útlima posición.\n", n);
        }
        list->length--;
    }
}


//show function
void show(struct list* list){
    struct node * pointer = list->head;
    while(pointer->next){
        printf("%d->", pointer->data);
        pointer = pointer->next;
    }
    printf("%d\n", pointer->data);
}

