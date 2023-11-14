#include <stdio.h>
#include "set.h"

int main() {
    printf("Hello, World!\n");
    printf("This is wonderful !\n");
    printf("test\n");
    t_d_cell* c = CreateCell(5, 2);
    printf("%d %p %p %p\n", c->value, c->next[0], c->next[1], c->next[2]);
    return 0;
}
