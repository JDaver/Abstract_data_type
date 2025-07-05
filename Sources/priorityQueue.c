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

static int isSet(priorityQueue* q){
    if(q==NULL) return 0;
    else return 1;
}

static void heapify(priorityQueue* q, int i){
    int tmp = 0;
    while(1){
        int largest = i;
        int left = 2*i +1;
        int right = 2*i +2;

        if(left < q->size && q->array[left] > q->array[largest]){
            largest = left;
        }
        if(right < q->size && q->array[right] > q->array[largest]){
            largest = right;
        }

        if(largest!=i){
            tmp = q->array[i];
            q->array[i] = q->array[largest];
            q->array[largest] = tmp;
            i = largest;
        }else{
            break;
        }
        }
    }


void initPQ(priorityQueue* q, int max){
    q->array = malloc(max*sizeof(int));
    q->capacity = max;
    q->size = 0;
}

void printPQ (priorityQueue* q){
    if(isSet(q)==0){
        printf("the priorityQueue does not exist!\n");
        return;
    } 
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

priorityQueue* extractMax(priorityQueue* q){
    if(isEmpty(q)==1){
        printf("Error, data structure is empty\n");
        return q;
    }
    q->size--;
    q->array[0] = q->array[q->size];
    heapify(q,0);
    return q;
}

void deletePQ(priorityQueue** q){
    if(q && *q){
        free((*q)->array);
        free(*q);
        *q = NULL;
    }
    
}


