#ifndef ITEM_H
#define ITEM_H

struct s_item{
    unsigned int id;//identifier
    int a;//size
    int c;//profit
};
typedef struct s_item item;

typedef item* tab_items;

#endif
