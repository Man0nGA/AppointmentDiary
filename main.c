#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "rdv.h"

int main() {

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
    InsertSortCell(l, c2);
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

    return 0;
}
