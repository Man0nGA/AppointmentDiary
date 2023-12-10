#include <stdio.h>
#include "menu.h"
#include "timer.h"

//calcul the complexity of our insert functions
void CalculInsert(t_d_list_diary * calendar){
    printf("Time for a inserting only at the level 0.\n");
    startTimer();
    FILE * f_name = fopen("files-names/noms2008nat_txt.txt", "r");
    if(f_name == NULL) printf("Can't open the file. File doesn't exist.\n");
    char name[30];
    while(fgets(name, 30, f_name)){
        Insert_DiaryCell(calendar, CreateCellDiary());
    }
    fclose(f_name);
    stopTimer();
    displayTime();

    printf("Time for a inserting at all levels.\n");
    startTimer();
    FILE * f_name2 = fopen("files-names/noms2008nat_txt.txt", "r");
    if(f_name == NULL) printf("Can't open the file. File doesn't exist.\n");
    char name2[30];
    while(fgets(name2, 30, f_name2)){
        Insert_DiaryCell(calendar, CreateCellDiary());
    }
    fclose(f_name);
    stopTimer();
    displayTime();
}

//calcul the complexity of our search functions
void CalculSearch(t_d_list_diary *calendar){
    printf("Time for a inserting only at the level 0.\n");
    startTimer();
    FILE * f_name = fopen("files-names/noms2008nat_txt.txt", "r");
    if(f_name == NULL) printf("Can't open the file. File doesn't exist.\n");
    char name[30];
    while(fgets(name, 30, f_name)){

        //transform all the capital letters to lowercase one
        int i=0;
        while(name[i]!='\0'){
            if(name[i]<=90 && name[i]>=65){
                name[i] += 32;
            }
            i++;
        }

        ClassicContactSearch(*calendar, name);
    }
    fclose(f_name);
    stopTimer();
    displayTime();

    //sorry from here this part of the function doesn't work :/
    printf("Time for a inserting at all levels.\n");
    startTimer();
    FILE * f_name2 = fopen("files-names/noms2008nat_txt.txt", "r");
    if(f_name == NULL) printf("Can't open the file. File doesn't exist.\n");
    char name2[30];
    while(fgets(name2, 30, f_name2)){
        ContactSearch(*calendar);
    }
    fclose(f_name);
    stopTimer();
    displayTime();
}

void UserInterface(int* run, t_d_list_diary* calendar){
    int choice;
    char buffer[256];  // Utilisé pour vider le tampon d'entrée

    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Create a contact\n");
        printf("2. Create an appointment for a contact\n");
        printf("3. Search for a contact\n");
        printf("4. View a contact's appointments\n");
        printf("5. Delete an appointment\n");
        printf("6. Save the file of all appointments\n");
        printf("7. Load an appointment file\n");
        printf("8. Calculate insertion time for a new contact\n");
        printf("0. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        // Vérification de l'entrée
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            // Vider le tampon d'entrée
            scanf("%s", buffer);
        }
        printf("\n");

        switch (choice) {
            case 1:;
                t_d_cell_diary* newContact = CreateCellDiary();
                InsertSort_DiaryCell(calendar, newContact);
                printf("Contact Created\n");
                break;
            case 2:;
                t_d_cell_diary * cell = ContactSearch(*calendar);
                if(cell!=NULL){
                    Add_rdv_InDiaryCell(cell);
                    printf("Appointment Created\n");
                }
                else printf("Can't add any appointment ! This contact doesn't exist !\n");
                break;
            case 3:;
                t_d_cell_diary * found_cell = ContactSearch(*calendar);
                if(found_cell!=NULL)
                {
                    printf("The contact '%s %s' has been found\n", found_cell->value.person.firstname, found_cell->value.person.surname);
                    printf("\n");
                }
                else
                {
                    printf("This contact has not been found : (\n");
                    printf("\n");
                }
                break;
            case 4:;
                t_d_cell_diary * view_cell = ContactSearch(*calendar);
                if(cell!=NULL) Display_Contact_rdv(*view_cell);
                else printf("This contact doesn't exist !\n");
                break;
            case 5:;
                t_d_cell_diary * del_cell = ContactSearch(*calendar);
                Delete_rdv_InDiaryCell(del_cell);
                break;
            case 6:;
                Save_rdv(*calendar);
                printf("Appointments saved\n");
                break;
            case 7:;
                //t_d_list_diary * list = Load_rdv();
                printf("Couldn't load a file.\n");
                break;
            case 8:
                printf("Complexity comparison on inserting a cell only at level zero and at all levels.\n");
                CalculInsert(calendar);
                printf("\n");
                printf("Complexity comparison on searching a contact only at level zero and at all levels.\n");
                CalculSearch(calendar);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                *run = 0;
                return;
            default:
                printf("Invalid choice. Please try again.\n"); //if the integer entered is not among the possible choices
                break;
        }
    printf("Press ENTER to continue.");
    fflush(stdin);
    getchar();
    } while (choice != 0);

    return;
}

