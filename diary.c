#include "diary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//create a contact
contact* CreateContact(){
    contact* newcontact = (contact*)malloc(sizeof(contact));
    printf("Enter information to create a new contact.\n");
    printf("firstname : \n");
    scanf("%s", newcontact->firstname);
    printf("surname : \n");
    scanf("%s", newcontact->surname);
    return newcontact;
}

//create a diary for a given contact
diary* CreateDiary(){
    diary* newdiary = (diary*)malloc(sizeof(diary));
    newdiary->person = *CreateContact();
    newdiary->list_rdv = CreateList_rdv();//initialise list_rdv with an empty list of rdv
    return newdiary;
}

//create a diary cell
t_d_cell_diary* CreateCellDiary(){
    t_d_cell_diary *newCell = (t_d_cell_diary*)malloc(sizeof(t_d_cell_diary));
    newCell->value = *CreateDiary();//initialise the contact contained in the cell
    newCell->MaxLevelNext = 4;
    newCell->next = (t_d_cell_diary**)malloc(sizeof(t_d_cell_diary)*newCell->MaxLevelNext);
    for(int i=0; i<=(newCell->MaxLevelNext)-1; i++) {
        newCell->next[i] = NULL;
    }
    return newCell;
}

//create a diary list
t_d_list_diary* CreateListDiary(){
    t_d_list_diary *LevelList = (t_d_list_diary*)malloc(sizeof(t_d_list_diary)); //allocate memory for the list that's going to be filled with diaries
    LevelList->MaxLevelHead = 4; //the max level of all the diary lists is four (given in subject paper)
    LevelList->head = (t_d_cell_diary **) malloc(sizeof(t_d_cell_diary*)*LevelList->MaxLevelHead);
    for(int i=0; i<=(LevelList->MaxLevelHead)-1; i++){
        LevelList->head[i] = NULL; //initialise all the heads of the list to NULL
    }
    return LevelList;
}

//add a rdv in the diary cell given
void Add_rdv_InDiaryCell(t_d_cell_diary* c){
    t_d_cell_rdv* rdv = CreateCell_rdv();
    InsertCell_rdv(c->value.list_rdv , rdv);
}

//t_d_cell_rdv* Delete_rdv_InDiaryCell(t_d_cell_diary* c, t_d_cell_rdv* rdv);//to be modified!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//search a given value in the level zero from a given list
t_d_cell_diary * ClassicContactSearch(t_d_list_diary list){
    //we ask the name to be searched to the contact
    char surname[30];
    printf("What is the surname of the contact your looking for : \n");
    scanf("%s", surname);

    // Get the head of the level zero
    int level = 0;
    t_d_cell_diary * temp = list.head[level] ;

    while(temp!=NULL && surname[0]<=(temp->value.person.surname[0])){
        if(temp->value.person.surname[0]==surname[0]){
            if(temp->value.person.surname[1]==surname[1]){
                if(temp->value.person.surname[2]==surname[2]){
                    if(temp->value.person.surname[3]==surname[3]){
                        return temp; //the value has been found
                    }
                }
            }
        }
        temp = temp->next[level];
    }
    return NULL;
}

//search a given contact in the list
//argument : the list, the contact we are looking for
//we go through the entire list from the highest level to 0 (level 0 = all the cells).
//We return the cell in which the contact has been found
t_d_cell_diary * ContactSearch(t_d_list_diary list)
{
    //we ask the name to be searched to the contact
    char surname[30];
    printf("What is the surname of the contact your looking for : \n");
    scanf("%s", surname);

    // Get the head of the last level
    int found = 0; //boolean to know if the value has been found
    int level = (list.MaxLevelHead)-1;
    t_d_cell_diary * temp = list.head[level] ;
    while(level >= 0 && found==0)
    {
        //careful : check if temp != NULL, otherwise, can't compare with surname[0]
        if(temp != NULL && temp->value.person.surname[0]==surname[0]) //if the value of the cell temp corresponds to surname[0]
        {
            if(temp->value.person.surname[1]==surname[1]){
                if(temp->value.person.surname[2]==surname[2]){
                    if(temp->value.person.surname[3]==surname[3]){
                        found = 1; //the value has been found
                    }
                }
            }
            break;
        }
        else //if the value is not found, change temp
        {
            if(temp==NULL || temp->value.person.surname[0]>surname[0])
            {
                temp = list.head[--level];//go to higher level
            }
            else
            {
                temp = temp->next[level];

            }
        }
    }

    if(found==1) return temp;

    else return NULL;
}

