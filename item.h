#ifndef ITEM_H
#define ITEM_H

struct _Item {
    double price;
    char *sku;
    char *name;
    char *category;
};
typedef struct _Item Item;

/*void add_item(Item *item_list, double price, const char *sku, const char *category, const char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);
Item *find_item(Item *item_list, int size, const char *sku);*/

#endif
