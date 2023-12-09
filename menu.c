#include <stdio.h>
#include "menu.h"


void UserInterface(int* run){
    int choice;
    char buffer[256];  // Utilisé pour vider le tampon d'entrée

    do {
        printf("\nMenu:\n");
        printf("1. Search for a contact\n");
        printf("2. View a contact's appointments\n");
        printf("3. Create a contact\n");
        printf("4. Create an appointment for a contact\n");
        printf("5. Delete an appointment\n");
        printf("6. Save the file of all appointments\n");
        printf("7. Load an appointment file\n");
        printf("8. Calculate insertion time for a new contact\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        // Vérification de l'entrée
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            // Vider le tampon d'entrée
            scanf("%s", buffer);
        }

        switch (choice) {
            case 1:
                printf("Hello world !!!");
                break;
            case 2:
                printf("Hello world !!!");
                break;
            case 3:
                printf("Hello world !!!");
                break;
            case 4:
                printf("Hello world !!!");
                break;
            case 5:
                printf("Hello world !!!");
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
