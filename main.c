#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "menu.h"

int main() {
    int a = 1;
    int* run = &a; // pointer which allows the menu to run or not
    t_d_list_diary* calendar = CreateListDiary(); //represent the list of every diaries

    while (*run!=0)
    {
        UserInterface(run, calendar);
    }

    return 0;
}
