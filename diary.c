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

    //transform all the capital letters to lowercase ones
    int i = 0;
    while(newcontact->firstname[i]!='\0'){
        if (newcontact->firstname[i] <= 90 && newcontact->firstname[i] >= 65) {
            newcontact->firstname[i] += 32;
        }
        i++;
    }
    i = 0;
    while(newcontact->surname[i]!='\0'){
        if (newcontact->surname[i] <= 90 && newcontact->surname[i] >= 65) {
            newcontact->surname[i] += 32;
        }
        i++;
    }
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

//delete an appointment in the diary cell
void Delete_rdv_InDiaryCell(t_d_cell_diary* c){
    char * purp = (char*)malloc(sizeof(char));
    printf("Purpose of the appointment you want to delete : \n");
    scanf("%s", purp);
    t_d_cell_rdv* temp = c->value.list_rdv->head;
    t_d_cell_rdv* prev = temp;
    while(temp!=NULL){
        if(strcmp(temp->value.purpose, purp)==0){//strcmp() return 0 if the two strings are equal
            printf("%s", temp->value.purpose);
            prev->next = temp->next;
            temp->next = NULL;
            free(temp->value.purpose);
            free(temp);
            free(purp);
            printf("Appointment deleted.\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

//search a given value in the level zero from a given list
t_d_cell_diary * ClassicContactSearch(t_d_list_diary list){
    //we ask the name to be searched to the contact
    char surname[30];
    printf("Enter the first three surname letters of the contact your looking for : \n");
    scanf("%s", surname);//have to secure input!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //transform all the capital letters to lowercase one
    int i=0;
    while(surname[i]!='\0'){
        if(surname[i]<=90 && surname[i]>=65){
            surname[i] += 32;
        }
        i++;
    }

    // Get the head of the level zero
    int level = 0;
    t_d_cell_diary * temp = list.head[level] ;

    while(temp!=NULL && surname[0]<=(temp->value.person.surname[0])){
        if(temp->value.person.surname[0]==surname[0] && temp->value.person.surname[1]==surname[1]
        && temp->value.person.surname[2]==surname[2]){

            int ind = 0, choice = 0;
            char buffer[256];

            //display all the contacts with the three letters provided
            t_d_cell_diary * current = temp;
            printf("Enter the number corresponding to your contact :\n");
            while(current!=NULL && current->value.person.surname[0] == surname[0] && current->value.person.surname[1] == surname[1] && current->value.person.surname[2] == surname[2]){
                printf("%d. %s %s\n", ind+1, current->value.person.firstname, current->value.person.surname);
                current = current->next[0];
                ind++;
            }

            while (scanf("%d", &choice) != 1) {
                printf("Invalid input. Please enter a number.\n");

                // Vider le tampon d'entrée
                scanf("%s", buffer);
            }
            printf("\n");

            //ensure that the pointer returned correspond to the contact chosen by the user
            for(int index = 0; index<ind-1; index++){
                temp = temp->next[0];
            }
            return temp; //the value has been found
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
    char surname[3];
    printf("Enter the first three surname letters of the contact your looking for : \n");
    scanf("%s", surname);//have to secure input!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //transform all the capital letters to lowercase one
    int i=0;
    while(surname[i]!='\0'){
        if(surname[i]<=90 && surname[i]>=65){
            surname[i] += 32;
        }
        i++;
    }

    // Get the head of the last level
    int found = 0; //boolean to know if the value has been found
    int level = (list.MaxLevelHead)-1;
    t_d_cell_diary * temp = list.head[level] ;

    while(level>=0 && (temp==NULL || temp->value.person.surname[0]>surname[0])){//decrease the list until the head isn't NULL and smaller or equal to surname[0]
        level--;
        temp = list.head[level];
    }
    while(level >= 0 && found==0)
    {
        if(temp->value.person.surname[0]==surname[0] && temp->value.person.surname[1]==surname[1]
           && temp->value.person.surname[2]==surname[2]){
            found = 1; //the value has been found
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
        int ind = 0, choice = 0;
        char buffer[256];

        t_d_cell_diary * current = temp;
        printf("Enter the number corresponding to your contact :\n");
        while(current!=NULL && current->value.person.surname[0] == surname[0] && current->value.person.surname[1] == surname[1] && current->value.person.surname[2] == surname[2]){
            printf("%d. %s %s\n", ind+1, current->value.person.firstname, current->value.person.surname);
            current = current->next[0];
            ind++;
        }

        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            // Vider le tampon d'entrée
            scanf("%s", buffer);
        }
        printf("\n");

        for(int index = 0; index<ind-1; index++){
            temp = temp->next[0];
        }
        return temp;
    }
    else
    {
        return NULL;
    }
}

//Insert a cell at the level 0, on the alphabetical order
void Insert_DiaryCell(t_d_list_diary* calendar, t_d_cell_diary* cell){
    t_d_cell_diary* prev = calendar->head[0]; //to go through the list and find the right place for cell
    t_d_cell_diary* temp = prev;
    if (calendar->head[0] == NULL) { //if the list is empty at the level 0
        calendar->head[0] = cell;
    }
    else {
        // Compare lastnames of temp and cell to determine the right place
        while (temp != NULL && strcmp(cell->value.person.surname, temp->value.person.surname) >
                               0) { //true if the last name (surname) of the person represented
            // by the cell structure comes alphabetically after the last name of the person represented by the temp structure
            prev = temp;
            temp = temp->next[0];
            //then we found the right place
        }
        if (prev == temp) {
            //the cell must be inserted at the head
            cell->next[0] = calendar->head[0]; //insert the cell for level 0 only*
            calendar->head[0] = cell;
        } else {
            //the cell must be insert after prev and before temp
            cell->next[0] = prev->next[0]; //insert the cell for level 0 only*
            prev->next[0] = cell;
        }
    }
}

//Insert a cell on a certain number of levels and at a certain place depending on its alphabetical order
void InsertSort_DiaryCell(t_d_list_diary* calendar, t_d_cell_diary* cell)
{
    int levelCell = 3; //variable which gives the number of level
    t_d_cell_diary* prev = calendar->head[0]; //to go through the list and find the right place for cell
    t_d_cell_diary* temp = prev;
    if (calendar->head[0] == NULL) { //if the list is empty at the level 0
        calendar->head[0] = cell;
        levelCell=3;
    }
    else {
        // Compare lastnames of temp and cell to determine the right place
        while (temp != NULL && strcmp(cell->value.person.surname, temp->value.person.surname) > 0)
        { //true if the last name (surname) of the person represented
            // by the cell structure comes alphabetically after the last name of the person represented by the temp structure
            prev = temp;
            temp = temp->next[0];
            //then we found the right place
        }
        if(prev == temp){
            //the cell must be inserted at the head
            cell->next[0] = calendar->head[0]; //insert the cell for level 0 only*
            calendar->head[0] = cell;
        }
        else{
            //the cell must be insert after prev and before temp
            cell->next[0] = prev->next[0]; //insert the cell for level 0 only*
            prev->next[0] = cell;
        }

        //now i need to find the level
        if (cell->value.person.surname[0] == prev->value.person.surname[0]) //level 3 : two cells are connected if the first letter of their string is different
        {
            levelCell--;
            cell->MaxLevelNext--;
            if (cell->value.person.surname[1] == prev->value.person.surname[1]) //level 2 :  the first letter of the cells' strings is the same but the second letter is different.
            {
                levelCell--;
                cell->MaxLevelNext--;
                if(cell->value.person.surname[2] == prev->value.person.surname[2]) //level 1: the first two letters of the cells' strings are the same but the third letter is different.
                {
                    levelCell--;
                    cell->MaxLevelNext--;
                }
            }

        }

    }

    //insertion at other levels
    for(int i=1; i<=levelCell; i++) {
        if (calendar->head[i] == NULL) { //if the list is empty at the level i
            calendar->head[i] = cell;

        }
        else {
            temp = calendar->head[i];
            prev = calendar->head[i];
            while (temp != NULL &&
                   strcmp(cell->value.person.surname, temp->value.person.surname) > 0)
            { //search the place to store the value by getting through the list
                prev = temp;
                temp = temp->next[i];
            }
            if(prev == temp){
                //the cell must be inserted at the head
                cell->next[i] = calendar->head[i]; //insert the cell
                calendar->head[i] = cell;
            }
            else{
                //the cell must be insert after prev and before temp
                cell->next[i] = prev->next[i]; //insert the cell
                prev->next[i] = cell;
            }
        }
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

//save all the appointments in a file
void Save_rdv(t_d_list_diary l){
    t_d_cell_diary * temp= l.head[0];
    FILE * save;
    save = fopen("Appointments_save.txt", "w+");
    if(save==NULL) printf("Error opening the file");
    while(temp!=NULL){
        fprintf(save, "%s %s\n",temp->value.person.firstname, temp->value.person.surname);
        t_d_cell_rdv * temp_rdv = temp->value.list_rdv->head;

        if(temp_rdv==NULL){
            fprintf(save, "No appointment !\n");
        }

        while(temp_rdv!=NULL){
            //calcul of the end time of the appointment
            int hour_end = (temp_rdv->value.duration[1]+temp_rdv->value.time[1])/60 + temp_rdv->value.duration[0]+temp_rdv->value.time[0]%24;
            int minute_end = (temp_rdv->value.duration[1]+temp_rdv->value.time[1])-(temp_rdv->value.duration[1]+temp_rdv->value.time[1])/60;
            fprintf(save, "%s\n%d %d %d\n%d %d\n%d %d\n",
                   temp_rdv->value.purpose, temp_rdv->value.date[0], temp_rdv->value.date[1], temp_rdv->value.date[2], temp_rdv->value.time[0], temp_rdv->value.time[1], hour_end, minute_end);
            temp_rdv = temp_rdv->next;
        }
        fprintf(save, "\n");
        temp = temp->next[0];
    }
    fclose(save);
}