// Written by: Jan Mohammadi YA Rza (AV2z3A) on 2024.01.14
#include "Imp_assignment.h"
#include <stdio.h>

int main() {
    store store1;
    cart cart1;
    char fileToLoad[500];
    char fileToWrite[500];
    int num;
    memoryStore(&store1);
    memoryCart(&cart1);

    do {
        printf("Tell me what you want to do :\n");
        printf("1. Load webshop store from a file\n");
        printf("2. Write the content of the store to a file\n");
        printf("3. Insert an item to cart\n");
        printf("4. Get the price of cart\n");
        printf("5. Buy the products\n");
        printf("6. Exit the program\n");

        printf("Enter your choice: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf ("Please write the file name that you want to load from: ");
                scanf("%s", &fileToLoad);
                load(&store1, fileToLoad);
                break;
            case 2:
                printf ("Please write the file name that you want to write to: ");
                scanf("%s", &fileToWrite);
                write(&store1,fileToWrite);
                break;
            case 3:
                insert(&cart1, &store1);
                break;
            case 4:
                printf("The total price of the cart is: %d\n\n", sumCart(&cart1, &store1));
                break;
            case 5:
                printf("Thanks for buying from us :)\n\n");
                buyCart(&cart1, &store1);
                break;
            case 6:
                exitProg(&cart1, &store1);
                break;
            default:
                printf("There is no such choice please choose again :). \n \n");
        }

    } while (num != 6);
    return 0;
}
