#ifndef TEST_SET_H
#define TEST_SET_H


typedef struct t_contact //define a structure of contact
{
    char** firstname;
    char** surname;
} contact;

typedef struct rendezvous //define a structure of meeting
{
    int date[3];
    int time[2];
    int duration[2];
    char** purpose;
} rdv;

//Structure of a cell
typedef struct s_d_cell
{
    rdv value;
    int MaxLevelNext;
    struct s_d_cell **next;
} t_d_cell_rdv;

//Structure of a list of cell
typedef struct s_d_list
{
    t_d_cell_rdv **head;
    int MaxLevelHead;
} t_d_list_rdv;


//Part 1
t_d_cell_rdv* CreateCell_rdv(rdv val, int MaxLevelPointer);
t_d_list_rdv* CreateList_rdv(int MaxLevelHead);
void InsertCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell);
void display_rdv(t_d_cell_rdv);
void display_all_rdv(t_d_list_rdv);

/*
void InsertSortCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell);


//Part 2
t_d_cell_rdv* ClassicSearch(t_d_list_rdv* list, int val, t_d_cell_rdv* prev);
t_d_cell_rdv* Search(t_d_list_rdv* list, int val);
 */

#endif //TEST_SET_H
