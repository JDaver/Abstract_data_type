
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/HashTable.h"

#define MAX_NAME_BUFFER 15

//HashTable AdjList collision method

void initHashTable(HashMap* newHash, int size){
    int i = 0;
    int j =0;
    newHash->array = (AdjList**)malloc(size*sizeof(AdjList*));
    if(newHash->array==NULL) goto allocError;

    for(i=0; i<size; i++){
        newHash->array[i] = (AdjList*)malloc(sizeof(AdjList));
        if(newHash->array[i] == NULL) goto allocError;

        newHash->array[i]->name = (char*)malloc(MAX_NAME_BUFFER*sizeof(char));
        if(newHash->array[i]->name == NULL) goto allocError;

        newHash->array[i]->name[0] = '\0';
        newHash->array[i]->next = NULL;
    }

    return ;

    allocError:
    printf("Error during allocation!\n");
    for(j=0; j<i; j++){
        if(newHash->array[j]){
            free(newHash->array[j]->name);
            free(newHash->array[j]);
        }
    }
    free(newHash->array);
        return ;
}

void Insert(AdjList** list,char* name, int val, int key){
    //TODO:
    //key calculation ---->   key % sizeOf(adjList*)
    //check for collision  ----> call a collision handler function() to manage the corrrect insert 
}

