#include <stdio.h>
#include "menu.h"


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
                if(cell!=NULL) Add_rdv_InDiaryCell(cell);
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
            case 6:
                printf("Hello world !!!");
                break;
            case 7:
                printf("Hello world !!!");
                break;
            case 8:
                printf("Hello world !!!");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                *run = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n"); //if the integer entered is not among the possible choices
                break;
        }

    } while (choice != 0);

    return;
}