t_d_cell_diary * ContactSearch2(t_d_list_diary list)
{
    //we ask the name to be searched to the contact
    char surname[30];
    printf("What is the surname of the contact your looking for : \n");
    scanf("%s", surname);

    // Get the head of the last level
    int found = 0; //boolean to know if the value has been found
    int level = (list.MaxLevelHead)-1;
    t_d_cell_diary * temp = list.head[level] ;
    //t_d_cell_diary * prev = temp;

    while(level>=0 && (temp==NULL || temp->value.person.surname[0]>surname[0])){//decrease the list until the head isn't NULL and smaller or equal to surname[0]
        level--;
        temp = list.head[level];
    }
    while(level >= 0 && found==0)
    {
        if(temp->value.person.surname[0]==surname[0]) //if the value of cell temp corresponds to surname[0]
        {
            if(temp->value.person.surname[1]==surname[1]){
                if(temp->value.person.surname[2]==surname[2]){
                    if(temp->value.person.surname[3]==surname[3]){
                        found = 1; //the value has been found
                    }
                }
            }
            break;
        }

        else //if the value is not found
        {
            if(temp->next[level]==NULL) level--;//decrease level if we are at the end of the list
            else
            {
                if(temp->next[level]->value.person.surname[0]<surname[0]){
                    temp = temp->next[level];//go through the list if temp contain a smaller surname[0] than the one we are searching for
                }
                else level--;
            }
        }
    }

    if(found==1)
    {
        return temp;
    }
    else
    {
        return NULL;
    }
}

//to be modified!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Insert_DiaryCell(t_d_list_diary* list, t_d_cell_diary* cell);

void InsertSort_DiaryCell(t_d_list_diary* calendar, t_d_cell_diary* cell)
{
    int levelCell = 0; //variable which gives the number of level
    //how do I get levelCell ??????????????????????????????????????????????????????????
    t_d_cell_diary* prev = calendar->head[0]; //to go through the list and find the right place for cell
    t_d_cell_diary* temp = prev;
    if (calendar->head[0] == NULL) { //if the list is empty at the level 0
        calendar->head[0] = cell;
        return;
    }
    // Compare lastnames of temp and cell to determine the right place
    while (temp != NULL && strcmp(cell->value.person.surname, temp->value.person.surname) > 0) { //true if the last name (surname) of the person represented
        // by the cell structure comes alphabetically after the last name of the person represented by the temp structure
        prev = temp;
        temp = temp->next[0];
        //then we found the right place
    }
    //the cell must be insert after prev and before temp
    cell->next[0] = temp; //insert the cell for level 0 only
    prev->next[0] = cell;
    //know i need to find the level
    if (cell->value.person.surname[0] != temp->value.person.surname[0]) //level 3 : two cells are connected if the first letter of their string is different
    {
        levelCell = 3;
        cell->MaxLevelNext = 4;
    }
    else if (cell->value.person.surname[1] != temp->value.person.surname[1]) //level 2 :  the first letter of the cells' strings is the same but the second letter is different.
    {
        levelCell = 2;
        cell->MaxLevelNext = 3;
    }
    else if(cell->value.person.surname[2] != temp->value.person.surname[2]) //level 1: the first two letters of the cells' strings are the same but the third letter is different.
    {
        levelCell = 1;
        cell->MaxLevelNext = 2;
    }
    else //level 0 : all cells are linked.
    {
        levelCell = 1;
        cell->MaxLevelNext = 0;
    }
    //insertion at other levels
    for(int i=1; i<levelCell; i++) {
        if (calendar->head[i] == NULL) { //if the list is empty at the level i
            calendar->head[i] = cell;
            return;
        }
        temp = calendar->head[i];
        prev = calendar->head[i];
        while (temp != NULL &&
                strcmp(cell->value.person.surname, temp->value.person.surname) > 0) { //search the place to store the value by getting through the list
            prev = temp;
            temp = temp->next[i];
        }
        cell->next[i] = temp; //insert the cell
        prev->next[i] = cell;
    }
}



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
    printf("\n");
}

//display the rdv of a given contact
void Display_Contact_rdv(t_d_cell_diary c){
    Display_all_rdv(*c.value.list_rdv);
}



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
void InsertSort_DiaryCell(t_d_list_rdv* list, t_d_cell_rdv* cell) {
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