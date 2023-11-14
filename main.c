#include <stdio.h>
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

    return 0;
}
