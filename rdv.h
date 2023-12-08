#ifndef TEST_SET_H
#define TEST_SET_H


typedef struct rendezvous //define a structure of meeting
{
    int date[3];
    int time[2];
    int duration[2];
    char* purpose;
} rdv;

//Structure of a cell
typedef struct s_d_cell_rdv
{
    rdv value;
    struct s_d_cell_rdv *next;
} t_d_cell_rdv;

//Structure of a list of cell
typedef struct s_d_list_rdv
{
    t_d_cell_rdv *head;
} t_d_list_rdv;


rdv* Create_rdv();
t_d_cell_rdv* CreateCell_rdv();
t_d_list_rdv* CreateList_rdv();
void InsertCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell);
void Display_rdv(t_d_cell_rdv cell);
void Display_all_rdv(t_d_list_rdv list);

/*
void InsertSortCell_rdv(t_d_list_rdv* list, t_d_cell_rdv* cell);

t_d_cell_rdv* ClassicSearch(t_d_list_rdv* list, int val, t_d_cell_rdv* prev);
t_d_cell_rdv* Search(t_d_list_rdv* list, int val);
 */

#endif //TEST_SET_H
