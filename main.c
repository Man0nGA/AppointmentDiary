#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "set.h"

int main() {

    t_d_cell* c = CreateCell(5, 2);
    t_d_list* l = CreateList(4);
    InsertCell(l, c);
    DisplayLevel(*l, 0);
    printf("\n");

    t_d_cell* c1 = CreateCell(21, 1);
    InsertSortCell(l, c1);
    DisplayList(*l);
    printf("\n");

    t_d_cell* c2 = CreateCell(12, 3);
    InsertSortCell(l, c2);
    DisplayList(*l);
    printf("\n");

    startTimer();
    for(int i=0; i<1000; i++){
        srand(time(NULL));
        Search(l, rand()%1000);
    }
    stopTimer();
    displayTime();

    return 0;
}
