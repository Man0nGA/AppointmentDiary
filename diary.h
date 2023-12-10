#ifndef MEGADIARY_DIARY_H
#define MEGADIARY_DIARY_H
#include "rdv.h"

//structure of a contact
typedef struct t_contact //define a structure of contact
{
    char firstname[30];//must create string with definite max size, else allocation problems
    char surname[30];//we use unsigned char for conversion to ASCII code
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
diary* CreateDiary();
t_d_cell_diary* CreateCellDiary();
t_d_list_diary* CreateListDiary();

//functions to search for a contact
t_d_cell_diary * ClassicContactSearch(t_d_list_diary list);
t_d_cell_diary * ContactSearch(t_d_list_diary list);
t_d_cell_diary * ContactSearch2(t_d_list_diary list);

//functions to manage rdv
void Add_rdv_InDiaryCell(t_d_cell_diary* c);
t_d_cell_rdv* Delete_rdv_InDiaryCell(t_d_cell_diary* c, t_d_cell_rdv* rdv);

//insert a diary cell in the diary list depending on the surname of the contact
void Insert_DiaryCell(t_d_list_diary* list, t_d_cell_diary* cell);
void InsertSort_DiaryCell(t_d_list_diary* list, t_d_cell_diary* cell);

//display functions
void Display_DiaryList(t_d_list_diary l);//display all the contacts in the list
void Display_Contact_rdv(t_d_cell_diary c);//display the rdv of a given contact




#endif //MEGADIARY_DIARY_H