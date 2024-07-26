// Written by: Jan Mohammadi YA Rza  (AV2z3A) on 2024.01.14
#include "Imp_assignment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_CAPACITY 10

void memoryStore(store *newStore) {
    newStore->products = (product *)malloc(FIRST_CAPACITY * sizeof(product));
    newStore->size = 0;
    newStore->capacity = FIRST_CAPACITY;
}
void memoryCart(cart *cart) {
    cart->products = (product *)malloc(FIRST_CAPACITY * sizeof(product));
    cart->size = 0;
    cart->capacity = FIRST_CAPACITY;
}

void load(store *newStore, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Can't read/open the file or the file is empty: %s\n", filename);
        return;
    }

    while (fscanf (file, "%s %d %d", newStore->products[newStore->size].name,&newStore->products[newStore->size].price,&newStore->products[newStore->size].quantity) == 3) {
        newStore->size++;

        if (newStore->size >= newStore->capacity) {
            newStore->capacity *= 2;
            newStore->products = realloc(newStore->products, newStore->capacity * sizeof(product));
        }
    }

    fclose(file);
}

void write(const store *newStore, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Can't open the given file for writing: %s\n", filename);
        return;
    }

    for (int i = 0; i < newStore->size; ++i) {
        fprintf(file, "%s %d %d\n", newStore->products[i].name,
                newStore->products[i].price, newStore->products[i].quantity);
    }

    fclose(file);
}

void insert(cart *newCart, const store *newStore) {
    printf("Type the product name: ");
    scanf("%s", newCart->products[newCart->size].name);

    for (int i = 0; i < newStore->size; ++i) {
        if (strcmp(newCart->products[newCart->size].name, newStore->products[i].name) == 0) {
            newCart->products[newCart->size].price = newStore->products[i].price;
            break;
        }
    }

    printf("Type the quantity: ");
    scanf("%d", &newCart->products[newCart->size].quantity);

    newCart->size++;

    if (newCart->size == newCart->capacity) {
        newCart->capacity *= 2;
        newCart->products = realloc(newCart->products, newCart->capacity * sizeof(product));
    }
}

int sumCart(const cart *newCart, const store *newStore) {
    int sum = 0;
    for (int i = 0; i < newCart->size; ++i) {
        sum += (newCart->products[i].price * newCart->products[i].quantity);
    }
    return sum;
}

void buyCart(cart *newCart, store *newStore) {
    for (int i = 0; i < newCart->size; ++i) {
        for (int j = 0; j < newStore->size; ++j) {
            if (strcmp(newCart->products[i].name, newStore->products[j].name) == 0) {
                if (newCart->products[i].quantity <= newStore->products[j].quantity) {
                    newStore->products[j].quantity -= newCart->products[i].quantity;
                } else {
                    printf("%s is missing. Only %d available.\n", newCart->products[i].name, newStore->products[j].quantity);
                    newStore->products[j].quantity = 0;
                }
                break;
            }
        }
    }
}

void exitProg(store *newStore, cart *newCart) {
    free(newStore->products);
    free(newCart->products);
    printf("Thanks for choosing us. See you again! \n\n");
}