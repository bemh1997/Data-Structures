/*
 \file main.c
 \Author Bernal Mondragon Humberto
 \Version 1.0
 \Date 09 / 04 /2022
 \Copyright GNU Public License v3
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char const * argv[]){
    
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    unsigned int data=0;
    int length = 0;
    int pops;

    push((struct stack *)&q->stack1, 0);
    push((struct stack *)&q->stack1, 1);
    push((struct stack *)&q->stack1, 2);
    push((struct stack *)&q->stack1, 3);
    push((struct stack *)&q->stack1, 4);
    pops = pop((struct stack *)&q->stack1);
    pops = pop((struct stack *)&q->stack1);
    data = peak((struct stack *)&q->stack1);
    length = slength((struct stack *)&q-> stack1);
    printf("Peak: %d \n", data);
    printf("Length: %d \n", length);

    showstack(q);
    printf("\n");
    //showstack(q);
    //pops = pop((struct stack *)&q->stack1);
    Clearstack((struct stack *)&q->stack1);
    showstack(q);
}