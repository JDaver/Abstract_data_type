#include "../Headers/priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

//MAX HEAP 

static int isEmpty(priorityQueue* q){
    if(q->size == 0) return 1;
    else return 0;
}

static int isFull(priorityQueue* q){
    if(q->size < q->capacity) return 0;
    else return 1;
}

void initPQ(priorityQueue* q, int max){
    q->array = malloc(max*sizeof(int));
    q->capacity = max;
    q->size = 0;
}

void printPQ (priorityQueue* q){
    for(int i =0; i< q->size; i++){
        printf(" elem: %d\n",q->array[i]);
    }
}
priorityQueue* insert(priorityQueue* q, int val){
    int i = q->size;
    int tmp = 0;
    if (isFull(q)==1) {
        return q;
    }
    q->array[i] = val;
    q->size++;
    
    while((i != 0) && (q->array[(i - 1) / 2] < q->array[i])){
        if(q->array[i]>q->array[(i-1)/2]){
            tmp = q->array[i];
            q->array[i] = q->array[(i-1)/2];
            q->array[(i-1)/2] = tmp;
            i = (i-1)/2;
        }
    }
    return  q;
}

