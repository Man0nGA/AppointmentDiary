#include "diary.h"
#include <stdlib.h>
#include <stdio.h>

//to be modify !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
//Part 1

//global variable telling us if the value was found
int a = 0;
int* found = &a; //global variable, which save the state of the search in search functions
int b = 0;
int* ind = &b; //global variable used in search functions, to save the index of the cells that has already been checked

//create a cell with as parameters rendez-vous "val" and the number of pointers "MaxLevelPointer"
t_d_cell_rdv* CreateCell(rdv val, int MaxLevelPointer){
    t_d_cell_rdv *newCell = (t_d_cell_rdv*)malloc(sizeof(t_d_cell_rdv));
    newCell->value = val;
    newCell->MaxLevelNext = MaxLevelPointer;
    newCell->next = (t_d_cell_rdv**) malloc(sizeof(t_d_cell_rdv*) * MaxLevelPointer);
    for (int i=0;i<MaxLevelPointer;i++){
        newCell->next[i]=NULL;
    }
    return newCell;
}

//create a list with, as parameters, the maximum number of levels this list can have
// Create a list of cells with, some rendez-vous inside the cells
t_d_list_rdv* CreateList(int MaxLevelHead){
    t_d_list_rdv *LevelList = (t_d_list_rdv*)malloc(sizeof(t_d_list_rdv)); //allocate memory for the list that's going to be filled with rendez-vous
    LevelList->MaxLevelHead = MaxLevelHead;
    LevelList->head = (t_d_cell_rdv**) malloc(sizeof(t_d_cell_rdv*) * MaxLevelHead); //allocate memory for the list of heads
    for (int i=0;i<MaxLevelHead;i++){
        LevelList->head[i]=NULL; //initialise every head to NULL beecause the list is empty right now
    }
    return LevelList;
}

//if it is possible, we insert a given cell into the list at the HEAD
void InsertCell(t_d_list_rdv* list, t_d_cell_rdv* cell) {
    if (cell->MaxLevelNext > list->MaxLevelHead) {
        printf("The cell to be inserted has too many levels!");
        return;
    }
    for(int i=0; i<cell->MaxLevelNext; i++) { //using a loop, then, every heads points toward the cell
        cell->next[i] = list->head[i];
        list->head[i] = cell;
    }
}

//display all the cell of a list at a level given
void DisplayLevel(t_d_list_rdv list, int level){
    if(level>list.MaxLevelHead){
        printf("This level doesn't exist in the list.");
        return;
    }
    printf("[list head_%d @-]-->", level);
    t_d_cell_rdv* temp = list.head[level];
    while(temp!=NULL){
        printf("[%s|@]-->", temp->value);
        temp = temp->next[level];
    }
    printf("NULL\n");
}

//display all the cell of a list at all levels
void DisplayList(t_d_list_rdv list) {
    for(int i=0; i<list.MaxLevelHead; i++){
        DisplayLevel(list, i);
    }
}

//if it is possible (not too many levels), we insert a given cell in a list with all values sorted
void InsertSortCell(t_d_list_rdv* list, t_d_cell_rdv* cell) {
    if (cell->MaxLevelNext > list->MaxLevelHead) { //too many levels
        printf("The cell to be inserted has too many levels!");
        return;
    }
    for(int i=0; i<cell->MaxLevelNext; i++) { //the list is empty
        if(list->head[i]==NULL){
            list->head[i] = cell;
            return;
        }
        t_d_cell_rdv *temp = list->head[i];
        t_d_cell_rdv *prev = list->head[i];
        while (temp != NULL && temp->value < cell->value) {  //find the place to insert
            prev = temp;
            temp = temp->next[i];
        }
        cell->next[i] = temp; //insertion
        prev->next[i] = cell;
    }
}

//Part 2

//search a given value in the level zero from a given list
t_d_cell_rdv* ClassicSearch(t_d_list_rdv* list, int val, t_d_cell_rdv* prev){
    t_d_cell_rdv* temp = list->head[*ind];
    while(temp!=NULL && val<=(temp->value)){
        if(temp->value==val){
            *found = 1;
            return temp;
        }
        prev = temp;
        temp = temp->next[*ind];
    }
    if(temp==NULL)return temp;
    if(temp->value>val){
        return prev;
    }
    return NULL;
}

//search a given value beginning from the highest level
t_d_cell_rdv* Search(t_d_list_rdv* list, int val) {
    t_d_cell_rdv* prev = list->head[list->MaxLevelHead];
    *ind = list->MaxLevelHead-1;
    t_d_cell_rdv* pointer = NULL;
    while(*ind>=0 && *found==0){
        pointer = ClassicSearch(list, val, prev);
        (*ind)--;
    }
    if(*found==1){
        return pointer;
    }
    return NULL;
}
 */