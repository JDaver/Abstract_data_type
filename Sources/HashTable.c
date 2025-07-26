
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/HashTable.h"

#define MAX_NAME_BUFFER 64

//HashTable AdjList collision method


/*STATIC METHODS */
 static AdjList* ScrollingCollision(AdjList* head){
    if(head == NULL) return NULL;

    AdjList* current = head;
    while(current != NULL) {
        if(current->name[0]=='\0') return current;
        if(current->next == NULL) break;
        current = current->next;
    }

    current->next = (AdjList*)malloc(sizeof(AdjList));
    if (current->next == NULL) return NULL;
    current = current->next;
    current->name[0] = '\0';
    current->next = NULL;
 
    return current;
 }


void initHashTable(HashMap* newHash, int size){
    if(size == 0){
        printf("ERROR: Invalid size number given, size must be major than 0.\n");
        return ;
    }
    int i = 0;
    int j =0;
    newHash->array = (AdjList**)malloc(size*sizeof(AdjList*));
    if(newHash->array==NULL) goto allocError;
    newHash->size = size; 

    for(i=0; i<size; i++){
        newHash->array[i] = (AdjList*)malloc(sizeof(AdjList));
        if(newHash->array[i] == NULL) goto allocError;

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

int Insert(HashMap* hash, char* newName, int val, int key){
    if(strlen(newName)>MAX_NAME_BUFFER){
        printf("Error: the given name is too long!\n");
        return 0;
    }
    //key calculation
    int newKey = key % hash->size;
    AdjList* element = ScrollingCollision(hash->array[newKey]);
    if (element == NULL) {
        printf("Error during allocation!\n");
        return 0;
    }

    strcpy(element->name ,newName);
    element->val = val;
    return 1;
}


void printHashMap(HashMap* Hash){
    for(int i = 0; i < Hash->size; i++){
        AdjList* current = Hash->array[i];
        printf("---element %d: ",i);
        while (current!=NULL) {
            if(current->name[0] == '\0') break;
            printf("name: %s  value: %d\n",current->name,current->val);
            current = current->next;
        }
        printf("**************************\n");
    }
}

