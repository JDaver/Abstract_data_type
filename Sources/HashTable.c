
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/HashTable.h"

#define MAX_NAME_BUFFER 15

//HashTable AdjList collision method


AdjList** initHashTable(int size){
    int i = 0;
    int j =0;

    AdjList** newHash = (AdjList**)malloc(size*sizeof(AdjList*));
    if(newHash==NULL) goto allocError;

    for(i=0; i<size; i++){
        newHash[i] = (AdjList*)malloc(sizeof(AdjList));
        if(newHash[i] == NULL) goto allocError;

        newHash[i]->name = (char*)malloc(MAX_NAME_BUFFER*sizeof(char));
        if(newHash[i]->name == NULL) goto allocError;

        newHash[i]->name[0] = '\0';
        newHash[i]->next = NULL;
    }

    return newHash;

    allocError:
    printf("Error during allocation!\n");
    for(j=0; j<i; j++){
        if(newHash[j]){
            free(newHash[j]->name);
            free(newHash[j]);
        }
    }
    free(newHash);
        return NULL;
}

void Insert(AdjList** list,char* name, int val, int key){
    //TODO:
    //key calculation ---->   key % sizeOf(adjList*)
    //check for collision  ----> call a collision handler function() to manage the corrrect insert 
}