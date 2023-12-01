#ifndef MEGADIARY_DIARY_H
#define MEGADIARY_DIARY_H
#include "rdv.h"


typedef struct t_contact //define a structure of contact
{
    char** firstname;
    char** surname;
} contact;

typedef struct t_diary
{
    contact person;
    t_d_list_rdv list_rdv;
}diary;

//Structure of a cell
typedef struct s_d_cell_diary
{
    diary value;
    int MaxLevelNext;
    struct s_d_cell_diary **next;
} t_d_cell_diary;

//Structure of a list of cell
typedef struct s_d_list_diary
{
    t_d_cell_diary **head;
    int MaxLevelHead;
} t_d_list_diary;


////////////////////////////////////////////////
/////////////////////////////////////////To be modify //////////////////
/*
//Part 1
t_d_cell_rdv* CreateCell(rdv val, int MaxLevelPointer);
t_d_list_rdv* CreateList(int MaxLevelHead);
void InsertCell(t_d_list_rdv* list, t_d_cell_rdv* cell);
void DisplayLevel(t_d_list_rdv list, int level);
void DisplayList(t_d_list_rdv list);
void InsertSortCell(t_d_list_rdv* list, t_d_cell_rdv* cell);

//Part 2
t_d_cell_rdv* ClassicSearch(t_d_list_rdv* list, int val, t_d_cell_rdv* prev);
t_d_cell_rdv* Search(t_d_list_rdv* list, int val);
 */
////////////////////////////////////////////////////////////////////////



#endif //MEGADIARY_DIARY_H
