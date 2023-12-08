#ifndef MEGADIARY_DIARY_H
#define MEGADIARY_DIARY_H
#include "rdv.h"

//structure of a contact
typedef struct t_contact //define a structure of contact
{
    char* firstname;
    char* surname;
} contact;

//structure of a diary
typedef struct t_diary
{
    contact person;
    t_d_list_rdv* list_rdv;
}diary;

//Structure of a diary cell
typedef struct s_d_cell_diary
{
    diary value;
    int MaxLevelNext;
    struct s_d_cell_diary **next;
} t_d_cell_diary;

//Structure of a list of diary cell
typedef struct s_d_list_diary
{
    t_d_cell_diary **head;
    int MaxLevelHead;
} t_d_list_diary;


//functions to create variable of a certain structure type
contact* CreateContact();
diary* CreateDiary(contact person);
t_d_cell_diary* CreateCellDiary(int MaxLevelNext);
t_d_list_diary* CreateListDiary(int MaxLevelHead);

//functions to search for a contact
t_d_cell_diary * ClassicContactSearch(t_d_list_diary* list, contact c);
t_d_cell_diary * ContactSearch(t_d_list_diary* list, contact c);

//functions to manage rdv
void Add_rdv_InCellDiary(t_d_cell_diary* c, t_d_cell_rdv* rdv);
t_d_cell_rdv* Delete_rdv_InCellDiary(t_d_cell_diary* c, t_d_cell_rdv* rdv);

//insert a diary cell in the diary list depending on the surname of the contact
void InsertSortCell(t_d_list_diary* list, t_d_cell_diary* cell);

//diplay functions
void Display_DiaryList(t_d_list_diary * l);//display all the contacts in the list
void Display_Contact_rdv_FromList(t_d_list_diary * l, contact c);//display the rdv of a given contact

//must add at the end a function to make it more user friendly (like the display Mailinh send on discord)


#endif //MEGADIARY_DIARY_H
