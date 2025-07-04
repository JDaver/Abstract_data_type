#include <stdio.h>
#include <stdlib.h>
#include "../Headers/stack.h"

/*
typedef struct{
    int max;
    int top;
    int *v;
} Stack;
*/

void init(Stack* s,int max){
    s->v = malloc(max * sizeof(int));
    if (s->v == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    s->max = max;
    s->top = EMPTY;
}

int top(Stack* s){
    if(s->top != EMPTY){
        return s->v[s->top];
    }
}

Stack * push(Stack* s,int val){
    if(s->top>= s->max -1){
        printf("Stack overflow!\n");
        return s;
    }
    s->top = s->top + 1;
    s->v[s->top] = val; 
    return s;
}

Stack* pop(Stack* s){
    if(isEmpty(s)<0){
        printf("Stack gia vuoto.");
        return s;
    }
    s->v[s->top] = 0;
    s->top--;
    return s;
}

int isEmpty(Stack* s){
    if(s->top == -1){
        return -1;;
    }
    return 1;
}