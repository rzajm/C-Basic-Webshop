// Imp_assignment.h
// Written by: Jan Mohammadi YA Rza  (AV2z3A) on 2024.01.14
#ifndef IMP_ASSIGNMENT_H

#define IMP_ASSIGNMENT_H

#define MAX_CAPACITY 20

typedef struct {
    char name[20];
    int price;
    int quantity;
} product;

typedef struct {
    product *products;
    int size;
    int capacity;
} store, cart;


void memoryStore(store *newStore);
void memoryCart(cart *newCart);
void load(store *newStore, char *filename);
void write(const store *newStore, char *filename);
void insert(cart *newCart, const store *newStore);
int sumCart(const cart *newCart, const store *newStore);
void buyCart(cart *newCart, store *newStore);
void exitProg(store *newStore, cart *newCart);

#endif // IMP_ASSIGNMENT_H