#include "set.h"
#include <stdlib.h>
#include <stdio.h>

//global variable telling us if the value was found
int a = 0;
int* found = &a;
int b = 0;
int* i = &b;

//create a cell with parameters a value and the number of pointers
t_d_cell* CreateCell(int val,int MaxLevelPointer){
    t_d_cell *newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    newCell->value = val;
    newCell->MaxLevelNext = MaxLevelPointer;
    newCell->next = (t_d_cell**) malloc(sizeof(t_d_cell*)*MaxLevelPointer);
    for (int i=0;i<MaxLevelPointer;i++){
        newCell->next[i]=NULL;
    }
    return newCell;
}

//create a list with parameters the maximum number of levels this list can have
t_d_list* CreateList(int MaxLevelHead){
    t_d_list *LevelList = (t_d_list*)malloc(sizeof(t_d_list));
    LevelList->MaxLevelHead = MaxLevelHead;
    LevelList->head = (t_d_cell**) malloc(sizeof(t_d_cell*)*MaxLevelHead);
    for (int i=0;i<MaxLevelHead;i++){
        LevelList->head[i]=NULL;
    }
    return LevelList;
}

void InsertCell(t_d_list* list, t_d_cell* cell) {
    if (cell->MaxLevelNext > list->MaxLevelHead) {
        printf("The cell to be inserted has too many levels!");
        return;
    }
    for(int i=0; i<cell->MaxLevelNext; i++) {
        cell->next[i] = list->head[i];
        list->head[i] = cell;
    }
}

void DisplayLevel(t_d_list list, int level){
    if(level>list.MaxLevelHead){
        printf("This level doesn't exist in the list.");
        return;
    }
    printf("[list head_%d @-]-->", level);
    t_d_cell* temp = list.head[level];
    while(temp!=NULL){
        printf("[%d|@]-->", temp->value);
        temp = temp->next[level];
    }
    printf("NULL\n");
}

void DisplayList(t_d_list list) {
    for(int i=0; i<list.MaxLevelHead; i++){
        DisplayLevel(list, i);
    }
}

void InsertSortCell(t_d_list* list, t_d_cell* cell) {
    if (cell->MaxLevelNext > list->MaxLevelHead) {
        printf("The cell to be inserted has too many levels!");
        return;
    }
    for(int i=0; i<cell->MaxLevelNext; i++) {
        if(list->head[i]==NULL){
            list->head[i] = cell;
            return;
        }
        t_d_cell *temp = list->head[i];
        t_d_cell *prev = list->head[i];
        while (temp != NULL && temp->value < cell->value) {
            prev = temp;
            temp = temp->next[i];
        }
        cell->next[i] = temp;
        prev->next[i] = cell;
    }
}

t_d_cell* ClassicSearch(t_d_list* list, int val, t_d_cell* prev){
    t_d_cell* temp = list->head[*i];
    while(temp!=NULL && val<=temp->value){
        if(temp->value==val){
            *found = 1;
            return temp;
        }
        prev = temp;
        temp = temp->next[*i];
    }
    if(temp->value>val){
        return prev;
    }
    return NULL;
}

//
t_d_cell* Search(t_d_list* list, int val) {
    t_d_cell* prev = list->head[list->MaxLevelHead];
    *i = list->MaxLevelHead;
    t_d_cell* pointer = NULL;
    while(*i>=0 && *found==0){
        pointer = ClassicSearch(list, val, prev);
        (*i)--;
    }
    if(*found==1){
        return pointer;
    }
    return NULL;
}