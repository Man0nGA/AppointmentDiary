#include "diary.h"
#include <stdlib.h>
#include <stdio.h>

//create a contact
contact* CreateContact(){
    contact* newcontact = (contact*)malloc(sizeof(contact));
    printf("Enter informations to create a new contact.\n");
    printf("firstname : \n");
    scanf("%s", newcontact->firstname);
    printf("surname : \n");
    scanf("%s", newcontact->surname);
    return newcontact;
}

//create a diary for a given contact
diary* CreateDiary(contact person){
    diary* newdiary = (diary*)malloc(sizeof(diary));
    newdiary->person = person;
    newdiary->list_rdv = NULL;
    return newdiary;
}

//create a diary cell
t_d_cell_diary* CreateCellDiary(){
    t_d_cell_diary *newCell = (t_d_cell_diary*)malloc(sizeof(t_d_cell_diary));
    newCell->value = *CreateDiary(*CreateContact());
    newCell->MaxLevelNext = 4;
    newCell->next = NULL;
    return newCell;
}

//create a diary list
t_d_list_diary* CreateListDiary(){
    t_d_list_diary *LevelList = (t_d_list_diary*)malloc(sizeof(t_d_list_diary)); //allocate memory for the list that's going to be filled with diaries
    LevelList->MaxLevelHead = 4; //the max level of all the diary lists is four (given in subject paper)
    LevelList->head = NULL; //initialise the list to NULL
    return LevelList;
}

//add a rdv in the diary cell given
void Add_rdv_InCellDiary(t_d_cell_diary* d, t_d_cell_rdv* r){
    if(d->value.list_rdv->head ==NULL){ //test if the list of rdv is empty
        d->value.list_rdv->head = r;
    }
    else{
        t_d_cell_rdv* temp = d->value.list_rdv->head;
        while(temp->next!=NULL){
            temp = temp->next; //add the rdv cell at the end of the list
        }
        temp->next = r;
    }
}

/*
//search a given value in the list
//argument : the list, the value we are looking for
//we go through the entire list from the highest level to 0 (level 0 = all the cells).
//We return the cell in which the value has been found
t_d_cell_diary * ContactSearch(t_d_list_diary * list, contact c)
{
    //get the first char of the contact


    // Get the head of the last level
    int found = 0; //boolean to know if the value has been found
    int level = (list->MaxLevelHead)-1;
    t_d_cell_diary * temp = list->head[level] ;
    t_d_cell_diary * prev = temp;
    while(level >= 0 && found==0)
    {
        //careful : check if temp != NULL, otherwise, can't compare with val
        if(temp != NULL && temp->value==val) //if the value of cell temp corresponds to val
        {
            found = 1;
            break;
        }
        else //if the value is not found, change temp
        {
            if(temp==NULL || temp->value>val)
            {
                temp = list->head[--level];//go to higher level
            }
            else
            {
                temp = temp->next[level];

            }
        }
    }

    if(found==1)
    {
        printf("The value %d has been found\n", temp->value);
        return temp;
    }
    else
    {
        printf("The value %d has not been found : (\n", val);
        return NULL;
    }
}
*/

//display all the contacts in the list
//we can change the display if we want to, this one is not required
//it is for us to better understand what's going on
void Display_DiaryList(t_d_list_diary l){
    for(int level=0; level<l.MaxLevelHead; level++){
        printf("[list head_%d @-]-->", level);
        t_d_cell_diary * temp = l.head[level];
        while(temp!=NULL){
            printf("[%s|@]-->", temp->value.person.surname);
            temp = temp->next[level];
        }
        printf("NULL\n");
    }
}

//display the rdv of a given contact
//void Display_Contact_rdv_FromList(t_d_list_diary l, contact c);



//to be modify !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*

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
*/