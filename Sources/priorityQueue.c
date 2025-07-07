#include "../Headers/priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void heapify(int* array, int i,int size){
    int tmp = 0;
    while(1){
        int largest = i;
        int left = 2*i +1;
        int right = 2*i +2;

        if(left < size && array[left] > array[largest]){
            largest = left;
        }
        if(right < size && array[right] > array[largest]){
            largest = right;
        }

        if(largest!=i){
            tmp = array[i];
            array[i] = array[largest];
            array[largest] = tmp;
            i = largest;
        }else{
            break;
        }
        }
    }

priorityQueue* buildHeap (int* array, int size){
    int parent = (size - 1)/2;
    priorityQueue* newQ = malloc(sizeof(priorityQueue));
    initPQ(newQ, size);
    while (parent>=0) {
        heapify(array, parent, size);
        parent--;
    }
    newQ->array = malloc(size * sizeof(int));
    memcpy(newQ->array,array, size * sizeof(int));
    newQ->size = size;
    return newQ;
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
     if (isFull(q)==1) {
        return q;
    }
    int i = q->size;
    int parent = (i-1)/2;
    q->array[i] = val;
    q->size++;
    
    while((i != 0) && (q->array[parent] < q->array[i])){
        int tmp = q->array[i];
        q->array[i] = q->array[parent];
        q->array[parent] = tmp;
        i = parent;
        parent=(i-1)/2;  
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
    heapify(q->array,0,q->size);
    return q;
}

void deletePQ(priorityQueue** q){
    if(q && *q){
        free((*q)->array);
        free(*q);
        *q = NULL;
    }
    
}


