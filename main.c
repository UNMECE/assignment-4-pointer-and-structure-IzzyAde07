#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    if (index >= 0 && index < 5){
    item_list[index].price = price;
    item_list[index].sku = malloc(sizeof(char) *strlen((sku)+1));
    item_list[index].name = malloc(sizeof(char) *strlen((name)+1));
    item_list[index].category = malloc(sizeof(char) *strlen((category)+1));
    strcmp(item_list[index].sku, sku);
    strcmp(item_list[index].name, name);
    strcmp(item_list[index].category, category);
	}
}

void free_items(Item *item_list, int size) {
    int i = 0;
    for (i; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += item_list[i].price;
    }
    if (size > 0) {
        return sum / size;
    } else {
        return 0.0;
    }
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %lf\n", item_list[i].price);
    }
    printf("###############\n");
}

Item *find_item(Item *item_list, int size, const char *sku) {
    int ct = 0;
    while (ct < size && strcmp(item_list[ct].sku, sku) != 0) {
        ct++;
    }
    if (ct < size) {
        return &item_list[ct];
    } else {
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    int size = 5;
    Item *items = (Item *)malloc(size * sizeof(Item));
    
    add_item(items, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(items, 3.95, "79862", "dairy", "milk", 1);
    add_item(items, 7.50, "56342", "snack", "chips", 2);
    add_item(items, 2.99, "23114", "drink", "soda", 3);
    add_item(items, 12.49, "87931", "meat", "steak", 4);
    
    print_items(items, size);
    printf("average price of items = %lf\n", average_price(items, size));
    
    if (argc > 1) {
        Item *found = find_item(items, size, argv[1]);
        if (found) {
            printf("Found item:\n");
            printf("item name = %s\n", found->name);
            printf("item sku = %s\n", found->sku);
            printf("item category = %s\n", found->category);
            printf("item price = %lf\n", found->price);
        } else {
            printf("Item not found.\n");
        }
    }
    
    free_items(items, size);
    return 0;
}

