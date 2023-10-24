#include "set.h"
#include <stdlib.h>

//create a cell with parameters a value and the number of pointers
t_d_cell* CreateCell(int val,int MaxLevelPointer){
    t_d_cell *newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    newCell->value = val;
    for (int i=0;i<=MaxLevelPointer;i++){
        newCell->next[i]=NULL;
    }
    return newCell;
}