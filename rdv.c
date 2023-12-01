#include "rdv.h"
#include <stdlib.h>
#include <stdio.h>


//global variable telling us if the value was found
int a = 0;
int* found = &a; //global variable, which save the state of the search in search functions
int b = 0;
int* ind = &b; //global variable used in search functions, to save the index of the cells that has already been checked

/*
//create a rendez-vous
//est-ce qu'on met les scanfs dans create rdv ???????????????????????????????????????????????????????????????????????????????????????????
rdv* Create_rdv(){
    rdv* newrdv = (rdv*)malloc(sizeof(rdv));
    newrdv->date = scanf();
    newrdv->time = scanf();
    newrdv->duration = scanf();
    newrdv->purpose = scanf();
}
*/

//create a cell with as parameters rendez-vous "val" and the number of pointers "MaxLevelPointer"
t_d_cell_rdv* CreateCell_rdv(rdv val, int MaxLevelPointer){
    t_d_cell_rdv *newCell = (t_d_cell_rdv*)malloc(sizeof(t_d_cell_rdv));
    newCell->value = val;
    newCell->next = NULL;
    return newCell;
}

// Create a list of cells with, some rendez-vous inside the cells
t_d_list_rdv* CreateList_rdv(int MaxLevelHead){
    t_d_list_rdv *LevelList = (t_d_list_rdv*)malloc(sizeof(t_d_list_rdv)); //allocate memory for the list that's going to be filled with rendez-vous
    LevelList->head = NULL; //initialise the list to NULL
    return LevelList;
}

//if it is possible, we insert a given cell into the list at the HEAD
void InsertCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell) {
    cell->next = list->head;
    list->head = cell;
}

void display_rdv(t_d_cell_rdv cell){
    //calcul of the end time of the appointment
    int hour_end = (cell.value.duration[1]+cell.value.time[1])%60 + (cell.value.duration[0]+cell.value.time[0])%24;
    int minute_end = (cell.value.duration[1]+cell.value.time[1])-(cell.value.duration[1]+cell.value.time[1])%60;
    printf("%s apointement the %d/%d/%d from %d:%d to %d:%d.\n",
           *(cell.value.purpose), cell.value.date[0], cell.value.date[1], cell.value.date[2], cell.value.time[0], cell.value.time[1], hour_end, minute_end);
}

void display_all_rdv(t_d_list_rdv list){
    t_d_cell_rdv* temp = list.head;
    if(temp==NULL){
        printf("No appointment !");
    }
    else {
        while (temp != NULL) {
            display_rdv(*temp);
            temp = temp->next;
        }
    }
}

/*
//if it is possible (not too many levels), we insert a given cell in a list with all values sorted
void InsertSortCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell) {
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