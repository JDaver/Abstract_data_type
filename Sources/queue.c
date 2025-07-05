#include "../Headers/queue.h"
#include <stdio.h>
#include <stdlib.h>



static int isEmpty(Queue* q){
    if(q->size == 0) return 1;
    else return 0;
}

void printQueue(Queue* q){
    int length = q->size;
    int index = q->front;

    while(length>0){
        printf("Valore = %d\n", q->array[index]);
        index = (index + 1) % q->capacity;
        length--;
    }
}

void initQueue(Queue* q, int max){
    q->capacity = max;
    q->array = malloc(max * sizeof(int));
    q->front = EMPTY;
    q->rear = EMPTY;
    q->size = 0;
}

Queue* enqueue(Queue* q, int val){
    if(q->size == q->capacity){
        return q;
    }else if (isEmpty(q) == 1 ) {
        q->front = 0;
        q->rear = 0;
    }
    q->size++;
    q->array[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    printf(" rear = %d \n",q->rear);
    return q;
}

Queue* dequeue(Queue* q){  
    if(isEmpty(q)==1){
        return q;
    }
    if (q->size==1){
        q->front = EMPTY;
        q->rear = EMPTY;
        q->size = 0;
    }else{
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }

    return q;
}




