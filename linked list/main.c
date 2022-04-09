/*
 \file main.c
 \Author Bernal Mondragon Humberto
 \Version 1.1
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const * argv[]){
    struct list * list = (struct list *)malloc(sizeof(struct list));
    insertstart(list,4);
    insertfinal(list, 5);
    insertfinal(list, 6);
    insertfinal(list, 7);
    insertfinal(list, 8);
    insert_nposition(list, 9,6);
    insert_nposition(list,71,4);
    insert_nposition(list,40,1);
    show(list);

    deletestart(list);
    show(list);

    insert_nposition(list,41,1);
    insert_nposition(list,42,2);
    show(list);

    deletestart(list);
    deletestart(list);
    deletefinal(list);
    show(list);

    printf("La lista contiene: %d elementos\n", list->length);

    delete_nposition(list, 6);
    delete_nposition(list, 4);
    delete_nposition(list, 6);
    
    show(list);
    deletefinal(list);
    deletefinal(list);
    show(list);
    free(list);

    return 0;
}