#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "menu.h"

int main() {
    int a = 1;
    int* run = &a; // pointer which allows the menu to run or not

    while (*run!=0)
    {
        UserInterface(run);
    }
    /*
    //test of the rdv functions
    //we insert a cell in a list, display the cell then the list
    t_d_cell_rdv* r_cell = CreateCell_rdv();
    t_d_list_rdv* r_list =  CreateList_rdv();
    InsertCell_rdv(r_list, r_cell);
    Display_rdv(*r_cell);
    Display_all_rdv(*r_list);

    //test of the diary functions
    t_d_cell_diary* d_cell =  CreateCellDiary();
    Add_rdv_InDiaryCell(d_cell, r_cell);
    t_d_list_diary* d_list = CreateListDiary();
    //add the cell in the list!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (InsertSort_DiaryCell())
    Display_DiaryList(*d_list);

    //search for a contact in the diary list
    ContactSearch(d_list, d_cell->value.person);


    //Part 1

    //create a cell c and a list l
    t_d_cell_rdv* c = CreateCell(5, 2);
    t_d_list_rdv* l = CreateList(4);
    //insert a cell in the list l
    InsertCell(l, c);
    //display the list at the level 0
    DisplayLevel(*l, 0);
    printf("\n");

    //create a cell c1
    t_d_cell_rdv* c1 = CreateCell(21, 1);
    //insert the cell c1 in l sorted
    InsertSortCell(l, c1);
    //display the list
    DisplayList(*l);
    printf("\n");

    //create a cell c2
    t_d_cell_rdv* c2 = CreateCell(12, 3);
    //insert the cell c2 in l sorted
    InsertSort_DiaryCell(l, c2);
    //display the list
    DisplayList(*l);
    printf("\n");

    //Part 2

    //view the complexity of searching a value
    startTimer();
    for(int i=0; i<1000; i++){
        srand(time(NULL));
        Search(l, rand()%1000);
    }
    stopTimer();
    displayTime();
    */
    return 0;
}
