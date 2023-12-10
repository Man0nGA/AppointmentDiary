#include "rdv.h"
#include <stdlib.h>
#include <stdio.h>


//create a rendez-vous
rdv* Create_rdv(){
    rdv* newrdv = (rdv*)malloc(sizeof(rdv));
    newrdv->purpose = (char*)malloc(sizeof(char));
    printf("Enter the information to create an appointment.\n");
    printf("date : JJ/MM/AAAA\n");
    scanf("%d/%d/%d", &newrdv->date[0], &newrdv->date[1], &newrdv->date[2]);
    printf("time : HOURS:MINUTES\n");
    scanf("%d:%d", &newrdv->time[0], &newrdv->time[1]);
    printf("duration : HOURS:MINUTES\n");
    scanf("%d:%d", &newrdv->duration[0], &newrdv->duration[1]);
    printf("purpose : appointment_purpose\n");
    scanf("%s", newrdv->purpose);
    return newrdv;
}

//create a cell with as parameters rendez-vous "val" and the number of pointers "MaxLevelPointer"
t_d_cell_rdv* CreateCell_rdv(){
    t_d_cell_rdv *newCell = (t_d_cell_rdv*)malloc(sizeof(t_d_cell_rdv));
    newCell->value = *Create_rdv(); //create a rdv and assign it to the value of the cell
    newCell->next = NULL;
    return newCell;
}

// Create a list of cells with, some rendez-vous inside the cells
t_d_list_rdv* CreateList_rdv(){
    t_d_list_rdv *LevelList = (t_d_list_rdv*)malloc(sizeof(t_d_list_rdv)); //allocate memory for the list that's going to be filled with rendez-vous
    LevelList->head = NULL; //initialise the list to NULL
    return LevelList;
}

//we insert a given cell into the list at the HEAD
void InsertCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell) {
    cell->next = list->head;
    list->head = cell;
}

//display the rdv contained in the cell given as parameter
void Display_rdv(t_d_cell_rdv cell){
    //calcul of the end time of the appointment
    int hour_end = (cell.value.duration[1]+cell.value.time[1])/60 + cell.value.duration[0]+cell.value.time[0]%24;
    int minute_end = (cell.value.duration[1]+cell.value.time[1])-(cell.value.duration[1]+cell.value.time[1])/60;
    printf("%s appointment, the %d/%d/%d, from %d:%d to %d:%d.\n",
           cell.value.purpose, cell.value.date[0], cell.value.date[1], cell.value.date[2], cell.value.time[0], cell.value.time[1], hour_end, minute_end);
}

//display all the rdv of a list of rdv
void Display_all_rdv(t_d_list_rdv list){
    t_d_cell_rdv* temp = list.head;
    if(temp==NULL){
        printf("No appointment !\n");
    }
    else {
        printf("List of appointment :\n");
        while (temp != NULL) {
            Display_rdv(*temp);
            temp = temp->next;
        }
    }
}
