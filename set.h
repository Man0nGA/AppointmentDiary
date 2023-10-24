#ifndef TEST_SET_H
#define TEST_SET_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell **next;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell **head;
    int MaxLevelHead;
} t_d_list;

t_d_cell* CreateCell(int val,int MaxLevelPointer);

#endif //TEST_SET_H
