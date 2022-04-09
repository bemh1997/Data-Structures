/*
 \file list.h
 \Author Bernal Mondragon Humberto
 \Version 1.1
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3.
 
 Definición del tipo de dato struct List,
 así como las funciones.
 Contigua es una lista donde la memoria
 se reserva con malloc para que se puedan
 tener los datos de forma contigua,
 como un arreglos.
 El tamaño crece al doble cada que se llena 
 y se reduce a la mitad cuando está desocupado
 la mitad del espacio.
*/
#ifndef __LIST_H_
#define __LIST_H_

#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct list{
    struct node * head;
    unsigned int length;
};
//node functions
struct node* Createnode(int data);
void deletenode(struct node* nodo);

//insert functions
void insertstart(struct list* list, int data);
void insertfinal(struct list* list, int data);
void insert_nposition(struct list* list, int data, int n);

//delete functions
void deletestart(struct list* list);
void deletefinal(struct list* list);
void delete_nposition(struct list* list, int n);

//show function
void show(struct list* list);

#endif