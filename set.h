#ifndef TEST_SET_H
#define TEST_SET_H

typedef struct s_d_cell
{
    int value, MaxLevelNext;
    struct s_d_cell **next;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell **head;
    int MaxLevelHead;
} t_d_list;

t_d_cell* CreateCell(int val,int MaxLevelPointer);
t_d_list* CreateList(int MaxLevelHead);
void InsertCell(t_d_list* list, t_d_cell* cell);
void DisplayLevel(t_d_list list, int level);
void DisplayList(t_d_list list);
void InsertSortCell(t_d_list* list, t_d_cell* cell);

#endif //TEST_SET_H
